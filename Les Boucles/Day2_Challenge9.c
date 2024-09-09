#include <stdio.h>
//Resolution de Challenge 9 de Day2 a Les Boucles:Calcul de la Puissance    

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
int Puissance(int BaseNombre,short ExposantNombre)
{
    if(ExposantNombre==0){return 0;}
    int P=BaseNombre;
    while(ExposantNombre!=1)
    {
        P*=BaseNombre;
        ExposantNombre--;
    }
    return P;
    
}


int main()
{
    int BaseN,ExposantN;
    BaseN=ValidationEntree("Entrer le Nombre de Base : ");
    printf("Entrer le Exposant nombre: ");
    scanf("%d",&ExposantN);
    while(ExposantN<0)
    {
        printf("Entrée non valide Entrez un nombre egal ou supérieur à 0: ");
        scanf("%d",&ExposantN);
    }
    printf("La Puissance de %d^%d = %d",BaseN,ExposantN,Puissance(BaseN,ExposantN));


    return 0;
}