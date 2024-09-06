#include <stdio.h>
//Resolution de Challenge 2 a les Boucles Day2:pyramide d'étoile





int main()
{
    short N_linge=0;
    printf("Entrer le nombre de les lignes pour le Pyramide: ");
    scanf("%hi",&N_linge);
int e=1;

int space=30;
    for(int i=0;i<N_linge;i++)
    {
        
        
            for(int j=1;j<space;j++)
            {
                printf(" ");
            }
            for(int k=0;k<e;k++)
            {
                printf("*");
            }
            
        do{
            e++;
        }while(e%2==0);
            space--;
            
            printf("\n");
        
        
    }




    return 0;
}