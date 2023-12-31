#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    int n, i;
    struct Student* students;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    students = (struct Student*)malloc(n * sizeof(struct Student));
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]s", students[i].name);

        printf("Enter age: ");
        scanf("%d", &students[i].age);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\nData for %d students:\n", n);
    for (i = 0; i < n; i++) {
        printf("\nDetails for Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}