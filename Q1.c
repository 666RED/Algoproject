#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void makeMilesKmTable(int*, int*);
int validValue(char*);
int main(){

   char start[10], stop[10];
   int startValue, stopValue;
   int result;
    do{
        do{
            printf("Input the starting value: ");
            scanf("\n%[^\n]", start);
            result = validValue(start);
            if(result == 0){
                printf("You have to enter a valid number.\n");
            }else if(result == -1){
                printf("Your number should greater than or equal to 0.\n");
            }else{
                startValue = atoi(start);
            }
        }while(result != 1);
        
        do{
            printf("Input the stopping value: ");
            scanf("\n%[^\n]", stop);
            result = validValue(stop);
            if(result == 0){
                printf("You have to enter a valid number.\n");
            }else if(result == -1){
                printf("Your number should greater than or equal to zero.\n");
            }else{
                stopValue = atoi(stop);
            }
        }while(result != 1);

        if(startValue > stopValue){
            printf("Starting value should not greater than stopping value.Please reinput both values.\n");
        }
    }while(startValue > stopValue);

    makeMilesKmTable(&startValue, &stopValue);
}

void makeMilesKmTable(int* start, int* stop){

    int difference = *stop - *start;
    int row = ((*stop - *start) / 2 + 1);
    printf("-----------------------------------------------------------------------------------------\n");
    printf("|\tMiles\t   |\t   Kilometers\t     |\t    Miles\t|\tKilometers\t|\n");
    printf("|------------------|-------------------------|------------------|-----------------------|\n");

    for(int i = 1; i <= row; i++){
        if(difference % 2 != 0){
            printf("|%10d\t   |%14.2f\t     |%10d\t|%15.2f\t|\n", *start, (*start) * 1.61, *start + row, ((*start) + row) * 1.61);
        }else{
            if(i == row){
                printf("|%10d\t   |%14.2f\t     |\t\t\t|\t\t\t|\n", *start, (*start) * 1.61); 
                break;             
            }  
            printf("|%10d\t   |%14.2f\t     |%10d\t|%15.2f\t|\n", *start, (*start) * 1.61, *start + row, ((*start) + row) * 1.61);
        }
        *start += 1;  
        if(i != row){
            printf("|------------------|-------------------------|------------------|-----------------------|\n");
        }
    }
    printf("-----------------------------------------------------------------------------------------\n");
}

int validValue(char* value){

        if(value[0] == 45){
            return -1;
        }
    for (int i = 0; i < strlen(value); i++){
        
        if(value[i] < 48 || value[i] > 57){
            return 0;
            break;
        }else if(i == strlen(value) - 1){
            return 1;
        }
    }
}