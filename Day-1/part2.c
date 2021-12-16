#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// dynamic array 

typedef struct {
    int *array; 
    size_t used; 
    size_t size; 
} dynamic_array; 

void initArray(dynamic_array *a, size_t initialsize){
    // aallocate this mush memory to the array 
    a->array = malloc(initialsize * sizeof(int));           
    a->used = 0; 
    a->size = initialsize; 
}

void insertArray(dynamic_array *a, int element) {
    // check if the array has been used up, in that case double the sze of the array
    if (a->used == a->size){
        a->size *= 2; 
        a->array = realloc(a->array, a->size * sizeof(int)); 
    }
    // add element to the array 
    a->array [a->used++] = element; 
}

void freeArray (dynamic_array *a){
    free(a->array); 
    a->array = NULL; 
    a->used = a->size = 0; 
}


int main (){

    printf("File name? ");
    char name[100]; 
    scanf("%s", name); 
    FILE *infill = fopen(name, "r");  

    //dynamic_array numbers; 
    //initArray(&numbers, 10);  

    int numbers[2000];
    int numbers_used = 0; 
    
    char str[] = {0, 0, 0, 0, 0};  
    char c; 
    char str_index = 0;
    int current_val = 0;
    char current_index = 0;
    int previous_val = 0;
    int count = 0; 
    
  

    do{
        // read one char from the txt file
        c = fgetc(infill);

        // if the entire number has not been read
        if(!(c == '\n')){            
            str[str_index] = (c); 
            str_index++; 
        } 
        // if the entire number has been read 
        else {                     
            str[str_index] = '\0';
            current_val = atoi(str);
            //insertArray(&numbers, current_val);
            numbers[numbers_used] = current_val;
            numbers_used++; 
            memset(str, 0, 5);
            str_index = 0;
            
        }
        current_val = 0; 
    // do while the txt file has not ended yet. 
    } while(!feof(infill));

    do{
        
        current_val += (numbers[current_index]+ 
                        numbers[current_index +1]+ 
                        numbers[current_index +2]);
        //printf("current index: %d previous: %d current: %d\n", current_index, previous_val, current_val);
        // no comparison is made for the first value
        if(current_index != 0){
            if (current_val > previous_val) count++; 
        }
        previous_val = current_val;
        current_val = 0;
        current_index++; 
        
    } while((current_index + 2) != numbers_used);
    //printf("%d\n", numbers.used);
    //printf("%d\n", current_index);
    //freeArray(&numbers);
    printf("%d", count);
    
    
}