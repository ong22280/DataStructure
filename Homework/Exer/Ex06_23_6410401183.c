// Sittipong Hemloun 6410401183
#include <stdio.h>

int count = 0;
void hanoi(int n, char A,char B,char C) {
	if(n==1) {
        count++;
        printf("move#%d:move(%c,%c,%c)\n",count, A, B, C);
    }
	else {
		hanoi(n-1,A,C,B);
		hanoi(1,A,B,C);
		hanoi(n-1,B,A,C);
	}
}

int main(void) {
    int N = 3;
    printf("Input N = %d\n", N);
    printf("Output:\n");
    hanoi(N, 'A', 'B', 'C');
}