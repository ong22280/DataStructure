#include <stdio.h>

long long int fibonacci(long long int n) {
  long long int i;
  long long int t1 = 0, t2 = 1;
  long long int nextTerm = t1 + t2;

  if (n == 0) {
    return 0;
  } 
  else if (n == 1) {
    return 1;
  } 
  else {
    for (i = 2; i <= n; i++) {
      nextTerm = t1 + t2;
      t1 = t2;
      t2 = nextTerm;
    }
    return nextTerm;
  }
}

int main(void) {
    long long int n;
    scanf("%lli", &n);
    for (long long int i = 0; i < n; i++) {
        printf("%llu\n", fibonacci(i));
    }
    return 0;
}