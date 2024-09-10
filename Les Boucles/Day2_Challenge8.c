#include <stdio.h>
//Resolution de Challenge 8 de Day2 a Les Boucles:Recherche Dichotomique

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
void RechercheDichotomique(int T[],short T_len,int Nombre)
{
    if(T[T_len/2]==Nombre){
        printf("\nLe nombre il se trouve a l'index %hi",T_len/2);
        return ;
    }
    if(T[T_len/2]>Nombre)
    {
        for(short i=T_len/2-1;i>=0;i--)
        {
            if(T[i]==Nombre){
        printf("\nLe nombre il se trouve a l'index %hi",i);
        return ;
        }}
        printf("\nLe nombre il pas trouve dans le tableau");
        return;}else{
        for(short i=T_len/2+1;i<T_len;i++)
        {
            if(T[i]==Nombre){
        printf("\nLe nombre il se trouve a l'index %hi",i);
        return ;    }   }
     printf("\nLe nombre il pas trouve dans le tableau");
        return;
    }

}


int main()
{
    int Entiers[]={2, 5, 8, 12, 16, 23, 38, 56, 72, 91,100,120,150,155,170};
    int Nombre=ValidationEntree("Entre a nombre : ");
    RechercheDichotomique(Entiers,15,Nombre);


    return 0;
}