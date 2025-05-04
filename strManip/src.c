/* Sketch - Password Requirement - Char Manipulation */
/* Author: CT (9/16/2024) */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

// PASSWORD VERIFICATION
// Pass password candidate via command line argument.

bool isValidPassword(char *passwordCandidate)
{
    // GUARD PATTERN
    assert(passwordCandidate != NULL); // for all pointers
    size_t n = strlen(passwordCandidate);
    assert(n > 0);

    // Assume that the passwordCandidate is not corrupted; \0
    // Requirements: Assume false until proven valid

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;

    // Assess password candidate

    for (int i = 0; i < n; i++)
    {
        char x = passwordCandidate[i];
        if (isupper(x))
        {
            hasUpper = true;
        }
        if (islower(x))
        {
            hasLower = true;
        }
        if (isdigit(x))
        {
            hasDigit = true;
        }
    }

    // Requirements check
    return hasUpper && hasLower && hasDigit; // AND OPERATION
}

int main(int argc, char *argv[])
{
    // char* passwordCandidate = argv[1];
    char *passwordCandidate = (char *)malloc(100 * sizeof(char));
    if (passwordCandidate == NULL)
    {
        printf("Memory allocation failed.\n");
    }
    else
    {
        printf("Memory allocation successful.\n");
    }
    printf("Enter your desired password: ");
    fgets(passwordCandidate, 100, stdin);
    size_t len = strlen(passwordCandidate);
    if (len > 0 && passwordCandidate[len - 1] == '\n')
    {
        passwordCandidate[len - 1] = '\0';
    }
    printf("%s is %s password\n", passwordCandidate, isValidPassword(passwordCandidate) ? "a Valid" : "an Invalid");

    free(passwordCandidate);
    return 0;
}