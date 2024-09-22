#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

// Precondition

char *totitleCase(char *str)
{
    assert(str != NULL);
    assert(str[0] != '\0');

    // convert to lowercase
    int n = strlen(str);
    for (int i = 1; i < n; i++)
    {
        str[i] = tolower(str[i]);
    }

    // Serve for character before ; use space to distunguish if it should be uppercase
    char prev;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
        }
    }

    return str;
}

int main(int argc, char **argv)
{
    char* s=totitleCase(argv[1);
    printf("%s\n", s);
    return 0;
}

/*
10 points
humanify
    totitlecase
    toTitleCase
    to_title_case

    --> To Title Case

toallower()
tocamelcase()
tounderscorecase()

*/