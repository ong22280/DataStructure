// Sittipong Hemloun 6410401183
// Recursion Sequence a = {2,5,8,11,14,...}

#include <stdio.h>

int linear_recursion_seq(int n) {
    if (n == 1) {
        return 2;
    }
    else {
        return linear_recursion_seq(n - 1) + 3;
    }
}

int main(void) {
    printf("a(n) = a(n-1) + 3 ,a(1) = 2\n");
    while (1) {
        int n;
        printf("n = ");
        scanf("%d", &n);
        printf("%d\n", linear_recursion_seq(n));
    }
}