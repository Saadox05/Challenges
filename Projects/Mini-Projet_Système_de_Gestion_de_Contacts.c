#include <stdio.h>
#include <string.h>


struct stContact {
    char Nom[40];
    char Numero[20];
    char Email[40];
};

short Contact_Counter=0;
struct stContact Contact1[100];
void ContactsMenu();
struct stContact RemplirUnContact()
{
    struct stContact ContactInfo;
    printf("\nEnter le Nom : ");
    scanf(" %[^\n]s",&ContactInfo.Nom);
    printf("\nEnter le Numero du Telephone: ");
    scanf(" %[^\n]s",&ContactInfo.Numero);
    printf("\nEnter le Email : ");
    scanf(" %[^\n]s",&ContactInfo.Email);

    printf("\n\nContact Ajoute avec succes!\n");
    Contact_Counter++;
    return ContactInfo;
}

void AjouteUnContact(short ContactNombre)
{
    Contact1[ContactNombre]=RemplirUnContact();
    
    ContactsMenu();
}

void ModifierUnContact()
{
    char M_Nom[40];
    if(Contact_Counter==0)
    {
        printf("\nil n'y à pas de contact a Modifier\n");
        ContactsMenu();
    }
    printf("Entre le Nom du contact que vous souhaitez modifier: ");
    scanf(" %[^\n]s",&M_Nom);
    for(short i=0;i<Contact_Counter;i++)
    {
        if(strcmp(M_Nom,Contact1[i].Nom)==0)
        {
            printf("Entrez le nouveau Numero: ");
            scanf(" %[^\n]s",&Contact1[i].Numero);
             printf("Entrez le nouveau Email: ");
            scanf(" %[^\n]s",&Contact1[i].Email);
             printf("\nLe Contact Modifie avec succes!\n");
             ContactsMenu();
        }
        
        }
        printf("\nLe Contact non trouve!\n");
        ContactsMenu();

}
void ContactSwitch(struct stContact *Con1,struct stContact *Con2)
{
    struct stContact TempCon;
    strcpy(TempCon.Nom,Con1->Nom);
    strcpy(TempCon.Numero,Con1->Numero);
    strcpy(TempCon.Email,Con1->Email);
    strcpy(Con1->Nom,Con2->Nom);
    strcpy(Con1->Numero,Con2->Numero);
    strcpy(Con1->Email,Con2->Email);
    strcpy(Con2->Nom,TempCon.Nom);
    strcpy(Con2->Numero,TempCon.Numero);
    strcpy(Con2->Email,TempCon.Email);
}
void SupprimerUnContact()
{
    char S_Nom[40];
    if(Contact_Counter==0)
    {
        printf("\nil n'y à pas de contact a être supprimé\n");
        ContactsMenu();
    }
    printf("Entre le Nom du contact que vous souhaitez Supprimer: ");
    scanf(" %[^\n]s",&S_Nom);
    for(short i=0;i<Contact_Counter;i++)
    {
        if(strcmp(S_Nom,Contact1[i].Nom)==0)
        {
            strcpy(Contact1[i].Numero,"");
           strcpy(Contact1[i].Email,"");
           strcpy(Contact1[i].Nom,"");
             printf("\nLe Contact Supprime avec succes!\n");
             ContactSwitch(&Contact1[i],&Contact1[Contact_Counter-1]);
             Contact_Counter--;
            ContactsMenu();
        }
        
        }
        printf("\nLe Contact non trouve!\n");
        ContactsMenu();
}
void AfficherContacts()
{
    if(Contact_Counter==0)
    {
        printf("\nil n'y à pas de contacts à Afficher\n");
        ContactsMenu();
    }
    printf("\nLe nombre total de contacts est: %hi \n",Contact_Counter);
   
    for(short i=0;i<Contact_Counter;i++)
    {
        printf("\n\nContact %hi:",i+1);
        printf("\n__________________________");
        printf("\nNom      :%s",Contact1[i].Nom);
        printf("\nNumero   :%s",Contact1[i].Numero);
        printf("\nEmail    :%s",Contact1[i].Email);
        printf("\n__________________________");

    }
    ContactsMenu();
}
void RechercheUnContact()
{
     char R_Nom[40];
    if(Contact_Counter==0)
    {
        printf("\nil n'y à pas de contact a Rechercher\n");
        ContactsMenu();
    }
    printf("Entre le Nom du contact que vous souhaitez Rechercher: ");
    scanf(" %[^\n]s",&R_Nom);
    for(short i=0;i<Contact_Counter;i++)
    {
        if(strcmp(R_Nom,Contact1[i].Nom)==0)
        {
            printf("\n\nContact trouvé à Contact nombre %hi:",i+1);
        printf("\n__________________________");
        printf("\nNom      :%s",Contact1[i].Nom);
        printf("\nNumero   :%s",Contact1[i].Numero);
        printf("\nEmail    :%s",Contact1[i].Email);
        printf("\n__________________________");
            ContactsMenu();
        }
        
        }
        printf("\nLe Contact non trouve!\n");

}

void ContactsMenu()
{
    short choix=0;
    printf("\n---------Contacts Menu--------\n");
    printf("=>Pour Ajouter un Contact cliquer sur nombre 1\n");
    printf("=>Pour Modifier un Contact cliquer sur nombre 2\n");
    printf("=>Pour Supprimer un Contact cliquer sur nombre 3\n");
    printf("=>Pour Afficher Tous les Contacts cliquer sur nombre 4\n");
    printf("=>Pour Rechercher un Contact cliquer sur nombre 5\n");
    printf("=>Pour Exit le Menu cliquer sur nombre 6\n");
    printf("=>");
    scanf("%hi",&choix);
    while(choix<=0||choix>6)
    {
        printf("\nMauvais numero entrez un nombre compris entre 1 et 6: ");
        scanf("%hi",&choix);
    }
    switch(choix)
    {
        case 1:{AjouteUnContact(Contact_Counter);break;}
        case 2:{ModifierUnContact();break;}
        case 3:{SupprimerUnContact();break;}
        case 4:{AfficherContacts();break;}
        case 5:{RechercheUnContact();break;}
        case 6:{printf("\nQuitté\n\n");}

    }
    
}
int main()
{
    ContactsMenu();
    return 0;
}
