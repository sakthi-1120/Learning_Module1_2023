#include <stdio.h>

char* xstrchr(const char* str, char ch) {
    while (*str != '\0') {
        if (*str == ch) {
            return (char*)str;  // Found the character, return the pointer
        }
        str++;
    }
    return NULL;  // Character not found, return NULL
}

int main() {
    const char* str = "Hello, World!";
    char ch = 'o';

    char* result = xstrchr(str, ch);
    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", ch, result - str);
    } else {
        printf("Character '%c' not found in the string.\n", ch);
    }

    return 0;
}
