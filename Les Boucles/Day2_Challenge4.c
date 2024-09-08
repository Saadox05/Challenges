#include <stdio.h>
//Resolution de Challenge 4 de Day2 a Les Boucles:Inversion d'un Entier


void InversionEntier(int Entier)
{
    int Inversion=0;
    while(Entier!=0)
    {
        short reste=0;
        reste=Entier%10;
        Inversion=(Inversion*10)+reste;
        Entier/=10;
    }


    printf("%d",Inversion);
}


int main()
{

    int Nombre=0;
    printf("Entrer une Nombre pour inverser: ");
    scanf("%d",&Nombre);
    printf("\nle nombre inverse est: ");
    InversionEntier(Nombre);


    return 0;
}