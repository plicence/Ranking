
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"




double absolute(double val){

	return val *((val>0) - (val<0));


}


double  conv(double * v1, double *v2, int taille){

	double res = 0;

		for(int i = 0; i < taille; i++){


			res += ABS(v1[i] - v2[i]);

		}

		return res;




}

/*	############												#############################
 * ################"											###########################
 *#################" 						MATRICES CREUSES	###########################
 * #################											############################
 * ################												##########################
 */

list ** newListOfElements(){


	FILE *f =NULL;
		f = fopen("/home/piere/Bureau/10001.txt", "r");

		if(f!=NULL){
			int a;
			int taille;
			fscanf(f, "%d %d", &a, &taille);
			printf("taille %d %d\n", taille, a);
			//printf("%d %d", a, taille);
			list ** mat = malloc(taille * sizeof(list*)) ;
			for(int i = 0; i < taille; i++) mat[i] = newList(); // on initialise chaque liste

			for(int i = 0; i < taille; i++){
				//printf("there");
				double nb_colonne;
				int k;
				fscanf(f,"%d %lf", &k, &nb_colonne);
				//printf("%d, %lf\n",k, nb_colonne);
				for(int j = 0; j < nb_colonne; j++){
					int colonne;
					matval * valeur = malloc(sizeof(matval));
					valeur->line = i;
					//double* valeur = malloc(sizeof(double));

				/*
				 * A CHANGER


				*/
					//fscanf(f, "%d %lf", &colonne, &(valeur->d));// pour les cas web1, web2, web3
					fscanf(f, "%lf %d", &(valeur->d), &colonne);// pour les cas 1000

				/*
				 * 			A CHANGER
				 * */

					//printf("ligne:%d;colonne:%d;valeur:%lf\n", i,colonne, valeur->d);
					//mat[i][colonne-1] = valeur;

				/**
				 * ATTENTION
				 *
				 */
					insertElem(mat[colonne ], valeur);

				/**
				 *
				 * ATTENTION
				 *
				 */
				}
				//printf("\n");

			}

			fclose(f);

			return mat;
		}
		else {
			printf("nope");

		}


		return NULL;


}


/*	############												#############################
 * ################"											###########################
 *#################" 				ETAPE 3						###########################
 * #################				GOOGLE						############################
 * ################												##########################
 */


double multScal(double * x, double * f ,int taille){

	double res = 0;

	for(int i = 0 ; i < taille ; i++){

		res += (x[i] * f[i]);

	}


	return res;
}


double * calculF(list ** mat,int taille){

	double * res = calloc (taille ,sizeof(double));
	for(int i = 0 ; i < taille ; i++){

		elem * tmp = mat[i]->head; // on prend le premier élément de la colonne i
		matval jsp ;			   // c'est l'élément contenant la ligne et la valeur
		int line;				   // ligne de l'élément

		while (tmp != NULL){ //on parcourt la liste en entier
			jsp= *(matval*)(tmp->val);
			line = jsp.line;
			tmp = tmp->next;

			res[line] += jsp.d; //on additionne l'élément de la colonne de pi0 correspondant à l'élément de la ligne de la matrice
		}


	}
	for(int i = 0; i < taille; i++){
		if(res[i])
			res[i] = 0;
		else
			res[i] = 1;

	}


	return res;
}



double * convergenceFinale(list **mat, double * pi0, int taille){

	double alpha = 0.85;
	double g = (1 - alpha) * (1/(double)taille);
	double d = alpha * (1/(double)taille);

	double * pin = calloc(taille ,sizeof(double)) ; //c 'est en fait pin+1
	double * pimem = calloc(taille ,sizeof(double)) ; //valeur qui retient pin
	double * f = calculF(mat, taille);
	for(int i =0; i < taille; i++){ //on copie pi0 dans pimem

		pimem[i] = pi0[i];

	}

	int iteration = 0;


	while( conv(pin, pimem, taille) > 1e-6){ //cela revient à comparer pin+1 et pin

		for(int i = 0; i < taille; i++){

			pin[i] = (g + d*(multScal(pi0, f, taille)) );

			elem * tmp = mat[i]->head; // on prend le premier élément de la colonne i
			matval jsp ;			   // c'est l'élément contenant la ligne et la valeur
			int line;				   // ligne de l'élément

			while (tmp != NULL){ //on parcourt la liste en entier
				jsp= *(matval*)(tmp->val);
				line = jsp.line;
				tmp = tmp->next;
				pin[i] += alpha * (pi0[line] * jsp.d) ; //on additionne l'élément de la colonne de pi0 correspondant à l'élément de la ligne de la matrice
			}			//axP                        +  [(1 − α)(1/N) + α(1/N)(x f t )]e

		}



		for(int i =0; i < taille; i++){ //on recopie
			pimem[i] = pi0[i];          // on met pi0 dans pimem qui est utilisé pour le test
			pi0[i] = pin[i];            // on met pin dans pi0 qui est utilisé pour le calcul suivant

		}


		iteration++;

	}
	printf("iteration: %d", iteration);
	free(pimem);
	free(f);
	return pin;
}

