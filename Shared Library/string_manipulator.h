#ifndef STRING_MANIPULATOR_H
#define STRING_MANIPULATOR_H

// Define the Name structure
typedef struct {
    char first_name[50];
    char last_name[50];
} Name;

// Function declarations
int read_names(const char *filename, Name **names);
int count_entries(const char *filename);
void sort_and_display_names(Name *names, int count);

#endif // STRING_MANIPULATOR_H
