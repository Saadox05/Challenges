#include <stdio.h>
//Resolution de Challenge 7 de Day2 a Les Boucles:Suite de Fibonacci

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
void FibonacciSuite(int N_Termes)
{
    int f0=0,f1=1,f=0;      
    for(int i=0;i<N_Termes;i++)
    {
        printf("%d",f0);
        f=f0+f1;
        f0=f1;
        f1=f;


    }
}


int main()
{

    int Nombre=ValidationEntree("Entre nombre de terms pour Fibonacci Suite : ");
    printf("\n %d termes de la suite de Fibonacci est: ",Nombre);
    FibonacciSuite(Nombre);


    return 0;
}