// Sittipong Hemloun 6410401183

#include <stdio.h>
int main()
{
    char dest[20], src[20];
    unsigned int num;
    unsigned int i = 0;
    unsigned int j = 0;

    printf("Enter the destination string: ");
    scanf("%s", dest);
    printf("Enter the source string: ");
    scanf("%s", src);
    printf("Enter the number: ");
    scanf("%u", &num);

    while (dest[i] != '\0')
    {
        i++;
    }

    while (j < num && src[j] != '\0')
    {
        dest[i + j] = src[j];
        j++;
    }

    dest[i + j] = '\0';

    printf("After concatenation: %s\n", dest);
}