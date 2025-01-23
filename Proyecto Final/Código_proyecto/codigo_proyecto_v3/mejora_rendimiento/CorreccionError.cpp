#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	char *nombrePadre;
	char *apellidoPadre;
	char *direccionCP;
	char *nombreHijo;
	char *direccionCS;
	char *sector;
	
}infoRegistroPd;

char*** leerArchivoCSV(const char* filepath, char sep, int numColumnas, int* numFilas) {
    FILE *f = fopen(filepath, "r");
    if (!f) {
        perror("Error opening file");
        return NULL;
    }

    // Contar el número de filas en el archivo CSV
    char line[1024];
    *numFilas = 0;
    while (fgets(line, sizeof(line), f)) {
        (*numFilas)++;
    }

    // Asignar memoria para la matriz CSV
    char ***csv = (char ***)malloc(*numFilas * sizeof(char **));
    for (int i = 0; i < *numFilas; i++) {
        csv[i] = (char **)malloc(numColumnas * sizeof(char *));
        for (int j = 0; j < numColumnas; j++) {
            csv[i][j] = NULL; // Inicializamos a NULL para usar realloc más tarde
        }
    }

    // Volver al principio del archivo para leer las líneas
    rewind(f);

    // Leer las líneas y separarlas por el delimitador
    int fila = 0;
    while (fgets(line, sizeof(line), f)) {
        char *token = strtok(line, &sep);
        int columna = 0;
        while (token != NULL && columna < numColumnas) {
            // Asignar memoria dinámicamente para cada campo
            csv[fila][columna] = (char *)malloc((strlen(token) + 1) * sizeof(char)); // +1 para el '\0'
            strncpy(csv[fila][columna], token, strlen(token) + 1);
            token = strtok(NULL, &sep);
            columna++;
        }
        fila++;
    }

    fclose(f);
    return csv;
}

void liberarCsv(char ***csv, int numFilas, int numColumnas) {
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            free(csv[i][j]);
        }
        free(csv[i]);
    }
    free(csv);
}

int encontrarPorNombre(infoRegistroPd padres[], int n, char* criteria){
	for (int i = 0; i < n; i++) {
		if (strcmp(padres[i].nombrePadre, criteria) == 0){
			return i;
		}
    }
	return -1;
}

int encontrarPorApellido(infoRegistroPd padres[], int n, char* criteria){
	for (int i = 0; i < n; i++) {
		if (strcmp(padres[i].apellidoPadre, criteria) == 0){
			return i;
		}
    }
	return -1;
}


int encontrarPorNombreApellido(infoRegistroPd padres[], int n, char* nombre, char* apellido){
	for (int i = 0; i < n; i++) {
		if (strcmp(padres[i].nombrePadre, nombre) == 0 && strcmp(padres[i].apellidoPadre, apellido) == 0){
			return i;
		}
    }
	return -1;
}

char* padre2Csv(infoRegistroPd padres[], int n ){
	// LOGCA ARCTHIVO "W"
	for (int i = 0; i < n; i++) {
		padres[i].nombrePadre + ";"  asd
    }
}

int main() {
    int numFilas, numColumnas = 6;
    char ***csv = leerArchivoCSV("DB1\\listadoPadres2.csv", ';', numColumnas, &numFilas);
    
    infoRegistroPd padres[numFilas];

    if (csv) {
        // Imprimir el contenido del CSV como ejemplo
        for (int i = 0; i < numFilas; i++) {
            //for (int j = 0; j < num_cols; j++) {
            //    printf("%s ", csv[i][j]);
            //}
            printf("\n");
            padres[i].nombrePadre = csv[i][0];
            padres[i].apellidoPadre = csv[i][1];
            padres[i].nombreHijo = csv[i][2];
            padres[i].direccionCP = csv[i][3];
            padres[i].direccionCS = csv[i][4];
            padres[i].sector = csv[i][5];
        }

        // Liberar la memoria asignada
        //free_csv(csv, num_rows, num_cols);
    }
    
    for (int i = 0; i < numFilas; i++) {
            printf("Nombre: %s, Apellido: %s\n",padres[i].nombrePadre, padres[i].apellidoPadre );
    }
    
    printf("%d\n", encontrarPorNombre(padres, numFilas, "Gabriel"));
    printf("%d\n", encontrarPorApellido(padres, numFilas, "Bastidas"));
    
    // Busco id del padre a modificar en base a su nombre y apellido
    int idPadreEncontrado = encontrarPorNombreApellido(padres, numFilas, "Cristian", "Bastidas");
    printf("Padre encontrado en: %d\n", idPadreEncontrado);
    
    // Como ya tengo el id, puedo setear rapidamente lo que quiero cambiar
    padres[idPadreEncontrado].apellidoPadre = "Verduga";
    
    // Imprimo
    for (int i = 0; i < numFilas; i++) {
            printf("Nombre: %s\tApellido: %s\n",padres[i].nombrePadre, padres[i].apellidoPadre );
    }
    
    liberarCsv(csv, numFilas, numColumnas);
    return 0;
}


