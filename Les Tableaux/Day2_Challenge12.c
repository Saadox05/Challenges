#include <stdio.h>
//Resolution de Challenge 12 de Day 2 a Les Tableaux:




void RemplirTableau(int T[],short T_length)
{
    for(short i=0;i<(T_length);i++)
    {
        printf("Entrez le Element nombre %hi: ",i+1);
        scanf("%d",&T[i]);
    }
    printf("Le Tableau a ete Remplir avec succes! ");
}

void AfficherElementPaire(int T[],short TableauLength)
{
    printf("\nLes Paire Elements est:");
    for(short i=0;i<TableauLength;i++)
    {
        if(T[i]%2==0){
        printf("\nElement %hi= %d",i+1,T[i]);
        }
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
    AfficherElementPaire(T1,T_Len);

    return 0;
    
    }
