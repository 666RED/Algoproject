#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validValue(char*);
float determinePreTax(int*);

int main(){

    const int MAXWEEKDAY = 4000, MAXNIGHT = 4000, MAXWEEKEND = 2000;
    char weekday[5], night[5], weekend[5];
    int weekdayMinute, nightMinute, weekendMinute, totalMinute;
    float preTax, averageCost, SST = 0.06, sstCost, totalBill;
    int result;

    do{
        printf("Input the number of weekday minutes: ");
        scanf("\n%[^\n]", weekday); 
        result = validValue(weekday);
        if(result == -1){
            printf("You can't input a number starting from 0.\n");
        }else if(result == -2){
            printf("The number should be positive value.\n");
        }else if(result == 0){
            printf("Invalid number.\n");
        }else{
            weekdayMinute = atoi(weekday);
            if(weekdayMinute > MAXWEEKDAY){
                printf("Invalid number.\n");
            }
        }
    }while(result != 1 || weekdayMinute > MAXWEEKDAY);

    do{
        printf("Input the number of night minutes: ");
        scanf("\n%[^\n]", night); 
        result = validValue(night);
        if(result == -1){
            printf("You can't input a number starting from 0.\n");
        }else if(result == -2){
            printf("The number should be positive value.\n");
        }else if(result == 0){
            printf("Invalid number.\n");
        }else{
            nightMinute = atoi(night);
            if(nightMinute > MAXNIGHT){
                printf("Invalid number.\n");
            }
        }
    }while(result != 1 || nightMinute > MAXNIGHT);   

    do{
        printf("Input the number of weekend minutes: ");
        scanf("\n%[^\n]", weekend); 
        result = validValue(weekend);
        if(result == -1){
            printf("You can't input a number starting from 0.\n");
        }else if(result == -2){
            printf("The number should be positive value.\n");
        }else if(result == 0){
            printf("Invalid number.\n");
        }else{
            weekendMinute = atoi(weekend);
            if(weekendMinute > MAXWEEKEND){
                printf("Invalid number.\n");
            }
        }
    }while(result != 1 || weekendMinute > MAXWEEKEND);     

    totalMinute = weekdayMinute + nightMinute + weekdayMinute;
    preTax = determinePreTax(&weekdayMinute);
    averageCost = preTax / totalMinute;
    sstCost = preTax * SST;
    totalBill = preTax + sstCost;

    printf("Weekday minute\t\t: %d\nNight minute\t\t: %d\nWeekend minute\t\t: %d\nTotal minute\t\t: %d\nPre-tax\t\t\t: RM %.2f\nAverage minute cost\t: RM %.2f\nSST cost\t\t: RM %.2f\nTotal bill\t\t: RM %.2f\n", weekdayMinute, nightMinute, weekdayMinute, totalMinute, preTax, averageCost, sstCost, totalBill);

}

int validValue(char* value){

    if(value[0] == 48){
        return -1;
    }else if(value[0] == 45){
        return -2;
    }

    for(int i = 0; i < strlen(value); i++){
        if(value[i] < 48 || value[i] > 57){
            return 0;
            break;
        }else if(i == strlen(value) - 1){
            return 1;
        }
    }
}

float determinePreTax(int* weekday){

    int maxWeekdayMinute = 600;
    float flatRate = 39.99;
    float addtionalCost = 0.20;
    float total;

    if(*weekday < 600){
        total = flatRate;
    }else{
        total = flatRate + ((*weekday - maxWeekdayMinute) * addtionalCost);
    }
    return total;
}   