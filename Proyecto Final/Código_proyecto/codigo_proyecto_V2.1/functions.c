//functions.c
#include <stdio.h>
#include <string.h>
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
		printf("No se ha encontrado el archivo de menu!");
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
	
	char nombreArchivo[4]="\0";
	char nombrePadre[50];
	char apellidoPadre[50];
	char direccion[50];
	char nombreHijo[50];
	char ruta[32] ="DB\\listadoPadres\\";
	
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
	strcat(nombreArchivo, nombrePadre);
	strcat(nombreArchivo, "_");
	strcat(nombreArchivo, nombreHijo);
	strcat(ruta, "_");
	strcat(ruta,nombreArchivo);
	fptr1=fopen(ruta, "w");
	
	fprintf(fptr1, " %s;%s;%s;%s\n", nombrePadre, apellidoPadre, direccion, nombreHijo);
	
	fclose(fptr1);
}

void RegistrarPagos(){
	FILE *fptr2;
	
	float pago;
	char nombrePadre[50];
	char fecha[10];
	
	printf("Ingrese el nombre del padre de familia: \n");
	scanf("%49s", nombrePadre);
	printf("Ingrese la fecha del pago realizado: \n");
	scanf("%49s", fecha);
	printf("Ingrese el pago realizado: \n");
	scanf("%d", &pago);
	
	//fptr1=fopen("C:\\Users\\G406\\Downloads\\RGPGOS00001", "w");
	fptr2=fopen("DB\\RGPGOS00001.txt", "w");
	
	fprintf(fptr2, "0001 %49s %49s %d", nombrePadre, fecha, pago);
	
	fclose(fptr2);
}

void modificarPadreFamilia(){
	
}
