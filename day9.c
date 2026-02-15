//Problem: A secret system stores code names in forward order. 
//To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order


#include <stdio.h>

void reverse(char str[]) {
    if (str[0] == '\0')   // Base case: end of string
        return;

    reverse(str + 1);     // Recursive call
    printf("%c", str[0]); // Print while returning
}

int main() {
    char str[100];

    scanf("%s", str);

    reverse(str);

    return 0;
}