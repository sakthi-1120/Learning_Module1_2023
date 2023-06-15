#include <stdio.h>

int main() {
    int arr[100];
    int size, sum = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i += 2) {
        sum += arr[i];
    }

    printf("Sum of alternate elements: %d\n", sum);

    return 0;
}
