#include <stdio.h>
#include <stdlib.h>
#include "string_manipulator.h"

int main() {
    const char *filename = "names.txt";
    
    Name *names = NULL;
    int count = read_names(filename, &names);

    if (count == -1) {
        return 1; 
    }

    printf("Total entries: %d\n", count);

    sort_and_display_names(names, count);

    // free(names);

    return 0;
}
