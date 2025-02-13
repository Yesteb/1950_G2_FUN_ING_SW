#include "functions.h"


int main(){
	int opc, opc1;
	char idRepresentante[32];
		
	IniciarSesion();

	while(1){
		
		imprimirArchivos("DB\\menu.txt", 244);
		scanf("%d", &opc);
		switch(opc){
			case 1:
				RegistroPadreFamilia();
				getch();
				break;
			case 2:
				RegistrarPagos();
				getch();
				break;
			case 3:
				puts("Ingrese el ID del Representante que desea actualizar: ");
				scanf("%31s", idRepresentante);
				modificarPadreFamilia(idRepresentante);
				getch();
				break;
			case 4:
				buscarRepresentante();
				getch();
				break;
			case 5:
				buscarPago();
				getch();
				break;
			case 6:
				return 0;
			default:
				printf("Opcion Invalida. ...");
				getch();
				return;
		}
	}
	
	
	printf("\n\nPresione una tecla para salir ...");
	getch();
	return 0;	
}
	
	

