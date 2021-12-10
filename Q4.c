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

	if(*isCountry){
        if(strcmp(name, "Japan") == 0){
            return "Tokyo";
        }else if(strcmp(name, "Canada") == 0){
            return "Ottawa";
        }else if(strcmp(name, "England") == 0){
            return "London";
        }else{
            return "Not found";
        }
    }else{
        if(strcmp(name, "Tokyo") == 0){
            return "Japan";
        }else if(strcmp(name, "Ottawa") == 0){
            return "Canada";
        }else if(strcmp(name, "London") == 0){
            return "England";
        }else{
            return "Not found";
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