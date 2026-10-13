#include <stdio.h>
#include <stdlib.h>

struct administracion{
	char calle1[20];
	char calle2[20];
	int trafico;
};
void ingreso_datos(struct administracion *vector,int cant_vehiculos );
void Mostrar(struct administracion *vector,int cant_vehiculos);
void Buscar(struct administracion *vector,int cant_vehiculos);
struct administracion*nuevos(struct administracion *vector,int cant_vehiculos);


int main(int argc, char *argv[]) {
	int opcion;
	int cant_vehiculo;
	printf("ingresar cantidad de semaforos:");
	scanf("%d",&cant_vehiculo);
	
	struct administracion *vector;
	
	vector = malloc(cant_vehiculo*sizeof(struct administracion));
	

	
	do {
		printf("-----Menu-------\n");
		printf("1.cargar datos\n");
		printf("2.Mostrar administracion\n");
		printf("3.Buscar semaforo\n");
		printf("4.Salir\n");
	
		
		printf("seleccionar opcion:\n");
		scanf("%d",&opcion);
		switch(opcion){
		case 1:
			ingreso_datos(vector,cant_vehiculo);
			break;
		case 2:
			Mostrar(vector,cant_vehiculo);
			break;
		case 3:
			Buscar(vector,cant_vehiculo);
			break;
		case 4:
			
			break;
		
	    }
		
		
		
	} while (opcion!=5);
	
	
	
	free(vector);
	return 0;
}

void ingreso_datos(struct administracion *vector,int cant_vehiculos ){
	for(int i=0;i<cant_vehiculos;i++){
		printf("Nombre de calle 1:");
		scanf("%s",vector[i].calle1);
		printf("Nombre de calle 2:");
		scanf("%s",vector[i].calle2);
		printf("Intensidad de trafico:");
		scanf("%d",&vector[i].trafico);
		printf("-----------\n");
	}
}
void Mostrar(struct administracion *vector,int cant_vehiculos){
	for(int i=0;i<cant_vehiculos;i++){
		printf("semaforo\n");
		printf("Nombre de calle2:%s\n",vector[i].calle1);
		printf("Nombre de calle1:%s\n",vector[i].calle2);
		printf("Trafico:%d",vector[i].trafico);
		printf("------------\n");
	}
}	
void Buscar(struct administracion *vector,int cant_vehiculos){
	//tambien podriamos hacerlo por strmp
	int buscar;
	int encontrado=0;
	int posicion;
	
	printf("Ingrese trafico:");
	scanf("%d",&buscar);

	for(int i=0;i<cant_vehiculos;i++){
		if(buscar==vector[i].trafico){
			buscar=vector[i].trafico;
			encontrado=1;
			posicion=i;
		}
	}
	if(encontrado==1){
		printf("Nombre de calle1:%s\n",vector[posicion].calle1);
		printf("Nombre de calle2:%s\n",vector[posicion].calle2);
		printf("Trafico:%d\n",vector[posicion].trafico);
	}else{
		printf("No encontrado");
	}
}
