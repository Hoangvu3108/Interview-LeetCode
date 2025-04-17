#include <stdio.h>

void intToRoman(int num) {
    // Mảng giá trị La Mã
    int values[] =    {1000, 900, 500, 400, 100, 90,  50, 40,  10,  9,   5,  4,  1};
    char* numerals[] = {"M", "CM", "D", "CD", "C","XC","L","XL","X","IX","V","IV","I"};

    int i = 0;
    while (num > 0) {
        while (num >= values[i]) {
            printf("%s", numerals[i]);
            num -= values[i];
        }
        i++;
    }
}

int main() {
    int number;
    printf("Nhap so nguyen can doi sang so La Ma: ");
    scanf("%d", &number);

    printf("So La Ma tuong ung: ");
    intToRoman(number);
    printf("\n");

    return 0;
}
