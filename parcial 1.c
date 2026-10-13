#include <stdio.h>
#include <stdlib.h>
//Agregamso la libreria para la busqueda por caracteres
#include <string.h>
struct administracion{
	char calle1[20];
	char calle2[20];
	int trafico;
};
void ingreso_datos(struct administracion *vector,int cant_vehiculos );
//Agragamos funcion para ingresar nuevos semaforos en cualquier momento 
struct administracion *nuevos(struct administracion *vector,int *cant_vehiculos);
void Mostrar(struct administracion *vector,int cant_vehiculos);
//Modificacion de la busqueda de entero a caracteres
void Buscar(struct administracion *vector,int cant_vehiculos);


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
		//Agregamos la opcion de ingresar datos en todo momento
		printf("2.Agregar datos\n");
		printf("3.Mostrar administracion\n");
		printf("4.Buscar semaforo\n");
		printf("5.Salir\n");
		
		printf("seleccionar opcion:\n");
		scanf("%d",&opcion);
		switch(opcion){
		case 1:
			ingreso_datos(vector,cant_vehiculo);
			break;
		case 2:
			//Hacemos la llamada del vector actualizado
			vector = nuevos(vector,&cant_vehiculo);
			break;
		case 3:
			Mostrar(vector,cant_vehiculo);
			break;
		case 4:
			Buscar(vector,cant_vehiculo);
			break;
		case 5:
			
			break;
	    }
		
		
		//Solucionamos la condicion para salir del bucle 
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
struct administracion *nuevos(struct administracion *vector,int *cant_vehiculos){
	//Modificamos la variable agregando uno mas 
	*cant_vehiculos = *cant_vehiculos + 1;
	//Creamos un puntero para guardar la nueva direccion
	struct administracion *temp;
	//Guardamos la nueva direcion para nuestra cantidad de vehiculos modificada
	temp = realloc(vector, (*cant_vehiculos) * sizeof(struct administracion));
	
	if(temp == NULL){
		printf("Error");
		return vector; //Si falla, devolvemos el vector original
	}
	//Actualizamos el puntero original
	vector = temp;
	//Cargamos los datos 
	int i = (*cant_vehiculos) - 1;
	printf("\n--- Cargar nuevo semaforo ---\n");
	printf("Nombre de calle 1: ");
	scanf("%s", vector[i].calle1);
	printf("Nombre de calle 2: ");
	scanf("%s", vector[i].calle2);
	printf("Intensidad de trafico (1-100): ");
	scanf("%d", &vector[i].trafico);
	printf("¡Semaforo agregado con exito!\n");
	//Devolvemos el vector actualizado
	return vector;
	
}
	
void Mostrar(struct administracion *vector,int cant_vehiculos){
	for(int i=0;i<cant_vehiculos;i++){
		printf("semaforo\n");
		printf("Nombre de calle2:%s\n",vector[i].calle1);
		printf("Nombre de calle1:%s\n",vector[i].calle2);
		printf("Trafico:%d\n",vector[i].trafico);
		printf("------------\n");
	}
}
//Funcion de busqueda modificada
void Buscar(struct administracion *vector,int cant_vehiculos){
	//Definimos una variable tipo char
	char busqueda [20];
	int encontrado = 0;
	
	printf("Ingrese nombre de la calle: ");
	//Guardamos el nombre de la calle ingresada en el char de arriba
	scanf("%s", busqueda);

	for(int i=0;i<cant_vehiculos;i++){
		//Comparamos si coincide con calle1 o calle2 usando strcmp
		if (strcmp(vector[i].calle1, busqueda) == 0 || strcmp(vector[i].calle2, busqueda) == 0) {
			//Imprime si se cuimple la condicion 
			printf("\n--- Interseccion encontrada ---\n");
			printf("Calle 1: %s\n", vector[i].calle1);
			printf("Calle 2: %s\n", vector[i].calle2);
			printf("Trafico: %d\n", vector[i].trafico);
			printf("-------------------------------\n");
			encontrado=1;
		}
	}
	if(!encontrado){
		printf("La se encontro interseccion para esa calle.\n");
	}
}
