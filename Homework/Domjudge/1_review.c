#include <stdio.h>

typedef struct {
    int id;
    float score;
    char name[100];
} people;

int main()
{
    // set number of reviews
    int numberOfReviews;
    scanf("%d", &numberOfReviews);
    if (numberOfReviews < 0)
    {
        printf("ERROR");
        return 0;
    }
    else if (numberOfReviews == 0)
    {
        printf("No reviews found");
        return 0;
    }
    
    // set id name and score
    double total = 0;
    people p[numberOfReviews+1];
    for (int i = 1; i <= numberOfReviews; i++)
    {
        p[i].id = i;
        scanf("%f", &p[i].score);
        scanf("%s", &p[i].name);
        total += p[i].score;
    }
    double average = total / numberOfReviews;
    printf("Average Score: %.2f\n", average);

    // create sorted array
    int sorted[numberOfReviews+1];
    for (int i = 1; i <= numberOfReviews; i++)
    {
        sorted[i] = i;
    }
    for (int i = 1; i <= numberOfReviews; i++)
    {
        for (int j = i+1; j <= numberOfReviews; j++)
        {
            if (p[sorted[i]].score < p[sorted[j]].score)
            {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    // print results
    for (int i = 1; i <= numberOfReviews; i++)
    {
        printf("%.2f %s (id: %d)\n", p[sorted[i]].score, p[sorted[i]].name ,p[sorted[i]].id);
    }
}