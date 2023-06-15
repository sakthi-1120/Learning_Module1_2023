#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

char* encode_string(const char* string) {
    char* encoded_string = (char*)malloc(strlen(string) * sizeof(char));
    strcpy(encoded_string, string);

    // Create a mapping of characters to random symbols
    char symbols[MAX_LENGTH];
    strcpy(symbols, string);
    srand(time(0));
    for (int i = strlen(symbols) - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        char temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }

    // Encode the string using the mapping
    for (int i = 0; i < strlen(encoded_string); ++i) {
        for (int j = 0; j < strlen(symbols); ++j) {
            if (encoded_string[i] == symbols[j]) {
                encoded_string[i] = j;
                break;
            }
        }
    }

    return encoded_string;
}

char* decode_string(const char* encoded_string, const char* symbols) {
    char* decoded_string = (char*)malloc(strlen(encoded_string) * sizeof(char));
    strcpy(decoded_string, encoded_string);

    // Decode the string using the mapping
    for (int i = 0; i < strlen(decoded_string); ++i) {
        if (decoded_string[i] >= 0 && decoded_string[i] < strlen(symbols)) {
            decoded_string[i] = symbols[decoded_string[i]];
        }
    }

    return decoded_string;
}

int main() {
    char original_string[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(original_string, sizeof(original_string), stdin);
    original_string[strcspn(original_string, "\n")] = '\0';

    char* encoded_string = encode_string(original_string);
    printf("Encoded String: %s\n", encoded_string);

    char symbols[MAX_LENGTH];
    strcpy(symbols, original_string);
    char* decoded_string = decode_string(encoded_string, symbols);
    printf("Decoded String: %s\n", decoded_string);

    free(encoded_string);
    free(decoded_string);

    return 0;
}
