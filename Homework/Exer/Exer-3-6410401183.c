#include <stdio.h>
void main()
{

    int j, k, *intPtr;
    k = 2;
    intPtr = &k;
    printf("k is stored at % p. \n", &k);
    printf("value of k is % d. \n", k);

    *intPtr += 5;
    printf("value of k is % d. \n",k);

    j = *intPtr;
    j++;
    printf("value of j is % d. \n", j);
    printf("value of k is % d. \n", k);
    printf("value of * intPtr is % d. \n", *intPtr);
}