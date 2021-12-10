#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float calculateParkingCharges(float*, int*);
int validNumber(char*);
int validHour(char*);
int main(){

    char number[10];
    int numberOfCars;
    float totalHours = 0;
    float totalCharge = 0;
    int result;
    do{
        printf("Number of cars: ");
        scanf("\n%[^\n]", number);
        result = validNumber(number);
        if(result == -1){
            printf("The number of cars should greater than 0.\n");
        }else if(result == 0){
            printf("Invalid number.\n");
        }else{
            numberOfCars = atoi(number);
        }
    }while(result != 1);

    char hour[numberOfCars][10];
    float hours[numberOfCars];

    for(int i = 0; i < numberOfCars; i++){
        do{
            printf("Car %d Hour: ", i + 1);
            scanf("\n%[^\n]", hour[i]);
            result = validHour(hour[i]);
            if(result == -1){
                printf("The hour should greater than 0.\n");
            }else if(result == 0){
                printf("Invalid hour.\n");
            }else if(result == -2){
                printf("The hour should not be zero.\n");
            }
            else{
                hours[i] = atof(hour[i]);
                if(hours[i] > 24){
                    printf("You can't park your car more than 24 hours.\n");
                }else if(hours[i] == 0){
                    printf("The hour should not be zero.\n");
                }
            }
        }while(result != 1 || hours[i] > 24 || hours[i] == 0);
        totalHours += hours[i];
    }
    printf("\nCar\tHours\t   Charge\n");
    for(int i = 0; i < numberOfCars; i++){
        printf("%d\t%.1f\t   RM %.2f\n", i + 1, hours[i], calculateParkingCharges(&hours[i], &numberOfCars));
        totalCharge += calculateParkingCharges(&hours[i], &numberOfCars);
    }
    printf("\n\nTOTAL Hours  %.1f\nTOTAL Charges RM %.2f", totalHours, totalCharge);
}

float calculateParkingCharges(float* hour, int* number){

    float minimumCharge = 5.00;
    float maximumCharge = 15.00;
    float extraCharge = 0.50;
    int extraHour;
    float charge;

    if(*hour <= 3.0){
        charge = minimumCharge;
    }else if(*hour > 3.0 && *hour < 23.0){
        extraHour = ceil((*hour - 3.0));
        charge = (extraHour * extraCharge) + minimumCharge;
    }else if(*hour >= 23.0){
        charge = maximumCharge;
    }
    return charge;
}

int validNumber(char* value){
   
    if(value[0] == 45){
        return -1;
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
   
int validHour(char* hour){
    
    if(hour[0] == 45){
        return -1;
    }else if(hour[0] == 48){
        if(hour[1] != 46){
            return -2;
        }
    }else if(hour[0] == 46){    
        return 0;
    }

    int numberOfPeriod = 0;
    for(int i = 0; i < strlen(hour); i++){
        if(hour[i] == 46){
            numberOfPeriod++;
        }
        if(numberOfPeriod > 1){
            return 0;
            break;
        }
        if(hour[i] != 46 && (hour[i] < 48 || hour[i] > 57)){
            return 0;
            break;
        }else if(i == strlen(hour) - 1){
            return 1;
        }
    }
}