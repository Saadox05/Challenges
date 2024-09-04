#include <stdio.h>
//Challenge 3;
int main()
{
    short nombre;
    int TableauSum=0;
    printf("Entrez le nombre d'elements pour le tableau: ");
    scanf("%hi",&nombre);
    int TabValeurs[nombre];
     printf("^\n\nEntrez les Valeurs de ces elements:\n");
    for(short i=0;i<nombre;i++)
    {
        printf("^\nEntrez le Valeur pour element nombre %hi : ",i+1);
        scanf("%hi",&TabValeurs[i]);
    }
    for(int i=0;i<nombre;i++)
    {
        TableauSum+=TabValeurs[i];
    }
     printf("^\n\nla somme totale de l'elements est = %hi",TableauSum);
    
    return 0;
}