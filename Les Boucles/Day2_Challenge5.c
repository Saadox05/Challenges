#include <stdio.h>
//Resolution de Challenge 5 de Day2 a Les Boucles:Somme des N Nombres

int ValidationEntree(char Message[100])
{

    int n=0;
    printf("%s",Message);
    scanf("%d",&n);
    while(n<=0)
    {
        printf("Entrée non valide Entrez un nombre supérieur à 0: ");
        scanf("%d",&n);
    }

    return n;
}
void Somme(int Entier)
{
    int n=1,somme=0;
    while(n<=Entier)
    {   
        somme+=n;
        if(n==Entier)
        {
            printf("%d = %d",n,somme);break;
        }
        printf("%d + ",n);
        n++;

    }
}


int main()
{

    int Nombre=ValidationEntree("Entre a nombre : ");
    printf("\nSomme des nombre de 1 à %d : ",Nombre);
    Somme(Nombre);


    return 0;
}