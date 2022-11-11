#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
typedef struct{
int jour;
int mois;
int annee;
}date;
typedef struct reclamation{
int idrecla;
int idobse;
int idbv;
int idliste;
char text[300];
date d;
}reclamation;
int ajouter(char * filename, reclamation p );
int modifierreclamation( char * filename, int idobse, reclamation nouv );
int supprimer(char * filename, int idobse);
reclamation chercher(char * filename, int idobse);

#endif // FUNCTION_H_INCLUDED
