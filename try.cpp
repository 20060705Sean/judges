#include <stdio.h>
#include <string.h>

int main() {
    char str1[32] = "hello world";
    memset(str1, '\0', 32); // or memset(str1, 0, 32);
    printf("%s\n", str1);

    printf("---\n");

    char str2[] = "hello world";
    memset(str2, 'a', 3);
    printf("%s\n", str2);

    printf("---\n");

    char str3[] = "hello world";
    memset(str3+5, 0, 6);
    printf("%s\n", str3);
    return 0;
}
