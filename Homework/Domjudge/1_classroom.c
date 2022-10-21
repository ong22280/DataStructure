#include <stdio.h>

int main()
{
    // set number of table
    int total_table;
    scanf("%d", &total_table);
    if (total_table < 1)
    {
        printf("Error");
        return 0;
    }
    else if (total_table > 40)
    {
        printf("Error!");
        return 0;
    }

    // initialize the table
    int row_table;
    if (total_table % 6 == 0)
    {
        row_table = total_table / 6;
    }
    else
    {
        row_table = (total_table / 6) + 1;
    }

    char table[row_table][6];
    int count_table = total_table;
    for (int i = 0; i < row_table; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (count_table > 0)
            {
                table[i][j] = 'X';
                count_table--;
            }
            else
            {
                table[i][j] = '\0';
            }
        }
    }

    // assign chair into table
    int num;
    scanf("%d", &num);
    int row, column;
    int count = 1;
    while (count <= num)
    {
        scanf("%d", &row);
        scanf("%d", &column);
        if (row < 1 || row > row_table || column < 1 || column > 6 || table[row-1][column-1] == '\0')
        {
            printf("%d %d Out of range!\n", row, column);
            continue;
        }
        table[row - 1][column - 1] = 'S';
        count++;
    }

    // print table
    for (int i = 0; i < row_table; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (table[i][j] != '\0')
            {
                printf("%c ", table[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}