#include <stdio.h>
//Resolution de Challeng 9 des Tableaux: Inversion d'un Tableau
void InversionTableau(int T[],short T_length)
{
    short l=T_length;
    int temp=0;
    for(short i=0;i<(T_length/2);i++)
    {
        temp=T[i];
        T[i]=T[--l];
        T[l]=temp;
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
    int T1[10]={4,5,33,44,2,5,66,67,3,9};
    printf("\nElements du tableau que tu entre est:");
    AfficheTableau(T1,10);
    InversionTableau(T1,10);
    printf("\n\nElements du meme tableau apres Invrsion est:");
    AfficheTableau(T1,10);

    return 0;
    
    }