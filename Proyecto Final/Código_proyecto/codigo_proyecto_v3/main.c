#include "functions.h"


int main(){
	int opc, opc1;

	//IniciarSesion();
	
	//menu
	while(1){
		
		imprimirArchivo("DB\\menu.txt", 256);
		scanf("%d", &opc);
		switch(opc){
			case 1:
				RegistroPadreFamilia();
				break;
			case 2:
				RegistrarPagos();
				break;
			case 3:
				imprimirArchivo("DB\\listadoPadres\\listaPadres1.txt", 16384);
				getch();
				break;
			case 4:
				modificarPadreFamilia();
				break;
			case 5:
				imprimirArchivo("DB\\listadoPagos\\listaPagos1.txt", 16384);
				getch();
				break;
			case 7:
				return 0;
			default:
				printf("Opcion Invalida. ...");
				return;
		}
	}
	
	
	printf("\n\nPresione una tecla para salir ...");
	getch();
	return 0;	
}
	
	

