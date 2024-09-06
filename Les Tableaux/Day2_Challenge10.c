#include <stdio.h>
#include <string.h>
//Resolution de Challeng 10 a Les Tableaux:
void RemplirTableau(int T[],short T_length)
{
    for(short i=0;i<(T_length);i++)
    {
        printf("Entrez le Element nombre %hi: ",i+1);
        scanf("%d",&T[i]);
    }
    printf("Le Tableau a ete Remplir avec succes! ");
}
void RechercheUnElement(int Tableau[],short T_Len,int ChercheUnElement)
{
    short trouve=0;
    for(int i=0;i<T_Len;i++)
    {
        if(Tableau[i]==ChercheUnElement)
        {
                printf("\nElement trouvé dans l'index nombre %d",i+1);
                trouve=1;
        }
    }
    if(!trouve){printf("\nElement non trouvé");}
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
    printf("Entrez le nombre d'elements: ");
    scanf("%hi",&T_Len);
    int T1[T_Len];
    
    int C=0;
   RemplirTableau(T1,T_Len);
   printf("\nEntre l'element que vous souhaitez rechercher: ");
   scanf("%d",&C);
    RechercheUnElement(T1,T_Len,C);
    

    return 0;
    
    }