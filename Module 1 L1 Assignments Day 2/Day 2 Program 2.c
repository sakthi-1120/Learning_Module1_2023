#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main() {
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(&x, &y, sizeof(int));

    printf("After swap: x = %d, y = %d\n", x, y);

    double a = 3.14, b = 2.71828;
    printf("Before swap: a = %f, b = %f\n", a, b);

    swap(&a, &b, sizeof(double));

    printf("After swap: a = %f, b = %f\n", a, b);

    return 0;
}