#include <stdio.h>
//Challenge 2;
int main()
{
    short nombre;
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
        printf("^\n\nla valeur de l'element numéro %hi est = %hi",i+1,TabValeurs[i]);
    }
    
    
    return 0;
}