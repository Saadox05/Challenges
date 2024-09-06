#include <stdio.h>
//Resolution de Challenge 14 de Day 2 a Les Tableaux:Calculer la Moyenne


void RemplirTableau(int T[],short T_length)
{
    for(short i=0;i<(T_length);i++)
    {
        printf("Entrez le Element nombre %hi: ",i+1);
        scanf("%d",&T[i]);
    }
    printf("Le Tableau a ete Remplir avec succes! ");
}

void CalculerLaMoyenne(int T[],short TableauLength)
{
    int M=0;
    printf("\nLe Moyenne des Elements est:");
    for(short i=0;i<TableauLength;i++)
    {
        M+=T[i];
    }
    printf("%d",M/TableauLength);
}
int main()
{
    short T_Len=0;
    printf("\nEntrez le nombre d'elements: ");
    scanf("%hi",&T_Len);
    int T1[T_Len];
    
    int C=0;
   RemplirTableau(T1,T_Len);
    CalculerLaMoyenne(T1,T_Len);

    return 0;
    
    }
