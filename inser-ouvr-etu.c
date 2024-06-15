//insertion d'un ouvrage-------------------------<<CELESTIN NDOLE SILVA>>---------------------------------------
 void IsertET (PlisteET *T){
	int i, NOVA ; // NOVA : le nombre d'etudiants que l'utulisateur  veut ajouter
	PlisteET p,Q; etudiant x;char s[50];

	  Q=*T;

 	while (Q->Suive!=NULL){
  		Q=Q->Suive ;
	 }

	printf ("\n 	//Donner le nombre d'etudiants que vous voullez ajouter a votre liste: ");
  	scanf("%d",&NOVA);


for (i=0;i<NOVA;i++){
	printf("\nDonner le matricule du l'etudiant N°%d : ",i+1);
	scanf("%d",&x.MC);
	printf("Donner son type d'abonnement ");

	do{		printf("Classique ou Premium? ");
			fflush(stdin);
 			gets(s);
	} while(strcmp(s,"Premium") && strcmp(s,"Classique"));

	if(!strcmp(s ,"Premium")){ x.TA='P';}else{	if(!strcmp(s ,"Classique")){ x.TA='C';  }  }
	x.PT=0;
  p=malloc(sizeof(Cellule2));
  p->VAL2=x;
  p->Suive=NULL;
  Q->Suive=p;
  Q=Q->Suive ;
}

}

void SupprimerET (PlisteET *T){
	PlisteET L=*T; PlisteET P,Pred;
	int matricule;

	printf("	- Donner le matricule de l'etudiant que vous voulez supprimer : ");
	scanf("%d",&matricule);

	P=L;Pred=L;
	while(P!=NULL ){
		if(P->VAL2.MC != matricule){
		Pred=P;
		P=P->Suive;
		}else{
			break;
		}

	}

	if(P==NULL){
		printf("	Votre etudiant n'existe pas dans la liste \n");
	}else{
		if(P==L){
			L=L->Suive;
			free(P);
			*T=L;
		}else{
			Pred->Suive=P->Suive;
			free(P);
			*T=L;
		}
	}

}


void ModifierET(PlisteET *T){
	int i , NOVA ;
	char s[50];int mat;
		PlisteET Q; etudiant x;
		 Q=*T;

	printf ("\n 	//Donner le nombre d'etudiants que vous voullez Modifier a votre liste: ");
  	scanf("%d",&NOVA);

	for (i=0;i<NOVA;i++){

			printf("\nDonner le matricule et le nv abonnement de l'etudiant N°%d\n",i+1);
			printf("Matricule : "); scanf("%d",&mat); printf("Abonnement ");
			do{
			printf("Classique ou Premium? ");
			fflush(stdin);
 			gets(s);
			} while(strcmp(s,"Premium") && strcmp(s,"Classique"));

				while (Q->VAL2.MC!=mat && Q->Suive!=NULL ){
  					Q=Q->Suive ;
	 			}

	 			if(Q!=NULL){	if(!strcmp(s ,"Premium")){ Q->VAL2.TA='P';Q->VAL2.PT=0;}else{ Q->VAL2.TA='C';Q->VAL2.PT=0; }  }else{
	 				printf("Votre Matricule est incorrect");exit(-1);	 }

	 		 Q=*T;
	}

}

//----les pénalités --------------------------<<CELESTIN NDOLE SILVA>>--------------------------------------------
void AffichePN(PlisteET T) {
	PlisteET P; etudiant x ; int i=1;
    P=T; printf("\nLa liste des penalites:\n");

  while(P!=NULL){
  	x=(P->VAL2);
  	printf("\nEtudiant %d sa penalite: %d\n",x.MC,x.PT);

	 P=P->Suive;i++;  }
}

int nombrePN(PlisteET P , int matricule){

	while(P!=NULL ){
		if(P->VAL2.MC != matricule){
		P=P->Suive;
		}else{
			break;
		}
	}

	if(P==NULL){
		printf("	Votre etudiant n'existe pas dans la liste \n"); return 8;
	}else{
		return P->VAL2.PT;
		}
	}



//-----------------------------FIN SILVA---------------------------------------------
void menuOv(PlisteOV *Q, char*cmpt) {
	char n[50];PlisteOV T=*Q;int nbr; char cmpt1[10];strcpy(cmpt,"oui"); char titre[50];

do{
printf("-------------------------<< Liste des Ouvrages >>-------------------------\n");
printf("1- Ajouter des ouvrages\n");
printf("2- Supprimer un ouvrage\n");
printf("3- Consulter la liste de tous les ouvrages\n");
printf("4- La disponibilite des exemplaires\n");
printf("5- Le maximum d’ouvrage a emprunter\n");
printf("6- Retourner au menu principal\n");

printf("--------------------------- <<o>> --------------------------\n\n");
do{
printf("- veuillez choisir le numero la fonction que vous voulez executer: "); fflush(stdin);gets(n);

} while(n[0]<'1' || n[0]>'6' || n[1]!= '\0') ;

switch (n[0])
  {
    case '1':
       IsertOV(&T);*Q=T;
       break;
    case '2':
       SupprimerOV (&T);*Q=T;
       break;
    case '3':
       AfficheOV(T);
       break;
    case '4':
    		printf("\n	//Donner l'ouvrage que vous chercher : ");fflush(stdin); gets(titre);
       ExemplairesDispo(&T,titre,&nbr);if(nbr==1){ printf("  -Exemplaires de votre ouvrage disponible \n");  }else{ printf("  -Exemplaires de votre ouvrage n'est pas disponible\n"); }
       nbr=0;T=*Q;
	   break;
    case '5':
       nbr=MaxOV(T);
	   printf("    -Le maximum d'ouvrage disponible a emprunter est : %d ouvrages\n",nbr); printf("	-Et le maximum pour chaque etudiant est 3 ouvrages\n");
       break;
    case '6':
    	strcpy(cmpt,"no");
       break;
 }


if(strcmp(cmpt,"no")){
	printf("\n 	//Voulez vous reexecuter le menu des Ouvrages? ");
do{
printf("oui ou non? ");
fflush(stdin);
  gets(cmpt1);
} while(strcmp(cmpt1,"oui") && strcmp(cmpt1,"non"));
strcpy(cmpt,cmpt1);
}

   } while(!strcmp(cmpt,"oui"));


}
