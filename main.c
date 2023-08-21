#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_menu(int, int, int**);
void fill_with_random(int, int, int**);
int highest_value(int, int, int**, char);
int** create_matrix(int, int);

int main() {
    int columns = 0, rows = 0, running = 0;
    char choise;

    printf("Para crear su matriz aleatoria\n");
    printf("Ingrese fila: "); scanf("%d", &rows);
    printf("Ingrese columna: "); scanf("%d", &columns);

    int** matrix = create_matrix(rows, columns);
    fill_with_random(rows, columns, matrix);
    print_menu(rows, columns, matrix);

    while (!running) {
        choise = getchar();

        switch (choise) {
        case 'f':
            printf("El mayor en esta fila es %d\n", highest_value(rows, columns, matrix, 'f'));
            break;
        case 'c':
            printf("El mayor en esta columna es %d\n", highest_value(rows, columns, matrix, 'c'));
            break;
        case 'q':
            running = 1;
            break;
        default:
            break;
        }
    }

    exit(0);
}

void print_menu(int rows, int columns, int **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Escribe 'c' para seleccionar columna\nEscribe 'f' para seleccionar fila\nEscribe 'q' si quieres salir\n");
}

void fill_with_random(int rows, int columns, int **matrix) {
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 1 + rand() % 100;
        }
    }
}

int highest_value(int rows, int columns, int **matrix, char option) {
    int input = 0, pivot = 0;

    if (option == 'c') {
        printf("Que numero de columna quieres? [%d-%d]: ", 0, columns -1);
        scanf("%d", &input);
        pivot = matrix[0][input];
        for (int i = 1; i < rows; i++) {
            if (pivot < matrix[i][input]) {
                pivot = matrix[i][input];
            }
        }
    }

    if (option == 'f') { 
        printf("Que numero de fila quieres? [%d-%d]: ", 0, rows -1);
        scanf("%d", &input);
        pivot = matrix[input][0];
        for (int i = 1; i < columns; i++) {
            if (pivot < matrix[input][i]) {
                pivot = matrix[input][i];
            }
        }
    }

    return pivot;
}

int** create_matrix(int rows, int columns) {
    int** matrix = malloc(sizeof(int) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(sizeof(int) * columns);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}
