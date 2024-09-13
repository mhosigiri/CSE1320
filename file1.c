#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);

    printf("%d inches is %f meters", n, 0.0254f * n);
    return 0;
}
