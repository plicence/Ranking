#include <stdio.h>
#include <stdlib.h>
#include "list.h"




list * newList(void){

	list * l = malloc (sizeof(*l));
	if(l){

			l->head = NULL;

			l->current = NULL;


	}

	else{

		printf("Memory failure");
		exit(EXIT_FAILURE);

	}

	return l;

}


void insertElem(list * l, void * v ){

	if(l){
		elem * e1 = l->current; //on se positionne à l'élément courant
		elem * e2 = NULL;
		//printf("here %lf\n", *(double*)v);
		e2 = malloc (sizeof(*e2));
		if(e2){

			e2->val = v;

			if(e1 == NULL){

				//free(l->head);
				l->head = e2;
				e2->next = NULL;
				l->current = l->head;

			}

			else{

				l->current->next = e2;
				l->current = l->current->next;
				l->current->next = NULL;
			}
		}

		else{

			printf("Not enough memory\n");
			exit(EXIT_FAILURE);

		}
	}
}

void removeNext(list * l){

	if(l && l->current){

		elem * e1 = l->current;
		elem * e2 = NULL;

		e2 = e1->next;
		e1->next = e2->next;

		free(e2);
		e2 = NULL;
	}

}


void listFirst(list * l){

	if(l){

		l->current = l->head->next;
	}

}

void removeFirst( list * l){

	if(l){

		l->current = l->head;
		removeNext(l);

	}

}


void deleteList(list ** l){

	if (l && *l){

		listFirst(*l);

	}

	while ((*l)->current->next != NULL){

		removeFirst(*l);
		free((*l)->current);
		(*l)->current = NULL;
		free(*l), *l = NULL;
	}

}

void myDeleteList(list * l){

	if(l){
		elem * e1 = l->head;
		elem * e2 = NULL;

		while(e1){

			e2 = e1;
			e1 = e1->next;

			free(e2->val);
			free(e2);

		}

			free(l);

	}

}
