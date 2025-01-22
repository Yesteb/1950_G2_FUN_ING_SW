//functions.c
#include <stdio.h>
#include <conio.h>
#include <time.h>

#include <string.h>
#include <stdlib.h>
/*Estos valores deben cambiar si se cambia
 	el usuario o la contraseña*/
#define passwordSave "contra"
#define usuarioSave "blanca"
//const char *passwordSave = "contra";
//const char *usuarioSave = "blanca";


	
//Estructura para registrar padres
	typedef struct {
		char nombrePadre[32];
		char apellidoPadre[32];
		char direccionCP[32];
		char nombreHijo[32];
		char direccionCS[32];
		char sector[32];
		
	}infoRegistroPd;
	
	typedef struct {
		char nombrePdr[32];
		char apellidoPdr[32];
		char nombreHj[32];
		float pago;
		
	}infoRegistroPg;
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
	return;
}
//Generar archivos con nombres determinados por su fecha y hora de creacion y concatenacion de la ruta
	/*strftime(nombreArchivo, sizeof(nombreArchivo), "registroPadre_%Y%m%d_H%M%S_", tmInfo);
	strcat(nombreArchivo,"_");
	strcat(nombreArchivo,apellidoPadre);
	strcat(ruta,nombreArchivo);*/
	
void RegistroPadreFamilia(){
	FILE *fptr1=fopen("DB\\listadoPadres\\listaPadres1.txt", "a");
	
	if(fptr1==NULL){
		printf("Archivo no encontrado\n");
	}
	

	infoRegistroPd registroPd;
	
	while(getchar()!= '\n');
	
	//Entrada de la informacion registrada por el usuario (En este caso el product owner) acerca de los datos personales de los representantes
	printf("Ingrese el primer nombre del representante: \n");
	fgets(registroPd.nombrePadre, 32, stdin);
	registroPd.nombrePadre[strcspn(registroPd.nombrePadre, "\n")]= 0;
	printf("Ingrese el primer apellido del representante: \n");
	fgets(registroPd.apellidoPadre, 32, stdin);
	registroPd.apellidoPadre[strcspn(registroPd.apellidoPadre, "\n")]= 0;
	printf("Ingrese la calle principal de domicilio: \n");
	fgets(registroPd.direccionCP, 32, stdin);
	registroPd.direccionCP[strcspn(registroPd.direccionCP, "\n")]= 0;
	printf("Ingrese la calle secundaria de domicilio: \n");
	fgets(registroPd.direccionCS, 32, stdin);
	registroPd.direccionCS[strcspn(registroPd.direccionCS, "\n")]= 0;
	printf("Ingrese el sector del domicilio: \n");
	fgets(registroPd.sector, 32, stdin);
	registroPd.sector[strcspn(registroPd.sector, "\n")]= 0;
	printf("Ingrese el primer nombre del estudiante representado: \n");
	fgets(registroPd.nombreHijo, 32, stdin);
	registroPd.nombreHijo[strcspn(registroPd.nombreHijo, "\n")]= 0;
	
	//Salida y lo que se escribira en el archivo sobre los datos personales del representante
	fprintf(fptr1, "Apellido: %s\n", registroPd.apellidoPadre);
	fprintf(fptr1, "Nombre: %s\n", registroPd.nombrePadre);
	fprintf(fptr1, "Nombre del representado: %s\n", registroPd.nombreHijo);
	fprintf(fptr1, "Direccion del domicilio: %s_%s_%s\n", registroPd.direccionCP, registroPd.direccionCS, registroPd.sector);
	fprintf(fptr1, "-----------------------------------------------------------------------------------------\n");
	
	fclose(fptr1);
	
	printf("Se registro la informacion del representante exitosamente...");
	getch();
	
	return;
}

//Es una funcion para registrar pagos
//Pide al usuario nombre del padre, apellido del padre
void RegistrarPagos(){
	FILE *fptr2=fopen("DB\\listadoPagos\\listaPagos1.txt", "a");
	if(fptr2==NULL){
		printf("Archivo no encontrado\n");
	}

	/*	time_t t; //Almacenar la cantidad de segundos
	struct tm *tmInfo; //Almaceno la estructura tm en un puntero tiempo-informacion
	
	time(&t); //Obtenemos la hora actual en segundos mediante la funcion time y almacenamos en la varibla t tipo time_t
	tmInfo= localtime(&t); //localtime toma la informacion de la cantidad de segundos almacenados en la variable t y lo convierte en la estructura tm
	*/
	
	time_t t; //Para almacenar los segundos
	struct tm *tmInfo; //Estructura donde se va a guardar
	
	time(&t); //Obtenemos la hora actual en segundos mediante la funcion time y almacenamos en la varibla t tipo time_t
	tmInfo=localtime(&t); //localtime toma la informacion de la cantidad de segundos almacenados en la variable t y lo convierte en la estructura tm
	
	char fecha[32];
	strftime(fecha, sizeof(fecha), "%Y/%m/%d a las %H:%M h", tmInfo);
	
	infoRegistroPg registroPg;
		
		while(getchar()!= '\n'); //Limpia la memoria temporal del programa
	
	//Entrada por teclado del usuario (En este caso el product owner)
	printf("Ingrese el primer nombre del representante: \n");
	fgets(registroPg.nombrePdr, 32, stdin);
	registroPg.nombrePdr[strcspn(registroPg.nombrePdr, "\n")]= 0;
	//Syntaxis de strcspn: strcspn(const char *string1, const char *string2);
	
	/*busca la primera aparición de un carácter en string1 que pertenece al conjunto de caracteres 
	especificado por string2 y devolverá la posición en name en la cual fue encontrado el match (Los caracteres nulos no se tienen en cuenta en la búsqueda: /0)*/
	
	printf("Ingrese el primer apellido del representante: \n");
	fgets(registroPg.apellidoPdr, 32, stdin);
	registroPg.apellidoPdr[strcspn(registroPg.apellidoPdr, "\n")]= 0;
	printf("Ingrese el primer nombre del estudiante representado: \n");
	fgets(registroPg.nombreHj, 32, stdin);
	registroPg.nombreHj[strcspn(registroPg.nombreHj, "\n")]= 0;
	printf("Ingrese el pago realizado: \n");
	scanf("%f", &registroPg.pago);
	
	//Salida y lo que escribira en el archivo
	fprintf(fptr2, "Apellido: %s\n", registroPg.apellidoPdr);
	fprintf(fptr2, "Nombre: %s\n", registroPg.nombrePdr);
	fprintf(fptr2, "Nombre del Representado: %s\n", registroPg.nombreHj);
	fprintf(fptr2, "Monto del pago efectuado: %.2f\n", registroPg.pago);
		
	fprintf(fptr2, "Fecha y hora del registro de pago: %s\n", fecha);
	fprintf(fptr2, "-----------------------------------------------------------------------------------------\n");
	
	fclose(fptr2);
	
	printf("Se registro el pago exitosamente...\n");
	getch();
	return;
}

//La función strstr en C se utiliza para buscar la primera aparición de una subcadena dentro de una cadena dada
//syntax: strstr(char * str, char * substring);

void modificarPadreFamilia(){
	FILE *fptr1=fopen("DB\\listadoPadres\\listaPadres1.txt", "r");
	char apellidoBuscado[32];
	int encontrar = 0;
	char linea[128];
	
	while(getchar()!= '\n' );
	
	printf("Ingrese el apellido del representante que desea encontrar\n");
	fgets(apellidoBuscado, 32, stdin);
	apellidoBuscado[strcspn(apellidoBuscado, "\n")] = 0;
	
	while(fgets(linea, 128, fptr1)){
		if(strstr(linea, apellidoBuscado) && strstr(linea, "Apellido: ")){ //La primera aparicion del apellidoBuscado y la primera aparicion de la cadena de caracteres "Apellido: " en la informacion guardada en la variable linea tiene que cumplirse para hacer el proceso             
			encontrar=1;
		printf("Informacion encontrada!\n");
		printf("Procesando....\n");
		 
		 do {
			printf("%s", linea);
		} while (fgets(linea, 128, fptr1) && strcmp(linea,"-----------------------------------------------------------------------------------------")!=0);
		}
			/*	if(!encontrar){
			printf("Informacion no encontrada\n");
			printf("No se encontro alguna informacion relacionada con el apellido: %s\n", apellidoBuscado);*/
	}
	
	fclose(fptr1);
		
	return;
	
}




