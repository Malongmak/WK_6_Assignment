#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Name structure
typedef struct {
    char first_name[50];
    char last_name[50];
} Name;

// Function to compare two names
int compare_names(const void *a, const void *b) {
    Name *nameA = (Name *)a;
    Name *nameB = (Name *)b;
    int last_name_cmp = strcmp(nameA->last_name, nameB->last_name);
    if (last_name_cmp != 0) {
        return last_name_cmp;
    }
    return strcmp(nameA->first_name, nameB->first_name);
}

// Function to read names from a file
int read_names(const char *filename, Name **names) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    Name *temp = malloc(sizeof(Name) * 100); 
    if (!temp) {
        perror("Memory allocation failed");
        fclose(file);
        return -1;
    }

    // Read names from this file
    while (fscanf(file, "%s %s", temp[count].first_name, temp[count].last_name) != EOF) {
        count++;
    }
    fclose(file);

    *names = temp;
    return count;
}

// Function to count how many entries are in the file
int count_entries(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%*s %*s") != EOF) {
        count++;
    }
    fclose(file);

    return count;
}

// Function to sort and display names
void sort_and_display_names(Name *names, int count) {
    qsort(names, count, sizeof(Name), compare_names);
    
    int i; 
    for (i = 0; i < count; i++) {
        printf("%s %s\n", names[i].first_name, names[i].last_name);
    }
}
