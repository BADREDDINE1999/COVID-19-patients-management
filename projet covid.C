#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define a 50
#define MAX 1538
#define Malloc(type)  (type *)malloc(sizeof(type))


typedef struct donnees_patients{
char ville[a];char secteur[a];char etat[a];
char nom[a];char prenom[a];char cin[a];
}donnees_patients;


typedef  struct ptrpatients{
donnees_patients* p;
struct ptrpatients *ps;
}ptrpatients;


typedef struct donnees_contacts{
char ville[a];char secteur[a];char nom[a];char prenom[a];char cin[a];
}donnees_contacts;


typedef  struct ptrcontacts{
donnees_contacts* c;
struct ptrcontacts *cs;
}ptrcontacts;


typedef struct donnees_gueris{
char ville[a];char secteur[a];char nom[a];char prenom[a];char cin[a];
}donnees_gueris;


typedef  struct ptrgueris{
donnees_gueris* g;
struct ptrgueris *gs;
}ptrgueris;


typedef struct donnees_deces{
char ville[a];char secteur[a];char nom[a];char prenom[a];char cin[a];
}donnees_deces;


typedef  struct ptrdeces{
donnees_deces* de;
struct ptrdeces* ds;
}ptrdeces;


typedef struct villes{
	char nomVille[a];
	ptrpatients *fstp;
	int nbrpatients;
	int nbrcritique;
	double lits;
	double reanimation;
	ptrcontacts *fstc;
	int nbrcontacts;
	double propagation;
	ptrgueris *fstg;
	int nbrgueris;
	double guerison[2];
	ptrdeces *fstd;
	int nbrdeces;
	double taux_deces[3];

} villes;



villes v[MAX]; //tableau des villes



villes* insererpatient( donnees_patients* pat,int choix){
int k,i,j;
	for(i=0;i<MAX;i++)
	{
		if(strcmp(v[i].nomVille,pat->ville)==0)
		{
		    v[i].nbrpatients++;
			break;
		}
}/*Dans cette boucle for :si la ville existe  on ajoute nbrpatients de 1 et on sort avec
l'indice de la case de la ville sinon càd la ville n'existe pas on cherche la 1 ére ville
 qui  n'a pas de patients et on affecte la nouvelle ville à cette case */
if (i<MAX){
        ptrpatients* curs=v[i].fstp;
    while(curs!=NULL)
		{
			if((strcmp(curs->p->cin,pat->cin)==0))
			{
				break;
			}
			else
			{
				curs=curs->ps;
			}
		}
if (curs!=NULL){
    printf("patient existe deja");
    return v;
}
else{
ptrpatients* d;
d=Malloc(ptrpatients);
d=v[i].fstp;
ptrpatients* nouveau=Malloc(ptrpatients);
nouveau->p=pat;
nouveau->ps=d;
d=nouveau;
k=i;
if(choix==0){
printf("donnez le nouveau taux des lits occupés");
scanf("%lf",&(v[k].lits));
printf("donnez le nouveau taux de lits de reanimation occupes");
scanf("%lf",&(v[k].reanimation));
if (strcmp(pat->etat,"critique")==0)
    v[k].nbrcritique++;
return v;}
else{
if (strcmp(pat->etat,"critique")==0)
    v[k].nbrcritique++;
return v;
}
}
}
else{
  for(j=0;j<MAX;j++)
	{
		if(v[j].nbrpatients==0)
		{
		    strcpy(v[j].nomVille,pat->ville);
		    v[j].nbrpatients++;
			break;
		}
}
ptrpatients* d;
d=v[j].fstp;
ptrpatients* nouveau=Malloc(ptrpatients);
nouveau->p=pat;
nouveau->ps=NULL;
d=nouveau;
k=j;
if(choix==0){
printf("donnez le nouveau taux des lits occupés");
scanf("%lf",&(v[k].lits));
printf("donnez le nouveau taux de lits de reanimation occupes");
scanf("%lf",&(v[k].reanimation));
if (strcmp(pat->etat,"critique")==0)
    v[k].nbrcritique++;
return v;}
else{
if (strcmp(pat->etat,"critique")==0)
    v[k].nbrcritique++;
return v;
}
}
}


villes* inserercontacts( donnees_contacts* pat,int choix){
int i,j,k;
	for(i=0;i<MAX;i++)
	{
		if(strcmp(v[i].nomVille,pat->ville)==0)
		{
		    v[i].nbrcontacts++;
			break;
		}

	}
if (i<MAX){
        ptrcontacts* curs=v[i].fstc;
    while(curs!=NULL)
		{
			if((strcmp(curs->c->cin,pat->cin)==0))
			{
				break;
			}
			else
			{
				curs=curs->cs;
			}
		}
if (curs!=NULL){
    printf("contact existe deja");
    return v;
}
else{
ptrcontacts* d;
d=v[i].fstc;
ptrcontacts* nouveau=Malloc(ptrcontacts);
nouveau->c=pat;
nouveau->cs=d;
d=nouveau;
k=i;
if (choix==0){
printf("donnez le nouveau taux de propagation");
scanf("%lf",&(v[k].propagation));
return v;
}
else{
return v;}
}
}
else{
  for(j=0;j<MAX;j++)
	{
		if(v[j].nbrcontacts==0)
		{
		    strcpy(v[j].nomVille,pat->ville);
		    v[j].nbrcontacts++;
			break;
		}
}
ptrcontacts* d;
d=v[j].fstc;
ptrcontacts* nouveau=Malloc(ptrcontacts);
nouveau->c=pat;
nouveau->cs=NULL;
d=nouveau;
k=j;
if (choix==0){
printf("donnez le nouveau taux de propagation");
scanf("%lf",&(v[k].propagation));
return v;
}
else{
return v;}
}

}


villes* inserergueris( donnees_gueris* pat,int choix){
int i,j,k;
	for(i=0;i<MAX;i++)
	{
		if(strcmp(v[i].nomVille,pat->ville)==0)
		{
		    v[i].nbrgueris++;
			break;
		}
	}
if (i<MAX){
    ptrgueris* curs=v[i].fstg;
    while(curs!=NULL)
		{
			if((strcmp(curs->g->cin,pat->cin)==0))
			{
				break;
			}
			else
			{
				curs=curs->gs;
			}
		}
if (curs==NULL){
    printf("gueris existe deja");
    return v;
}
else{
ptrgueris* d;
d=Malloc(ptrgueris);
d=v[i].fstg;
ptrgueris* nouveau=Malloc(ptrgueris);
nouveau->g=pat;
nouveau->gs=d;
d=nouveau;
k=i;
if (choix==0){
printf("donnez le nouveau taux de guérison par jour");
scanf("%lf",&((v[k].guerison)[0]));
printf("donnez le nouveau taux de guérison total");
scanf("%lf",&((v[k].guerison)[1]));
return v;}
else{return v;}
}
}
else{
  for(j=0;j<MAX;j++)
	{
		if(v[j].nbrgueris==0)
		{
		    strcpy(v[j].nomVille,pat->ville);
		    v[j].nbrgueris++;
			break;
		}
}
ptrgueris* d;
d=v[j].fstg;
ptrgueris* nouveau=Malloc(ptrgueris);
nouveau->g=pat;
nouveau->gs=NULL;
d=nouveau;
k=j;
if (choix==0){
printf("donnez le nouveau taux de guérison par jour");
scanf("%lf",&((v[k].guerison)[0]));
printf("donnez le nouveau taux de guérison total");
scanf("%lf",&((v[k].guerison)[1]));
return v;}
else{return v;}
}

}


villes* insererdeces( donnees_deces* pat,int choix){
int i,j,k;
	for(i=0;i<MAX;i++)
	{
		if(strcmp(v[i].nomVille,pat->ville)==0)
		{
		    v[i].nbrdeces++;
			break;
		}
	}
if (i<MAX){
ptrdeces* curs=v[i].fstd;
    while(curs!=NULL)
		{
			if((strcmp(curs->de->cin,pat->cin)==0))
			{
				break;
			}
			else
			{
				curs=curs->ds;
			}
		}
if (curs==NULL){
    printf("deces existe deja");
    return v;
}
else{
ptrdeces* d;
d=Malloc(ptrdeces);
d=v[i].fstd;
ptrdeces* nouveau=Malloc(ptrdeces);
nouveau->de=pat;
nouveau->ds=d;
d=nouveau;
k=i;
if(choix==0){
printf("donnez le nouveau taux de déces par jour");
scanf("%lf",&((v[k].taux_deces)[0]));
printf("donnez le nouveau taux de déces par jour par ville ");
scanf("%lf",&((v[k].taux_deces)[1]));
printf("donnez le nouveau taux de guérison total");
scanf("%lf",&((v[k].taux_deces)[2]));
return v;}
else{return v;}
}
}
else{
  for(j=0;j<MAX;j++)
	{
		if(v[j].nbrdeces==0)
		{
		    strcpy(v[j].nomVille,pat->ville);
		    v[j].nbrdeces++;
			break;
		}
}
ptrdeces* d;
d=v[j].fstd;
ptrdeces* nouveau=Malloc(ptrdeces);
nouveau->de=pat;
nouveau->ds=NULL;
d=nouveau;
k=j;
if(choix==0){
printf("donnez le nouveau taux de déces par jour");
scanf("%lf",&((v[k].taux_deces)[0]));
printf("donnez le nouveau taux de déces par jour par ville ");
scanf("%lf",&((v[k].taux_deces)[1]));
printf("donnez le nouveau taux de guérison total");
scanf("%lf",&((v[k].taux_deces)[2]));
return v;}
else{return v;}
}
}


villes* suppatient(donnees_patients* patient,int resultat){ //resultat 1 gueris resultat 0 deces
donnees_gueris* gue=Malloc(donnees_gueris);
strcpy(gue->nom,patient->nom);
strcpy(gue->prenom,patient->prenom);
strcpy(gue->cin,patient->cin);
strcpy(gue->ville,patient->ville);
strcpy(gue->secteur,patient->secteur);
donnees_deces* dec=Malloc(donnees_deces);
strcpy(dec->nom,patient->nom);
strcpy(dec->prenom,patient->prenom);
strcpy(dec->cin,patient->cin);
strcpy(dec->ville,patient->ville);
strcpy(dec->secteur,patient->secteur);
	int i;
	for(i=0;i<MAX;i++)  //trouver la ville
	{
		if(strcmp(v[i].nomVille,patient->ville)==0)
		{
			break;
		}
	 }
	if (i<MAX && v[i].nbrpatients!=0)
	{
	    if(strcmp(patient->etat,"critique"))
           {v[i].nbrcritique--;}
	    v[i].nbrpatients--;
		ptrpatients *pat,*q;
		pat=v[i].fstp;
		while(pat!=NULL)
		{
			if((strcmp(pat->p->cin,patient->cin)==0))
			{
				break;
			}
			else
			{
				q=pat;
				pat=pat->ps;
			}
		}

		if (pat==NULL)
		{
			printf("patient n'existe pas.\n");
			return v;
		}
		else
		{
		    printf("donnez le nouveau taux des lits occupés");
            scanf("%lf",&(v[i].lits));
            printf("donnez le nouveau taux de lits de reanimation occupes");
            scanf("%lf",&(v[i].reanimation));
            if(resultat==0)
                insererdeces(dec,0);
            else
                inserergueris(gue,0);
			if(pat==v[i].fstp)  //s'il est le 1er noeud de la liste
			{
				if (pat->ps!=NULL)   //liste contient plsrs patients
				{
					v[i].fstp = pat->ps;
					free(pat);
					return v;
				}
				else   //contient un patient à supprimer
				{
				    strcpy(v[i].nomVille,"");
					v[i].fstp=NULL;
					free(pat);

				}
			}

			else
			{
				q->ps=pat->ps;
				free(pat);
			}
		}
	}

	else
	{
		printf("\nLa ville n'existe pas.\n");
	}
return v;
}


villes* supcontact(donnees_contacts* contact,int resultat,char etat[a]){ //resultat 1 n'est pas affecte, resultat 0 patient
donnees_patients* patient=Malloc(donnees_patients);
strcpy(patient->nom,contact->nom);
strcpy(patient->prenom,contact->prenom);
strcpy(patient->cin,contact->cin);
strcpy(patient->ville,contact->ville);
strcpy(patient->secteur,contact->secteur);
strcpy(patient->etat,etat);
	int i;
	for(i=0;i<MAX;i++)  //trouver la ville
	{
		if(strcmp(v[i].nomVille,contact->ville)==0)
		{
			break;
		}
	 }
	if (i<MAX && v[i].nbrcontacts!=0)
	{
        v[i].nbrcontacts--;
		ptrcontacts *pat,*q;
		pat=v[i].fstc;
		while(pat!=NULL)
		{
			if((strcmp(pat->c->cin,contact->cin)==0))
			{
				break;
			}
			else
			{
				q=pat;
				pat=pat->cs;
			}
		}

		if (pat==NULL)
		{
			printf("contact n'existe pas.\n");
			return v;
		}
		else
		{   printf("donnez le nouveau taux de propagation");
            scanf("%lf",&(v[i].propagation));
            if(resultat==0)
                    insererpatient(patient,0);

			if(pat==v[i].fstc)  //s'il est le 1er noeud de la liste
			{
				if (pat->cs!=NULL)   //liste contient plsrs patients
				{
					v[i].fstc = pat->cs;
					free(pat);
					return v;
				}
				else   //contient un patient à supprimer
				{
				    strcpy(v[i].nomVille,"");
					v[i].fstc=NULL;
					free(pat);

				}
			}

			else
			{
				q->cs=pat->cs;
				free(pat);
			}
		}

	}

	else
	{
		printf("\nLa ville n'existe pas.\n");
	}
return v;
}


villes* supgueris(donnees_gueris* gueris){
	int i;
	for(i=0;i<MAX;i++)  //trouver la ville
	{
		if(strcmp(v[i].nomVille,gueris->ville)==0)
		{
			break;
		}
	 }
	if (i<MAX && v[i].nbrgueris!=0)
	{
	    v[i].nbrgueris--;
		ptrgueris *pat,*q;
		pat=v[i].fstg;
		while(pat!=NULL)
		{
			if((strcmp(pat->g->cin,gueris->cin)==0))
			{
				break;
			}
			else
			{
				q=pat;
				pat=pat->gs;
			}
		}

		if (pat==NULL)
		{
			printf("gueris n'existe pas.\n");
			return v;
		}
		else
		{printf("donnez le nouveau taux de guérison par jour");
        scanf("%lf",&((v[i].guerison)[0]));
        printf("donnez le nouveau taux de guérison total");
        scanf("%lf",&((v[i].guerison)[1]));
			if(pat==v[i].fstg)  //s'il est le 1er noeud de la liste
			{
				if (pat->gs!=NULL)   //liste contient plsrs patients
				{
					v[i].fstg = pat->gs;
					free(pat);
					return v;
				}
				else   //contient un patient à supprimer
				{
				    strcpy(v[i].nomVille,"");
					v[i].fstg=NULL;
					free(pat);

				}
			}

			else
			{
				q->gs=pat->gs;
				free(pat);
			}
		}

	}

	else
	{
		printf("\nLa ville n'existe pas.\n");
	}
return v;
}


villes* supdeces(char cin[a],char nomV[a]){
	int i;
	for(i=0;i<MAX;i++)  //trouver la ville
	{
		if(strcmp(v[i].nomVille,nomV)==0)
		{
			break;
		}
	 }
	if (i<MAX && v[i].nbrdeces!=0)
	{
	    v[i].nbrdeces--;
		ptrdeces *pat,*q;
		pat=v[i].fstd;
		while(pat!=NULL)
		{
			if((strcmp(pat->de->cin,cin)==0))
			{
				break;
			}
			else
			{
				q=pat;
				pat=pat->ds;
			}
		}

		if (pat==NULL)
		{
			printf("gueris n'existe pas.\n");
			return v;
		}
		else
		{   printf("donnez le nouveau taux de déces par jour");
            scanf("%lf",&((v[i].taux_deces)[0]));
            printf("donnez le nouveau taux de déces par jour par ville ");
            scanf("%lf",&((v[i].taux_deces)[1]));
            printf("donnez le nouveau taux de guérison total");
            scanf("%lf",&((v[i].taux_deces)[2]));
			if(pat==v[i].fstd)  //s'il est le 1er noeud de la liste
			{
				if (pat->ds!=NULL)   //liste contient plsrs patients
				{
					v[i].fstd = pat->ds;
					free(pat);
					return v;
				}
				else   //contient un patient à supprimer
				{
				    strcpy(v[i].nomVille,"");
					v[i].fstd=NULL;
					free(pat);

				}
			}

			else
			{
				q->ds=pat->ds;
				free(pat);
			}
		}

	}

	else
	{
		printf("\nLa ville n'existe pas.\n");
	}
return v;
}


villes* modifier_patient(donnees_patients* patient){
int i;
	for(i=0;i<MAX;i++)  //trouver la ville
	{
		if(strcmp(v[i].nomVille,patient->ville)==0)
		{
			break;
		}
	 }
if (i<MAX){
    ptrpatients* pat=v[i].fstp;
    while(pat!=NULL)
		{
			if((strcmp(pat->p->cin,patient->cin)==0))
			{
				break;
			}
			else
			{
				pat=pat->ps;
			}
		}

		if (pat==NULL)
		{
			printf("patient n'existe pas.\n");
			return v;
		}
		else{
            pat->p=patient;
            if (strcmp(patient->etat,"critique")==0)
                v[i].nbrcritique++;

        }
}
else {
    printf("le patient n'existe pas\n");
}
return v;
}


villes* modifier_contact(donnees_contacts* contact){
int i;
	for(i=0;i<MAX;i++)  //trouver la ville
	{
		if(strcmp(v[i].nomVille,contact->ville)==0)
		{
			break;
		}
	 }
if (i<MAX){
    ptrcontacts* pat=v[i].fstc;
    while(pat!=NULL)
		{
			if((strcmp(pat->c->cin,contact->cin)==0))
			{
				break;
			}
			else
			{
				pat=pat->cs;
			}
		}

		if (pat==NULL)
		{
			printf("contact n'existe pas.\n");
			return v;
		}
		else{
            pat->c=contact;
        }
}
else {
    printf("le contact n'existe pas\n");
}
return v;
}


villes* modifier_gueris(donnees_gueris* gueris){
int i;
	for(i=0;i<MAX;i++)  //trouver la ville
	{
		if(strcmp(v[i].nomVille,gueris->ville)==0)
		{
			break;
		}
	 }
if (i<MAX){
    ptrgueris* pat=v[i].fstg;
    while(pat!=NULL)
		{
			if((strcmp(pat->g->cin,gueris->cin)==0))
			{
				break;
			}
			else
			{
				pat=pat->gs;
			}
		}

		if (pat==NULL)
		{
			printf("gueris n'existe pas.\n");
			return v;
		}
		else{
            pat->g=gueris;
        }
}
else {
    printf("le gueris n'existe pas\n");
}
return v;
}


villes* modifier_deces(donnees_deces* deces){
int i;
	for(i=0;i<MAX;i++)  //trouver la ville
	{
		if(strcmp(v[i].nomVille,deces->ville)==0)
		{
			break;
		}
	 }
if (i<MAX){
    ptrdeces* pat=v[i].fstd;
    while(pat!=NULL)
		{
			if((strcmp(pat->de->cin,deces->cin)==0))
			{
				break;
			}
			else
			{
				pat=pat->ds;
			}
		}

		if (pat==NULL)
		{
			printf("deces n'existe pas.\n");
			return v;
		}
		else{
            pat->de=deces;
        }
}
else {
    printf("le deces n'existe pas\n");
}
return v;
}



void afficherPatientsVille(char *nomV){
  int i;
  for(i=0;i<MAX;i++)
	{
		if(strcmp(v[i].nomVille,nomV)==0)

                break;
    }
if(i<MAX)
    {

    //int n=0;
    if (v[i].nbrpatients>0)
    {
    ptrpatients *parcours;
    parcours=v[i].fstp;
    while(parcours!=NULL){
    printf("%s\t %s\t %s\t %s\t %s\t %s\n",parcours->p->ville,parcours->p->secteur, parcours->p->etat,parcours->p->nom, parcours->p->prenom,parcours->p->cin);
    // d’autres infos évent.
    //n++;
    parcours=parcours->ps;
    }
    }
  printf("Il existe %d patients dans %s",v[i].nbrpatients,nomV);

    }
else
    printf("Désolé, la ville n'existe pas \n Veuillez entrer une ville valide\n");
}


void afficherPatientsToutesVilles(){
  int i;
  for(i=0;i<MAX;i++)
  {if(v[i].nbrpatients==0)
    continue;
    else{
      printf("---------%s",v[i].nomVille);
      afficherPatientsVille(v[i].nomVille);}
  }
}


void afficherContactsVille(char *nomV){
  int i;
  for(i=0;i<MAX;i++)
	{
		if(strcmp(v[i].nomVille,nomV)==0)

                break;
    }
if(i<MAX)
    {

    //int n=0;
    if (v[i].nbrcontacts>0)
    {
    ptrcontacts *parcours;
    parcours=v[i].fstc;
    while(parcours!=NULL){
    printf("%s\t %s\t %s\t %s\t %s\n",parcours->c->ville,parcours->c->secteur,parcours->c->nom, parcours->c->prenom,parcours->c->cin);
    // d’autres infos évent.
    //n++;
    parcours=parcours->cs;
    }
    }
  printf("Il existe %d contacts dans %s",v[i].nbrcontacts,nomV);

    }
else
    printf("Désolé, la ville n'existe pas \n Veuillez entrer une ville valide");
}


void afficherContactsToutesVilles(){
  int i;
  for(i=0;i<MAX;i++)
  {if(v[i].nbrcontacts==0)
    continue;
    else{
      printf("---------%s",v[i].nomVille);
      afficherContactsVille(v[i].nomVille);}
  }
}


void afficherDecesVille(char *nomV){
  int i;
  for(i=0;i<MAX;i++)
	{
		if(strcmp(v[i].nomVille,nomV)==0)

                break;
    }
if(i<MAX)
    {

    //int n=0;
    if (v[i].nbrdeces>0)
    {
    ptrdeces *parcours;
    parcours=v[i].fstd;
    while(parcours!=NULL){
    printf("%s\t %s\t %s\t %s\t %s\n",parcours->de->ville,parcours->de->secteur,parcours->de->nom, parcours->de->prenom,parcours->de->cin);
    // d’autres infos évent.
    //n++;
    parcours=parcours->ds;
    }
    }
  printf("Il existe %d patients dans %s",v[i].nbrdeces,nomV);

    }
else
    printf("Désolé, la ville n'existe pas \n Veuillez entrer une ville valide");
}


void afficherDecesToutesVilles(){
  int i;
  for(i=0;i<MAX;i++)
  {if(v[i].nbrdeces==0)
    continue;
    else{
      printf("---------%s",v[i].nomVille);
      afficherDecesVille(v[i].nomVille);}
  }
}


void afficherGuerisVille(char *nomV){
  int i;
  for(i=0;i<MAX;i++)
	{
		if(strcmp(v[i].nomVille,nomV)==0)

                break;
    }
if(i<MAX)
    {

    //int n=0;
    if (v[i].nbrgueris>0)
    {
    ptrgueris *parcours;
    parcours=v[i].fstg;
    while(parcours!=NULL){
    printf("%s\t %s\t %s\t %s\t %s\n",parcours->g->ville,parcours->g->secteur,parcours->g->nom, parcours->g->prenom,parcours->g->cin);
    // d’autres infos évent.
    //n++;
    parcours=parcours->gs;
    }
    }
  printf("Il existe %d patients dans %s",v[i].nbrgueris,nomV);

    }
else
    printf("Désolé, la ville n'existe pas \n Veuillez entrer une ville valide");
}


void afficherGuerisToutesVilles(){
  int i;
  for(i=0;i<MAX;i++)
  {if(v[i].nbrgueris==0)
    continue;
    else{
      printf("---------%s",v[i].nomVille);
      afficherGuerisVille(v[i].nomVille);}
  }
}



void sauvegarderPatients(){
  FILE *flot;
  //OUVERTURE FICHIER (VERIFICATION D’ERREUR)
  flot =fopen("patients.txt", "w");
int i;
  for(i=0;i<MAX;i++)
 { if (v[i].nbrpatients!=0){fprintf(flot,"%s   %d   %d   %f   %f\n",v[i].nomVille,v[i].nbrpatients,v[i].nbrcritique,v[i].lits,v[i].reanimation);
  ptrpatients *aux=v[i].fstp;
  while(aux!=NULL){
    fprintf(flot,"%s   %s   %s   %s   %s   %s\n",aux->p->ville,aux->p->secteur,aux->p->etat,aux->p->nom,aux->p->prenom,aux->p->cin);
   // ECRITURE LISTE DES OBJETS
    aux=aux->ps;
  }}
}
  fclose (flot);
}


donnees_patients * chargerdonnees_patients(FILE *flot){
    donnees_patients *d = Malloc (donnees_patients);
    fscanf (flot,"%s   %s   %s   %s   %s   %s\n",(d->ville),(d->secteur),(d->etat),(d->nom),(d->prenom),(d->cin));
  return d;
}


void chargerpatients(){

  FILE *flot;
  //OUVERTURE FICHIER (VERIFICATION D’ERREUR)
  flot =fopen("patients.txt", "r");

    int i,j;
    for(i=0;i<MAX;i++)
    {fscanf(flot,"%s   %d   %d   %lf   %lf\n",(v[i].nomVille),&(v[i].nbrpatients),&(v[i].nbrcritique),&(v[i].lits),&(v[i].reanimation));
    for(j=0;j<v[i].nbrpatients;j++) {
   donnees_patients * d=chargerdonnees_patients(flot);
   insererpatient(d,1);
  }
  }
  fclose (flot);
}


void sauvegardercontacts(){
  FILE *flot;
  //OUVERTURE FICHIER (VERIFICATION D’ERREUR)
  flot =fopen("contacts.txt", "w+");
  int i;
  for(i=0;i<MAX;i++)

 {if (v[i].nbrcontacts!=0){fprintf(flot,"%s   %d   %f\n",v[i].nomVille,v[i].nbrcontacts,v[i].propagation);
  ptrcontacts *aux=v[i].fstc;
  while(aux!=NULL){
    fprintf(flot,"%s   %s   %s   %s   %s\n",aux->c->ville,aux->c->secteur,aux->c->nom,aux->c->prenom,aux->c->cin);
   // fwrite (aux->p, sizeof(donnees_patients), 1, flot); // ECRITURE LISTE DES OBJETS
    aux=aux->cs;
  }}
}
  fclose (flot);
}


donnees_contacts * chargerdonnees_contacts(FILE *flot){
    donnees_contacts *d = Malloc (donnees_contacts);
    fscanf (flot,"%s   %s   %s   %s   %s\n",(d->ville),(d->secteur),(d->nom),(d->prenom),(d->cin));
  return d;
}


void chargercontacts(){

  FILE *flot;
  //OUVERTURE FICHIER (VERIFICATION D’ERREUR)
  flot =fopen("contacts.txt", "a");
    int i,j;
    for(i=0;i<MAX;i++)
    {fscanf(flot,"%s   %d   %lf\n",(v[i].nomVille),&(v[i].nbrcontacts),&(v[i].propagation));
    for(j=0;j<v[i].nbrcontacts;j++) {
   donnees_contacts * d=chargerdonnees_contacts(flot);
   inserercontacts(d,1);
  }
  }
  fclose (flot);
}


void sauvegardergueris(){
  FILE *flot;
  //OUVERTURE FICHIER (VERIFICATION D’ERREUR)
  flot =fopen("gueris.txt", "w+");
int i;
  for(i=0;i<MAX;i++)
 { if (v[i].nbrgueris!=0){fprintf(flot,"%s   %d   %f   %f\n",v[i].nomVille,v[i].nbrgueris,(v[i].guerison)[0],(v[i].guerison)[1]);
  ptrgueris *aux=v[i].fstg;
  while(aux!=NULL){
    fprintf(flot,"%s   %s   %s   %s   %s\n",aux->g->ville,aux->g->secteur,aux->g->nom,aux->g->prenom,aux->g->cin);
   // ECRITURE LISTE DES OBJETS
    aux=aux->gs;
  }}
}
  fclose (flot);
}


donnees_gueris * chargerdonnees_gueris(FILE *flot){
    donnees_gueris *d = Malloc (donnees_gueris);
    fscanf (flot,"%s   %s   %s   %s   %s\n",(d->ville),(d->secteur),(d->nom),(d->prenom),(d->cin));
  return d;
}


void chargergueris(){

  FILE *flot;
  //OUVERTURE FICHIER (VERIFICATION D’ERREUR)
  flot =fopen("gueris.txt", "a");
    int i,j;
    for(i=0;i<MAX;i++)
    {fscanf(flot,"%s   %d   %lf   %lf\n",(v[i].nomVille),&(v[i].nbrgueris),&((v[i].guerison)[0]),&((v[i].guerison)[1]));
    for(j=0;j<v[i].nbrgueris;j++) {
   donnees_gueris * d=chargerdonnees_gueris(flot);
   inserergueris(d,1);
  }
  }
  fclose (flot);
}


void sauvegarderdeces(){
  FILE *flot;
  //OUVERTURE FICHIER (VERIFICATION D’ERREUR)
  flot =fopen("deces.txt", "w+");
int i;
  for(i=0;i<MAX;i++)
 { if (v[i].nbrdeces!=0){fprintf(flot,"%s   %d   %f   %f   %f\n",v[i].nomVille,v[i].nbrdeces,(v[i].taux_deces)[0],(v[i].taux_deces)[1],(v[i].taux_deces)[2]);
  ptrdeces *aux=v[i].fstd;
  while(aux!=NULL){
    fprintf(flot,"%s   %s   %s   %s   %s\n",aux->de->ville,aux->de->secteur,aux->de->nom,aux->de->prenom,aux->de->cin);
   // ECRITURE LISTE DES OBJETS
    aux=aux->ds;
  }}
}
  fclose (flot);
}


donnees_deces * chargerdonnees_deces(FILE *flot){
    donnees_deces *d = Malloc (donnees_deces);
    fscanf (flot,"%s   %s   %s   %s   %s\n",(d->ville),(d->secteur),(d->nom),(d->prenom),(d->cin));
  return d;
}


void chargerdeces(){

  FILE *flot;
  //OUVERTURE FICHIER (VERIFICATION D’ERREUR)
  flot =fopen("deces.txt", "a");
    int i,j;
    for(i=0;i<MAX;i++)
    {fscanf(flot,"%s   %d   %lf   %lf   %lf\n",(v[i].nomVille),&(v[i].nbrdeces),&((v[i].taux_deces)[0]),&((v[i].taux_deces)[1]),&((v[i].taux_deces)[2]));
    for(j=0;j<v[i].nbrdeces;j++) {
   donnees_deces * d=chargerdonnees_deces(flot);
   insererdeces(d,1);
  }
  }
  fclose (flot);
}



int main(){

for(int i=0;i<1538;i++){
    v[i].nbrpatients=0;
    strcpy(v[i].nomVille,"");
    v[i].nbrcontacts=0;
    v[i].nbrgueris=0;
    v[i].nbrdeces=0;
    }

int fin=0;//,finp=0,finc=0,fing=0,find=0;

int c;
while(!fin)
{
    printf("HELLO\nPour la Gestion des patients entrez '1'\nPour la Gestion des contacts entrez '2'\nPour la Gestion des gueris entrez '3'\nPour la Gestion des deces entrez '4'\nPour la Quitter le programme entrez '5'\n");

    scanf("%d",&c);

    switch(c)
    {
    case 1:
        {
        chargerpatients();
        donnees_patients *pati;
        pati=Malloc(donnees_patients);
        int k;

       // while(!finp)
        {getchar();
        printf("1. Inserer 1\n"
          "2. Afficher 2\n"
          "3. Supprimer 3\n"
          "4. modifier 4\n"
          "5. Quitter 5\n");

          scanf("%d",&k);
          switch(k)
          {
            case 1:
            {printf("ville=?\t secteur=?\t etat=?\t nom=?\t prenom=?\t cin=?\n");
            scanf("%s %s %s %s %s %s",(pati->ville),(pati->secteur),(pati->etat),(pati->nom),(pati->prenom),(pati->cin));
            insererpatient(pati,0);
           // system("@cls||clear");
            break;}

            case 3:
            {int res;
            printf("ville=?\t secteur=?\t etat=?\t nom=?\t prenom=?\t cin=?\n");
            scanf("%s %s %s %s %s %s ",(pati->ville),(pati->secteur),(pati->etat),(pati->nom),(pati->prenom),(pati->cin));

            printf("si le patient est décés entrez  0\ns'il est guéris entrez n'importe quelle valeur differente de 0\n");
            scanf("%d",&res);

            suppatient(pati,res);
            break;}


            case 2:
            {int ap;
            printf("Pour la liste des patients d'une seule ville entrez   0\nPour la liste des patients de toutes les villes Entrez n'importe quelle valeur differente de 0 \n");
            scanf("%d",ap);
            if(!ap)
            {
                char *nV;



               printf("Entrez le nom de la ville que vous voulez afficher\n");
                scanf("%s",nV);

                int i;
                for(i=0;i<MAX;i++)
                 {
		         if(strcmp(v[i].nomVille,nV)==0)
		          {
                    break;
		          }
                 }
                 if (i<MAX){

                             afficherPatientsVille(v[i].nomVille);
                  }
                  else       printf("la ville que vous avez entrer n'existe pas\n");

                  }
                  else afficherPatientsToutesVilles();

                  break;}



                case 4:
                          {printf("ville=?\t secteur=?\t etat=?\t nom=?\t prenom=?\t cin=?\n");
                          scanf("%s %s %s %s %s %s",(pati->ville),(pati->secteur),(pati->etat),(pati->nom),(pati->prenom),(pati->cin));
                          modifier_patient(pati);
                          break;}


                case 5:{ /* finp=1;
                         system("@cls||clear");*/
                         break;}


                default: {printf("Seuls les choix de 1 a 5 sont valides\nVeuillez entrez un choix valide");
                        break;}

                }
                break;}
                sauvegarderPatients();

                }








            case 2:{
                chargercontacts();
                donnees_contacts *cont=Malloc(donnees_contacts);
                 int m;

          //while(!finc)
          {
           getchar();
          printf("1. Inserer 1\n"
          "2. Afficher 2\n"
          "3. Supprimer 3\n"
          "4. modifier 4\n"
          "5. Quitter 5\n");

          scanf("%d",&m);
          switch(m)
          {
            case 1:
            {
                printf("ville=?\t secteur=?\t nom=?\t prenom=?\t cin=?\n");
            scanf("%s %s %s %s %s %s",(cont->ville),(cont->secteur),(cont->nom),(cont->prenom),(cont->cin));
            inserercontacts(cont,0);
            system("@cls||clear");
            break;}

            case 3:
            {int resc;char etat[a];
            printf("ville=?\t secteur=?\t nom=?\t prenom=?\t cin=?\n");
            scanf("%s %s %s %s %s %s ",(cont->ville),(cont->secteur),(cont->nom),(cont->prenom),(cont->cin));

            printf("si le contact du patient est affecté entrez   0\nsi le contact du patient n'est pas affecté  entrez n'importe quelle valeur differente de 0 \n");
            scanf("%d",&resc);
            printf("donnez l'etat du nouveau patient(normal, critique,besoin d’aide respiratoire)\n");
            scanf("%s",etat);
            supcontact(cont,resc,etat);
            break;}


            case 2:
            {int ac;
            printf("Pour la liste des contacts d'une seule ville entrez   0\nPour la liste des contacts de toutes les villes Entrez n'importe quelle valeur differente de 0 \n");
            if(!ac)
            {
                char *nV;
                printf("Entrez le nom de la ville que vous voulez afficher\n");
                scanf("%s",nV);

                int i;
                for(i=0;i<MAX;i++)
                 {
		         if(strcmp(v[i].nomVille,nV)==0)
		          {
                    break;
		          }
                 }
                 if (i<MAX){

                             afficherContactsVille(v[i].nomVille);
                  }
                  else       printf("la ville que vous avez entrer n'existe pas\n");

                  }
                  else afficherContactsToutesVilles();

                  break;}



                case 4:
                         {printf("ville=?\t secteur=?\t nom=?\t prenom=?\t cin=?\n");
                         scanf("%s %s %s %s %s %s",(cont->ville),(cont->secteur),(cont->nom),(cont->prenom),(cont->cin));
                          modifier_contact(cont);
                          break;}


                case 5:  {/*finc=1;
                             system("@cls||clear");*/
                          break;}

                default: {printf("Seuls les choix de 1 a 5 sont valides\nVeuillez entrez un choix valide");
                         break;}

                }
                break;}
                sauvegardercontacts();
                }







                   case 4:
                {   chargerdeces();
                    donnees_deces *dece=Malloc(donnees_deces);
        int h;

       // while(!find)
        {

        getchar();
        printf("1. Inserer 1\n"
          "2. Afficher 2\n"
          "3. Supprimer 3\n"
          "4. modifier 4\n"
          "5. Quitter 5\n");

          scanf("%d",&h);
          switch(h)
          {
            case 1:
            {printf("ville=?\t secteur=?\t nom=?\t prenom=?\t cin=?\n");
            scanf("%s %s %s %s %s",(dece->ville),(dece->secteur),(dece->nom),(dece->prenom),(dece->cin));
            insererdeces(dece,0);
           // system("@cls||clear");
            break;
            }

            case 3:

            {printf("ville=?\t secteur=?\t nom=?\t prenom=?\t cin=?\n");
            scanf("%s %s %s %s %s",(dece->ville),(dece->secteur),(dece->nom),(dece->prenom),(dece->cin));

            supdeces(dece->cin,dece->ville);
            break;}


            case 2:
            {int ad;
            printf("Pour la liste des deces d'une seule ville entrez   0\nPour la liste des deces de toutes les villes Entrez n'importe quelle valeur differente de 0 \n");
            if(!ad)
            {
                char *nV;
                printf("Entrez le nom de la ville que vous voulez afficher\n");
                scanf("%s",nV);

                int i;
                for(i=0;i<MAX;i++)
                 {
		         if(strcmp(v[i].nomVille,nV)==0)
		          {
                    break;
		          }
                 }
                 if (i<MAX){

                             afficherDecesVille(v[i].nomVille);
                  }
                  else       printf("la ville que vous avez entrer n'existe pas\n");

                  }
                  else afficherDecesToutesVilles();

                  break;}



                case 4:
                        {printf("ville=?\t secteur=?\t nom=?\t prenom=?\t cin=?\n");
                        scanf("%s %s %s %s %s",(dece->ville),(dece->secteur),(dece->nom),(dece->prenom),(dece->cin));

                          modifier_deces(dece);
                          break;}


                case 5:
                         {/*find=1;
                         system("@cls||clear");*/
                         break;}

                 default: {printf("Seuls les choix de 1 a 5 sont valides\nVeuillez entrez un choix valide");
                  break;}

                }
                break;}

                sauvegarderdeces();}











                   case 3:{

                chargergueris();
                donnees_gueris *guer=Malloc(donnees_gueris);
        int f;

        //while(!fing)
        {
        getchar();
        printf("1. Inserer 1\n"
          "2. Afficher 2\n"
          "3. Supprimer 3\n"
          "4. modifier 4\n"
          "5. Quitter 5\n");

          scanf("%d",&f);
          switch(f)
          {
            case 1:
            {printf("ville=?\t secteur=?\t nom=?\t prenom=?\t cin=?\n");
            scanf("%s %s %s %s %s",(guer->ville),(guer->secteur),(guer->nom),(guer->prenom),(guer->cin));
            inserergueris(guer,0);
           // system("@cls||clear");
            break;}

            case 3:

            {printf("ville=?\t secteur=?\t nom=?\t prenom=?\t cin=?\n");
            scanf("%s %s %s %s %s",(guer->ville),(guer->secteur),(guer->nom),(guer->prenom),(guer->cin));

            supgueris(guer);
            break;}


            case 2:
            {int ag;
            printf("Pour la liste des guéris d'une seule ville entrez   0\nPour la liste des guéris de toutes les villes Entrez n'importe quelle valeur differente de 0 \n");
            if(!ag)
            {
                char *nV;
                printf("Entrez le nom de la ville que vous voulez afficher\n");
                scanf("%s",nV);

                int i;
                for(i=0;i<MAX;i++)
                 {
		         if(strcmp(v[i].nomVille,nV)==0)
		          {
                    break;
		          }
                 }
                 if (i<MAX){

                             afficherGuerisVille(v[i].nomVille);
                  }
                  else       printf("la ville que vous avez entrer n'existe pas\n");

                  }
                  else afficherGuerisToutesVilles();

                  break;}



                case 4:
                      {printf("ville=?\t secteur=?\t nom=?\t prenom=?\t cin=?\n");
                      scanf("%s %s %s %s %s",(guer->ville),(guer->secteur),(guer->nom),(guer->prenom),(guer->cin));

                         modifier_gueris(guer);
                         break;}


                case 5:
                         {/*fing=1;
                         system("@cls||clear");*/
                         break;}
                 default: {printf("Seuls les choix de 1 a 5 sont valides\nVeuillez entrez un choix valide");
                  break;}

                }
                break;}
                sauvegardergueris();}





                  case 5:{
                            fin=1;
                            break;
                  }


                  default: {printf("Seuls les choix de 1 a 5 sont valides\nVeuillez entrez un choix valide\n\n");
                  break;}

                }


}
return 0;}

