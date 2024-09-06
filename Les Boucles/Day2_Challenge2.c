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
        if(e%2!=0)
        {
            for(int i=1;i<space;i++)
            {
                printf(" ");
            }
            for(int i=0;i<e;i++)
            {
                printf("*");
            }
            space--;
            printf("\n");
        }
        e++;
    }




    return 0;
}