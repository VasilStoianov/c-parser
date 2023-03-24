#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "list.h"
#include "file_search.h"
#define HELP_COMMAND "-help"
#define SEARCH_COMMAND "-search"


int main(int argc, char *argv[])
{
    parse_args(argv);
}