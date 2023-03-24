#ifndef _file_search_h
#define _file_search_h
#include <stdlib.h>


void parse_args(char *arguments[]);
int string_compare(char *str1, char *str2);
int search_file(char *file);

void parse_args(char *arguments[])
{
    int count = 0;
    while (arguments[count] != NULL)
    {
        if (string_compare(arguments[count], HELP_COMMAND) == 1)
        {
            printf("-v helpping \n-o something else\n "); // TODO fix the message
        };
        if (string_compare(arguments[count], SEARCH_COMMAND) == 1)
        {
            printf("SEARCHING FOR %s", arguments[count + 1]); // TODO fix the search  and add search types etc dir,file
            if (search_file(arguments[count + 1]) == 1)
            {
                break;
            };
        }
        count++;
    }
};

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

int search_file(char *file)
{
    struct dirent *de;
    DIR *dir = opendir(".");
    if (dir == NULL) // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory");
        return 0;
    }
    iterate_and_compare(dir, file);

    return 1;
}

int iterate_and_compare(struct DIR *dir, char *file)
{
    struct dirent *de;
    while ((de = readdir(dir)) != NULL)
    {
        printf("COMPARING %s and %s \n", de->d_name, file);
        if (string_compare(de->d_name, file) == 1)
        {
            printf("File found\n");
            return 1;
        }
    }
}

#endif