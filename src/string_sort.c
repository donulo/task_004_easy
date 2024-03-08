#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1025

int input(char string[MAX_LENGTH], int* itemMenu);
void output(char string[MAX_LENGTH]);
void menu(char string[MAX_LENGTH], int itemMenu);
int charComparer(const void* a, const void* b);
void sort(void* array, int count, size_t size, int (*compare)(const void*, const void*));
void swap(void* a, void* b, size_t size);
void reverse(char string[MAX_LENGTH]);
void exception();

int main() {
    char string[MAX_LENGTH];
    int itemMenu = 0;
    input(string, &itemMenu) ? menu(string, itemMenu), output(string) : exception();
}

int input(char string[MAX_LENGTH], int* itemMenu) {
    int status = 0;
    if (scanf("%1024s %d", string, itemMenu) == 2) status = 1;
    return status;
}

void output(char string[MAX_LENGTH]) { printf("%s", string); }

void menu(char string[MAX_LENGTH], int itemMenu) {
    switch (itemMenu) {
        case 1:
            sort(string, strlen(string), sizeof(char), charComparer);
            break;
        case 2:
            sort(string, strlen(string), sizeof(char), charComparer);
            reverse(string);
            break;
        default:
            exception();
    }
}

int charComparer(const void* a, const void* b) {
    const char *ta = a, *tb = b;
    return strcmp(ta, tb);
}

void sort(void* array, int count, size_t size, int (*compare)(const void*, const void*)) {
    char* buffer = array;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (compare((buffer + i * size), (buffer + j * size)) > 0)
                swap((buffer + i * size), (buffer + j * size), size);
        }
    }
}

void swap(void* a, void* b, size_t size) {
    char *p = a, *q = b;
    for (size_t i = 0; i != size; ++i) {
        char temp;
        temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}

void reverse(char string[MAX_LENGTH]) {
    char reverse[MAX_LENGTH] = {0};
    int count = 0;
    for (int i = strlen(string) - 1; i >= 0; --i) {
        reverse[count++] = string[i];
    }
    strcpy(string, reverse);
}

void exception() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}