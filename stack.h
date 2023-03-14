#ifndef _stack_h
#define _stack_h
#include <stdlib.h>

 struct stack
{
    int data[15];
    int length;
    int values;
} stack_default = {0,15,0};

typedef struct stack stack;

void add_value_to_stack(stack stak,int value);

void resize_stack(stack *stak);

void add_value_to_stack(stack stak,int value){
     if(stak.length - stak.values < 4){
        resize_stack(&stak);
     }  
     stak.data[stak.length] = value;
     stak.length++; 
};

void resize_stack(stack *stak){
    
        int new_array_size = stak->length + stak->length/2;
        int new_arr[new_array_size];
        for(int i = 0; i<=stak->values;i++){
            new_arr[i] = stak->data[i];
        }

        *stak->data = *new_arr;
    };

void print_stack(stack *stak){
    for(int i = 0; i<= stak->values; i++){
        printf("Value of index %d is %d\n",i,stak->data[i]);
    }
}    

#endif




