#include "list.h"

#define ABS(value) ((value >= 0) ? (value) : -(value));

double * convergence(double **mat, double *pi0 ,int taille);

list ** newListOfElements();

double * convergenceFinale(list **mat, double * pi0, int taille);

double * calculF(list ** mat,int taille);

double * Gauss_Seidel(list **mat, double * pi0, int taille);
