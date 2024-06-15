//----------------------------------<<JONATHAN BADIBANGA>>--------------------------------------------

PlisteOV CreerFIFO() {
 PlisteOV  P=NULL,T ; PlisteOV P1;
     ouvrage x; int i;int n,j,nbr=0;
     char*chaine=(char*)malloc(100+1);char tmp1[]=" "; char s[50];

     	FILE* fichier = NULL; char*nomFich=(char*)malloc(100+1);

	printf("	<<Donner le nom de votre fichier d'ouvrages>>: "); //les_ouvrages.txt
	gets(nomFich);
	fichier = fopen(nomFich, "r");
	if(fichier==NULL){
		do{
			printf("	//Nous n'avons pas trouver votre fichier, \n	//Si votre fichier ne trouve pas au meme dossier que votre programme\n	//Donner le chemin absolu: ");
			gets(nomFich);
			fichier = fopen(nomFich, "r");
		}while(fichier==NULL);
	}
     rewind(fichier);
     	while (!feof(fichier)){
     		fgets(chaine, 100, fichier); i=0;
     		n=strlen(chaine);if(chaine[n-1]=='\n'){ chaine[n-1]='\0';}
     		char *token = strtok(chaine,tmp1);

   				while(token != NULL){

   					switch(i){
   						case 0:
      					strcpy((x.cote),token);
      					break;
      					case 1:
      						strcpy(s,token);
      					strcpy((x.Titre),s);
      					break;
      					case 2:
      					strcpy(s,token);j=0	;
      					while(s[j]!='\0'){  nbr = nbr*10+(int)s[j] - 48;j++;}
      					(x.Ne)=nbr;nbr=0;
      					break;
      					case 3:
      					strcpy(s,token);j=0	;
      					while(s[j]!='\0'){  nbr = nbr*10+(int)s[j] - 48;j++;}
      					(x.Nee)=nbr;nbr=0;
      					break;
					   }

       				 token = strtok(NULL, tmp1);i++;
   					 }

					   if(P==NULL){
					   	P=(PlisteOV)malloc(sizeof(Cellule));
					   	P->VAL1=x;
        		  		P->Suivo=NULL;
        		  		P1=P;
					   }
					   else{

					   	P1->Suivo=(PlisteOV)malloc(sizeof(Cellule));
						P1=P1->Suivo;
						P1->VAL1=x;
						P1->Suivo=NULL;


					   }

		 }

     return P;
}

//procedure affichage
void AfficheOV(PlisteOV T) {
	PlisteOV P; ouvrage x ;
    P=T; printf("\nLes elements de la liste sont:\n");

  while(P!=NULL){
  	x=(P->VAL1);
  	printf("\nla cote est : %s",x.cote);

 	printf("\nle nombre d'exemplaire est : %d",x.Ne);

 	printf("\nle nombre d'exeplaire emprunte est : %d",x.Nee);

  	printf("\nle titre est : %s\n",x.Titre);

	 P=P->Suivo;  }
}


//insertion d'un ouvrage
 void IsertOV (PlisteOV *T){
	int i, NOVA ; // NOVA : le nombre des ouvrages que l'utulisateur  veut ajouter
	PlisteOV p,Q; ouvrage x;

	  Q=*T;

 	while (Q->Suivo!=NULL){
  		Q=Q->Suivo ;
	 }

	printf ("\n 	//Donner le nombre des ouvrages que vous voullez ajouter a votre liste: ");
  	scanf("%d",&NOVA);


for (i=0;i<NOVA;i++){
	printf ("\nVeuillez saisir les caracteristique du l'ouvrage N°%d : \n",i+1);
    printf("Donner la cote: ");
    fflush(stdin);
    scanf("%s",&x.cote);
  	printf("Donner le nombre d'exemplaire dans la bibliotheque: ");
    scanf("%d",&x.Ne);
   	printf("Donner le nombre d'exemplaire emprunte: ");
    scanf("%d",&x.Nee);
  	printf("Donner le titre: ");
    fflush(stdin);
	scanf("%s",&x.Titre);
  p=malloc(sizeof(Cellule));
  p->VAL1=x;
  p->Suivo=NULL;
  Q->Suivo=p;
  Q=Q->Suivo ;
}


}


void ExemplairesDispo (PlisteOV *P1 ,char *titre ,int *n){
int nbr=0; *n=nbr;PlisteOV P=*P1;
//printf("------%s----",titre);
	while(P!=NULL && nbr==0){
		if(!strcmp(P->VAL1.Titre,titre) && P->VAL1.Ne>0 ){nbr++;*n=nbr;*P1=P ;break; }
		P=P->Suivo;
	}


}

int MaxOV (PlisteOV P){
	int nbr=0;
	while(P!=NULL){
		nbr= nbr + P->VAL1.Ne;
		P=P->Suivo;
	}
	return nbr;
}

PlisteOV SupprimerOV (PlisteOV *T){
	PlisteOV L=*T; PlisteOV P,Pred;
	char*titre=(char*)malloc(50+1);

	printf("	- Donner le titre de votre ouvrage que vous voulez supprimer : ");
	fflush(stdin);
	gets(titre);

	P=L;Pred=L;
	while(P!=NULL ){
		if(strcmp(P->VAL1.Titre ,titre )!=0){
			Pred=P;
		P=P->Suivo;
		}else{
			break;
		}

	}

	if(P==NULL){
		printf("	Votre ouvrage n'existe pas dans la liste \n");
	}else{
		if(P==L){
			L=L->Suivo;
			free(P);
			*T=L;
		}else{
			Pred->Suivo=P->Suivo;
			free(P);
			*T=L;
		}
	}

}


//----les fonctions Etudiant------------------------------------------------------------------------------------------------

PlisteET CreerFIFOET() {
 PlisteET  P=NULL,T ; PlisteET P1;
     etudiant x; int i;int n,j,nbr=0;
     char*chaine=(char*)malloc(100+1);char tmp1[]=" "; char s[50];

     	FILE* fichier = NULL; char*nomFich=(char*)malloc(100+1);

	printf("	<<Donner le nom de votre fichier d'etudiant>>: "); // taper: les_etudiants.txt
	gets(nomFich);
	fichier = fopen(nomFich, "r");
	if(fichier==NULL){
		do{
			printf("	//Nous n'avons pas trouver votre fichier, \n	//Si votre fichier ne trouve pas au meme dossier que votre programme\n	//Donner le chemin absolu: ");
			gets(nomFich);
			fichier = fopen(nomFich, "r");
		}while(fichier==NULL);
	}

     rewind(fichier);
     	while (!feof(fichier)){
     		fgets(chaine, 100, fichier); i=0;
     		n=strlen(chaine);if(chaine[n-1]=='\n'){ chaine[n-1]='\0';}
     		char *token = strtok(chaine,tmp1);

   				while(token != NULL){

   					switch(i){
   						case 0:
      					strcpy(s,token);j=0	;
      					while(s[j]!='\0'){  nbr = nbr*10+(int)s[j] - 48;j++;}
      					(x.MC)=nbr;nbr=0; x.PT=0;
      					break;
      					case 1:
      						strcpy(s,token);
      					if(!strcmp(s ,"Premium")){ x.TA='P';}else{	if(!strcmp(s ,"Classique")){ x.TA='C';  }else{ x.TA='N'; }  }
      					break;

					   }

       				 token = strtok(NULL, tmp1);i++;
   					 }

					   if(P==NULL){
					   	P=(PlisteET)malloc(sizeof(Cellule2));
					   	P->VAL2=x;
        		  		P->Suive=NULL;
        		  		P1=P;
					   }
					   else{
        		  		P1->Suive=(PlisteET)malloc(sizeof(Cellule2));
						P1=P1->Suive;
						P1->VAL2=x;
						P1->Suive=NULL;
					   }


		 }

     return P;
}

//procedure affichage
void AfficheET(PlisteET T) {
	PlisteET P; etudiant x ; int i=1;
    P=T; printf("\nLes elements de la liste sont:\n");

  while(P!=NULL){
  	x=(P->VAL2);
  	printf("\nEtudiant %d matricule: %d",i,x.MC);

	if(x.TA == 'P'){printf("\nEtudiant %d abonnement: Premuim ",i); } else {if (x.TA == 'C') {printf("\nEtudiant %d abonnement: Classique ",i); }else{printf("\nEtudiant %d verifier son abonnement ",i); } }

 	printf("\nEtudiant %d penalite = %d\n",i,x.PT);

	 P=P->Suive;i++;  }
}
