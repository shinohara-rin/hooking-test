#include "./mach_override/mach_override.h"
#include "stdio.h"
#include "dlfcn.h"

int minus(int a, int b)
{
    return a - b;
}

const char *get_goobyeworld()
{
    return "Goodbye world...";
}

unsigned long fake_time()
{
    return 1337;
}

__attribute__((constructor)) static void init()
{
    puts("libshit loaded");
    void *hndl = dlopen(NULL, RTLD_NOW | RTLD_NOLOAD);
    void *fget_helloworld = dlsym(hndl, "get_helloworld");
    void *fadd = dlsym(hndl, "add");
    void *ftime = dlsym(RTLD_DEFAULT, "time");
    mach_override_ptr(fget_helloworld, &get_goobyeworld, NULL);
    mach_override_ptr(fadd, &minus, NULL);
    mach_override_ptr(ftime, &fake_time, NULL);
}