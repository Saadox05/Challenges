#include <stdio.h>
#include <string.h>
#include <ctype.h>




enum Departements{
    None,Informatique,Mathematiques,Physique,Chimie,Biologie,Litterature,Economie

};

struct Date{
    short Jour;
    short Mois;
    int Annee;

};
struct etudiant{

    int ID;
    char Nom[40];
    char Prenom[40];
    struct Date Date_Naissance;
    enum Departements Departement;
    float Note_Generale;
    short estReussi;

};
struct etudiant etudiants[100];
int _ID=0;
int Etudiants_Nombre=0;
void MenuPrincipal();
enum Departements Return_ENUM(int Choix)
{
    enum Departements D=(enum Departements)Choix;
    return D;
}
void RemplirDefualtEtudiantsInfo()
{
    char Noms[11][40]={"saad","asmae","raja","amine","taha","imad","mouad","mohamed","salma","samir","hind"};
    char Prenoms[11][40]={"el quaul","balou","ahmid","zaroun","mlouk","nasar","zitoun","lamine","seraj","holim","bnan"};
    short Jours[11]={1,12,3,8,22,14,26,22,27,1,5};
    short Moiss[11]={9,7,8,3,1,11,5,8,12,4,9};
    int Annees[11]={2000,2003,2001,2000,2002,2001,2000,1999,2004,2001,1998};
    enum Departements D[11]={Informatique,Physique,Mathematiques,Biologie,Physique,Informatique,Physique,Economie,Biologie,Informatique,Mathematiques};
    float N_Generale[11]={17.50,16,9.25,10.75,12.75,8.75,7.50,15,18,11.50,19.25};
    for(int i=0;i<11;i++)
    {   Etudiants_Nombre++;
        etudiants[i].ID=Etudiants_Nombre;
        strcpy(etudiants[i].Nom,Noms[i]);
        strcpy(etudiants[i].Prenom,Prenoms[i]);
        etudiants[i].Date_Naissance.Jour=Jours[i];
        etudiants[i].Date_Naissance.Mois=Moiss[i];
        etudiants[i].Date_Naissance.Annee=Annees[i];
        etudiants[i].Departement=D[i];
        etudiants[i].Note_Generale=N_Generale[i];
        if(etudiants[i].Note_Generale<10)
        {
            etudiants[i].estReussi=0;
        }else{
            etudiants[i].estReussi=1;

        }
	_ID=Etudiants_Nombre+1;



    }




}
int LireUnChoix(int from,int to)
{
    int Choix=0;
    scanf("%d",&Choix);
    while(Choix<from||Choix>to)
    {
        printf("\nVeuillez entrer votre choix (%d-%d) : ",from,to);
        scanf("%d",&Choix);
    }
    return Choix;


}
void Swap(struct etudiant *S1,struct etudiant *S2)
{
    struct etudiant TempS = *S1;
    *S1=*S2;
    *S2=TempS;



}

void AjouterChoixMenu()
{
    
    printf("\nVoulez-vous ajouter un etudiant ou plusieurs etudiants ?");
    printf("\n_____________________________________\n");
    printf("|    1-Ajouter un etudiant           |\n");
    printf("|    2-Ajouter plusieurs etudiants   |\n");
    printf("|    3-Retourner a menu principal    |\n");
    printf("|____________________________________|\n");
    printf("|  Veuillez entrer votre choix (1-3) |\n");
    printf("|____________________________________|\n");
    
}
void AjouteUnEtudiant()
{   
        printf("\n_______________________________________________________\n");
        //printf("\nVeuillez saisir le numero unique de l'etudiant: ");
        //scanf("%d",etudiants[Etudiants_Nombre].ID);
        printf("Veuillez entrer le nom de l'etudiant: ");
        scanf(" %[^\n]s",etudiants[Etudiants_Nombre].Nom);
        for(int i=0;i<strlen(etudiants[Etudiants_Nombre].Nom);i++)
    {
       etudiants[Etudiants_Nombre].Nom[i]=tolower(etudiants[Etudiants_Nombre].Nom[i]);
    }
    etudiants[Etudiants_Nombre].Nom[0]=toupper(etudiants[Etudiants_Nombre].Nom[0]);
        printf("Veuillez entrer le prenom de l'etudiant: ");
        scanf(" %[^\n]s",etudiants[Etudiants_Nombre].Prenom);
        for(int i=0;i<strlen(etudiants[Etudiants_Nombre].Prenom);i++)
    {
       etudiants[Etudiants_Nombre].Prenom[i]=tolower(etudiants[Etudiants_Nombre].Prenom[i]);
    }
    etudiants[Etudiants_Nombre].Prenom[0]=toupper(etudiants[Etudiants_Nombre].Prenom[0]);
        printf("Veuillez saisir la date de naissance de l'etudiant: \n");
        printf("saisir le jour : ");
        scanf("%hi",&etudiants[Etudiants_Nombre].Date_Naissance.Jour);
        printf("saisir le mois : ");
        scanf("%hi",&etudiants[Etudiants_Nombre].Date_Naissance.Mois);
        printf("saisir l'annee : ");
        scanf("%d",&etudiants[Etudiants_Nombre].Date_Naissance.Annee);
        printf("Veuillez indiquer le departement dans lequel l'etudiant est inscrit \n");
        printf("| 1-Informatique | 2-Mathematiques | 3-Physique |\n| 4-Chimie | 5-Biologie | 6-Litterature | 7-Economie |\n==>");
        etudiants[Etudiants_Nombre].Departement=(enum Departements)LireUnChoix(1,7);
        printf("Veuillez entrer la note generale de l'etudiant : ");
        scanf("%f",&etudiants[Etudiants_Nombre].Note_Generale);
        printf("\n_______________________________________________________\n");
        if(etudiants[Etudiants_Nombre].Note_Generale>=10)
        {
            etudiants[Etudiants_Nombre].estReussi=1;

        }else{
            etudiants[Etudiants_Nombre].estReussi=0;
        }
        
        etudiants[Etudiants_Nombre].ID=_ID;_ID++;
        Etudiants_Nombre++;
}
void AjouterUnEtudiantMenu()
    {
        printf("\n#####################-AJOUTER-#####################\n");
        AjouterChoixMenu();
        printf("==>");
        short choix=LireUnChoix(1,3);
        int N_DeAjoute=1;
        switch(choix)
        {
            case 1:{AjouteUnEtudiant();printf("\nl'etudiant ajoutee avec succes!\n");break;}
            case 2:{printf("\nEntrez le nombre d'etudiants que vous souhaitez ajouter : ");
                    scanf("%d",&N_DeAjoute);
                    for(int i=0;i<N_DeAjoute;i++)
                    {
                        printf("\nSaisir les information d Etudiant %d",i+1);
                        AjouteUnEtudiant();

                    }
                    printf("\nles etudiantes ajoute avec succes!");break;        }

            case 3:{   return;         }
        }

        return;

 }

int Rechercher(short choix)
{   
    int TempID=0;
    char TempNom[40];
    switch(choix)
    {
        case 1:{
                nouveau1:
                printf("\nEntrer ID de Etudiant: ");
                scanf("%d",&TempID);
            for(int i=0;i<Etudiants_Nombre;i++)
        {
            if(etudiants[i].ID==TempID)
            {
                return i;
            }
        }
            
            printf("\nEtudiant non trouvee!");
            printf("\nVoulez-vous Rechercher a nouveau? \n| 1-Oui | ou | 2-Non et Retourner a menu principal |");
            printf("\nEntrer votre choix: ");
            choix=LireUnChoix(1,2);
            if(choix==1){goto nouveau1;}
            return -1;
        
        
        
              }
        case 2:{
            nouveau2:
            printf("\nEntrer le Nom de Etudiant: ");
                scanf(" %[^\n]s",&TempNom);
            for(int i=0;i<Etudiants_Nombre;i++)
        {
            if(strcmp(etudiants[i].Nom,TempNom)==0)
            {
                return i;
            }
        }
            
            printf("\nEtudiant non trouvee!");
            printf("\nVoulez-vous Rechercher a nouveau? \n| 1-Oui | ou | 2-Non et Retourner a menu principal |");
            printf("\nEntrer votre choix: ");
            choix=LireUnChoix(1,2);
            if(choix==1){goto nouveau2;}
            return -1;

        }


    }

}
const char* NomDeDepartement(int Choix)
{   
    enum Departements D=(enum Departements)Choix;
    switch(D)
    {   
        case None:{ return "None";
            }
        case Informatique:{ return "Informatique";
            
        }
        case Mathematiques:{ return "Mathematiques";
    
        }
        case Physique:{ return "Physique";
            
        }
        case Chimie:{ return "Chimie";
            
        }
        case Biologie:{ return "Biologie";
            
        }
        case Litterature:{ return "Litterature";
            
        }
        case Economie:  { return "Economie";
            
        }
    }

}
void AfficherEtudiantInfo(int index)
{
    printf("\n-----------------Etudiant Info-----------------\n");
    printf("| ID                : #%d\n",etudiants[index].ID);
    printf("| Nom               : %s\n",etudiants[index].Nom);
    printf("| Prenom            : %s\n",etudiants[index].Prenom);
    printf("| Date de naissance : %hi/%hi/",etudiants[index].Date_Naissance.Jour,etudiants[index].Date_Naissance.Mois);
    printf("%d\n",etudiants[index].Date_Naissance.Annee);
    printf("| Departement       : %s\n",NomDeDepartement(etudiants[index].Departement));
    printf("| Note generale     : %0.2f\n",etudiants[index].Note_Generale);
    printf("|________________________________________________\n");
}


 
void ModifierUnEtudiant()
{  
    printf("\n#####################-Modification-#####################");
     int Trouvee=Rechercher(1);
     if(Trouvee!=-1)
     {  
        printf("\nEtudiant trouvee avec succes: ");
        AfficherEtudiantInfo(Trouvee);
        printf("\nVoules vous continuer a Modifier cet etudiant ?\n | 1-Oui | au | 2-Non et Retourner a menu principal |\n");
        if(LireUnChoix(1,2)==1){
        printf("\nEntrez la nouvelle Nom: ");
        scanf(" %[^\n]",&etudiants[Trouvee].Nom);
        printf("\nEntrez la nouvelle Prenom: ");
        scanf(" %[^\n]",&etudiants[Trouvee].Prenom);
        printf("\nEntrez la nouvelle Date de naissance: ");
        printf("\nle Jour: ");
        scanf("%hi",&etudiants[Trouvee].Date_Naissance.Jour);
        printf("\nle Mois: ");
        scanf("%hi",&etudiants[Trouvee].Date_Naissance.Mois);
        printf("\nl'Annee: ");
        scanf("%d",&etudiants[Trouvee].Date_Naissance.Annee);
        printf("\nEntrez la nouvelle Departement: \n");
        printf("| 1-Informatique | 2-Mathematiques | 3-Physique |\n| 4-Chimie 5-Biologie | 6-Litterature | 7-Economie |\n");
        etudiants[Trouvee].Departement=(enum Departements)LireUnChoix(1,7);
        printf("\nEntrez la nouvelle note generale: ");
        scanf("%f",&etudiants[Trouvee].Note_Generale);
        printf("\nEtudiant modifie avec succes");
        printf("\nVoulez vous modifier un autre etudiant?\n| 1-Oui | au | 2-Non et Retourner a menu principal |\n");
        if(LireUnChoix(1,2)==1)
        {
            ModifierUnEtudiant();
        }
        }
            
        

     }
     return;
}
void SupprimerUnEtudiant()
{
    printf("\n#####################-SUPPRESSION-#####################");
     int Trouvee=Rechercher(1);
     if(Trouvee!=-1)
     {  
        printf("Etudiant trouvee avec succes: ");
        AfficherEtudiantInfo(Trouvee);
        printf("\nVoules vous continuer a Supprimer cet etudiant ?\n | 1-Oui | au | 2-Non et Retourner a menu principal |\n");
        if(LireUnChoix(1,2)==1){
        
        etudiants[Trouvee].ID=0;
        strcpy(etudiants[Trouvee].Nom,"");
        strcpy(etudiants[Trouvee].Prenom,"");
        etudiants[Trouvee].Date_Naissance.Jour=0;
        etudiants[Trouvee].Date_Naissance.Mois=0;
        etudiants[Trouvee].Date_Naissance.Annee=0;
        etudiants[Trouvee].Departement=None;
        etudiants[Trouvee].Note_Generale=0;
        Swap(&etudiants[Trouvee],&etudiants[Etudiants_Nombre-1]);
        Etudiants_Nombre--;
        // a tri a bulles pour trier les etudiants par ID
        for(int i=1;i<Etudiants_Nombre;i++)
        {
            short swapped=0;
            for(int j=0;j<Etudiants_Nombre-1;j++)
            {
                if(etudiants[j].ID>etudiants[j+1].ID)
                {
                    Swap(&etudiants[j],&etudiants[j+1]);
                    swapped=1;
                }
                
                
            }
            if(swapped==0){break;}
        }
            
        printf("\nEtudiant Suprimees avec succes");
        printf("\nVoulez vous Suprprimer un autre etudiant?\n| 1-Oui | au | 2-Non et Retourner a menu principal |\n");
        if(LireUnChoix(1,2)==1)
        {
            SupprimerUnEtudiant();
        }
        
            
        

     }
     return;
}}

void ModifierOuSupprimerMenu()
{
    printf("\nVoulez-vous Modifier ou Superrimer ? ?");
    printf("\n_____________________________________\n");
    printf("|    1-Modifier                      |\n");
    printf("|    2-Superrimer                    |\n");
    printf("|    3-Retourner au menu principal   |\n");
    printf("|____________________________________|\n");
    printf("|  Veuillez entrer votre choix (1-3) |\n");
    printf("|____________________________________|\n==>");
    short Choix=LireUnChoix(1,3);
    switch(Choix)
    {
        case 1:{ModifierUnEtudiant();break;}

        case 2:{SupprimerUnEtudiant();break;}


        case 3:{ break;}
    }
return;



}

void AfficherEtudiantInfoMenu()
{   
    int index=Rechercher(1);
    if(index!=-1)
    {   printf("\nEtudiant trouvee avec succes: ");
        AfficherEtudiantInfo(index);
        printf("\nVoules vous Rechercher un autre etudiant ?\n | 1-Oui | au | 2-Non et Retourner a menu principal |\n");
        if(LireUnChoix(1,2)==1)
        {
            AfficherEtudiantInfoMenu();
        }

    }
    return;
}


float MoyenneGeneral(short Choix,int *NombreDetudiant,int *NombreDeReussi)
{  
    float NotesSomme=0;
    *NombreDeReussi=0;
    *NombreDetudiant=0;//Nombre Des Etudiant on a Specifique Departement
    
    switch(Choix)
    {
        case 8:{
            for(int i=0;i<Etudiants_Nombre;i++)
            {
                if(etudiants[i].estReussi==1){(*NombreDeReussi)++;}
                NotesSomme+=etudiants[i].Note_Generale;
                (*NombreDetudiant)++;

            }
            return (NotesSomme/Etudiants_Nombre);

        }
        case 1:{
            for(int i=0;i<Etudiants_Nombre;i++)
            {
                if(etudiants[i].Departement==Informatique){
                NotesSomme+=etudiants[i].Note_Generale;
                 (*NombreDetudiant)++;
                 (*NombreDeReussi)++;
                }
            }
            
            return (NotesSomme/(*NombreDetudiant));

        }
        case 2:{
            for(int i=0;i<Etudiants_Nombre;i++)
            {
                if(etudiants[i].Departement==Mathematiques){
                NotesSomme+=etudiants[i].Note_Generale;
                (*NombreDetudiant)++;
                (*NombreDeReussi)++;
                }
            }
            
            return (NotesSomme/(*NombreDetudiant));

        }
        case 3:{
            for(int i=0;i<Etudiants_Nombre;i++)
            {
                if(etudiants[i].Departement==Physique){
                NotesSomme+=etudiants[i].Note_Generale;
                (*NombreDetudiant)++;
                (*NombreDeReussi)++;
                }
            }
            
            return (NotesSomme/(*NombreDetudiant));

        }
        case 4:{
            for(int i=0;i<Etudiants_Nombre;i++)
            {
                if(etudiants[i].Departement==Chimie){
                NotesSomme+=etudiants[i].Note_Generale;
                (*NombreDetudiant)++;
                (*NombreDeReussi)++;
                }
            }
            
            return (NotesSomme/(*NombreDetudiant));

        }
        case 5:{
            for(int i=0;i<Etudiants_Nombre;i++)
            {
                if(etudiants[i].Departement==Biologie){
                NotesSomme+=etudiants[i].Note_Generale;
                (*NombreDetudiant)++;
                (*NombreDeReussi)++;
                }
            }
            
            return (NotesSomme/(*NombreDetudiant));

        }
        case 6:
        {
            for(int i=0;i<Etudiants_Nombre;i++)
            {
                if(etudiants[i].Departement==Litterature){
                NotesSomme+=etudiants[i].Note_Generale;
                (*NombreDetudiant)++;
                (*NombreDeReussi)++;
                }
            }
            
            return (NotesSomme/(*NombreDetudiant));

        }
        case 7:
        {
            for(int i=0;i<Etudiants_Nombre;i++)
            {
                if(etudiants[i].Departement==Economie){
                NotesSomme+=etudiants[i].Note_Generale;
                (*NombreDetudiant)++;
                (*NombreDeReussi)++;
                }
            }
            
            return (NotesSomme/(*NombreDetudiant));

        }







    }




}
void CalculerMoyenneGenerale()
{
    printf("\n________________ Calcul de la Moyenne Generale________________");
    printf("\n|\t\t\t\t**************");
    printf("\n|   1-Calculer la moyenne generale de chaque departement");
    printf("\n|   2-Calculer la moyenne generale de l'universite entiere");
    printf("\n|   3-Retourner a la menu principal");
    printf("\n|_____________________________________________________________\n==>");
    int a=0,b=0;
    switch (LireUnChoix(1,3))
    {
    case 1:{
        
        printf("\nQuel departement vous souhaitez calculer la moyenne generale :");
        printf("\n| 1-Informatique | 2-Mathematiques | 3-Physique | 4-Chimie         |\n| 5-Biologie | 6-Litterature | 7-Economie | 8-Tous les departements|\n==>");
        short Choix=LireUnChoix(1,8);
        
        printf("\nhii\nDep: \n %0.2f",MoyenneGeneral(8,&a,&b));
        if(Choix==8){
        printf("\nLa Moyenne Generale de tous les departements est : %0.2f",MoyenneGeneral(8,&a,&b));
        }else{
            printf("\nLa Moyenne Generale de Departement %s est : %0.2f",NomDeDepartement(Choix),MoyenneGeneral(Choix,&a,&b));
        }
        break;
    }
    case 2:{
        printf("\nLa Moyenne Generale de  l'universite entiere est : %0.2f",MoyenneGeneral(8,&a,&a));break;
    }

    case 3:{
            break;
    }

    }
    return;

}



void AfficherListeEtudiant(short Choix)
{

    printf("\n###################################-La liste des Etudiant-###############################");
    printf("\n_____________________________________*******************_________________________________");
    printf("\n|  ID     | Nom        | Prenom      | Date Naissance   | Departement   | Note Generale |");
    printf("\n|---------------------------------------------------------------------------------------|");
    
    short estInscrits=0;
switch(Choix)
{

    case 1:{
        for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].Departement==Informatique){
                printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
                    estInscrits=1;
            }
            if(estInscrits==0){
                printf("\n|              il n'y a pas d'etudiants inscrits dans ce departement                    |");
                
            }
            printf("\n|_________|____________|_____________|__________________|_______________|_______________|\n");
            }break;}

    case 2:{
         for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].Departement==Mathematiques){
                printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
                    estInscrits=1;
            }
            }
            if(estInscrits==0){
                printf("\n|              il n'y a pas d'etudiants inscrits dans ce departement                    |");
                
            }
            printf("\n|_________|____________|_____________|__________________|_______________|_______________|\n");
            break;

    }
    case 3:{
         for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].Departement==Physique){
                printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
                    estInscrits=1;
            }
            }
            if(estInscrits==0){
                printf("\n|              il n'y a pas d'etudiants inscrits dans ce departement                    |");
                
            }
            printf("\n|_________|____________|_____________|__________________|_______________|_______________|\n");
        break;

    }
    case 4:{
             for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].Departement==Chimie){
                printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
                    estInscrits=1;
            }
            }
            if(estInscrits==0){
                printf("\n|              il n'y a pas d'etudiants inscrits dans ce departement                    |");
                
            }
            printf("\n|_________|____________|_____________|__________________|_______________|_______________|\n");
            break;

    }
    case 5:{
         for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].Departement==Biologie){
                printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
                    estInscrits=1;
            }
            }
            if(estInscrits==0){
                printf("\n|              il n'y a pas d'etudiants inscrits dans ce departement                    |");
                
            }
            printf("\n|_________|____________|_____________|__________________|_______________|_______________|\n");
            break;


    }
    case 6:
    {    for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].Departement==Litterature){
                printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
                estInscrits=1;
            }
            }
            if(estInscrits==0){
                printf("\n|              il n'y a pas d'etudiants inscrits dans ce departement                    |");
                
            }
            printf("\n|_________|____________|_____________|__________________|_______________|_______________|\n");
            
            break;

    }
    case 7:{
             for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].Departement==Economie){
                printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
                estInscrits=1;
            }
            }
            if(estInscrits==0){
                printf("\n|              il n'y a pas d'etudiants inscrits dans ce departement                    |");
                
            }
            printf("\n|_________|____________|_____________|__________________|_______________|_______________|\n");
            break;
    }
    case 8:{
                for(int i=0;i<Etudiants_Nombre;i++)
            {
                printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
            }
            printf("\n|_________|____________|_____________|__________________|_______________|_______________|\n");
            break;



    }












}






}
void RechercherUnEtudiantMenu()
{
    printf("\n#####################-RECHERCHER-#####################");
    printf("\n|   1-Rechercher un etudiant ");
    printf("\n|   2-Afficher la liste des etudiants dans un departement");
    printf("\n|   3-Retourner a la menu principal");
    printf("\nEntrez voutre Choix (1 a 3): ");
    switch(LireUnChoix(1,3)){

      case 1:{  AfficherEtudiantInfoMenu();break;
      }
       case 2: {
        printf("\nQuel departement vous souhaitez Afficher au Voir la liste des etudiants :");
        printf("\n| 1-Informatique | 2-Mathematiques | 3-Physique | 4-Chimie |\n| 5-Biologie | 6-Litterature | 7-Economie | 8-Tous les departements\n");
        AfficherListeEtudiant(LireUnChoix(1,8));



       }
    case 3: break;
    }
    return;
    }
void TrierAlphabetique(short choix)
{
    //Tri a Bulles
    if(choix==1){
    for(int i=1;i<Etudiants_Nombre;i++)
    {   
        for(int j=0;j<Etudiants_Nombre-1;j++)
        {
            if(etudiants[j].Nom[0]>etudiants[j+1].Nom[0])
            {
                Swap(&etudiants[j],&etudiants[j+1]);
            }


        }



    }}else{
        for(int i=0;i<Etudiants_Nombre;i++)
        {
            for(int j=0;j<Etudiants_Nombre-1;j++)
            {   
                if(etudiants[j].Nom[0]<etudiants[j+1].Nom[0])
                {
                    Swap(&etudiants[j],&etudiants[j+1]);
                }


            }


        }
    }
    return;

}
void TriParMoyenneGenerale(short choix)
{
    if(choix==1)
    {
        for(int i=1;i<Etudiants_Nombre;i++)
        {
            struct etudiant TempEtudiant=etudiants[i];
            int j=i-1;
                  while(j>=0&&TempEtudiant.Note_Generale>etudiants[j].Note_Generale)
            {
                Swap(&etudiants[j+1],&etudiants[j]);
                j--;                

            }
        etudiants[j+1]=TempEtudiant;

        }
        return;

    }
    for(int i=1;i<Etudiants_Nombre;i++)
        {
            struct etudiant TempEtudiant=etudiants[i];
            int j=i-1;
                  while(j>=0&&TempEtudiant.Note_Generale<etudiants[j].Note_Generale)
            {
                Swap(&etudiants[j+1],&etudiants[j]);
                j--;                

            }
        etudiants[j+1]=TempEtudiant;

        }
        return;




}

void TriParStatut(int choix)
{
    short estReussis=0;
    if(choix==1)
    {    printf("\n################################-La liste des Etudiant Reussi-############################");
    printf("\n_____________________________________*******************________________________________");
    printf("\n|  ID     | Nom        | Prenom      | Date Naissance   | Departement   | Note Generale |");
    printf("\n|---------------------------------------------------------------------------------------|");
     for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].estReussi==1){
                printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
                estReussis=1;
            }
           
            }
            
    }else{
         printf("\n################################-La liste des Etudiant Echec-############################");
    printf("\n_____________________________________*******************________________________________");
    printf("\n|  ID     | Nom        | Prenom      | Date Naissance   | Departement   | Note Generale |");
    printf("\n|---------------------------------------------------------------------------------------|");
     for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].estReussi==0){
                 printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|  %02hi/%02hi/%-9d ",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);


    }}





}
}
void TrierEtudiantsMenu()
{
    printf("\n#####################-TRIER LES ETUDIANTS-#####################");
    printf("\n|   1-trier les etudiants par leur nom de famille ? ");
    printf("\n|   2-trier les etudiants par leur note generale ?");
    printf("\n|   3-trier les etudiants en fonction de leur statut de reussite ?");
    printf("\n|   4-Retourner a la menu principal");
    printf("\nEntrez voutre Choix (1 a 4): ");

    switch(LireUnChoix(1,4))
    {

        case 1:{
            printf("\n--------------TRIER LES ETUDIANTS PAR NOM -----------------");
            printf("\n|   1-Trier Alphabetique de A a Z (Croissant) ");
            printf("\n|   2-Trier Alphabetique de Z a A (Decroissant)");
            printf("\n|___________________________________________________________");
            printf("\nEntrez voutre Choix (1 a 2): ");
            if(LireUnChoix(1,2)==1)
            {
                TrierAlphabetique(1);
                printf("\n Les Etudiants Triee avec succes");break;
            }
            TrierAlphabetique(2);
            printf("\n Les Etudiants Triee avec succes");
                break;

        }


        case 2:{
            printf("\n--------TRIER LES ETUDIANTS PAR MOYENNE GENERALE -------------");
            printf("\n|   1-Du plus eleve au plus faible ");
            printf("\n|   2-Du plus faible au plus eleve");
            printf("\n|______________________________________________________________");
            printf("\nEntrez voutre Choix (1 a 2): ");
            if(LireUnChoix(1,2)==1)
            {
                TriParMoyenneGenerale(1);
                printf("\n Les Etudiants Triee avec succes");break;
            }
            TriParMoyenneGenerale(2);
            printf("\n Les Etudiants Triee avec succes");
                break;


        }


        case 3:{
             printf("\n------------------TRIER LES ETUDIANTS PAR  STATUT DE REUSSITE -----------------");
            printf("\n|   1-Reussite (moyenne ≥ 10/20) ");
            printf("\n|   2-Echec (moyenne < 10/20)");
            printf("\n|______________________________________________________________");
            printf("\nEntrez voutre Choix (1 a 2): ");
            if(LireUnChoix(1,2)==1)
            {
                TriParStatut(1);
                printf("\n Les Etudiants Triee avec succes");break;
            }
            TriParStatut(2);
            printf("\n Les Etudiants Triee avec succes");
                break;



        }




        case 4:{
                break;
        }




    }
    return;


}

void Statistiques(short choix)
{
    int compteur=0;
    switch(choix)
    {
        case 1:{
            printf("\n| Le nombre total d'etudiants inscrits est : %d",Etudiants_Nombre);
            break;
        }
        case 2:{
            printf("\nQuel departement vous souhaitez afficher ses etudiants:");
        printf("\n| 1-Informatique | 2-Mathematiques | 3-Physique | 4-Chimie |\n| 5-Biologie | 6-Litterature | 7-Economie | 8-Tous les departements\n");
        short Choix=LireUnChoix(1,8);int NombreDeEtudiant=0;
        MoyenneGeneral(Choix,&NombreDeEtudiant,0);
        if(Choix==8){
            
            printf("\nLe nombre de etudiants dans tous les departements est: %d ",NombreDeEtudiant);
        }else{

            printf("\nLe nombre de etudiants dans departement %s est : %d",NomDeDepartement((enum Departements)Choix),NombreDeEtudiant);
        }


        }
        case 3:{
            float seuil=0;
            printf("\nVeuillez entrer le seuil de la moyenne generale: ");
            scanf("%f",&seuil);
            printf("\n################################-La liste des Etudiant Superieur a %f -############################",seuil);
    printf("\n_____________________________________*******************_______________________________");
    printf("\n|  ID     | Nom        | Prenom      | Date Naissance | Departement   | Note Generale |");
    printf("\n|-------------------------------------------------------------------------------------|");
    TriParMoyenneGenerale(2);
    for(int i=0;i<Etudiants_Nombre;i++)
            {   if(etudiants[i].Note_Generale<seuil){
                break;
            }
            printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|    %hi/%hi/%-8d",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
            }
            break;




        }
        case 4:{
            printf("\n################################-La liste de TOP 3 etudiants-############################");
    printf("\n_____________________________________*******************_______________________________");
    printf("\n|  ID     | Nom        | Prenom      | Date Naissance | Departement   | Note Generale |");
    printf("\n|-------------------------------------------------------------------------------------|");
    TriParMoyenneGenerale(2);
    for(int i=0;i<3;i++)
            {
            printf("\n| #%-7d| %-11s| %-12s",etudiants[i].ID,etudiants[i].Nom,etudiants[i].Prenom);
                printf("|    %hi/%hi/%-8d",etudiants[i].Date_Naissance.Jour,etudiants[i].Date_Naissance.Mois,etudiants[i].Date_Naissance.Annee);
                printf("| %-14s|    %-11.2f|",NomDeDepartement(etudiants[i].Departement),etudiants[i].Note_Generale);
            }
            break;



        }
        case 5:{
            printf("\nQuel departement vous souhaitez Afficher le nombre d'etudiants ayant reussi :");
            printf("\n| 1-Informatique | 2-Mathematiques | 3-Physique | 4-Chimie |\n| 5-Biologie | 6-Litterature | 7-Economie | 8-Tous les departements\n");
            int n_reussi=0;
            int choix=LireUnChoix(1,8);
            MoyenneGeneral(choix,0,&n_reussi);
            if(choix==8)
            {   

                printf("\nLe nombre d'etudiants ayant reussi dans tous les departement est : %d ",n_reussi);

                break;
            }
            printf("\nLe nombre d'etudiants ayant reussi dans departement %s est : %d",NomDeDepartement((enum Departements)choix),n_reussi);
            break;

        }
        case 6:{

            break;

        }
    }

    return;


}


void    StatistiqueMenu()
{
    printf("\n#####################-STATISTIQUES-#####################");
    printf("\n|   1-Afficher le nombre total d'etudiants inscrits ");
    printf("\n|   2-Afficher le nombre d'etudiants dans chaque departement");
    printf("\n|   3-Afficher les etudiants ayant une moyenne générale supérieure à un certain seuil");
    printf("\n|   4-Afficher les 3 étudiants ayant les meilleures notes.");
    printf("\n|   5-Afficher le nombre d'etudiants ayant réussi dans chaque departement");
    printf("\n|   6-Quitter et Routeurner a la prancipal Menu");
    printf("\nEntrez voutre Choix (1 a 6): ");

    Statistiques(LireUnChoix(1,6));
    return;

}


void MenuAffichage()
{
    printf("\n____________________________________________________\n");
    printf("|                                                  |\n");
    printf("|              Gestion des etudiants               |\n");
    printf("|__________________________________________________|\n");
    printf("|                                                  |\n");
    printf("|                  Prancipal Menu                  |\n");
    printf("|__________________________________________________|\n");
    printf("|                                                  |\n");
    printf("|    1-Ajouter un etudiant                         |\n");
    printf("|    2-Modifier ou Supprimer un etudiant           |\n");
    printf("|    3-Afficher les details d'un etudiant          |\n");
    printf("|    4-Calculer la moyenne generale                |\n");
    printf("|    5-Rechercher un etudiant                      |\n");
    printf("|    6-Trier les etudiants                         |\n");
    printf("|    7-Statistiques                                |\n");
    printf("|    8-Quitter                                     |\n");
    printf("|                                                  |\n");
    printf("|__________________________________________________|\n");
    printf("|                                                  |\n");
    printf("|      Veuillez entrer votre choix (1-8)           |\n");
    printf("|__________________________________________________|\n");
    printf("==>");
}
void MenuPrincipal()
{ 

 int Choix=0;
 do{
 
 MenuAffichage();
Choix=LireUnChoix(1,8);

switch(Choix)
{
    case 8:{printf("\nMenu Quitte");break;}
    case 1:{ AjouterUnEtudiantMenu();break;
        }
    case 2:{ModifierOuSupprimerMenu();break;
        }
    case 3:{AfficherEtudiantInfoMenu();break;
        }
    case 4:{
        CalculerMoyenneGenerale();break;
    }
    case 5:{
        RechercherUnEtudiantMenu();break;

    }
    case 6:{ TrierEtudiantsMenu();break;
        

    }
    case 7:{ StatistiqueMenu();break;

        
    }

}
}while(Choix!=0);

return;

}

int main()
{
RemplirDefualtEtudiantsInfo();
MenuPrincipal();

    return 0;
}