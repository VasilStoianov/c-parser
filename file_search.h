#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#define HELP_COMMAND "-help"
#define SEARCH_COMMAND "-search"


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

