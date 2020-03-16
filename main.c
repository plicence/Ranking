#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"



int main(){

int taille = 10001;
double *pi0= malloc(taille*sizeof(double));
for(int i = 0; i < taille; i++){

		pi0[i]=1/(double)taille;

}


list ** test = newListOfElements();

double *res =NULL;
res = convergenceFinale(test, pi0, taille);
//res = Gauss_Seidel(test, pi0, taille);
for(int i = 0; i < taille; i++){

	printf("%lf\n", res[i]);


}

free(res);
free(pi0);



for(int i = 0; i < taille ; i++){

	myDeleteList(test[i]);


}
free(test);

	return 0;


}

