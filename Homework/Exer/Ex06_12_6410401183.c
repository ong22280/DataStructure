// Sittipong Hemloun 6410401183
// Tail Recursion Sequence a = {2,5,8,11,14,...}

#include <stdio.h>

int tail_recursion_seq(int n, int a) {
    if (n == 1) {
        return a;
    }
    else {
        return tail_recursion_seq(n - 1, a + 3);
    }
}

int main(void) {
    printf("a(n) = a(n-1) + 3 ,a(1) = 2\n");
    while (1) {
        int n;
        printf("n = ");
        scanf("%d", &n);
        printf("%d\n", tail_recursion_seq(n, 2));
    }
}