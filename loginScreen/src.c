#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASS 50

void trim(char *str)
{
    int i, j;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)str[i]))
        {
            break;
        }
    }
    if (i > 0)
    {
        for (j = 0; str[i] != '\0'; j++, i++)
        {
            str[j] = str[i];
        }
        str[j] = '\0';
    }
    for (i = strlen(str) - 1; i >= 0 && isspace((unsigned char)str[i]); i--)
    {
        str[i] = '\0';
    }
}

int main()
{
    char ch;
    char pass[MAX_PASS];
    char saved_pass[MAX_PASS];
    int i = 0;

    printf("Enter password: \n");
    while (1)
    {
        ch = getchar();
        if (ch == '\n')
        {
            pass[i] = '\0';
            break;
        }
        else if (i < MAX_PASS - 1)
        {
            pass[i++] = ch;
        }
    }
    trim(pass);
    printf("\nYou Entered : %s\n", pass);

    FILE *ptr;
    ptr = fopen("pass.txt", "r");
    if (ptr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    if (fgets(saved_pass, MAX_PASS, ptr) == NULL)
    {
        printf("Error reading from the file!\n");
        fclose(ptr);
        return 1;
    }
    fclose(ptr);

    trim(saved_pass);
    printf("Saved Password: '%s'\n", saved_pass);

    if (strcmp(pass, saved_pass) == 0)
    {
        printf("LOGIN SUCCESSFUL");
    }
    else
    {
        printf("INCORRECT PASSWORD. TRY AGAIN");
        printf("Lengths - Input: %lu, Saved: %lu\n", strlen(pass), strlen(saved_pass));
    }

    return 0;
}