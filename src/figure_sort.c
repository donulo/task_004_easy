#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int a;
    int b;
} Rectangle;

void input(int* count, Rectangle** rects);
void output(int count, Rectangle* rects);
int square(Rectangle rect);
int rectangleComparer(const void* a, const void* b);
void sort(void* array, int count, size_t size, int (*compare)(const void*, const void*));
void swap(void* a, void* b, size_t size);
void exception();

int main(void) {
    int count;
    Rectangle* rects = NULL;
    input(&count, &rects);
    sort(rects, count, sizeof(Rectangle), rectangleComparer);
    output(count, rects);
}

void input(int* count, Rectangle** rects) {
    if (scanf("%d", count) == 1 && *count > 0) {
        *rects = calloc(*count, sizeof(Rectangle));
        for (int i = 0; i < *count; i++) {
            if (scanf("%d%d%d", &(*rects)[i].index, &(*rects)[i].a, &(*rects)[i].b) != 3) exception();
        }
    } else
        exception();
}

void output(int count, Rectangle* rects) {
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", rects[i].index, square(rects[i]));
    }
    free(rects);
}

int square(Rectangle rect) { return rect.a * rect.b; }

int rectangleComparer(const void* a, const void* b) {
    Rectangle ta = *((Rectangle*)a), tb = *((Rectangle*)b);
    int status;
    status = square(ta) > square(tb) ? 1 : -1;
    if (square(ta) == square(tb)) status = 0;
    // printf("%d: %d > %d\n", status, square(ta), square(tb));
    return status;
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

void exception() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}