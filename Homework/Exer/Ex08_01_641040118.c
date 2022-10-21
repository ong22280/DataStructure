#include <stdio.h>

int stack_balancing_symbols(char *s) {
    int i = 0;
    int stack[100];
    int top = -1;
    int balanced = 1;
    while (s[i] != '\0') {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            top++;
            stack[top] = s[i];
        } else if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
            if (top == -1) {
                balanced = 0;
                break;
            } else {
                top--;
            }
        }
        i++;
    }
    if (top != -1) {
        balanced = 0;
    }
    return balanced;
}


int main() {

    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    if (stack_balancing_symbols(s)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}