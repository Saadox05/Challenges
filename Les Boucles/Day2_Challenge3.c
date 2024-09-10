#include <stdio.h>
//Resolution de Challenge 3 de Day2 a Les Boucles: Affichage des Nombres Premiers
int LireUnNombre()
{
    int n=0;
    printf("Entrer a nombre de votre choix pour l'Affichage des Nombre Premiers de 1 a votre nombre: ");
    scanf("%d",&n);
    return n;
}
void AffichageDesNombrePremiers(int Nombre)
{
    
    for(int i=2;i<Nombre;i++)
    {
        short Premier=1;
        
        for(int j=2;j<=(i/2);j++)
        {
            if(i%j==0){
                Premier=0;
            }
            
        }
        if(Premier==1){printf("%hi ",i);}
    }


}

int main(){




int n=LireUnNombre();
AffichageDesNombrePremiers(n);




    return 0;
}