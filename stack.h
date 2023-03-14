#ifndef _stack_h
#define _stack_h
#include <stdlib.h>


struct stack
{
    int data[15];
    int values;   // values in the array
} stack_default = {0,0};

typedef struct stack stack;
void add_value_to_stack(stack *stak,int value);

void resize_stack(stack *stak);

void add_multiple_values(stack *stak, int values[]);

void add_value_to_stack(stack *stak,int value){
    int length = sizeof(int) / sizeof(stak->data[0]);
     if(length - stak->values <= 4){
        resize_stack(stak);
     }  
     stak->data[stak->values] = value;
     stak->values++; 
};

void resize_stack(stack *stak){
        int old_size = sizeof(stak->data)/sizeof(stak->data[0]);
        int new_array_size =  old_size + old_size/2;
        int new_arr[new_array_size];
        for(int i = 0; i <= stak->values;i++){
            new_arr[i] = stak->data[i];
        }

        *stak->data = *new_arr;
    };

void print_stack(stack *stak){
    for(int i = 0; i<= stak->values; i++){
        printf("Value of index %d is %d\n",i,stak->data[i]);
    }
} 

void add_multiple_values(stack *stak, int arr[]){
    int arrays_size = sizeof(int)/sizeof(arr[0]);
    for(int i = 0; i<arrays_size; i++){
        stak->data[stak->values +1] = arr[i];
        stak->values++;
    }

}

#endif




