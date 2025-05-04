#include <stdio.h>

struct student
{
    int stuno;
};

int main(int argc, char **argv)
{
    // system("color F0");
    struct student stu1;
    struct student *pstu;
    pstu = &stu1;
    stu1.stuno = 10;
    printf("%d\n", stu1.stuno);
    printf("%d\n", pstu->stuno);
    return 0;
}