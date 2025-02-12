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
		int idRepresentante;
		char nombreRepresentante[32];
		char apellidoRepresentante[32];
		char correoElectronico[32];
		int numeroCelular;
		char direccionCP[32];
		char nombreHijo[32];
		char direccionCS[32];
		char sector[32];
		
	}infoRegistroRepresentante;
	
	typedef struct {
		int idReprsant;
		char nombreRprsant[32];
		char apellidoRprsant[32];
		char nombreHj[32];
		char correoElectr[32];
		int numeroCell;
		float pago;
	}infoRegistroPg;

/**
 * Imprime el contenido de un archivo especificado.
 * @param char* rutaArchivo la ruta donde se encuentra almacenado el archivo.
 * @param int charMax tamanio maximo del buffer.
 * @return void
 */
 
 void limpiarPantalla(){
	system("cls");
	
 }

 void historialPagos(char *rutaArchivo, int charMax) {
    FILE *fptr = fopen(rutaArchivo, "r");
    if (fptr == NULL) {
        printf("No se ha encontrado el archivo!\n");
        return;
    }
    char buffer[charMax];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, charMax - 1, fptr)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    }
    fclose(fptr);
}
/*void historialPagos(char *rutaArchivo, int charMax){
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
}*/


void IniciarSesion(){
	char usuario[20];
	char password[10];
	
	printf("USUARIO: ");
	scanf("%s", usuario);

	printf("PASSWORD: ");
	scanf("%s", password);
	
	if(strcmp(usuarioSave, usuario) == 0 && strcmp(passwordSave, password) == 0){
		printf("Se ha registrado exitosamente\n");
		limpiarPantalla();
	}else{
		printf("Escriba correctamente sus credenciales\n");
		exit(0);
	}
	return;
}
//Generar archivos con nombres determinados por su fecha y hora de creacion y concatenacion de la ruta
	/*strftime(nombreArchivo, sizeof(nombreArchivo), "registroPadre_%Y%m%d_H%M%S_", tmInfo);
	strcat(nombreArchivo,"_");
	strcat(nombreArchivo,apellidoPadre);
	strcat(ruta,nombreArchivo);*/
	
void RegistroPadreFamilia(){
	FILE *fptr1=fopen("DB\\listadoRepresentante\\listaRepresentantes1.txt", "a");
	
	if(fptr1==NULL){
		printf("Archivo no encontrado\n");
	}
	

	infoRegistroRepresentante registroRepresentante;
	
	//Entrada de la informacion registrada por el usuario (En este caso el product owner) acerca de los datos personales de los representantes
	
	puts("Ingrese el numero de cedula del representante: ");
	scanf("%d", &registroRepresentante.idRepresentante);
	
	while(getchar()!= '\n');
	
	puts("Ingrese el primer nombre del representante: ");
	fgets(registroRepresentante.nombreRepresentante, 32, stdin);
	registroRepresentante.nombreRepresentante[strcspn(registroRepresentante.nombreRepresentante, "\n")]= 0;
		
	puts("Ingrese el primer apellido del representante: ");
	fgets(registroRepresentante.apellidoRepresentante, 32, stdin);
	registroRepresentante.apellidoRepresentante[strcspn(registroRepresentante.apellidoRepresentante, "\n")]= 0;
	
	puts("Ingrese el correo electronico del representante: ");
	fgets(registroRepresentante.correoElectronico, 32, stdin);
	registroRepresentante.correoElectronico[strcspn(registroRepresentante.correoElectronico, "\n")]= 0;
	
	puts("Ingrese el numero de celular del representante: ");
	scanf("%d", &registroRepresentante.numeroCelular);
	while(getchar()!= '\n');
	
	puts("Ingrese la calle principal de domicilio: ");
	fgets(registroRepresentante.direccionCP, 32, stdin);
	registroRepresentante.direccionCP[strcspn(registroRepresentante.direccionCP, "\n")]= 0;
	
	puts("Ingrese la calle secundaria de domicilio: ");
	fgets(registroRepresentante.direccionCS, 32, stdin);
	registroRepresentante.direccionCS[strcspn(registroRepresentante.direccionCS, "\n")]= 0;
	
	puts("Ingrese el sector del domicilio: ");
	fgets(registroRepresentante.sector, 32, stdin);
	registroRepresentante.sector[strcspn(registroRepresentante.sector, "\n")]= 0;
	
	puts("Ingrese el primer nombre del estudiante representado: ");
	fgets(registroRepresentante.nombreHijo, 32, stdin);
	registroRepresentante.nombreHijo[strcspn(registroRepresentante.nombreHijo, "\n")]= 0;
	
	//Salida y lo que se escribira en el archivo sobre los datos personales del representante
	fprintf(fptr1, "\nID: %d\n", registroRepresentante.idRepresentante);
	fprintf(fptr1, "Apellido: %s\n", registroRepresentante.apellidoRepresentante);
	fprintf(fptr1, "Nombre: %s\n", registroRepresentante.nombreRepresentante);
	fprintf(fptr1, "Correo electronico: %s\n", registroRepresentante.correoElectronico);
	fprintf(fptr1, "Numero celular: %d\n", registroRepresentante.numeroCelular);
	fprintf(fptr1, "Nombre del representado: %s\n", registroRepresentante.nombreHijo);
	fprintf(fptr1, "Direccion del domicilio: %s_%s_%s\n", registroRepresentante.direccionCP, registroRepresentante.direccionCS, registroRepresentante.sector);
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
	
	time_t t; //Para almacenar los segundos
	struct tm *tmInfo; //Estructura donde se va a guardar
	
	time(&t); //Obtenemos la hora actual en segundos mediante la funcion time y almacenamos en la varibla t tipo time_t
	tmInfo=localtime(&t); //localtime toma la informacion de la cantidad de segundos almacenados en la variable t y lo convierte en la estructura tm
	
	char fecha[32];
	strftime(fecha, sizeof(fecha), "%Y/%m/%d a las %H:%M h", tmInfo);
	
	infoRegistroPg registroPg;
		
		 
	
	//Entrada por teclado del usuario (En este caso el product owner)
	puts("Ingrese el numero de cedula del representante: ");
	scanf("%d", &registroPg.idReprsant);

	while(getchar()!= '\n');
	
	puts("Ingrese el primer nombre del representante: (Escriba todo en mayusculas o minusculas)");
	fgets(registroPg.nombreRprsant, 32, stdin);
	registroPg.nombreRprsant[strcspn(registroPg.nombreRprsant, "\n")]= 0;
	
	
	/*busca la primera aparición de un carácter en string1 que pertenece al conjunto de caracteres 
	especificado por string2 y devolverá la posición en name en la cual fue encontrado el match (Los caracteres nulos no se tienen en cuenta en la búsqueda: /0)*/

	puts("Ingrese el primer apellido del representante: (Escriba todo en mayusculas o minusculas)");
	fgets(registroPg.apellidoRprsant, 32, stdin);
	registroPg.apellidoRprsant[strcspn(registroPg.apellidoRprsant, "\n")]= 0;
	
	puts("Ingrese el correo electronico del representante: ");
	fgets(registroPg.correoElectr, 32, stdin);
	registroPg.correoElectr[strcspn(registroPg.correoElectr, "\n")]= 0;
	
	puts("Ingrese el numero de celular del representante: ");
	scanf("%d", &registroPg.numeroCell);
	
	while(getchar()!= '\n'); 
	
	puts("Ingrese el primer nombre del estudiante representado: (Escriba todo en mayusculas o minusculas)");
	fgets(registroPg.nombreHj, 32, stdin);
	registroPg.nombreHj[strcspn(registroPg.nombreHj, "\n")]= 0;
	
	puts("Ingrese el pago realizado: ");
	scanf("%f", &registroPg.pago);
	
	//Salida y lo que escribira en el archivo
	fprintf(fptr2, "\nID: %d\n", registroPg.idReprsant);
	fprintf(fptr2, "Apellido: %s\n", registroPg.apellidoRprsant);
	fprintf(fptr2, "Nombre: %s\n", registroPg.nombreRprsant);
	fprintf(fptr2, "Correo electronico: %s\n", registroPg.correoElectr);
	fprintf(fptr2, "Numero celular: %d\n", registroPg.numeroCell);
	fprintf(fptr2, "Nombre del Representado: %s\n", registroPg.nombreHj);
	fprintf(fptr2, "Monto del pago efectuado: %.2f\n", registroPg.pago);
		
	fprintf(fptr2, "Fecha y hora del registro de pago: %s\n", fecha);
	fprintf(fptr2, "-----------------------------------------------------------------------------------------\n");
	
	fclose(fptr2);
	
	puts("Se registro el pago exitosamente...");
	getch();
	return;
}
void buscarRepresentante() {
    FILE *fptr = fopen("DB/listadoRepresentante/listaRepresentantes1.txt", "r");
    if (fptr == NULL) {
        puts("No se ha encontrado el archivo de representantes!");
        return;
    }
    
    char criterio[32];
    puts("Ingrese el ID o Apellido del representante a buscar: ");
    scanf("%s", criterio);
    
    char linea[128];
    int encontrado = 0;
    
    while (fgets(linea, 128, fptr)) {
        if (strstr(linea, criterio)) {
            encontrado = 1;
            puts("\nRepresentante encontrado: ");
            
            do {
                printf("%s", linea);
            } while (fgets(linea, 128, fptr) && strcmp(linea, "-----------------------------------------------------------------------------------------\n") != 0);
            printf("-----------------------------------------------------------------------------------------\n");
        }
    }
    
    if (!encontrado) {
        printf("No se encontró ningún representante con el criterio '%s'.\n", criterio);
    }
    
    fclose(fptr);
}

// Función para buscar un pago por nombre del representante o estudiante
void buscarPagoApellido() {
    FILE *fptr = fopen("DB/listadoPagos/listaPagos1.txt", "r");
    if (fptr == NULL) {
        puts("No se ha encontrado el archivo de pagos!");
        return;
    }
    
    char criterio[32];
    puts("Ingrese el Apellido del Representante: ");
    scanf("%s", criterio);
    
    char linea[128];
    int encontrado = 0;
    
    while (fgets(linea, 128, fptr)) {
        if (strstr(linea, criterio)) {
            encontrado = 1;
            puts("\nPago encontrado:");
            
            do {
                printf("%s", linea);
            } while (fgets(linea, 128, fptr) && strcmp(linea, "-----------------------------------------------------------------------------------------\n") != 0);
            printf("-----------------------------------------------------------------------------------------\n");
        }
    }
    
    if (!encontrado) {
        printf("No se encontro ningun pago con el criterio '%s'.\n", criterio);
    }
    
    fclose(fptr);
}

void buscarPagoID() {
    FILE *fptr = fopen("DB/listadoPagos/listaPagos1.txt", "r");
    if (fptr == NULL) {
        printf("No se ha encontrado el archivo de pagos!\n");
        return;
    }
    
    char criterio[32];
    printf("Ingrese el ID del Representante o del Estudiante a buscar: ");
    scanf("%s", criterio);
    
    char linea[128];
    int encontrado = 0;
    
    while (fgets(linea, 128, fptr)) {
        if (strstr(linea, criterio)) {
            encontrado = 1;
            printf("\nPago encontrado:\n");
            
            do {
                printf("%s", linea);
            } while (fgets(linea, 128, fptr) && strcmp(linea, "-----------------------------------------------------------------------------------------\n") != 0);
            printf("-----------------------------------------------------------------------------------------\n");
        }
    }
    
    if (!encontrado) {
        printf("No se encontro ningun pago con el criterio '%s'.\n", criterio);
    }
    
    fclose(fptr);
}
//La función strstr en C se utiliza para buscar la primera aparición de una subcadena dentro de una cadena dada
//syntax: strstr(char * str, char * substring);
//Esta funcion va a permitir editar la informacion registrada anteriormente
void modificarPadreFamilia(char *idRepresentante){
	FILE *fptr=fopen("DB\\listadoRepresentante\\listaRepresentantes1.txt", "r");
	FILE *fptr1 = fopen("DB\\listadoRepresentante\\temp.txt", "w");
	char linea[128];
    int encontrado = 0; 
    
    
	while (getchar() != '\n');
    while (fgets(linea, 128, fptr)) {
        // Buscar la línea que contiene el ID del producto
        if (strstr(linea, idRepresentante) && strstr(linea, "ID: ")) {
            encontrado = 1;


            // Pedir nueva información al usuario
            char nuevoNombre[32];
            char nuevoApellido[32];
            char nuevoCP[32];
            char nuevoCS[32];
            char nuevoSector[32];
            char nuevoNombreHijo[32];
            int idRepresentante;
			while (getchar() != '\n');
			
            puts("Representante encontrado. Ingrese los nuevos datos: ");
            puts("Ingrese nuevamente el ID para confirmar");
            scanf("%d", &idRepresentante);
            while (getchar() != '\n');
            puts("Ingrese el nuevo nombre del representante: ");
            fgets(nuevoNombre,32, stdin);
            nuevoNombre[strcspn(nuevoNombre, "\n")] = 0; 
			printf("Ingrese el nuevo apellido del representante: \n");
            fgets(nuevoApellido,32, stdin);
            nuevoApellido[strcspn(nuevoApellido, "\n")] = 0; 
            
			printf("Ingrese el nueva calle principal del domicilio: \n");
            fgets(nuevoCP,32, stdin);
             nuevoCP[strcspn(nuevoCP, "\n")] = 0; 
            
			printf("Ingrese el nueva calle secundaria del domicilio: \n");
            fgets(nuevoSector,32, stdin);
            nuevoCS[strcspn(nuevoCS, "\n")] = 0; 
            
           printf("Ingrese el nuevo sector del representante: \n");
            fgets(nuevoSector,32, stdin);
            nuevoSector[strcspn(nuevoSector, "\n")] = 0; 
            
            printf("Ingrese el nuevo nombre del representado: \n");
            fgets(nuevoNombreHijo,32, stdin);
            nuevoNombreHijo[strcspn(nuevoNombreHijo, "\n")] = 0; 
            
            // Escribir la nueva información en fptr1
            fprintf(fptr1, "ID: %d\n", idRepresentante);
			fprintf(fptr1, "Apellido: %s\n", nuevoNombre);
			fprintf(fptr1, "Nombre: %s\n", nuevoApellido);
			fprintf(fptr1, "Nombre del representado: %s\n", nuevoNombreHijo);
			fprintf(fptr1, "Direccion del domicilio: %s_%s_%s\n", nuevoCP, nuevoCS, nuevoSector);
			fprintf(fptr1, "-----------------------------------------------------------------------------------------\n");

           
            while (fgets(linea, 128, fptr) &&
                   strcmp(linea, "-----------------------------------------------------------------------------------------\n") != 0);
        } else {
            
            fputs(linea, fptr1);
        }
    }

    fclose(fptr);
    fclose(fptr1);

    if (encontrado) {
        remove("DB\\listadoRepresentante\\listaRepresentantes1.txt");
        rename("DB\\listadoRepresentante\\temp.txt", "DB\\listadoRepresentante\\listaRepresentantes1.txt");
        printf("La informacion del representante con ID '%s' ha sido actualizada.\n", idRepresentante);
    } else {
        remove("DB\\listadoRepresentante\\temp.txt"); 
        printf("No se encontro algun representante con el ID %s.\n", idRepresentante);
    }
    getch();
    return;
}
	


	/*	 do {
			printf("%s", linea);
		} while (fgets(linea, 128, fptr1) && strcmp(linea,"-----------------------------------------------------------------------------------------")!=0);
		}
			if(!encontrar){
			printf("Informacion no encontrada\n");
			printf("No se encontro alguna informacion relacionada con el apellido: %s\n", apellidoBuscado);*/



