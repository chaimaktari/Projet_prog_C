#include <stdio.h>
#include <string.h>
#include"function.h"

int main()
{
    reclamation L1={1,2,3,4,"observateur",1,2,3};
    reclamation L2={4,3,2,1,"reclamation",3,2,1};
    reclamation L3;
    int x ;

  /* x=ajouter("reclama.txt",L1);

    if(x==1)
        printf("\najout de point avec succes");
    else printf("\nechec ajout"); */


 /*  x=modifierreclamation("reclama.txt",2,L2);
    if(x==1)
        {
            printf("\nModification de point avec succés");
        }
    else if(x!=1){
            printf("\nechec Modification");
    }  */

      x=supprimer("reclama.txt",3 );
    if(x==1)
        printf("\nSuppression de point avec succes");
    else printf("\nechec Suppression"); 
   
  /* L3=chercher("reclama.txt",2);
    if(L3.idobse==-1)
        {
            printf("\nintrouvable");
        }
        else if (L3.idobse!=-1)
        {
        printf("\nreclamation trouver");
        }*/

    return 0;
}

