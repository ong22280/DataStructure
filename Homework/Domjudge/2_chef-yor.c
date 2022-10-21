#include <stdio.h>

void add(char *menu)
{
    for (int i = 0; menu[i] == 0; i++)
    {
        scanf("%d", &menu[i]);
    }
}

void del(char *menu)
{
    int no;
    scanf("%d", &no);
    for (int i = no-1; menu[i] != 0; i++)
    {
        menu[i] = menu[i + 1];
    }
}

void show(char *menu)
{
    printf("<<Menu>>\n");
    int line = 1;
    int i = 0;
    while(menu[i] != 0)
    {
        printf("%d. %d\n", line, menu[i]);
        i++;
        line++;
    }
}

int main(void)
{
    char menu[100] = 0;
    while(1)
    {
        char *command;
        printf(">");
        scanf("%s", command);
        if (command == "add")
        {
            add(menu);
        }
        else if (command == "del")
        {
            del(menu);
        }
        else if (command == "show")
        {
            show(menu);
        }
        else if (command == "exit")
        {
            show(menu);
            break;
        }
    }
    return 0;
}