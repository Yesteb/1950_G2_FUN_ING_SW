#include <stdio.h>
#include <stdlib.h>

int main() {
    char nombre[50], apellido[50], fechaPago[20];
    float montoPago;
    FILE *archivo;

    // Solicitar datos del pago
    printf("Ingrese el nombre del cliente: ");
    fgets(nombre, sizeof(nombre), stdin);
    
    printf("Ingrese el apellido del cliente: ");
    fgets(apellido, sizeof(apellido), stdin);
    
    printf("Ingrese la fecha del pago (DD/MM/AAAA): ");
    fgets(fechaPago, sizeof(fechaPago), stdin);
    
    printf("Ingrese el monto a pagar: ");
    scanf("%f", &montoPago);

    // Abrir el archivo en modo de escritura
    archivo = fopen("registro_pensiones.txt", "a");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar los datos.\n");
        return 1;
    }

    // Escribir los datos en el archivo
    fprintf(archivo, "Nombre: %s", nombre);
    fprintf(archivo, "Apellido: %s", apellido);
    fprintf(archivo, "Fecha de Pago: %s", fechaPago);
    fprintf(archivo, "Monto a Pagar: %.2f\n", montoPago);
    fprintf(archivo, "------------------------------------------\n");

    // Cerrar el archivo
    fclose(archivo);

    printf("Datos del pago guardados exitosamente en 'registro_pensiones.txt'.\n");

    return 0;
}

