#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void swapFields(struct Person* person1, struct Person* person2) {
    struct Person temp;

    // Swap name field
    strcpy(temp.name, person1->name);
    strcpy(person1->name, person2->name);
    strcpy(person2->name, temp.name);

    // Swap age field
    int tempAge = person1->age;
    person1->age = person2->age;
    person2->age = tempAge;
}

int main() {
    struct Person person1 = { "John", 25 };
    struct Person person2 = { "Alice", 30 };

    printf("Before swapping:\n");
    printf("Person 1: Name - %s, Age - %d\n", person1.name, person1.age);
    printf("Person 2: Name - %s, Age - %d\n", person2.name, person2.age);

    // Swap the fields of person1 and person2
    swapFields(&person1, &person2);

    printf("\nAfter swapping:\n");
    printf("Person 1: Name - %s, Age - %d\n", person1.name, person1.age);
    printf("Person 2: Name - %s, Age - %d\n", person2.name, person2.age);

    return 0;
}