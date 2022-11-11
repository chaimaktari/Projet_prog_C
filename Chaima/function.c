#include "function.h"
#include <stdio.h>
#include <string.h>

int ajouter(char * filename, reclamation P )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %s %d %d %d \n",P.idrecla,P.idobse,P.idbv,P.idliste,P.text,P.d.jour,P.d.mois,P.d.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifierreclamation( char * filename, int idobse, reclamation nouvL )
{
    int tr;
    reclamation P;
    FILE * f=fopen(filename,"r");
    FILE * f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %d %d %d \n",&P.idrecla,&P.idobse,&P.idbv,&P.idliste,&P.text,&P.d.jour,&P.d.mois,&P.d.annee)!=EOF)
        {
            if(P.idobse== idobse)
            {
                fprintf(f2,"%d %d %d %d %s %d %d %d \n",nouvL.idrecla,nouvL.idobse,nouvL.idbv,nouvL.idliste,nouvL.text,nouvL.d.jour,nouvL.d.mois,nouvL.d.annee);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %s %d %d %d \n",P.idrecla,P.idobse,P.idbv,P.idliste,P.text,P.d.jour,P.d.mois,P.d.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int idobse)
{
    int tr=0;
    reclamation P;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %d %d %d \n",&P.idrecla,&P.idobse,&P.idbv,&P.idliste,&P.text,&P.d.jour,&P.d.mois,&P.d.annee)!=EOF)
        {
            if(P.idobse== idobse)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %s %d %d %d \n",P.idrecla,P.idobse,P.idbv,P.idliste,P.text,P.d.jour,P.d.mois,P.d.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
reclamation chercher(char * filename, int idobse)
{
    reclamation P;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d %s %d %d %d \n",&P.idrecla,&P.idobse,&P.idbv,&P.idliste,&P.text,&P.d.jour,&P.d.mois,&P.d.annee)!=EOF)
        {
            if(P.idobse== idobse)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        P.idobse=-1;
    return P;

}

