#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// global variables

int current = 0;
int previous = 0; 
int count = 0; 
char nr = 0; 



int main (){

    printf("File name? ");
    char name[100]; 
    scanf("%s", name); 
    FILE *infill = fopen(name, "r");  

    
    char str[] = {0, 0, 0, 0, 0}; 
    int sums[] = {0, 0, 0};
    char c; 
    char str_index = 0; 
    char sum_index = 0;
    char nrs_read = 0;

    do{
        c = fgetc(infill);
        if(!(c == '\n')){            // om talet inte är slut än 
            str[str_index] = (c); 
            str_index++; 
        } else {                    // om det är slutet på talet 
            str[str_index] = '\0';
            current = atoi(str);
            memset(str, 0, 5);
            if(current > previous) count++; 
            printf("previous = %d\t current = %d\n", previous, current);
            previous = current;
            str_index = 0;
            
        }
    } while(!feof(infill));          // gör så länge det inte är slutet av filen 

    count--;
    printf("%d", count);
    
    /*char c[5];
    fgets(c, 5, infill);
    previous = atoi(c);
    while(!feof(infill)){
        
        fgets(c, 5, infill);
        current = atoi(c);
        if(current>previous) count++; 
        previous = current;
        printf("%d", count);
        
    }*/  
    //int c = fgetc(infill);
    
}