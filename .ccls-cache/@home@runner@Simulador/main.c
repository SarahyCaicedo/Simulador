#include <stdio.h>
#include <string.h>

#define MAX 100

int memory[MAX];
char keys[MAX][MAX];
int accumulator = 0;

int get_index(char *key) {
    for (int i = 0; i < MAX; i++) {
        if (strcmp(keys[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

void set_value(char *key, int value) {
    int index = get_index(key);
    if (index == -1) {
        for (int i = 0; i < MAX; i++) {
            if (keys[i][0] == '\0') {
                strcpy(keys[i], key);
                memory[i] = value;
                break;
            }
        }
    } else {
        memory[index] = value;
    }
}

int get_value(char *key) {
    int index = get_index(key);
    if (index != -1) {
        return memory[index];
    }
    return 0;
}

void show_all() {
    printf("Accumulator: %d\n", accumulator);
    for (int i = 0; i < MAX && keys[i][0] != '\0'; i++) {
        printf("%s: %d\n", keys[i], memory[i]);
    }
}

int main() {
    char command[MAX];
    char key[MAX];
    int value;

    FILE *file = fopen("programa4.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo programa1.txt\n");
        return 1;
    }

    while (fscanf(file, "%s", command) != EOF) {
        if (strcmp(command, "END") == 0) {
            break;
        } else if (strcmp(command, "SET") == 0) {
            fscanf(file, "%s %d", key, &value);
            set_value(key, value);
        } else if (strcmp(command, "SHW") == 0) {
            fscanf(file, "%s", key);
            printf("%d\n", get_value(key));
        } else if (strcmp(command, "ADD") == 0) {
            char key2[MAX];
            fscanf(file, "%s %s", key, key2);
            accumulator += get_value(key) + get_value(key2);
        } else if (strcmp(command, "LDR") == 0) {
            fscanf(file, "%s", key);
            accumulator = get_value(key);
        } else if (strcmp(command, "INC") == 0) {
            fscanf(file, "%s", key);
            set_value(key, get_value(key) + 1);
        } else if (strcmp(command, "DEC") == 0) {
            fscanf(file, "%s", key);
            set_value(key, get_value(key) - 1);
        } else if (strcmp(command, "STR") == 0) {
            fscanf(file, "%s", key);
            set_value(key, accumulator);
            accumulator = 0;
        } else if (strcmp(command, "PAUSE") == 0) {
            show_all();
        }
    }

    fclose(file);

    return 0;
}