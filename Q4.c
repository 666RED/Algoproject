#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* find(char*, bool*);
void capitalize(char*);
void lower(char*);

int main(){

    char countryOrCapital;
    bool end;
    do{
        char name[30];
		char name1[30];
        bool isCountry;
        char command[10];
        bool invalidInput;
        do{
            end = false;
            invalidInput = false;
            printf("\nCountry(A), Capital(B): ");
            countryOrCapital = getch();
            printf("%c",countryOrCapital);
            countryOrCapital = toupper(countryOrCapital);

            if(countryOrCapital == 'A'){
                isCountry = true;
                printf("\nPlease input the country's name: ");
				scanf("\n%[^\n]", name);
				capitalize(name);
				strcpy(name, find(name, &isCountry));
				if(strcmp(name, "Not found") == 0){
					printf("%s", name);
				}else{
					printf("Capatil: %s", name);
				}
			}else if(countryOrCapital == 'B'){
                isCountry = false;
                printf("\nPlease input the capital's name: ");
                scanf("\n%[^\n]", name);
                capitalize(name);
				strcpy(name, find(name, &isCountry));
				if(strcmp(name, "Not found") == 0){
					printf("%s", name);
				}else{
					printf("Country: %s", name);
				}
            }else{
                printf("\nInvalid input.\n");
                invalidInput = true;
            }
        }while(invalidInput == true);

        do{
            printf("\nContinue(Con) / End:\n");
            scanf("\n%[^\n]", command);
            capitalize(command);
            if(strcmp(command, "Con") == 0){
                break;
            }else if(strcmp(command, "End") == 0){
                end = true;
                printf("\nThanks for using!");
                break;
            }else{
                printf("\nInvalid input.");
                invalidInput = true;
            }
        }while(invalidInput == true);
    }while(end == false);
}

char* find(char* name, bool* isCountry){

	int sizeOfCountry = 12;
    int sizeOfCapital = 12;
	char** country = (char**)malloc(sizeOfCountry * sizeof(char*));
	char** capital = (char**)malloc(sizeOfCapital * sizeof(char*));
	for(int i = 0; i < sizeOfCountry; i++){
		country[i] = (char*)malloc(30 * sizeof(char));
		capital[i] = (char*)malloc(30 * sizeof(char));
	}
	country[0] = "Canada";
	country[1] = "England";
	country[2] = "France";
	country[3] = "Germany";
	country[4] = "India";
	country[5] = "Israel";
	country[6] = "Italy";
	country[7] = "Japan";
	country[8] = "Mexico";
	country[9] = "People's";
	country[10] = "Russia";
	country[11] = "United States";

	capital[0] = "Ottawa";
	capital[1] = "London";
	capital[2] = "Paris";
	capital[3] = "Bonn";
	capital[4] = "New Delhi";
	capital[5] = "Jerusalem";
	capital[6] = "Rome";
	capital[7] = "Tokyo";
	capital[8] = "Mexico City";
	capital[9] = "Republic of China Beijing";
	capital[10] = "Moscow";
	capital[11] = "Washington";

	for(int i = 0; i < sizeOfCountry; i++){
		if(*isCountry){
			if(strcmp(name, country[i]) == 0){
				return capital[i];
				for(int i = 0; i < sizeOfCountry; i++){
					free(country[i]);
					free(capital[i]);
				}
				break;
			}else if(i == sizeOfCountry - 1){
				return ("Not found.");
				for(int i = 0; i < sizeOfCountry; i++){
					free(country[i]);
					free(capital[i]);
				}
				break;
			}
		}else{
			if(strcmp(name, capital[i]) == 0){
				return country[i];
				for(int i = 0; i < sizeOfCountry; i++){
					free(country[i]);
					free(capital[i]);
				}
				break;
			}else if(i == sizeOfCountry - 1){
				return ("Not found.");
				for(int i = 0; i < sizeOfCountry; i++){
					free(country[i]);
					free(capital[i]);
				}
				break;
			}			
		}
	}
}

void lower(char* name){

	for(int i = 0; i < strlen(name); i++){
		name[i] = tolower(name[i]);
	}
}

void capitalize(char* name){
	
	lower(name);
	name[0] = toupper(name[0]);
    for(int i = 0; i < strlen(name); i++){
        if(name[i] == 32){
			name[i + 1] = toupper(name[i + 1]);
		}
    }
}