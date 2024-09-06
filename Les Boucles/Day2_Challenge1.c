#include <stdio.h>
//Resultion de Challenge 1 a Les Boucles:Table de Multiplication Inversée





int main()
{
    int N=0;
    printf("\nEntrer a nombre pour le table de multiplication: ");
    scanf("%d",&N);

    for(short i=10;i>0;i--)
    {
        printf("\n%d * %hi = %d",N,i,i*N);
    }



    return 0;
}