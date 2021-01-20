#include "stdio.h"
#include "time.h"
#include "unistd.h"

const char *get_helloworld()
{
    return "Hello world";
}

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    puts(get_helloworld());
    printf("2+3 is %d\n", add(2, 3));
    printf("now time->%lu\n", time(NULL));
}
