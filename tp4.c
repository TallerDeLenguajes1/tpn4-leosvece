#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//problema con el codigo
/*despues de cargar los datos, elijo dos tareas a realizar para iniciar una prueba. Cuando interactuo para determinar cuales de las tareas se realizaron,
si eligo que la primera fue realizada, me muestra el programa que la tarea fue realizada, pero solo me muestra el ID de la pendiente.
si eligo que la segunda fue realizada, me muestra como que todas fueron realizadas y, en este caso, me muestra las tareas pendientes,
que en el anterio eleccion no me permitia*/

typedef struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}tarea;



void cargarTarea(tarea **T,int x);
void mostrar(tarea **T, int x);
void estadoDetarea(tarea **R, tarea **P, int x);
//void listarTarea(tarea **T,int x);

int main(){
    tarea *tareasPendientes, *tareasRealizadas;
    srand(time(NULL));
    int x;
    
    printf("Cuantas tareas se deben realizar: ");
    scanf("%d",&x);
    fflush(stdin);
    
    tareasPendientes = (tarea*)malloc((x+1)*sizeof(tarea));
    if (tareasPendientes== NULL){
    	printf("compre otra pc perro no tiene memoria");
	}
	
	tareasRealizadas = (tarea*)malloc((x+1)*sizeof(tarea));
    if (tareasRealizadas== NULL){
    	printf("compre otra pc perro no tiene memoria");
	}
	
	
	cargarTarea(&tareasPendientes,x);
	estadoDetarea(&tareasRealizadas,&tareasPendientes,x);
	//listarTarea(&tareasPendientes,x);
	
	printf("las tareas realizadas son:");
	mostrar(&tareasRealizadas,x);
	
	printf("\n tareas pendientes\n");
	mostrar(&tareasPendientes,x);
	
	free(tareasPendientes);
	free(tareasRealizadas);
    return 0;
}

void cargarTarea(tarea **T, int x){
   char aux[100];
    int i;
	tarea *t = *T;

    for (i=0;i<x;i++){
    	t[i].TareaID = i;
    	printf("%d) de una descripcion: ",i+1);
    	gets(aux);
    	t[i].Descripcion = (char*)malloc((strlen(aux)+1)*sizeof(char));
    	strcpy(t[i].Descripcion,aux);
    	t[i].Duracion =10+ rand()%100;
	}  
    
}

void estadoDetarea(tarea **R, tarea **P, int x){
	
	tarea *p=*P, *r= *R;
	//tarea *aux = NULL;
	int i,j=0, band=0, aux = NULL;
	
	for (i=0;i<x;i++){
		printf("la tarea numero %d fue realizada?\n1)si		2)no\n",i);
		scanf("%d",&band);
		fflush(stdin);
		if(band ==1){
			r[j] = p[i]; //p =pendiente r=realizada
			p[i].Descripcion = NULL;
			p[i].Duracion = aux;
			p[i].TareaID= aux;
			j++;
		}
		else{
			r[j].Descripcion = NULL;
			r[j].Duracion = aux;
			r[j].TareaID = aux;
			j++;
		}
	}	
}
/*
void listarTarea(tarea **T,int x){
	int i;
	tarea *t=*T;
	
	for(i=0;i<x;i++){
		if( t[i].Descripcion == NULL){
			t[i].Descripcion = t[i+1].Descripcion;
			t[i].Duracion = t[i+1].Duracion;
			t[i].TareaID=t[i+1].TareaID;
		}	
	}
}*/

void mostrar(tarea **T, int x){
	tarea *t = *T;
	int i, aux = -1;
	 for (i=0;i<x;i++){
	 	if(t[i].Descripcion != NULL){
    		printf("\nID: %d",t[i].TareaID);
    		printf("\nDescripcion: %s",t[i].Descripcion);
    		printf("\nDuracion: %d\n",t[i].Duracion);
    	}
	}	
}
