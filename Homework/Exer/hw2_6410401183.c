// Sittipong Hemloun 6410401183

#include <stdio.h>

int main()
{
    typedef struct
    {
        char name[20];
        int score;
    } Student;

    Student s[5];

    double total = 0.0;
    int count = 0;

    printf("5 students' scores:\n");
    int i = 0;
    while (i < 5)
    {
        printf("Name's student: ");
        scanf("%s", s[i].name);
        printf("Enter score: ");
        scanf("%d", &s[i].score);
        total += s[i].score;
        count++;
        i++;
    }

    double average = total / count;
    printf("Average: %.2f\n", average);

    i = 0;
    while (i < 5)
    {
        if (s[i].score > average)
        {
            printf("%s is above average (%d)\n", s[i].name, s[i].score);
        }
        i++;
    }

    return 0;
}