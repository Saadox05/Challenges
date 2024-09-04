#include <stdio.h>
//Challenge 7 : Tableau en Ordre Croissant
int main()
{
    int TabValeurs[5];
     printf("\n\nEntrez les Valeurs de ces elements:\n");
    for(int i=0;i<5;i++)
    {
        printf("\nEntrez le Valeur pour element nombre %d : ",i+1);
        scanf("%d",&TabValeurs[i]);
    }
    int tempValeur=0;
    for(int i=0;i<4;i++)
    {
        
        for(int k=0;k<=4-1;k++){
        if(TabValeurs[k]>TabValeurs[k+1])
        {
            tempValeur=TabValeurs[k];
            TabValeurs[k]=TabValeurs[k+1];
            TabValeurs[k+1]=tempValeur;
        }
        }
    }
     printf("\n\nles Resultats de Tableaux en Ordre Croissant:");
        for(int i=0;i<5;i++)
        {
            printf("\nElement nombre %d = %d",i+1,TabValeurs[i]);
        }
    
    return 0;
}