#include <stdio.h>

int extractDigits(int number, int digits[]) {
    int count = 0;
    while (number > 0) {
        digits[count++] = number % 10;
        number /= 10;
    }
    return count;
}

int isFriend(int a, int b) {
    int aDigits[10] = {0};
    int bDigits[10] = {0};
    int aCount = extractDigits(a, aDigits);
    int bCount = extractDigits(b, bDigits);

    for (int i = 0; i < aCount; i++) {
        for (int j = 0; j < bCount; j++) {
            if (aDigits[i] == bDigits[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int end, counter = 0;
    printf("Enter the end value: ");
    scanf("%d", &end);

    for (int i = 1; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            counter += isFriend(i, j);
        }
    }

    printf("%d friends found in the interval 1 .. %d.\n", counter, end);

    return 0;
}
