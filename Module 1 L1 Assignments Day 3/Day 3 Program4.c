#include <stdio.h>

void find_smallest_and_largest_digits(int n, ...) {
    va_list numbers;
    va_start(numbers, n);

    int smallest_digit = 9;
    int largest_digit = 0;
    int valid_count = 0;

    for (int i = 0; i < n; i++) {
        int num = va_arg(numbers, int);
        int temp = num;

        while (temp != 0) {
            int digit = temp % 10;
            if (digit < smallest_digit) {
                smallest_digit = digit;
            }
            if (digit > largest_digit) {
                largest_digit = digit;
            }
            temp /= 10;
        }

        valid_count++;
    }

    va_end(numbers);

    if (valid_count == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallest_digit);
        printf("Largest Digit: %d\n", largest_digit);
    }
}

int main() {
    find_smallest_and_largest_digits(3, 8, 156, 123450);
    return 0;
}