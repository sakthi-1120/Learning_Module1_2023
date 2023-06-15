#include <stdio.h>
#include <string.h>

void sortNames(char names[][100], int size) {
    char temp[100];
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main() {
    int size;

    printf("Enter the number of names: ");
    scanf("%d", &size);

    char names[size][100];

    printf("Enter the names:\n");
    for (int i = 0; i < size; i++) {
        scanf("%s", names[i]);
    }

    sortNames(names, size);

    printf("Names in alphabetical order:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
