#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "file_search.h"



int main(int argc, char *argv[])
{
    // if (argc != 3)
    // {
    //     printf("Usage: %s <filename> <directory>\n", argv[0]);
    //     return 1;
    // }

    parse_args(argv);
   
    return 0;
}
