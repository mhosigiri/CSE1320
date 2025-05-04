#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"

// Function Prototypes
void pprint_mat(int *mat, int m, int n);
void print_usage(const char *program_name);

// Pretty Print 2D Matrix
void pprint_mat(int *mat, int m, int n)
{

    printf(ANSI_BOLD ANSI_COLOR_CYAN "\n----- Matrix (%d x %d) -----\n" ANSI_COLOR_RESET, m, n);

    for (int i = 0; i < m; i++)
    {
        printf(ANSI_COLOR_YELLOW "| " ANSI_COLOR_RESET);
        for (int j = 0; j < n; j++)
        {
            int value = *(mat + i * n + j);
            if (value < 0)
            {
                printf(ANSI_COLOR_RED);
            }
            else if (value == 0)
            {
                printf(ANSI_COLOR_BLUE);
            }
            else
            {
                printf(ANSI_COLOR_YELLOW);
            }
            printf("%3d ", value);
            printf(ANSI_COLOR_RESET);
            printf("%d ", *(mat + i * n + j)); // Pointer arithmetic to access matrix elements
        }
        printf(ANSI_COLOR_YELLOW "\n" ANSI_COLOR_RESET);
        printf(ANSI_BOLD ANSI_COLOR_CYAN "--------------------------\n" ANSI_COLOR_RESET);
    }
}

void print_usage(const char *program_name)
{
    fprintf(stderr, "Usage: %s [rows] [column]\n", program_name);
    fprintf(stderr, "If no arguments are provided, a default 2x3 matrix will be used.\n");
}
// You can take CLI arguments, but give us a error message that tells us how to use it.
int main(int argc, char **argv)
{
    int m = 2, n = 3;

    if (argc > 1)
    {
        if (argc != 3)
        {
            print_usage(argv[0]);
            return 1;
        }
        m = atoi(argv[1]);
        n = atoi(argv[2]);
        if (m <= 0 || n <= 0)
        {
            fprintf(stderr, "Error: Matric dimensions must be positive integers.\n");
            return 1;
        }
    }

    int *mat = (int *)malloc(m * n * sizeof(int));
    if (mat == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < m * n; i++)
    {
        mat[i] = (i % 5) - 2;
    }

    pprint_mat((int *)mat, 2, 3); // Pass the address of the first element and dimensions
    free(mat);
    return 0;
}
