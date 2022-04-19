#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "ptentry.h"

#define PGSIZE 4096

int main(void)
{
    char *ptr = sbrk(PGSIZE); // Allocate one page
    mencrypt(ptr, 1);         // Encrypt the pages
    printf(1, "alan\n");
    struct pt_entry pt_entry;
    int retval = getpgtable(&pt_entry, 1, 0); // Get the page table information for newly allocated page
    printf(1, "%d\n", retval);
    exit();
}
