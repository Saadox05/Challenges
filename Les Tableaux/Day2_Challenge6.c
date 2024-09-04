#include <stdio.h>
//Challenge 6 : Multiplication des Éléments;
int main()
{
    int nombre;
    int F;//facteur
    printf("Entrez le nombre d'elements pour le tableau: ");
    scanf("%d",&nombre);
    int TabValeurs[nombre];
     printf("\n\nEntrez les Valeurs de ces elements:\n");
    for(int i=0;i<nombre;i++)
    {
        printf("\nEntrez le Valeur pour element nombre %d : ",i+1);
        scanf("%d",&TabValeurs[i]);
    }
    printf("\nEntrez le Facteur de multiplication: ");
        scanf("%d",&F);
    for(int i=0;i<nombre;i++)
    {
        TabValeurs[i]*=F;
            
        }
     printf("\n\nles Resultats apres  Multiplication:");
        for(int i=0;i<nombre;i++)
        {
            printf("\nElement nombre %d = %d",i+1,TabValeurs[i]);
        }
    
    return 0;
}