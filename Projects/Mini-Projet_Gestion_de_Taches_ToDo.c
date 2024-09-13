#include <stdio.h>
#include <time.h>
#include <string.h>
//Mini Project a Gestion de Taches:ToDo List
#define Max_Titre_char 100
#define Max_Description_char 200
#define Max_Taches 200

struct date{
    short Jour;
    short Moi;
    int Anne;
    short Minutes;
    short Heure;

};
enum enStatut{
    aRealiser=1,EnCoursDeRealisation,Finalisee

};
struct Tache{
    char T_Titre[Max_Titre_char];
    char T_Description[Max_Description_char];
    enum enStatut statut;
    short id;
    struct date deadline;
    struct date HeureDeDebut;

};
enum Affichage
    {
        Simple=1,Ascending=2,Descending=3

    };







int main()
{   
    time_t now= time(0);
    struct tm *local_time=localtime(&now);
    struct Tache Tache1[100];
    short choix=0;
    short DesTache_Nombre=0;
    do{
printf("\n----------------------------Menu--------------------------");
printf("\nPour Ajouter une nouvelle tache cliquer sur 1");
printf("\nPour Afficher la liste de toutes les taches cliquer sur 2");
printf("\nPour Modifier une tache cliquer sur 3");
printf("\nPour Supprimer une tache cliquer sur 4");
printf("\nPour Rechercher une tache cliquer sur 5");
printf("\nPour Afficher Statistiques cliquer sur 6");
printf("\nPour Exit cliquer sur 0");
printf("\n----------------------------------------------------------\n =>:");
scanf("%hi",&choix);
while(choix<1||choix>6)
{
    printf("Entrer votre choix de 1 a 6: ");
    scanf("%hi",&choix);
}
   switch(choix)
{
    case 0:printf("\nMenu fermé!");break;
     case 1: 
     {short c=0;short n_tachesPourAjoute=1;
      printf("\nPour Ajouter une nouvelle tache cliquer sur 1");
        printf("\nPour Ajouter plusieurs nouvelles taches cliquer sur 2");
        printf("\nPour Quiter et retourner a la menu cliquer sur 3\n=>:");
        scanf("%hi",&c);
        
        while(c<1||c>3)
        {
             printf("\nInvalid choix re entrer 1 ou 3: ");
            scanf("%hi",&c);
        }
        if(c==3)break;
        
        if(c==2){
            
            printf("Entrer le nombre de Taches que vous souhaitez ajouter : ");
            scanf("%hi",&n_tachesPourAjoute);
            while(n_tachesPourAjoute<1)
            {
                printf("Entrer un nombre de Taches eqal ou superieur a 1: ");
                    scanf("%hi",&n_tachesPourAjoute);
            }
            
            
            
        }
        
        do{
            for(int i=0;i<n_tachesPourAjoute;i++){
        printf("\n___________________Ajouter une Tache___________________");
        printf("\nEntrer le titre de Tache: ");
            scanf(" %[^\n]s,",Tache1[DesTache_Nombre].T_Titre);
            for(short i=0;i<DesTache_Nombre;i++)
            {
                if(strcmp(Tache1[DesTache_Nombre].T_Titre,Tache1[i].T_Titre)==0)
                {
                    do{printf("Ce titre de tache existe deja choisir un autre titre : ");
                        scanf("%s",Tache1[DesTache_Nombre].T_Titre);
                    }while(Tache1[DesTache_Nombre].T_Titre==Tache1[i].T_Titre);
                    break;
                }
            }
            printf("\nEntrer une Description: ");
            scanf(" %[^\n]s",Tache1[DesTache_Nombre].T_Description);
            Tache1[DesTache_Nombre].statut= 1;
            Tache1[DesTache_Nombre].id=DesTache_Nombre+1;

            Tache1[DesTache_Nombre].HeureDeDebut.Jour=local_time->tm_mday;
            Tache1[DesTache_Nombre].HeureDeDebut.Moi=local_time->tm_mon;
            Tache1[DesTache_Nombre].HeureDeDebut.Anne=local_time->tm_year;
            Tache1[DesTache_Nombre].HeureDeDebut.Heure=local_time->tm_hour;
            Tache1[DesTache_Nombre].HeureDeDebut.Minutes=local_time->tm_min;
            printf("\nEntrer un deadline:\n entrer Anne : ");
            scanf("%d",&Tache1[DesTache_Nombre].deadline.Anne);
            while(Tache1[DesTache_Nombre].deadline.Anne<(local_time->tm_year+1900))
            {
                    printf("Votre entrée pour l année doit "); printf("être >=%d : ",local_time->tm_year+1900);
                    scanf("%d",&Tache1[DesTache_Nombre].deadline.Anne);
            };
            printf("\nEntrer Moi:");
            scanf("%hi",&Tache1[DesTache_Nombre].deadline.Moi);
            while(Tache1[DesTache_Nombre].deadline.Moi<local_time->tm_mon||Tache1[DesTache_Nombre].deadline.Moi>12)
            {
                    printf("Le mois de l année doit être compris entre %d et 12 : ",local_time->tm_mon);
                    scanf("%d",&Tache1[DesTache_Nombre].deadline.Moi);
            }
    
            printf("\nEntrer Jour:");
            scanf("%hi",&Tache1[DesTache_Nombre].deadline.Jour);
            short moi_j=0;
           
            switch(Tache1[DesTache_Nombre].deadline.Moi)
            {
                case 1:{
                    
                     moi_j=31;
                }
                case 2:{
                    if(Tache1[DesTache_Nombre].deadline.Anne%4==0||(Tache1[DesTache_Nombre].deadline.Anne%100!=0&&Tache1[DesTache_Nombre].deadline.Anne%400==0)&&(Tache1[DesTache_Nombre].deadline.Moi==2))
            {
                moi_j=29;break;
            }else{
                moi_j=28;break;
            }
                }
                case 3:{
                    moi_j=31;break;
                }
                case 4:{
                    moi_j=30;break;
                }
                case 5:{
                    moi_j=31;break;
                }
                case 6:{
                    moi_j=30;break;
                }
                case 7:{
                    moi_j=31;break;
                }
                case 8:{
                    moi_j=31;break;
                }
                case 9:{moi_j=30;break;}
                case 10:{moi_j=31;break;}
                case 11:{moi_j=30;break;}
                case 12:{moi_j=31;break;}
                }
            while(Tache1[DesTache_Nombre].deadline.Jour<local_time->tm_mday||Tache1[DesTache_Nombre].deadline.Jour>moi_j)
            {
                    printf("Le jour de moi doit être compris entre %d et %d",local_time->tm_mday,moi_j);
                    scanf("%d",&Tache1[DesTache_Nombre].deadline.Moi);
            }
            printf("\nTache ajoutee avec succes!");
            printf("\n___________________________________________________");
            DesTache_Nombre++;
            }
            if(c==1)break;
            printf("voulez-vous ajouter un autre tache? oui=1/non=2:");
            scanf("%hi",&c);
            while(c<1||c>2)
        {
             printf("\nInvalid choix re entrer 1 ou 2: ");
            scanf("%hi",&c);
        }
            
            

     }while(c!=3||c!=1);break;
     



     }
    
case 2:{
    printf("\nLa list des taches: ");
    printf("\n_____________________________________");
    if(DesTache_Nombre==0)
    {
        printf("\nil n'y a pas de taches actuellement");
         printf("\n\n_____________________________________");break;

    }
    for(short i=0;i<DesTache_Nombre;i++)
    {
        printf("\nTitre de Tache: %s",Tache1[i].T_Titre);
        printf("\nIdentifiant de Tache: %hi",Tache1[i].id);
        printf("\nDesciption de Tache: %s",Tache1[i].T_Description);
        printf("\nStatut de Tache: ");
        if(Tache1[i].statut==aRealiser)
        {
            printf("a Realiser");
        }else{printf("Finalisee");}
        printf("\nHeure de Debut: %hi/%hi/%d a %2.hi:%2.hi",Tache1[i].HeureDeDebut.Jour,Tache1[i].HeureDeDebut.Moi,Tache1[i].HeureDeDebut.Anne,
        Tache1[i].HeureDeDebut.Heure,Tache1[i].HeureDeDebut.Minutes);
        printf("\nDeadline de Tache: %hi/%hi/%d",Tache1[i].deadline.Jour,Tache1[i].deadline.Moi,Tache1[i].deadline.Anne);
        printf("\n\n_____________________________________");

}
break;


}

case 3:{
    printf("\n________________Modification________________");
    if(DesTache_Nombre==0)
{
    printf("\nil n'y a pas de tâche a modifier!");break;
}
    nouveau:
    short C=0;
    
    printf("\nModfier par:\n-Titre 1 \n-ID 2\n-Retour au Menu 3 : ");
    scanf("%hi",C);
    switch(C)
    {
        case 1:{char t[Max_Titre_char];
        
        printf("\nEntrer le Titre de Tache: ");
        scanf("%s",t);
        for(short i=0;i<DesTache_Nombre;i++)
        {
            if(Tache1[i].T_Titre==t)
            {
                printf("\nEntrer la nouvelle Description: ");
                scanf("%s",Tache1[i].T_Description);
                printf("\nEntrer la nouvelle Statut:\n-a Realiser 1 \n-en cours de Realisation 2\n-Finalisee 3 : ");
                scanf("%d",(enum enStatut)Tache1[i].statut);
                printf("\nEntrer la nouvelle Deadline: ");
                printf("\nEntrer Deadline Jour: ");
                scanf("%hi",Tache1[i].deadline.Jour);
                printf("\nEntrer Deadline Moi: ");
                scanf("%hi",Tache1[i].deadline.Moi);
                printf("\nEntrer Deadline Anne: ");
                scanf("%d",Tache1[i].deadline.Anne);
                printf("\nLa tache a ete modifiee avec succes ");
                printf("vous souhaitez modifier une autre tâche ? Oui=1 au Non=2");
                scanf("%hi",C);
                while(C<1||C>2){
                 printf("\nInvalid choix re entrer 1 ou 2: ");
                 scanf("%hi",&C);
                }
                if(C==1)
                {
                        goto nouveau;
                      }

                break;


            }
        }

        printf("\nLa Tache n'a pas ete trouvee!");
        printf("\nrechercher à nouveau pour Modifier ? cliquez sur 1");
        printf("\nretournez au menu cliquez sur 2 ");
        scanf("%hi",&C);
        while(C<1||C>2){
            printf("\nInvalid choix re entrer 1 ou 2: ");
            scanf("%hi",&C);
        }
        if(C==1)
        {
            goto nouveau;
        }
        break;
        }
        case 2:{
            printf("\nEntrer le ID de Tache: ");
            short ID=0;
        scanf("%hi",&ID);
        for(short i=0;i<DesTache_Nombre;i++)
        {
            if(Tache1[i].id==ID)
            {
                printf("\nEntrer la nouvelle Description: ");
                scanf("%s",Tache1[i].T_Description);
                printf("\nEntrer la nouvelle Statut:\n-a Realiser 1 \n-en cours de Realisation 2\n-Finalisee 3 : ");
                scanf("%d",(enum enStatut)Tache1[i].statut);
                printf("\nEntrer la nouvelle Deadline: ");
                printf("\nEntrer Deadline Jour: ");
                scanf("%hi",Tache1[i].deadline.Jour);
                printf("\nEntrer Deadline Moi: ");
                scanf("%hi",Tache1[i].deadline.Moi);
                printf("\nEntrer Deadline Anne: ");
                scanf("%d",Tache1[i].deadline.Anne);
                printf("\nLa tache a ete modifiee avec succes ");
                printf("vous souhaitez modifier une autre tâche ? Oui=1 au Non=2");
                scanf("%hi",C);
                while(C<1||C>2){
                 printf("\nInvalid choix re entrer 1 ou 2: ");
                 scanf("%hi",&C);
                }
                if(C==1)
                {
                        goto nouveau;
                      }

                break;


            }
        }

        printf("\nLa Tache n'a pas ete trouvee!");
        printf("\nrechercher à nouveau pour Modifier ? cliquez sur 1");
        printf("\nretournez au menu cliquez sur 2 ");
        scanf("%hi",&C);
        while(C<1||C>2){
            printf("\nInvalid choix re entrer 1 ou 2: ");
            scanf("%hi",&C);
        }
        if(C==1)
        {
            goto nouveau;
        }
        break;
        

        }


    }



}
case 4:{
    printf("\n________________________Supprimer________________________");
    nouveau2:
    printf("Entrer le ID pour supprimer une Tache: ");
    short ID=0,C=0;
    scanf("%hi",ID);
    for(short i=0;i<DesTache_Nombre;i++)
        {
    if(Tache1[i].id==ID)
            {   printf("\ntâche trouvée êtes-vous sûr de vouloir la supprimer ? Oui=1,Non=2");
                scanf("%d",C);
                while(C<1||C>2){
            printf("\nInvalid choix re entrer 1 ou 2: ");
            scanf("%hi",&C);
                     }
                    if(C==1)
                 {  strcpy(Tache1[i].T_Titre,"");
                    strcpy(Tache1[i].T_Description,"");
                    Tache1[i].deadline.Anne=0;
                    Tache1[i].deadline.Jour=0;
                    Tache1[i].deadline.Moi=0;
                    Tache1[i].HeureDeDebut.Anne=0;
                    Tache1[i].HeureDeDebut.Moi=0;
                    Tache1[i].HeureDeDebut.Jour=0;
                    Tache1[i].HeureDeDebut.Heure=0;
                    Tache1[i].HeureDeDebut.Minutes=0;
                    Tache1[i].statut=Finalisee;
                    printf("\nTache ID nombre : %hi supprimée avec succès ",Tache1[i].id);
                    printf("\nVous souhaitez supprimer une autre tâche ? Oui=1 Non=2 :");
                    scanf("%hi",&C);
                        while(C<1||C>2){
                 printf("\nInvalid choix re entrer 1 ou 2: ");
                 scanf("%hi",&C);
                }
                if(C==1)
                {
                        goto nouveau2;
                      }

                break;
            
                                 }
        break;


            }
            printf("\nLa Tache n'a pas ete trouvee!");
        printf("\nrechercher à nouveau pour suprimier ? cliquez sur 1");
        printf("\nretournez au menu cliquez sur 2 ");
        scanf("%hi",&C);
        while(C<1||C>2){
            printf("\nInvalid choix re entrer 1 ou 2: ");
            scanf("%hi",&C);
        }
        if(C==1)
        {
            goto nouveau2;
        }
        break;


        }

}
case 5:{printf("\n________________________Rechercher________________________");
    nouveau3:
    short C=0,ID=0;
    printf("\nRechercher une Tache:");
    printf("-\npar Tache ID cliquer sur 1");
    printf("\n-par Tache Titre cliquer sur 2");
    printf("Routeur a la Menu cliquer sur 3");
    while(C<1||C>3){
            printf("\nInvalid choix re entrer 1 ou 3: ");
            scanf("%hi",&C);
        }
    switch(C)
    {
        case 1:{
        printf("\n____vous avez choisi de rechercher par identifiant___");
        printf("Entrer le ID pour Rechercher une Tache: ");
        scanf("%hi",&ID);
        for(short i=0;i<DesTache_Nombre;i++)
        {
            if(Tache1[i].id==ID)
            {   printf("\nTache trouvee avec succes:");
            printf("\n______________________________________________");
                printf("\nTache titre : %s",Tache1[i].T_Titre);
                printf("\nTache ID : %hi",Tache1[i].id);
                printf("\nTache Description : %s",Tache1[i].T_Description);
                printf("\nHeure de Debut de Tache: %hi/%hi/%d a %2.hi:%2.hi",Tache1[i].HeureDeDebut.Jour,Tache1[i].HeureDeDebut.Moi,Tache1[i].HeureDeDebut.Anne,Tache1[i].HeureDeDebut.Heure,Tache1[i].HeureDeDebut.Minutes);
                printf("\nTache Deadline: %hi/%hi/%d",Tache1[i].deadline.Jour,Tache1[i].deadline.Moi,Tache1[i].deadline.Anne);
                printf("\nTach Statut: ");
                switch(Tache1[i].statut)
                {
                    case aRealiser:printf("\nTache a Realisir");break;
                    case EnCoursDeRealisation:printf("\nTache en cours de realisation");break;
                    case Finalisee:printf("\nTache Finalisee");break;
                }
                printf("\n______________________________________________");
                printf("\nrechercher à nouveau ? cliquez sur 1");
        printf("\nretournez au menu cliquez sur 2 ");
        scanf("%hi",&C);
        while(C<1||C>2){
            printf("\nInvalid choix re entrer 1 ou 2: ");
            scanf("%hi",&C);
        }
        if(C==1)
        {
            goto nouveau3;
        }
                break;

            }
            

        }
        printf("\nLa Tache n'a pas ete trouvee!");
            printf("\nrechercher à nouveau ? cliquez sur 1");
        printf("\nretournez au menu cliquez sur 2 ");
        scanf("%hi",&C);
        while(C<1||C>2){
            printf("\nInvalid choix re entrer 1 ou 2: ");
            scanf("%hi",&C);
        }
        if(C==1)
        {
            goto nouveau3;
        }
        break;
        }

        case 2:{ 
            
         printf("\n____vous avez choisi de rechercher par Titre___");
        printf("Entrer le Titre pour Rechercher une Tache: ");
        char titre2[Max_Titre_char];
        scanf(" %[^\n]s",titre2);
        for(short i=0;i<DesTache_Nombre;i++)
        {
            if(strcmp(Tache1[i].T_Titre,titre2)==0)
            {   printf("\nTache trouvee avec succes:");
            printf("\n______________________________________________");
                printf("\nTache titre : %s",Tache1[i].T_Titre);
                printf("\nTache ID : %hi",Tache1[i].id);
                printf("\nTache Description : %s",Tache1[i].T_Description);
                printf("\nHeure de Debut de Tache: %hi/%hi/%d a %2.hi:%2.hi",Tache1[i].HeureDeDebut.Jour,Tache1[i].HeureDeDebut.Moi,Tache1[i].HeureDeDebut.Anne,Tache1[i].HeureDeDebut.Heure,Tache1[i].HeureDeDebut.Minutes);
                printf("\nTache Deadline: %hi/%hi/%d",Tache1[i].deadline.Jour,Tache1[i].deadline.Moi,Tache1[i].deadline.Anne);
                printf("\nTach Statut: ");
                switch(Tache1[i].statut)
                {
                    case aRealiser:printf("\nTache a Realisir");break;
                    case EnCoursDeRealisation:printf("\nTache en cours de realisation");break;
                    case Finalisee:printf("\nTache Finalisee");break;
                }
                printf("\n______________________________________________");
                 printf("\nrechercher à nouveau ? cliquez sur 1");
        printf("\nretournez au menu cliquez sur 2 ");
        scanf("%hi",&C);
        while(C<1||C>2){
            printf("\nInvalid choix re entrer 1 ou 2: ");
            scanf("%hi",&C);
        }
        if(C==1)
        {
            goto nouveau3;
        }
                break;

            }
            




        }
        printf("\nLa Tache n'a pas ete trouvee!");
            printf("\nrechercher à nouveau ? cliquez sur 1");
        printf("\nretournez au menu cliquez sur 2 ");
        scanf("%hi",&C);
        while(C<1||C>2){
            printf("\nInvalid choix re entrer 1 ou 2: ");
            scanf("%hi",&C);
        }
        if(C==1)
        {
            goto nouveau3;
        }
        break;
        }
        case 3:{
            break;

        }
    }


}



case 6:{





    }










    

   
   
   
   
   
    }}while(choix!=0);



    return 0;
    }