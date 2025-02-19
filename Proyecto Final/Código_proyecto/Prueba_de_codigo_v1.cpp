#include <stdio.h>
#include <string.h>

void IniciarSesion(){
	
	char passwordSave[20]=("blanca_hicaiza32.");
	char usuarioSave[10]=("blanca");
	char usuario[8];
	char password[12];
	
	printf("USUARIO: ");
	scanf("%s", usuario);
	printf("PASSWORD: ");
	scanf("%s", password);
	
	if(strcmp(usuarioSave, usuario)==0){
		printf("Su usuario es correcto\n");
	} else{
		printf("Su usuario es incorrecto\n");
	}
	
	if(strcmp(passwordSave, password)==0){
		printf("Su password es correcto");
	} else {
		printf("Su password es incorrecta");
	}

	
}

void menu(){
	printf("\n");
	printf("//Bienvenido...//");
	printf("1. REGISTRAR PADRE DE FAMILIA");
	printf("2. REGISTRAR PAGOS");
	printf("3. LISTA DE PADRES DE FAMILIA");
	printf("4. MODIFICAR INFORMACION DE PADRES DE FAMILIA")
	printf("5. HISTORIAL DE PAGOS");
	printf("6. ELIMINAR PADRE DE FAMILIA");
}

void RegistroPadreFamilia(){
	FILE *fptr; 
	
	char nombrePadre[50];
	char direccion[50];
	char nombreHijo[50];
	
	printf("Ingrese el nombre y apellido: ");
	scanf("%50s", nombrePadre);
	printf("Ingrese la direccion de domicilio: ");
	scanf("%50s", direccion);
	printf("Ingrese el nombre del estudiante representado: ");
	scanf("%50s", nombreHijo);
	
	fptr=fopen("C:\\Users\\G406\\Downloads", "w");
	
	fprintf(fptr, "%50s", nombrePadre);
	fprintf(fptr, "%50s", direccion);
	fprintf(fptr, "%50s", nombreHijo);
	
	fclose(fptr);
	
	
}

void RegistrarPagos(){
	File *fptr1;
	
	float pago;
	char nombrePadre[50];
	char fecha[10];
	
	printf("Ingrese el nombre del padre de familia: ");
	scanf("%50s", nombrePadre);
	printf("Ingrese la fecha del pago realizado: ");
	scanf("%50", fecha);
	printf("Ingrese el pago realizado: ");
	scanf("%d", &pago);
	
	fptr1=fopen("C:\\Users\\G406\\Downloads", "w");
	
	fprintf(fptr1, "%50s", nombrePadre);
	fprintf(fptr1, "%50s", fecha);
	fprintf(fptr1, "%d", pago);
	
	fclose(fptr1);
	
}
int main(){
	return 0;
}
