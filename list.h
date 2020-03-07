
typedef struct matval{

	double d;
	int line;


}matval;

typedef struct elem{

	struct elem * next;
	void * val;


}elem;


typedef struct list{

	elem * head;
	elem * current;

}list;





list * newList(void);

void insertElem(list * l, void * v);

void removeNext(list * l);

void listFirst(list * l);

void removeFirst( list * l);

void deleteList(list ** l);

void myDeleteList(list * l);
