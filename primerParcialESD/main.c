#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define FILAS_MATRIZ_B 6
#define COLUMNAS_MATRIZ_B 59
#define FILAS_MATRIZ_A 59
#define COLUMNAS_MATRIZ_A 6

char temporal[100];

char ***valores = NULL;
int *campos_por_linea = NULL;

char *pivote = NULL;
char *archivo = NULL;
int lineas = 0;
int campos = 0;
int longitud = 0;
int i, j;
int datos [59][6];
int transponer_datos [6][59];
int producto[FILAS_MATRIZ_A][COLUMNAS_MATRIZ_B];

void leer_archivo_csv(char ubicacion[73]) {
    FILE *archivo = NULL;
    archivo = fopen(ubicacion, "r");
    if (archivo != NULL) {
        do {
            memset(temporal, 0, 100);
            fgets(temporal, 100, archivo);
            lineas++;
            valores = realloc(valores, lineas * sizeof (char*));
            campos_por_linea = realloc(campos_por_linea, lineas * sizeof (int));
            valores[lineas - 1] = NULL;
            pivote = strtok(temporal, ",");
            campos = 0;
            while (pivote != NULL) {
                campos++;
                valores[lineas - 1] = realloc(valores[lineas - 1], sizeof (char*)*campos);
                longitud = strlen(pivote);
                valores[lineas - 1][campos - 1] = calloc(longitud + 1, sizeof (char));
                strncpy(valores[lineas - 1][campos - 1], pivote, longitud);
                pivote = strtok(NULL, ",");
            }
            campos_por_linea[lineas - 1] = campos;
        } while (feof(archivo) == 0);
        fclose(archivo);
    } else {
        printf("Error leyendo el archivo\n");
    }
    return;
}

void generar_matriz() {
    for (int filas = 0; filas < lineas - 2; filas++) {
        for (int columnas = 0; columnas < 6; columnas++) {
            datos[filas][columnas] = strtol(valores[filas + 1][columnas + 1], NULL, 10);
        }
    }
    return;
}

void transponer_matrices() {
    for (int filas = 0; filas < lineas - 2; filas++) {
        for (int columnas = 0; columnas < 6; columnas++) {
            transponer_datos[columnas][filas] = datos[filas][columnas];
        }
    }
    return;
}

void multiplicar_matrices() {
    if (COLUMNAS_MATRIZ_A != FILAS_MATRIZ_B) {
        printf("Columnas de matriz A deben ser igual a filas de matriz B");
        return;
    }

    for (int i = 0; i < FILAS_MATRIZ_A; i++) {
        for (int a = 0; a < COLUMNAS_MATRIZ_B; a++) {
            int suma = 0;
            for (int j = 0; j < COLUMNAS_MATRIZ_A; j++) {
                suma += ((datos[i][j]) * (transponer_datos[j][a]));
            }
            producto[i][a] = suma;
        }
    }
    return;
}

const char* integrantes() {
    return "fa20011";
}

int main(int argc, char** argv) {
    leer_archivo_csv("C:\\Users\\Carito Flores\\Downloads\\DATOS\\peliculasFavoritasESD135_2021.csv");
    generar_matriz();
    transponer_matrices();
    multiplicar_matrices();
    integrantes();
    return (EXIT_SUCCESS);
}

