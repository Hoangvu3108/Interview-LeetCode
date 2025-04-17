#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int romanToInt(char* s) {
    int total = 0;
        int prevValue = 0;
    
        // Duyệt qua từng ký tự trong chuỗi từ phải sang trái
        for (int i = strlen(s) - 1; i >= 0; i--) {
            int currentValue;
    
            // Xác định giá trị của ký tự La Mã
            switch (s[i]) {
                case 'I': currentValue = 1; break;
                case 'V': currentValue = 5; break;
                case 'X': currentValue = 10; break;
                case 'L': currentValue = 50; break;
                case 'C': currentValue = 100; break;
                case 'D': currentValue = 500; break;
                case 'M': currentValue = 1000; break;
                default: currentValue = 0; // Ký tự không hợp lệ
            }
            //Duyệt qua từng ký tự trong chuỗi từ phải sang trái
            // Nếu giá trị hiện tại nhỏ hơn giá trị trước đó, trừ nó
            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                // Nếu không, cộng nó
                total += currentValue;
            }
    
            // Cập nhật giá trị trước đó
            prevValue = currentValue;
        }
    
        return total;
    }


int main ()
{
    char s[100];
    printf("Enter a Roman numeral:");
    scanf("%s", s);
    int result = romanToInt(s);
    printf("The integer value is: %d\n", result);
    return 0;
}