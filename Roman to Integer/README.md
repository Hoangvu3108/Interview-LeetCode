Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
**Ý tưởng chính**
- Duyệt ký tự từ cuối cùng đến ký tự đầu tiên, điều này giúp xử lý các trường hợp trừ như **IV** và **IX** dễ dàng hơn, vì bạn có thể so sánh ký tự hiện tại với ký tự trước đó. 
- Xác định giá trị của ký tự La Mã : Sử dụng Switch để gán giá tri tương ứng cho từng ký tự La Mã
- Cộng hoặc trừ giá trị so sánh CurrentValue với PreValue nếu currentValue < preValue thì trừ, ví dụ:
```c
IV = 5 - 1 = 4
IX = 10 - 1 = 9
``` 
- Nếu currentValue >= preValue thì sẽ cộng 
```c
VI = 5 + 1 = 6
XIII = 10 + 1 + 1 + 1 = 13
```

```c
****#include <stdio.h>
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
```
**Bài toán viết số quy đổi thành số La Mã**
**Ý tưởng chính**
Tạo ra một mảng giá trị La Mã với một mảng ký tự có cùng vị trí rồi so sánh  việc yêu cầu nhập num để so sánh với các giá trị có trong mảng giá trị nếu lơn hơn thì trừ biến num với giá trị ngay trước đó và cộng biến đêm i lên một khi đã i vào trong mảng
```c
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

```
