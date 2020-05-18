#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char * Descripcion; //
int Duracion; // entre 10 ï¿½ 100
}tarea;

typedef struct nodo{
tarea T;
struct nodo *Siguiente;
}nodo;

void cargarTarea(nodo **star,int x);
void mostrar(nodo **star);
//nodo *finalizarTarea(nodo **star);
nodo *estadoDetarea(nodo **star);
void busquedas(nodo **lista);
nodo *busquedaID(int id, nodo **lista);
nodo *busquedaNombre(char nombre[], nodo **lista);




int main(){
	nodo *lista =NULL, listaSup;
    nodo *tareaPend= NULL;
    nodo *tareaReal=NULL, *aux;
    srand(time(NULL));
    int x,i, band;
	
	printf("ingrese la cantidad de tareas a realizar: ");
	scanf("%d",&x);
	fflush(stdin);
	
	cargarTarea(&lista,x);
	
	do {
		busquedas(&lista);
		printf("la realizar otra tarea?\n1)si		2)no\n",i);
		scanf("%d",&band);
	}while(band==1);
	

	for(i=0;i<x;i++){
		
		printf("la tarea numero %d fue realizada?\n1)si		2)no\n",i)+1;
		scanf("%d",&band);
		aux = estadoDetarea(&lista);
		
		if(band ==1){
			
			tareaReal = (nodo*)malloc(sizeof(nodo));
			tareaReal->Siguiente =  aux;
			aux = tareaReal;
			tareaReal = tareaReal->Siguiente; //sin esto inicializa el primero como basura ¿porque?
		}
		else{
			
			tareaPend = (nodo*)malloc(sizeof(nodo));
			tareaPend->Siguiente =  aux;
			aux = tareaReal;
			tareaPend = tareaPend->Siguiente;	//sin esto inicializa el primero como basura ¿porque?
		}	
	}
	
	
	if(tareaReal != NULL){
	
	printf("\nlas tareas realizadas son:");
	mostrar(&tareaReal);
	}
	
	if(tareaPend !=NULL){

	printf("\nTareas pendientes\n");
	mostrar(&tareaPend);
	}	

	
	free(lista);
	free(tareaReal);
	free(tareaPend);
	
    return 0;
}


void busquedas(nodo **lista){
	nodo * aux = *lista;
	nodo *busqueda =NULL;
	int buscar, id;
	char nombre[100];
	
	printf("¿que tarea desea buscar? \n1)por ID    2)por nombre");
	scanf("%d",&buscar);
		
		if(buscar ==1){
			printf("escriba el ID de la tarea que busca");
			scanf("%d",&id);
			busqueda = busquedaID(id,&aux);
			mostrar(&busqueda);
	
		}else{
			printf("escriba el nombre de la tarea:\n");
			fflush(stdin);
			gets(nombre);
			busqueda = busquedaNombre(nombre,&aux);
			mostrar(&busqueda); 
		}
	
}

void cargarTarea(nodo **star, int x){
   	char aux1[100];
    int i=0;
	nodo *aux;	
	
	aux = (nodo*)malloc(sizeof(nodo));
	
	for(i=0;i<x;i++){
		*star = (nodo*)malloc(sizeof(nodo));

	 //con esto el forma carga una basura ¿porque?
	/* 	(*star)->T.TareaID = i;
	    printf("%d) de una descripcion: ",i+1);
	    gets(aux1);
	    (*star)->T.Descripcion = (char*)malloc((strlen(aux1)+1)*sizeof(char));
	    strcpy((*star)->T.Descripcion,aux1);
	    (*star)->T.Duracion =10+ rand()% 90; 
	    (*star)->Siguiente = NULL;
	    
	    
	   	(*star)->Siguiente = aux;
		aux = *star;
		*star = (*star)->Siguiente;*/ 

		
		aux->T.TareaID = i;
	    printf("%d) de una descripcion: ",i+1);
	    gets(aux1);
	    aux->T.Descripcion = (char*)malloc((strlen(aux1)+1)*sizeof(char));
	    strcpy(aux->T.Descripcion,aux1);
	    aux->T.Duracion =10+ rand()% 90;
	    //aux->Siguiente = NULL; // si cargo esto se llena de basura
	    
	    (*star)->Siguiente = aux;
		aux = *star;
		*star = (*star)->Siguiente; // si no pongo esto, el primero se llena de basura ¿porque?
	    
	}

}


nodo *estadoDetarea(nodo **star){
	
	nodo  *Pendiente = *star, *aux =NULL;

		//aux = finalizarTarea(&Pendiente);
		//####################################recordatorio############################
		// al inicializar con pendiente se realizaba una copia, o eso es lo que creo, y no modificaba el original, haciendo que se copie todo
			
		aux = *star;
		*star = (*star)->Siguiente;
		aux->Siguiente = NULL; // con esto las dos guardan el mismo nodo, el ultimo, en vez de solo guardar el que pido, sin esto guardan los dos nodos todos los nodos
		
		return aux;	
	
	
}
/*
nodo *finalizarTarea(nodo **star){
	nodo *aux = *star; 
	*star = (*star)->Siguiente;
	return aux; 
}*/


nodo *busquedaID(int id, nodo **lista){
	nodo *aux = *lista;
	while ( aux->Siguiente && aux->T.TareaID != id){
		aux = aux->Siguiente;
	}
	if (aux->Siguiente != NULL){
		aux->Siguiente = NULL;
		return aux;		
	}
	else{
		printf("su tarea no existe");
		return NULL;
	}

}

nodo *busquedaNombre(char nombre[], nodo **lista){
	nodo *aux = *lista;
	
	while ( aux->Siguiente && strcmp(aux->T.Descripcion,nombre) != 0){
		aux = aux->Siguiente;
	}
	if (aux != NULL){
		aux->Siguiente = NULL;
		return aux;		
	}
	else{
		printf("su tarea no existe");
		return NULL;
	}

}





void mostrar(nodo **star){
	nodo *t = *star;
	
	while(t !=NULL){
		printf("\nID: %d",t->T.TareaID);
    	printf("\nDescripcion: %s",t->T.Descripcion);
    	printf("\nDuracion: %d\n",t->T.Duracion);
    	t = t->Siguiente;
	}

}
