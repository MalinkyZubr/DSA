#include <stdio.h>
#include <string.h>

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
char flag_glob[30];

void xorString(char* str, double key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = str[i] ^ (int)key;
    }
}

int compute(int x) {
    return x * x * x - 6 * x * x + 12 * x - 8;
}

int main() {
    int x;
    char flag[] = "dnceyvjkq]kq]c]vgor]dnce\x7f";

    memset(flag_glob, 0, 30);
    memcpy(flag_glob, flag, strlen(flag));

    printf("Enter a value for x: ");
    scanf("%d", &x);
    
    // check if x is in a
    int found = 0;
    for (int i = 0; i < 10; i++) {
        if (x == a[i]) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("fail\n");
        return 0;
    }

    if (compute(x) == 0) {
        xorString(flag, x);
        printf("Here is your flag: %s\n", flag);
    } else {
        printf("fail\n");
    }
    return 0;
}