#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FILENAME argv[1]
#define BUFFERSIZE 500

void trim(char *str)
{
    char *end;

    while (isspace((unsigned char)*str))
        str++;

    if (*str == 0)
        return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    *(end + 1) = 0;
}

int main(int argc, char *argv[])
{

    FILE *fp = fopen(FILENAME, "r");

    if (fp == NULL)
    {
        perror("Error");
        exit(1);
    }

    char buffer[BUFFERSIZE];
    int line_number = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        line_number++;
        if (strchr(buffer, '\n') == NULL && !feof(fp))
        {
            fprintf(stderr, "Line too long, skipping\n");
            int ch;
            while ((ch = fgetc(fp)) != EOF && ch != '\n')
                ;
            continue;
        }
        trim(buffer);

        if (strlen(buffer) == 0)
        {
            continue;
        }
        // Process the valid data: sum of the numbers on the line
        char *token;
        double sum = 0.0;
        int valid_numbers = 0;

        token = strtok(buffer, " ");
        while (token != NULL)
        {

            trim(token);
            char *endptr;
            double num = strtod(token, &endptr);

            if (endptr != token)
            {
                sum += num;
                valid_numbers++;
            }
            else
            {
                fprintf(stderr, "Warning: Invalid number '%s' on line %d\n", token, line_number);
            }
            token = strtok(NULL, "");
        }
        if (valid_numbers > 0)
        {
            printf("Line %d sum: %.2f\n", line_number, sum);
        }
        else
        {
            printf("Line %d No Valid Numbers Found\n", line_number);
        }
    }
    if (ferror(fp))
    {
        perror("Error reading from file");
    }

    fclose(fp);
    return 0;
}