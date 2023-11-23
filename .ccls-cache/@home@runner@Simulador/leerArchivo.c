#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escribirArchivo(char *value); 

void leerArchivo() {
    char fileName[100];
    printf("Ingrese el nombre del archivo: ");
    scanf("%s", fileName);
    FILE *archivo = fopen(strcat(fileName, ".txt"), "r");
    char line[256];
    int accumulator = 0;

    struct KeyValuePair {
        char key[20];
        int value;
    };
    struct KeyValuePair memory[100];

    if (archivo != NULL) {
        while (fgets(line, sizeof(line), archivo)) {
            char *token;
            token = strtok(line, " \n");
            int count = 0;
            char *palabras[4];

            while (token != NULL) {
                palabras[count++] = token;
                token = strtok(NULL, " \n");
            }

            // Operación SET
            if (count >= 3 && strcmp(palabras[0], "SET") == 0) {
                int value = atoi(palabras[2]);
                strcpy(memory[value].key, palabras[1]);
                memory[value].value = value;
            }

            // Operación SHOW
            if (count >= 2 && strcmp(palabras[0], "SHW") == 0) {
                int value = memory[atoi(palabras[1])].value;
                printf("%d\n", value);
                char show[20];
                sprintf(show, "%d", value);
                escribirArchivo(show);
            }

          // Operación ADD
          if (count >= 3 && strcmp(palabras[0], "ADD") == 0) {
              int accumulator_value = accumulator;
              int value;

              if (strcmp(palabras[2], "NULL") == 0 && strcmp(palabras[3], "NULL") == 0) {
                  value = memory[atoi(palabras[1])].value;
                  accumulator = accumulator_value + value;
              } else if (strcmp(palabras[2], "NULL") != 0 && strcmp(palabras[3], "NULL") == 0) {
                  int value2 = memory[atoi(palabras[2])].value;
                  accumulator = accumulator_value + value2;
              } else if (strcmp(palabras[2], "NULL") != 0 && strcmp(palabras[3], "NULL") != 0) {
                  int value1 = memory[atoi(palabras[1])].value;
                  int value2 = memory[atoi(palabras[2])].value;
                  int suma = value1 + value2;
                  memory[atoi(palabras[3])].value = suma;
              }
          }

          // Operación LDR
          if (count >= 2 && strcmp(palabras[0], "LDR") == 0) {
              accumulator = memory[atoi(palabras[1])].value;
          }

          // Operación MUL
          if (count >= 3 && strcmp(palabras[0], "MUL") == 0) {
              int accumulator_value = accumulator;
              int value;

              // Implementación similar a las operaciones anteriores (ADD) pero para la multiplicación
              // ...
          }

          // Operación SUB
          // Implementación similar a las operaciones anteriores (ADD, MUL) pero para la resta

          // Operación DIV
          // Implementación similar a las operaciones anteriores (ADD, MUL) pero para la división

          // Operación INC
          // Implementación similar a las operaciones anteriores para incrementar

          // Operación DEC
          // Implementación similar a las operaciones anteriores para decrementar

          // Operación MOV
          // Implementación similar a las operaciones anteriores para mover valores

          // Operación STR
          // Implementación similar a las operaciones anteriores para almacenar valores

        }
        fclose(archivo);
    }
}

void escribirArchivo(char *value) {
    char shw[20];
    strcpy(shw, value);
    char fileName[100];
    time_t timeP = time(NULL);
    srand((unsigned int)timeP);

    int randomNumber = rand() % 10000;

    sprintf(fileName, "exit_%d.txt", randomNumber);

    FILE *archivo = fopen(fileName, "w");

    if (archivo != NULL) {
        fprintf(archivo, "%s\n", shw);
        fclose(archivo);
    }
}

int main() {
    leerArchivo();
    return 0;
}