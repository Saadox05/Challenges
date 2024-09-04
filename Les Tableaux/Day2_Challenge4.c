#include <stdio.h>
//Challenge 4;
int main()
{
    short nombre;
    
    printf("Entrez le nombre d'elements pour le tableau: ");
    scanf("%hi",&nombre);
    int TabValeurs[nombre];
     printf("\n\nEntrez les Valeurs de ces elements:\n");
    for(short i=0;i<nombre;i++)
    {
        printf("\nEntrez le Valeur pour element nombre %hi : ",i+1);
        scanf("%d",&TabValeurs[i]);
    }
    int Max=0;
    for(int i=0;i<nombre;i++)
    {
        if(TabValeurs[i]>Max)
        {
        Max=TabValeurs[i];
            
        }
    }
     printf("\n\nle Maximum Element est = %d",Max);
    
    return 0;
}