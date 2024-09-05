#include <stdio.h>
//Resolution de Challenge 8 des Tableaux:


void  CopieTableau(int sourceT[],int Tcopie[],short sourceT_Length)
{
    for(short i=0;i<sourceT_Length;i++)
    {
        Tcopie[i]=sourceT[i];
    }
    printf("\nTableu Copie avec succes!\n");
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
    int T1[10]={4,5,33,44,2,5,66,67,3,9};
    int Tc1[10];
    CopieTableau(T1,Tc1,10);
    printf("\nTableau 1 elements est:");
    AfficheTableau(T1,10);
    printf("\n\nTableau 2 elements est:");
    AfficheTableau(Tc1,10);

    return 0;
    
    }