#include <stdio.h>
//Resolution de Challenge 15 de Day 2 a Les Tableaux:Fusion de Deux Tableaux


void RemplirTableau(int T[],short T_length)
{
    for(short i=0;i<(T_length);i++)
    {
        printf("Entrez le Element nombre %hi: ",i+1);
        scanf("%d",&T[i]);
    }
    printf("Le Tableau a ete Remplir avec succes! ");
}

void FusionDeuxTableaux(int T1[],short T1_Length,int T2[],short T2_Length,int T3[])
{
    for(short i=0;i<T1_Length;i++)
    {
        T3[i]=T1[i];
    }
    short index=0;
    for(short i=T1_Length;i<T1_Length+T2_Length;i++)
    {
        T3[i]=T2[index++];
    }
    printf("\nTableaux 3 ete Remlpir avec succes!");
}
int main()
{
    short T1_Len=0;
    printf("\nEntrez le nombre d'elements de Tableau 1: ");
    scanf("%hi",&T1_Len);
    int T1[T1_Len];
   RemplirTableau(T1,T1_Len);
   int T2_Len=0;
   printf("\nEntrez le nombre d'elements de Tableau 2: ");
    scanf("%hi",&T2_Len);
    int T2[T2_Len];
    int T3[T1_Len+T2_Len];
    RemplirTableau(T2,T2_Len);
    FusionDeuxTableaux(T1,T1_Len,T2,T2_Len,T3);
    printf("Les Valeurs de Elements de Tableau 3 est: ");
    for(short i=0;i<T1_Len+T2_Len;i++)
    {
        printf("\nElement %hi Valuer est : %d",i+1,T3[i]);
    }
    return 0;
    
    }
