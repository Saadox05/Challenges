#include <stdio.h>
//Resolution de Challenge 6 de Day2 a Les Boucles: Facteurs d'un Nombre

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
void NombreFacteurs(int Entier)
{
    int n=1;
    while(n<=Entier)
    {   
        if(n==Entier)
        {
            printf("%d.",n);break;
        }
        if(Entier%n==0)
        {
            printf("%d, ",n);
        }
        n++;

    }
}


int main()
{

    int Nombre=ValidationEntree("Entre a nombre : ");
    printf("\nLes facteurs de %d est: ",Nombre);
    NombreFacteurs(Nombre);


    return 0;
}