#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3 // number of attempts for entering password
#define MAX_LINE_LENGTH 1000

void open_file(const char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
    }
    printf("\nOpening file: %s\n\n", filename);
    printf("File contents\n");
    printf("------------------------\n");

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    printf("-------------------------\n");
    fclose(file);
}
int main()
{

    char pass[20], saved_pass[20], saved_name[20], user_name[20];
    int attempts = 0;
    FILE *ptr;
    ptr = fopen("pass.txt", "r");
    if (ptr == NULL)
    {
        printf("Error openning the file\n");
        return 1;
    }

    fscanf(ptr, "%s %s", saved_name, saved_pass);
    fclose(ptr);

    while (attempts < MAX_ATTEMPTS)
    {
        printf("Enter username: ");
        scanf("%s", user_name);

        if (strcmp(user_name, saved_name) != 0)
        {
            printf("Incorrect username, Please try again \n");
            attempts++;
            continue;
        }
        printf("Enter your password: ");
        scanf("%s", pass);

        if (strcmp(pass, saved_pass) != 0)
        {
            printf("Incorrect Password, Please try agian. \n");
            attempts++;
        }
        else
        {
            printf("login Successful. \n");
            open_file("docu.txt");
            return 0;
        }
    }

    if (attempts >= MAX_ATTEMPTS)
    {
        printf("Too many incorrect attempts. Exiting program.\n");
    }
    return 0;
}