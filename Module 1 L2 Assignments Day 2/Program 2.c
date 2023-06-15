#include <stdio.h>

int compareBoxes(int boxA[], int boxB[], int size) {
    int count[size]; // Array to track the count of each item in boxA

    // Initialize count array with zeros
    for (int i = 0; i < size; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each item in boxA
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (boxA[i] == boxB[j]) {
                count[i]++;
                break; // Exit inner loop after finding a match
            }
        }
    }

    // Check if each item in boxA has a one-to-one mapping in boxB
    for (int i = 0; i < size; i++) {
        if (count[i] != 1) {
            return 0; // Not a one-to-one mapping
        }
    }

    return 1; // One-to-one mapping found
}

int main() {
    int size = 3;
    int boxA[] = {200, 10, -90};
    int boxB[] = {-90, 200, 10};

    int result = compareBoxes(boxA, boxB, size);

    printf("Result: %d\n", result);

    return 0;
}
