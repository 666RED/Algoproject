#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int validValue(char*);
int validName(char*);
int validID(char*);
int validAge(char*);
int validGrossSalary(char*);
float determineInsurance(int*);
float determineIncomeTaxRate(float*);
float determineAverageValue(float*, int*);
void lower(char*);
void capitalize(char*);

int main(){

    char numberOfEmployee[5];
    int realNumberOfEmployee;
    int result, j;
    float averageInsurance = 0.0, averageGrossSalary = 0.0, averageIncomeTax = 0.0, averageNetSalary = 0.0, averageIncomeTaxRate = 0.0;
    do{
        printf("\nNumber of Employee to process: ");
        scanf("\n%[^\n]", numberOfEmployee);
        result = validValue(numberOfEmployee);
        if(result == -1){
            printf("You can't input the number starting from 0.\n");
        }else if(result == -2){
            printf("The number should be a positive value.\n");
        }else if(result == 0){
            printf("Invalid number.\n");
        }else{
            realNumberOfEmployee = atoi(numberOfEmployee);
            break;
        }
    }while(result != 1);

    char name[realNumberOfEmployee][50];
    char dataOfName[realNumberOfEmployee][50];
    char dataOfId[realNumberOfEmployee][50];
    char idNumber[realNumberOfEmployee][10];
    char age[realNumberOfEmployee][5];
    char grossSalary[realNumberOfEmployee][10];

    int realAge[realNumberOfEmployee];
    float realGrossSalary[realNumberOfEmployee];
    float insurance[realNumberOfEmployee];
    float incomeTaxRate[realNumberOfEmployee];
    float netSalary[realNumberOfEmployee];
    float incomeTax[realNumberOfEmployee];

    for(int i = 0; i < realNumberOfEmployee; i++){

        do{
            printf("Employee%d's name: ", i + 1);
            scanf("\n%[^\n]", name[i]);
            result = validName(name[i]);
            if(result){
                capitalize(name[i]);
                if(strlen(name[i]) < 3){
                    printf("The name should not less than 3 characters.\n");
                }else if(strlen(name[i]) > 50){
                    printf("The name should not exceed 50 characters.\n");
                }else{
                    strcpy(dataOfName[i], name[i]);
                    if(i > 0){
                        for(j = 0; j < i; j++){
                            if(strcmp(name[i], dataOfName[j]) == 0){
                                printf("The employees' names should be different.\n");
                                result = 0;
                                break;
                            }
                        }
                    }
                }
            }else{
                printf("Invalid name.\n");
            }
        }while(result != 1 || strlen(name[i]) < 3 || strlen(name[i]) > 50);

        do{
            printf("Employee ID: ");
            scanf("\n%[^\n]", idNumber[i]);
            result = validID(idNumber[i]);
            if(result == -1){
                printf("Your can't input the ID starting from 0.\n");
            }else if(result == 0){
                printf("Invalid ID.\n");
            }else{
                if(strlen(idNumber[i]) != 4){
                    printf("The ID should be in the range of 1000 to 9999.\n");
                }else{
                    strcpy(dataOfId[i], idNumber[i]);
                    if(i > 0){
                        for(j = 0; j < i; j++){
                            if(strcmp(idNumber[i], dataOfId[j]) == 0){
                                printf("The employees' ID should be different.\n");
                                result = 0;
                                break;
                            }      
                        }   
                    }
                }
            }
        }while(result != 1 || strlen(idNumber[i]) != 4);

        do{
            printf("Employee's age: ");
            scanf("\n%[^\n]", age[i]);
            result = validAge(age[i]);
            if(result == -1){
                printf("You can't input the age starting from 0.\n");
            }else if(result == -2){
                printf("The age should be a positive value.\n");
            }else if(result == 0){
                printf("Invalid age.\n");
            }
            else{
                realAge[i] = atoi(age[i]);
                if(realAge[i] < 18 || realAge[i] > 99){
                    printf("The age should be in the range of 18 to 99.\n");
                }else{
                    insurance[i] = determineInsurance(&realAge[i]);
                }
            }
        }while(result != 1 || realAge[i] < 18 || realAge[i] > 99);

        do{
            printf("Employee's gross salary (RM): ");
            scanf("\n%[^\n]", grossSalary[i]);
            result = validGrossSalary(grossSalary[i]);
            if(result == -1){
                printf("The gross salary should be a positive value.\n");
            }else if(result == 0){
                printf("Invalid value.\n");
            }else{
                realGrossSalary[i] = atof(grossSalary[i]);
                if(realGrossSalary[i]  < 0.0 || realGrossSalary[i] >= 10000){
                    printf("The gross salary should be in the range from RM 0.0 to RM 9999.99.\n");
                }else{
                    incomeTaxRate[i] = determineIncomeTaxRate(&realGrossSalary[i]);
                }
            }
        }while(result != 1 || realGrossSalary[i]  < 0.0 || realGrossSalary[i] >= 10000);

        incomeTax[i] = incomeTaxRate[i] * realGrossSalary[i];
        netSalary[i] = realGrossSalary[i] - insurance[i] - incomeTax[i];

    }
    averageInsurance = determineAverageValue(insurance, &realNumberOfEmployee);
    averageIncomeTax = determineAverageValue(incomeTax, &realNumberOfEmployee);
    averageGrossSalary = determineAverageValue(realGrossSalary, &realNumberOfEmployee);
    averageNetSalary = determineAverageValue(netSalary, &realNumberOfEmployee);
    averageIncomeTaxRate = determineAverageValue(incomeTaxRate, &realNumberOfEmployee);

    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| No. | Name\t\t\t\t\t\t   |   ID   |  Age  |  Insurance  |  GrossSalary  | IncomeTaxRate | IncomeTax  |  NetSalary  |\n");
    printf("|-----|----------------------------------------------------|--------|-------|-------------|---------------|---------------|------------|-------------|\n");
    for(int i = 0; i < realNumberOfEmployee; i++){
        printf("|%3d  | %-51s|%6s  |%5d  |  RM %-8.2f|  RM %-10.2f|%9.1f%%     |  RM %-7.2f|  RM %-8.2f|\n", i + 1, name[i], idNumber[i], realAge[i], insurance[i], realGrossSalary[i],incomeTaxRate[i] * 100, incomeTax[i], netSalary[i]);
        if(i == realNumberOfEmployee - 1){
            printf("|-----|---------------------------------------------------------------------|-------------|---------------|---------------|------------|-------------|\n");
        }else{
            printf("|-----|----------------------------------------------------|--------|-------|-------------|---------------|---------------|------------|-------------|\n");
        }
    }
    printf("|     |\t\t\tAverage\t\t\t\t\t\t    |  RM %-8.2f|  RM %-10.2f|%11.3f%%   |  RM %-7.2f|  RM %-8.2f|\n", averageInsurance, averageGrossSalary, averageIncomeTaxRate * 100, averageIncomeTax , averageNetSalary);
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
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

int validName(char* name){

    lower(name);
    for(int i = 0; i < strlen(name); i++){
        if(name[i] == 32 && name[i + 1] == 32){
            return 0;
            break;
        }
        if((name[i] < 97 || name[i] > 122 )&& name[i] != 32){
            return 0;
            break;
        }else if(i == strlen(name) - 1){
            return 1;
        }
    }
}

int validID(char* id){

    if(id[0] == 48){
        return -1;
    }
    for(int i = 0; i < strlen(id); i++){
        if(id[i] < 48 || id[i] > 57){
            return 0;
            break;
        }else if(i == strlen(id) - 1){
            return 1;
        }
    }
}

int validAge(char* age){

    if(age[0] == 48){
        return -1;
    }
    for(int i = 0; i < strlen(age); i++){
        if(age[i] < 48 || age[i] > 57){
            return 0;
            break;
        }else if( strlen(age) - 1){
            return 1;
        }
    }
}

int validGrossSalary(char* salary){

    int numberOfPeriod = 0;
    if(salary[0] == 46){
        return 0;
    }else if(salary[0] == 45){
        return -1;
    }else if(salary[0] == 48){
        if(salary[1] != 46){
            return 0;
        }
    }
    for(int i = 0; i < strlen(salary); i++){
        if(salary[i] == 46){
            numberOfPeriod++;
            if(salary[i + 3] >= 48 && salary[i + 3] <= 57){
                return 0;
            }
        }
        if(numberOfPeriod > 1){
            return 0;
            break;
        }
        if((salary[i] < 48 || salary[i] > 57) && salary[i] != 46){
            return 0;
            break;
        }else if(i == strlen(salary) - 1){
            return 1;
        }
    }
}

float determineInsurance(int* age){

    if(*age >= 18 && *age <=35){
        return (110.00);
    }else if(*age >= 36 && *age <= 65){
        return (160.00);
    }else{
        return (250.00);
    }
}

float determineIncomeTaxRate(float* salary){

    if(*salary >= 0.0 && *salary <= 999.99){
        return 0;
    }else if(*salary >= 1000.00 && *salary <= 2999.99){
        return 0.025;
    }else{
        return 0.05;
    }
}

float determineAverageValue(float* value, int* number){

    float total = 0.0;
    float average;
    for(int i = 0; i < *number; i++){
        total += value[i];
    }
    average = total / *number;
    return average;
}

void lower(char* name){

    for(int i = 0; i < strlen(name); i++){
        name[i] = tolower(name[i]);
    }
}

void capitalize(char* name){

    lower(name);
    name[0] = toupper(name[0]);
    for(int i = 1; i < strlen(name); i++){
        if(name[i] == 32){
            if((name[i + 1]) == 32){
                break;
            }else{
                name[i + 1] = toupper(name[i + 1]);
            }
        }
    }
}