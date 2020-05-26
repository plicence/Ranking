#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"



int main(){

int taille = 281903;
//int taille = 9;
double *pi0= malloc(taille*sizeof(double));
for(int i = 0; i < taille; i++){

		pi0[i]=1/(double)taille;

}


list ** test = newListOfElements();
//printf("LIste créée\n");

/*for(int i = 0; i<taille; i++){

	elem *tmp = test[i]->head;
	matval jsp;
    while(tmp !=NULL){

   	 	jsp = *(matval*)(tmp->val);
    	tmp = tmp->next;
		printf("COlonne[%d]line[%d] = %lf\n",i+1,jsp.line+1,jsp.d);
	}
}*/


double *res1 =NULL;
double *res2 =NULL;

//res1 = convergenceFinale(test, pi0, taille);
res2 = Gauss_Seidel(test, pi0, taille);

for(int i = 0; i < 10; i++){

	//printf("res1[%d] = %lf\n",i, res1[i]);
	printf("res2[%d] = %lf\n",i, res2[i]);


}

free(res1);
free(res2);
free(pi0);



for(int i = 0; i < taille ; i++){

	myDeleteList(test[i]);


}
free(test);

	return 0;


}

