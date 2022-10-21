#include <stdio.h>

int Ack(int m, int n) {
    if (m == 0) {
        printf("return %d\n", n);
        return n + 1;
    }
    else if (m > 0 && n == 0) {
        return Ack(m - 1, 1);
    }
    else {
        return Ack(m - 1, Ack(m, n - 1));
    }
}

int main(void) {
    printf("%d\n", Ack(2, 3));
}