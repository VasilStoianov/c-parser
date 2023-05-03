#ifndef _list_h
#define _list_h
#include <stdlib.h>
#include <stdio.h>



struct list
{
    int data[15];
    int values;   // values in the array
} list_default = {0,0};

typedef struct list list;
void add_value_to_list(list *list,int value);

void resize_list(list *list);

void add_multiple_values(list *list, int values[]);

void add_value_to_list(list *list,int value){
    int length = sizeof(int) / sizeof(list->data[0]);
     if(length - list->values <= 4){
        resize_list(list);
     }  
     list->data[list->values] = value;
     list->values++; 
};

void resize_list(list *list){
        int old_size = sizeof(list->data)/sizeof(list->data[0]);
        int new_array_size =  old_size + old_size/2;
        int new_arr[new_array_size];
        for(int i = 0; i <= list->values;i++){
            new_arr[i] = list->data[i];
        }

        *list->data = *new_arr;
    };

void print_list(list *list){
    for(int i = 0; i<= list->values; i++){
        printf("Value of index %d is %d\n",i,list->data[i]);
    }
} 

void add_multiple_values(list *list, int arr[]){
    int arrays_size = sizeof(int)/sizeof(arr[0]);
    for(int i = 0; i<arrays_size; i++){
        list->data[list->values +1] = arr[i];
        list->values++;
    }

}

#endif




