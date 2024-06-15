#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List3* PlisteEP;
 typedef struct List3 {
     emprunt VAL3;
    PlisteEP Suivp;
 } Cellule3;
//----les fonctions Emprunts-------------------------<<KALALA KALALA BENJAMIN>>---------------------------------------------

PlisteEP CreerFIFOEP() {
 PlisteEP  P=NULL,T ; PlisteEP P1;
     emprunt x; int i;int n,j,nbr=0;
     char*chaine=(char*)malloc(100+1);char tmp1[]=" "; char s[50];

     	FILE* fichier = NULL; char*nomFich=(char*)malloc(100+1);

	printf("	<<Donner le nom de votre fichier des Emprunts>>: ");  //taper: les_emprunts.txt
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
      						(x.MC)=nbr;nbr=0;
      					break;
      					case 1:
      						strcpy(s,token);
      						strcpy((x.cote),s);
      					break;
      					case 2:
      						strcpy(s,token);
      						j=0	;
      						while(s[j]!='\0'){ if(s[j]!='-'){nbr = nbr*10+(int)s[j] - 48;j++;}else{	switch(j){case 2:
      																											x.DE.JJ=nbr;nbr=0;j++;
      																										  break;
      																										  case 5:
      																											x.DE.MM=nbr;nbr=0;j++;
      																										  break;} }
											 }
							  x.DE.AA=nbr;nbr=0;
      					break;
      					case 3:
      						strcpy(s,token);
      						j=0	;
      						while(s[j]!='\0'){ if(s[j]!='-'){nbr = nbr*10+(int)s[j] - 48;j++;}else{	switch(j){case 2:
      																											x.DR.JJ=nbr;nbr=0;j++;
      																										  break;
      																										  case 5:
      																											x.DR.MM=nbr;nbr=0;j++;
      																										  break;} }
											 }
							  x.DR.AA=nbr;nbr=0;
      					break;

					   }

       				 token = strtok(NULL, tmp1);i++;
   					 }

					   if(P==NULL){
					   	P=(PlisteEP)malloc(sizeof(Cellule3));
					   	P->VAL3=x;
        		  		P->Suivp=NULL;
        		  		P1=P;
					   }
					   else{
        		  		P1->Suivp=(PlisteEP)malloc(sizeof(Cellule3));
						P1=P1->Suivp;
						P1->VAL3=x;
						P1->Suivp=NULL;
					   }


		 }

     return P;
}
//----
void AfficheEP(PlisteEP T) {
	PlisteEP P; emprunt x ;
    P=T; printf("\nLes elements de la liste des emprunts sont:\n");

  while(P!=NULL){
  	x=(P->VAL3);
  	printf("\nle Matricule est : %d",x.MC);

 	printf("\nla cote : %s",x.cote);

 	printf("\nla date d'emprunte est : %d-%d-%d",x.DE.JJ,x.DE.MM,x.DE.AA);

  	printf("\nla date de retour : %d-%d-%d\n",x.DR.JJ,x.DR.MM,x.DR.AA);

	 P=P->Suivp;  }
}
//----
void AjouterEP(PlisteEP *T2,PlisteET *T1,PlisteOV *T){
	PlisteEP Q,P,L2=*T2;PlisteET L1=*T1;PlisteOV L=*T; int matricule,nbrPN=8,nbrOV,nbr=0;char *titre=(char*)malloc(50+1);

	printf("	-Donner le matricule de l'etudiant qui va emprunter");
	scanf("%d",&matricule);

	Q=L2;
		while (Q!=NULL){
			if(Q->VAL3.MC==matricule) nbr++;
  		Q=Q->Suivp;
	 	}

	if(nbr<4){
		nbrPN=nombrePN(L1, matricule); // !=0
	}else{
		printf("	-Vous n'avez pas le droit d'emprunter un live "); // prcq fat le nbr masmoh bih
	}


if(nbrPN<7 ){
	printf("\n	//Donner l'ouvrage que vous chercher : ");fflush(stdin); gets(titre);
	ExemplairesDispo (&L,titre,&nbrOV); }else{
	if(nbrPN==7)	printf("	-Vous n'avez pas le droit d'emprunter un live ");
	}


	if(nbrPN<7 && nbrOV!=0 ){
		L->VAL1.Ne--;L->VAL1.Nee++;
		P=malloc(sizeof(Cellule3));
		strcpy(P->VAL3.cote,L->VAL1.cote);
		P->VAL3.MC=matricule;
		printf("	- Donner la date d'aujourd'hui:\n	- Jour: ");scanf("%d",&P->VAL3.DE.JJ);
		printf("	- Mois: ");scanf("%d",&P->VAL3.DE.MM);
		printf("	- Annee: ");scanf("%d",&P->VAL3.DE.AA);

		printf("	- Donner la date de retour:\n	- Jour: ");scanf("%d",&P->VAL3.DR.JJ);
		printf("	- Mois: ");scanf("%d",&P->VAL3.DR.MM);
		printf("	- Annee: ");scanf("%d",&P->VAL3.DR.AA);
		L=*T;Q=L2;
		while (Q->Suivp!=NULL){
  		Q=Q->Suivp;
	 	}

  		P->Suivp=NULL;
  		Q->Suivp=P;
  		Q=Q->Suivp ;

	}

	*T2=L2;*T1=L1;*T=L;
}

//----
void SupprimerEP (PlisteEP *T, int *n ,date *x){
	PlisteEP L=*T; PlisteEP P,Pred; char cote[50];
	int matricule; date x1;

	printf("\n	- Donner le matricule de l'etudiant que vous voulez supprimer son emprunte : ");
	scanf("%d",&matricule);
	*n=matricule;

	printf("\n	- Donner la cote de l'ouvrage : ");
	fflush(stdin);
	gets(cote);


	P=L;Pred=L;
	while(P!=NULL ){
		if(P->VAL3.MC != matricule && P->VAL3.cote!=cote){
		Pred=P;
		P=P->Suivp;
		}else{
			break;
		}

	}

	if(P==NULL){
		printf("	Verifier le matricule ou la cote il y a une erreur dans la saisie \n");
	}else{
		x1.JJ=P->VAL3.DR.JJ;
		x1.MM=P->VAL3.DR.MM;
		x1.AA=P->VAL3.DR.AA;
		*x=x1;
		if(P==L){
			L=L->Suivp;
			free(P);
			*T=L;
		}else{
			Pred->Suivp=P->Suivp;
			free(P);
			*T=L;
		}
	}

}
// cas spe hadi tae penalite drtha hna prcq nkhdm biha tahtha
void AjouterPN(PlisteET P){

	P->VAL2.PT++;
	printf("\n	- Votre penalite a etait augmenter car vous n'avez pas rendu le livre a temps\n");

}
//-----
void RetournerEP (PlisteEP *T, PlisteET *T1){
	PlisteEP L=*T; int mat=0; date x,x1;
	PlisteET P,L1=*T1;

	printf("	- Donner la date d'aujourd'hui:\n	- Jour: ");scanf("%d",&x.JJ);
	printf("	- Mois: ");scanf("%d",&x.MM);
	printf("	- Annee: ");scanf("%d",&x.AA);

	SupprimerEP(&L,&mat,&x1);

	if(x1.AA<=x.AA && mat!=0){
		if(x1.MM<=x.MM){

			P=L1;
		while(P!=NULL ){
		if(P->VAL2.MC != mat){
		P=P->Suive;
		}else{
			break;
			}
		}

		AjouterPN(P); }else{
			if(x1.JJ<x.JJ){
			P=L1;
		while(P!=NULL ){
		if(P->VAL2.MC != mat){
		P=P->Suive;
		}else{
			break;
			}
		}

		AjouterPN(P);
			}
		}

	}

	*T=L;
	*T1=L1;
}
//--
void ModifierEP(PlisteEP *T){
	PlisteEP P,L=*T;
	int matricule;

	printf("\n	- Donner le matricule de l'etudiant que vous voulez modifier sa date de retour d'emprunte : ");
	scanf("%d",&matricule);

	P=L;
	while(P!=NULL ){
		if(P->VAL3.MC != matricule){
		P=P->Suivp;
		}else{
			break;
		}

	}


	if(P==NULL){
		printf("	Votre etudiant n'existe pas dans la liste \n");
	}else{
	printf("	- Donner la nouvelle date de retour:\n	- Jour: ");scanf("%d",&P->VAL3.DR.JJ);
	printf("	- Mois: ");scanf("%d",&P->VAL3.DR.MM);
	printf("	- Annee: ");scanf("%d",&P->VAL3.DR.AA);
	}

	*T=L;
}
//---
void dureeEP (){
	printf("	- Chaque etudiant avec un abonnement Classique a une duree de 1 mois, \n	et pour ceux qui dispose d'un abonnement Premium auront une duree de 2 mois\n");
}

