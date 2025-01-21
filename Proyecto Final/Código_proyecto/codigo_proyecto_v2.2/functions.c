//functions.c
#include <stdio.h>
#include <time.h>
#include <string.h>
// Estos valores deben cambiar si se cambia
// el usuario
#define passwordSave "contra"
#define usuarioSave "blanca"
//const char *passwordSave = "contra";
//const char *usuarioSave = "blanca";

/**
 * Imprime el contenido de un archivo especificado.
 * @param char* rutaArchivo la ruta donde se encuentra almacenado el archivo.
 * @param int charMax tamanio maximo del buffer.
 * @return void
 */

	
void imprimirArchivo(char *rutaArchivo, int charMax){
	FILE *fptr = fopen(rutaArchivo, "r");
	char buffer[charMax];
	
	if (fptr == NULL){
		printf("No se ha encontrado el archivo!");
	}
	
	while (!feof(fptr)){ // No es caracter de fin de archivo? "/0"
		fread(buffer, 1, charMax, fptr); //se utiliza para leer bloques de datos de un archivo
		printf("%s", buffer); 
	}

	fclose(fptr);
	return;
}


void IniciarSesion(){
	char usuario[20];
	char password[10];
	
	printf("USUARIO: ");
	scanf("%s", usuario);

	printf("PASSWORD: ");
	scanf("%s", password);
	
	if(strcmp(usuarioSave, usuario) == 0 && strcmp(passwordSave, password) == 0){
		printf("Se ha registrado exitosamente\n");
	}else{
		printf("Escriba correctamente sus credenciales\n");
	}
}


void RegistroPadreFamilia(){
	FILE *fptr1;
	
/*	time_t t; //Almacenar la cantidad de segundos
	struct tm *tmInfo; //Almaceno la estructura tm en un puntero tiempo-informacion
	
	time(&t); //Obtenemos la hora actual en segundos mediante la funcion time y almacenamos en la varibla t tipo time_t
	tmInfo= localtime(&t); //localtime toma la informacion de la cantidad de segundos almacenados en la variable t y lo convierte en la estructura tm
	*/
	char nombrePadre[50];
	char apellidoPadre[50];
	char direccion[50];
	char nombreHijo[50];
	
	
	printf("Ingrese el primer nombre del representante: \n");
	scanf("%49s", nombrePadre);
	printf("Ingrese el primer apellido del representante: \n");
	scanf("%49s", apellidoPadre);
	printf("Ingrese la calle principal de domicilio: \n");
	scanf("%49s", direccion);
	printf("Ingrese el primer nombre del estudiante representado: \n");
	scanf("%49s", nombreHijo);
	
	/*strftime(nombreArchivo, sizeof(nombreArchivo), "registroPadre_%Y%m%d_H%M%S_", tmInfo);
	strcat(nombreArchivo,"_");
	strcat(nombreArchivo,apellidoPadre);
	strcat(ruta,nombreArchivo);*/

	fptr1=fopen("DB\\listadoPadres\\listaPadres1.txt", "a");
	
		if(fptr1 == NULL){
			printf("No se ha encontrado el archivo");
		}
	
	fprintf(fptr1, " %s;%s;%s;%s\n", nombrePadre, apellidoPadre, direccion, nombreHijo);
	
	fclose(fptr1);
}

//Es una funcion para registrar pagos
//Pide al usuario nombre del padre, apellido del padre
void RegistrarPagos(){
	FILE *fptr2;
	time_t t; //Para almacenar los segundos
	struct tm *tmInfo; //Estructura donde se va a guardar
	
	time(&t); //Obtenemos la hora actual en segundos mediante la funcion time y almacenamos en la varibla t tipo time_t
	tmInfo=localtime(&t); //localtime toma la informacion de la cantidad de segundos almacenados en la variable t y lo convierte en la estructura tm
	
	char nombrePadre[50];
	char apellidoPadre[50];
	char nombreHijo[50];
	float pago[8];
	char fecha[32];
	char cedulaPadre[16];
	
	printf("Ingrese el nro de cedula del representante: \n");
	scanf("%15s", cedulaPadre);
	printf("Ingrese el nombre del representante: \n");
	scanf("%49s", nombrePadre);
	printf("Ingrese el primer apellido del representante: \n");
	scanf("%49s", apellidoPadre);
	printf("Ingrese el primer nombre del estudiante representado: \n");
	scanf("%49s", nombreHijo);
	
	printf("Ingrese el pago realizado: \n");
	scanf("%d", &pago);
	
	strftime(fecha, sizeof(fecha), "%Y/%m/%d a las %H:%M h", tmInfo);
	
	//fptr1=fopen("C:\\Users\\G406\\Downloads\\RGPGOS00001", "w");
	fptr2=fopen("DB\\listadoPagos\\listaPagos1.txt", "a");
	
		if (fptr2 == NULL){
		printf("No se ha encontrado el archivo!");
		}
	fprintf(fptr2, "%s;%s;%s;%s; Pago realizado: %.2f; %s\n",cedulaPadre , nombrePadre, apellidoPadre, nombreHijo, pago, fecha);
	
	fclose(fptr2);
}


void modificarPadreFamilia(){
	
}
