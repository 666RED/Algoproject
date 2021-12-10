#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void printTable();
float findBmr(float*, float*, int*, char*);
float findDcr(char*, float*);
void lower(char*);
void capitalize(char*);
bool validName(char*);
bool validAge(char*);
bool validValue(char*);
bool validGender(char*);
bool validLevel(char*);

int main(){

    char age[10], height[10], weight[10];
    int realAge; 
    float realHeight, realWeight;
    char name[50];
    char gender[10];
    float bmr, dcr;
    char level[30];
    bool result;

    printTable();
    do{
        printf("Name\t\t: ");
        scanf("\n%[^\n]", name);
        lower(name);
        result = validName(name);
        if(strlen(name) < 3){
            printf("The length of your name should not less than 3 characters.\n");
        }else if(strlen(name) > 50){
            printf("The length of your name should be exceed 50 characters.\n");
        }else if(result){
            capitalize(name);
            break;
        }else{
            printf("Invalid name.\n");
        }
    }while(strlen(name) < 3 || strlen(name) > 50 || result == false);

    do{
        printf("Age\t\t: ");
        scanf("\n%[^\n]", age);
        result = validAge(age);
        if(result){
            realAge = atoi(age);
            if(realAge > 122){
                printf("Invalid age.\n");
            }else{
                break;
            }            
        }else{
            printf("Invalid age.\n");
        }
    }while(realAge > 122 || result == false);

    do{
        printf("Weight(kg)\t: ");
        scanf("\n%[^\n]", weight);
        result = (validValue(weight));
        if(result){
            realWeight = atof(weight);
            if(realWeight >= 600 || realWeight <= 2){
                printf("Invalid weight.\n");
            }else{
                break;
            }
        }else{
            printf("Invalid weight.\n");
        }
    }while(realWeight >= 600 || realWeight <= 2 || result == false);

    do{
        printf("Height(cm)\t: ");
        scanf("\n%[^\n]", height);
        result = validValue(height);
        if(result){
            realHeight = atof(height);
            if(realHeight >= 270 || realHeight <= 46){
                printf("Invalid height.\n");
            }else{
                break;
            }
        }else{
            printf("Invalid height.\n");
        }
    }while(realHeight >= 270 || realHeight <= 46 || result == false);
    
    do{
        printf("Gender(Male/Female): ");
        scanf("\n%[^\n]", gender);
        lower(gender);
        result = validGender(gender);
        if(result == false){
            printf("Invalid gender.\n");
        }
    }while(result == false);

    do{
        printf("Level of Activity: ");
        scanf("\n%[^\n]", level);   
        lower(level);
        result = validLevel(level);
        if(result == false){
            printf("Invalid level.\n");
        }else{
            capitalize(level);
            break;
        }
    }while(result == false);

    bmr = findBmr(&realWeight, &realHeight, &realAge, gender);
    dcr = findDcr(level, &bmr);
    gender[0] = toupper(gender[0]);
    printf("\n\nName\t\t   : %s\nAge\t\t   : %d\nWeight(kg)\t   : %.2f\nHeight(cm)\t   : %.2f\nGender(Male/Female): %s\nLevel of Activity  : %s", name, realAge, realWeight, realHeight, gender, level);
    printf("\n\nBMR\t: %.2f\nDCR\t: %.2f\nNote\t: Based on this calculations, you would need %.2f calories from food to sustain your daily activities.", bmr, dcr, dcr);
}

bool validName(char* name){

    for(int i = 0; i < strlen(name); i++){
        if(name[i] == 32){
            if(name[i + 1] == 32){
                return false;
            }
        }
        if((name[i] < 97 || name[i] > 122) && name[i] != 32){
            return false;
            break;
        }else if(i == strlen(name) - 1){
            return true;
        }
    }
    
}

bool validAge(char* value){

    for(int i = 0; i < strlen(value); i++){
        if(value[i] < 48 || value[i] > 57){
            return false;
            break;
        }else if(i == strlen(value) - 1){
            return true;
        }
    }
}

bool validValue(char* value){

        if(value[0] == 46){
            return false;
        }
    int numberOfPeriod = 0;
    for(int i = 0; i < strlen(value); i++){
        if(value[i] == 46){
            numberOfPeriod++;
        }
        if((value[i] < 48 || value[i] > 57 ) && value[i] != 46){
            return false;
            break;
        }else if(numberOfPeriod > 1){
            return false;
            break;
        }
        else if(i == strlen(value) - 1){
            return true;
        }
    }    
}
bool validGender(char* gender){

    if((strcmp(gender, "male") == 0) || (strcmp(gender, "female") == 0)){
        return true;        
    }else{
        return false;
    }
}

bool validLevel(char* level){

    if((strcmp(level, "sedentary") == 0) || (strcmp(level, "light activity") == 0) || (strcmp(level, "moderate activity") == 0) || (strcmp(level, "very active") == 0) || (strcmp(level, "extra active") == 0)){
        return true;
    }else{
        return false;
    }
}
float findBmr(float* weight, float* height, int* realAge, char* gender){

    float bmr;
    if(strcmp(gender, "male") == 0){
        bmr = 66 + (13.7 * *weight) + (5 * *height) - (6.8 * *realAge);
    }else{
        bmr = 655 + (9.6 * *weight) + (1.8 * *height) - (4.7 * *realAge);
    }
    return bmr;
}

float findDcr(char* level, float* bmr){

    float dcr;
    if(strcmp(level, "Sedentary") == 0){
        dcr = *bmr * 1.2;
    }else if(strcmp(level, "Light Activity") == 0){
        dcr = *bmr * 1.375;
    }else if(strcmp(level, "Moderate Activity") == 0){
        dcr = *bmr * 1.55;
    }else if(strcmp(level, "Very Active") == 0){
        dcr = *bmr * 1.725;
    }else if(strcmp(level, "Extra Active") == 0){
        dcr = *bmr * 1.9;
    }
    return dcr;
}
void lower(char* value){

    for(int i = 0; i < strlen(value); i++){
        value[i] = tolower(value[i]);
    }
}

void capitalize(char* name){

    name[0] = toupper(name[0]);
    for(int i = 0; i < strlen(name); i++){
        if(name[i] == 32){
            name[i + 1] = toupper(name[i + 1]);
        }
    }
}
void printTable(){

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|   Level Of Activity    |\t\t\t\t\tActivities\t\t\t\t\t|\n");
    printf("|------------------------|--------------------------------------------------------------------------------------|\n");
    printf("| Sedentary\t\t | Little or no exercise, desk job\t\t\t\t\t\t\t|\n");
    printf("|------------------------|--------------------------------------------------------------------------------------|\n");
    printf("| Light Activity\t | Light exercise/sports 1-3 days/wk\t\t\t\t\t\t\t|\n");
    printf("|------------------------|--------------------------------------------------------------------------------------|\n");
    printf("| Moderate Activity\t | Moderate exercise/sports 3-5days/wk\t\t\t\t\t\t\t|\n");
    printf("|------------------------|--------------------------------------------------------------------------------------|\n");
    printf("| Very active\t\t | Hard exercise/sports 6-7 days/wk\t\t\t\t\t\t\t|\n");
    printf("|------------------------|--------------------------------------------------------------------------------------|\n");
    printf("| Extra Active\t\t | Hard daily exercise/sports & physical job or 2xday trainning, i.e. marathon, contest |\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}