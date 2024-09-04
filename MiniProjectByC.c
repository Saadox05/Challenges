#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char _Titre[100][40];
char _Auteur[100][30];
float _Prix[100];
int _Quantite[100];
int _livre_comp=0;
void MenuDeChoix();
void LivreInfo(char Titre[40],char Auteur[30],float Prix,int Quantite)
{
    printf("\nLivre Titre est %s:",Titre);
    printf("\nLivre Auteur est %s:",Auteur);
    printf("\nLivre Prix est %.2f:",Prix);
    printf("\nivre Quantite est %d:",Quantite);
}
void AjouterUnLivre()
{
    printf("Entrez le Titre du livre:");
    scanf("%s",&_Titre[_livre_comp]);
    printf("Entrez le Auteur du livre:");
    scanf("%s",&_Auteur[_livre_comp]);
    printf("Entrez le Prix du livre:");
    scanf("%f",&_Prix[_livre_comp]);
    printf("Entrez le Quantite du livre:");
    scanf("%d",&_Quantite[_livre_comp]);
    _livre_comp++;
}
void AfficherLesLivreDisponible()
{
    if(_livre_comp==0)
    {
        printf("\nil n'ya pas de livre disponible sur le stock\n");
        MenuDeChoix();
    }
    else{
        printf("Les livres Disponible sont:\n");
        for(int i=0;i<_livre_comp;i++)
        {
            printf("\nLivre %d:\n_______________________________\n",i+1);
            LivreInfo(_Titre[i],_Auteur[i],_Prix[i],_Quantite[i]);
            printf("\n_______________________________\n");
        };
    }
}

void  MettreJourQuantite()
{
    char LivreTitre1[40];
    printf("Entrez le Titre de livre que vous souhaitez mettre a jour:");
    scanf("%s",LivreTitre1);
    for(int i=0;i<_livre_comp;i++)
    {
        if(strcmp(LivreTitre1, _Titre[i])==0)
        {
            printf("Entrez le nouvelle Quantite:");
            scanf(" %d",&_Quantite[i]);
            MenuDeChoix();
        }
            
    }
    printf("\nle livre que vous recherchez n'est introuvable!\n");
    
}

void SupprimerUnLivre()
{
    char Empty[]="   ";
    char livretitre[40];
    printf("Entrez le Titre de livre que vous souhaitez supprimer:");
    scanf("%s",livretitre);
    for(int i=0;i<_livre_comp;i++)
    {
        if(strcmp(livretitre, _Titre[i]) == 0){
            strcpy(_Auteur[i]," ");
            strcpy(_Titre[i]," ");
            _Prix[i]=0;
            _Quantite[i]=0;
           
            printf("\nle livre supprime avec succes!\n");
            MenuDeChoix();
        }
           
    }
     printf("\nle livre que vous recherchez n'est introuvable!\n");
     MenuDeChoix();
}
void MenuDeChoix()
{
            short choix=0;
    while(choix!=6)
    {
        printf("\npour Ajouter un Livre au Stock cliquer sur 1");
        printf("\npour Afficher Tous les Livres Disponibles cliquer sur 2");
        printf("\npour Mettre a Jour la Quantite d'un Livre cliquer sur 3");
        printf("\npour Supprimer un Livre du Stock cliquer sur 4");
        printf("\npour Afficher le Nombre Total de Livres en Stock cliquer sur 5");
        printf("\npour Enregistrer les modifications et Sortir cliquer sur 6: ");
        scanf("%hi",&choix);
        switch(choix)
        {
           
            case 1:{AjouterUnLivre();MenuDeChoix();break;}
            case 2:{AfficherLesLivreDisponible();MenuDeChoix();break;}
            case 3:{MettreJourQuantite();MenuDeChoix();break;}
            case 4:{SupprimerUnLivre();break;}
            case 5:{printf("Total Livers en Stock est %d",_livre_comp);MenuDeChoix();break;}
             case 6:{printf("\nMerci pour votre Modifications\n");break;}
        }
    }
}
int main()
{
     printf("--Bienvenue a le Stock de Livres--\n\n");
    MenuDeChoix();
    return 0;
    
    }