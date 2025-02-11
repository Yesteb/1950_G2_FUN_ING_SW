#include "functions.h"


int main(){
	int opc, opc1;
	char idRepresentante[32];
	IniciarSesion();
	
	
	while(1){
		
		imprimirArchivo("DB\\menu.txt", 256);
		scanf("%d", &opc);
		while (getchar() != '\n');
		switch(opc){
			case 1:
				RegistroPadreFamilia();
				break;
			case 2:
				RegistrarPagos();
				break;
			case 3:
				imprimirArchivo("DB\\listadoRepresentante\\listaRepresentantes1.txt", 16384);
				printf("Ingrese el ID del producto que desea actualizar: ");
				scanf("%31s", idRepresentante);
				modificarPadreFamilia(idRepresentante);
				break;
			case 4:
				buscarRepresentante();
				break;
			case 5:
				buscarPago();
				getch();
				break;
			case 6:
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
	
	

