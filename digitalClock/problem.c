#include <stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] =
    {
        " ",
        "\n\n\nJanuary",
        "\n\n\nFebuary",
        "\n\n\nMarch",
        "\n\n\nApril",
        "\n\n\nMay",
        "\n\n\nJune",
        "\n\n\nJuly",
        "\n\n\nAugust",
        "\n\n\nSeptember",
        "\n\n\nOctober",
        "\n\n\nNovember",
        "\n\n\nDecember",
};

int inputyear(void)
{
    int year;
    printf("please enter a year (example: 1990): ");
    scanf("%d", year);
    return year;
}

int determineleapyear(int year)
{
    if (year % 4 == FALSE && year % 100 != FALSE || year % 400 == FALSE)
    {
        days_in_month[2] = 29;
        return TRUE;
    }
    else
    {
        days_in_month[2] = 28;
        return FALSE;
    }
}

int determineDayCode(int year)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1.) / 4.0;
    d2 = (year - 1.) / 100.;
    d3 = (year - 1.) / 400.;
    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}

void calendar(int year, int daycode)

    int main()
{

    return 0;
}