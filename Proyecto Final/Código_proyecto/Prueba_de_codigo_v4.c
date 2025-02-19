#include <stdio.h>
#include <stdlib.h>

int main() {
    char nombrePadre[50], apellidoPadre[50], direccion[100], nombreHijo[50];
    FILE *archivo;

    // Se solicitar datos del padre de familia
    printf("Ingrese el nombre del padre de familia: ");
    fgets(nombrePadre, sizeof(nombrePadre), stdin);
    
    printf("Ingrese el apellido del padre de familia: ");
    fgets(apellidoPadre, sizeof(apellidoPadre), stdin);
    
    printf("Ingrese la direccion del padre de familia: ");
    fgets(direccion, sizeof(direccion), stdin);
    
    printf("Ingrese el nombre del hijo: ");
    fgets(nombreHijo, sizeof(nombreHijo), stdin);

    // Se Abrira el archivo en modo de escritura
    archivo = fopen("registro_padres.txt", "a");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar los datos.\n");
        return 1;
    }

    // Escribir los datos en el archivo
    fprintf(archivo, "Nombre del Padre: %s", nombrePadre);
    fprintf(archivo, "Apellido del Padre: %s", apellidoPadre);
    fprintf(archivo, "Direccion: %s", direccion);
    fprintf(archivo, "Nombre del Hijo: %s", nombreHijo);
    fprintf(archivo, "------------------------------------------\n");

    // Cerrar el archivo
    fclose(archivo);

    printf("Datos guardados exitosamente en 'registro_padres.txt'.\n");

    return 0;
}

