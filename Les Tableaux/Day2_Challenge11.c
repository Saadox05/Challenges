#include <stdio.h>
#include <string.h>
//Resolution de Challeng 11 a Les Tableaux:
void RemplirTableau(int T[],short T_length)
{
    for(short i=0;i<(T_length);i++)
    {
        printf("Entrez le Element nombre %hi: ",i+1);
        scanf("%d",&T[i]);
    }
    printf("Le Tableau a ete Remplir avec succes! ");
}

short RechercherUnElement(int Tableau[],short T_Len,int ChercheUnElement)
{
    
    for(int i=0;i<T_Len;i++)
    {
        if(Tableau[i]==ChercheUnElement)
        {
                printf("\nElement trouvé dans l'index nombre %d",i);
                return i;
                
        }
    }
    printf("\nElement non trouvé");
    return -1;
}  
void RemplacerUnValeur(int *Valeur,int NouvelleValeur)
{
    *Valeur=NouvelleValeur;
}
void RemplacerUnElement(int Tableau[],short T_Len,int ChercheUnElement)
{
    int N_Valeur;
    printf("\nPour Remplacer un Element:");
    short trouve=RechercherUnElement(Tableau,T_Len,ChercheUnElement);
    if(trouve==-1)
    {
        return;
    }else{
        printf("\nEntre la nouvelle Valeur: ");
        scanf("%d",&N_Valeur);
        RemplacerUnValeur(&Tableau[trouve],N_Valeur);
        printf("\nle Valeur d'Element ete Remplacer avec succes");
    }
}
void AfficheTableau(int T[],short TableauLength)
{
    for(short i=0;i<TableauLength;i++)
    {
        printf("\nElement %hi= %d",i+1,T[i]);
    }
}
int main()
{
    short T_Len=0;
    printf("\nEntrez le nombre d'elements: ");
    scanf("%hi",&T_Len);
    int T1[T_Len];
    
    int C=0;
   RemplirTableau(T1,T_Len);
   printf("\nEntre l'element que vous souhaitez rechercher: ");
   scanf("%d",&C);
    RemplacerUnElement(T1,T_Len,C);
    AfficheTableau(T1,T_Len);

    return 0;
    
    }