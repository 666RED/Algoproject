#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YEAR 12

int validValue(char*);
float findMonthlyPayment(float*, float*, int*);
float findTotalCost(int*, float*, float*);

int main(){

    char price[10], rateOfDownPayment[10], interestRate[10];
    float realPrice, realRateOfDownPayment, realInterestRate;
    float downPayment;
    float monthlyPayment;
    float totalLoan;
    float totalCost;
    int result;
    int minYear = 3, maxYear = 7;
    do{
        printf("Car Price (RM)\t\t\t: ");
        scanf("\n%[^\n]", price);
        result = validValue(price);
        if(result == -2){
            printf("You can't input the price starting from 0.\n");
        }else if(result == -1){
            printf("The price should be a positive value.\n");
        }else if(result == 0){
            printf("Invalid price.\n");
        }else{
            realPrice = atof(price);
            if(realPrice < 5600 || realPrice > 79000000){
                printf("The car price should be in the range from RM 5600 to RM 79 billion\n");
            }
        }
    }while(result != 1 || realPrice < 5600 || realPrice > 79000000);

    do{
        printf("Percentage of Down Payment (%%)\t: ");
        scanf("\n%[^\n]", rateOfDownPayment);
        result = validValue(rateOfDownPayment);
        if(result == -2){
            printf("You can't input the rate starting from 0.\n");
        }else if(result == -1){
            printf("The rate should be a positive value.\n");
        }else if(result == 0){
            printf("Invalid rate.\n");
        }else{
            realRateOfDownPayment = atof(rateOfDownPayment);
            if(realRateOfDownPayment < 10 || realRateOfDownPayment > 20){
                printf("The rate should be in the range from 10%% to 20%%.\n");
            }
        }
    }while(result != 1 || realRateOfDownPayment < 10 || realRateOfDownPayment > 20);

    downPayment = realPrice * realRateOfDownPayment / 100;
    printf("Down Payment (RM)\t\t: %.2f\n", downPayment);

    do{
        printf("Interest Rate (%%)\t\t: ");
        scanf("\n%[^\n]", interestRate);
        result = validValue(interestRate);
        if(result == -2){
            printf("You can't input the rate starting from 0.\n");
        }else if(result == -1){
            printf("The rate should be a positive value.\n");
        }else if(result == 0){
            printf("Invalid rate.\n");
        }else{
            realInterestRate = atof(interestRate);
            if(realInterestRate > 5){
                printf("The interest rate should not exceed 5%%\n");  
            }
        }   
    }while(result != 1 || realInterestRate > 5);
    
    totalLoan = realPrice - downPayment;
    
    printf("-------------------------------------------------------------------------\n");
    printf("| Period (Year) | Total Months | Monthly Payment |      Total Cost      |\n");
    printf("|---------------|--------------|-----------------|----------------------|\n");
    for(int i = minYear; i <= maxYear; i++){
        monthlyPayment = findMonthlyPayment(&realInterestRate, &totalLoan, &i);
        totalCost = findTotalCost(&i, &monthlyPayment, &downPayment);
        printf("|\t%d\t|%8d      |   RM %-11.2f|\tRM %-13.2f|\n", i, i * YEAR, monthlyPayment, totalCost);
        if(i == maxYear){
            printf("-------------------------------------------------------------------------\n");
        }else{
            printf("|---------------|--------------|-----------------|----------------------|\n");

        }
    }
}

int validValue(char* value){

    int numberOfPeriod = 0;
    if(value[0] == 45){
        return -1;
    }else if(value[0] == 46){
        return 0;
    }else if(value[0] == 48){
        return -2;
    }

    for(int i = 0; i < strlen(value); i++){

        if(value[i] == 46){
            numberOfPeriod++;
            if(value[i + 3] > 48 && value[i + 3] < 57){
                return 0;
            }
        }
        if(numberOfPeriod > 1){
            return 0;
            break;
        }
        if((value[i] < 48 || value[i] > 57) && value[i] != 46){
            return 0;
            break;
        }else if(i == strlen(value) - 1){
            return 1;
        }
    }
}

float findMonthlyPayment(float* rate, float* loan, int* year){

    float monthlyPayment;

    monthlyPayment = (*loan + (*year * *loan * *rate / 100)) / (*year * YEAR);
    return monthlyPayment;
}

float findTotalCost(int *year, float* monthyPayment, float* downpayment){

    float totalCost;

    totalCost = (*year * YEAR * *monthyPayment) + *downpayment;
    return totalCost;
}
