#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HELP_COMMAND "-help"

void parse_args(char *arguments[]);
int string_compare(char *str1, char *str2);

int main(int argc, char *argv[])
{
    parse_args(argv);
    return 1;
}


void parse_args(char *arguments[]){
    int count = 0;
    while(arguments[count] != NULL){
        if(string_compare(arguments[count],HELP_COMMAND) == 1){
            printf("-v helpping \n-o something else\n ");//TODO fix the message
                    break;
        };
        count++;
    }

};


int string_compare(char *str1, char *str2){
     int str1_size = strlen(str1);
     int str2_size = strlen(str2);
     if(str1_size > str2_size || str1_size < str2_size){
        return 0;
     };

     for(int c = 0; c<=str1_size; ++c){
        if(str1[c] != str2[c]) {return 0;};
     };
     return 1;

}