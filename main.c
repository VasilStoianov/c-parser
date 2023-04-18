#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Function to recursively search for a file in a directory tree
char *search_file(char *filename, char *dir_path)
{
    // Open the directory
    DIR *dir = opendir(dir_path);
    if (!dir)
    {
        perror("Error opening directory");
        return NULL;
    }

    // Iterate through each item in the directory
    struct dirent *entry;
    struct stat path_stat;
    char *full_path = malloc(strlen(dir_path) + NAME_MAX + 2);
    char *result = NULL;

    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Construct the full path to the current entry
        snprintf(full_path, strlen(dir_path) + NAME_MAX + 2, "%s/%s", dir_path, entry->d_name);

        // Get the file status
        if (stat(full_path, &path_stat) == -1)
        {
            perror("Error getting file status");
            continue;
        }

        // Recurse into subdirectories
        if (S_ISDIR(path_stat.st_mode))
        {
            char *sub_result = search_file(filename, full_path);
            if (sub_result)
                result = sub_result;
        }
        else if (S_ISREG(path_stat.st_mode))
        {
            // Check if the current entry matches the filename
            if (strcmp(entry->d_name, filename) == 0)
            {
                result = strdup(full_path);
                break;
            }
        }
    }

    // Clean up and return the result
    free(full_path);
    closedir(dir);
    return result;
}

int main(int argc, char *argv[])
{
    // if (argc != 3)
    // {
    //     printf("Usage: %s <filename> <directory>\n", argv[0]);
    //     return 1;
    // }

    char *result = search_file("zimb.h", ".");
    if (result)
        printf("%s\n", result);
    else
        printf("File not found\n");

    free(result);
    return 0;
}

int string_compare(char *str1, char *str2)
{
    int str1_size = strlen(str1);
    int str2_size = strlen(str2);
    if (str1_size > str2_size || str1_size < str2_size)
    {
        return 0;
    };

    for (int c = 0; c <= str1_size; ++c)
    {
        if (str1[c] != str2[c])
        {
            return 0;
        };
    };
    return 1;
}
