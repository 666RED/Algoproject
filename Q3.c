#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>

void printTable();
void equivalent(char*, char*);
int main(){

    char alphabet[9] = {'B', 'C', 'D', 'F', 'G', 'I', 'J', 'M', 'S'};
    char command;
    bool correctInput1;
    bool correctInput2;
    do{
        char firstCurrency, secondCurrency;
        printTable();
        do{
            correctInput1 = false;
            printf("\nPlease input the alphabet of the first desired currency: ");
            firstCurrency = getch();
            printf("%c",firstCurrency);
            firstCurrency = toupper(firstCurrency);
            for(int i = 0; i <= 9; i++){
                if(firstCurrency == alphabet[i]){
                    correctInput1 = true;
                    break;
                }
            }
            if(correctInput1 == false){
                printf("\nInvalid input.\n");
            }
        }while(correctInput1 == false);
        do{
            do{
                correctInput2 = false;
                printf("\nPlease input the alphabet of the second desired currency: ");
                secondCurrency = getch();
                printf("%c",secondCurrency);
                secondCurrency = toupper(secondCurrency);
                if(secondCurrency == firstCurrency){
                    printf("\nBoth of the currencies should be different.\n");
                }
            }while(secondCurrency == firstCurrency);
            for(int i = 0; i <= 9; i++){
                if(secondCurrency == alphabet[i]){
                    correctInput2 = true;
                    break;
                }
            }
            if(correctInput2 == false){
                printf("\nInvalid input.\n");
            }
        }while(correctInput2 == false);
                  
        equivalent(&firstCurrency, &secondCurrency);
        do{       
            printf("\nDo you want to use this system again?(Y/N): ");
            command = getch();
            printf("%c",command);
            command = toupper(command);
            if(command != 'Y' && command != 'N'){
                printf("\nInvalid input.\n");
            }
        }while(command != 'Y' && command != 'N');
    }while(command != 'N' && command == 'Y');
    printf("\nThanks for using!");
}

void printTable(){

    printf("\n--------------------------------------------------------------------\n");
    printf("|  Alphabet  |\tCountry & Currency  |\t\tEquivalent\t   |\n");
    printf("|------------|----------------------|------------------------------|\n");

    printf("|     B      |\t   British pound    |\t0.65 pound per U.S dollar  |\n");
    printf("|------------|----------------------|------------------------------|\n");
    printf("|     C      |\t   Canadian dollar  |\t1.5 dollars per U.S dollar |\n");
    printf("|------------|----------------------|------------------------------|\n");
    printf("|     D      |\t   Dutch guilder    |\t1.7 guilders per U.S dollar|\n");
    printf("|------------|----------------------|------------------------------|\n");
    printf("|     F      |\t   French franc     |\t5.3 francs per U.S dollar  |\n");
    printf("|------------|----------------------|------------------------------|\n");
    printf("|     G      |\t   German mark      |\t1.5 marks per U.S dollar   |\n");
    printf("|------------|----------------------|------------------------------|\n");
    printf("|     I      |\t   Italian lira     |\t1570 lira per U.S dollar   |\n");
    printf("|------------|----------------------|------------------------------|\n");
    printf("|     J      |\t   Japanese yen     |\t98 yen per U.S dollar\t   |\n");
    printf("|------------|----------------------|------------------------------|\n");
    printf("|     M      |\t   Mexican peso     |\t3.5 pesos per U.S dollar   |\n");
    printf("|------------|----------------------|------------------------------|\n");
    printf("|     S      |\t   Swiss franc      |\t1.3 francs per U.S dollar  |\n");
    printf("--------------------------------------------------------------------\n");
}

void equivalent(char* first, char* second){

    switch(*first){
        case 'B' :
            printf("\n1 British pound = ");
            switch(*second){
                case 'C' : printf("%.5f Canadian dollar.", 1.5 / 0.65);
                break;
                case 'D' : printf("%.5f Dutch guilder.", 1.7 / 0.65);
                break;
                case 'F' : printf("%.5f French franc", 5.3 / 0.65);
                break;
                case 'G' : printf("%.5f German mark.", 1.5 / 0.65);
                break;
                case 'I' : printf("%.5f Italian lira.", 1570 / 0.65);
                break;
                case 'J' : printf("%.5f Japenese yen", 98 / 0.65);
                break;
                case 'M' : printf("%.5f Mexican peso.", 3.5 / 0.65);
                break;
                case 'S' : printf("%.5f Swiss franc", 1.3 / 0.65);
                break;
            }
            break;
        case 'C' :
            printf("\n1 Canadian dollar = ");
            switch(*second){
                case 'B' : printf("%.5f British pound.", 0.65 / 1.5);
                break;
                case 'D' : printf("%.5f Dutch guilder.", 1.7 / 1.5);
                break;
                case 'F' : printf("%.5f French franc", 5.3 / 1.5);
                break;
                case 'G' : printf("%.5f German mark.", 1.5 / 1.5);
                break;
                case 'I' : printf("%.5f Italian lira.", 1570 / 1.5);
                break;
                case 'J' : printf("%.5f Japenese yen", 98 / 1.5);
                break;
                case 'M' : printf("%.5f Mexican peso.", 3.5 / 1.5);
                break;
                case 'S' : printf("%.5f Swiss franc", 1.3 / 1.5);
                break;
            }
            break;
        case 'D' :
            printf("\n1 Dutch guilder = ");
            switch(*second){
                case 'B' : printf("%.5f British pound.", 0.65 / 1.7);
                break;
                case 'C' : printf("%.5f Canadian dollar.", 1.5 / 1.7);
                break;
                case 'F' : printf("%.5f French franc", 5.3 / 1.7);
                break;
                case 'G' : printf("%.5f German mark.", 1.5 / 1.7);
                break;
                case 'I' : printf("%.5f Italian lira.", 1570 / 1.7);
                break;
                case 'J' : printf("%.5f Japenese yen", 98 / 1.7);
                break;
                case 'M' : printf("%.5f Mexican peso.", 3.5 / 1.7);
                break;
                case 'S' : printf("%.5f Swiss franc", 1.3 / 1.7);
                break;
            }
            break;
        case 'F' :
            printf("\n1 French franc = ");
            switch(*second){
                case 'B' : printf("%.5f British pound.", 0.65 / 5.3);
                break;
                case 'C' : printf("%.5f Canadian dollar.", 1.5 / 5.3);
                break;
                case 'D' : printf("%.5f Dutch guilder", 1.7 / 5.3);
                break;
                case 'G' : printf("%.5f German mark.", 1.5 / 5.3);
                break;
                case 'I' : printf("%.5f Italian lira.", 1570 / 5.3);
                break;
                case 'J' : printf("%.5f Japenese yen", 98 / 5.3);
                break;
                case 'M' : printf("%.5f Mexican peso.", 3.5 / 5.3);
                break;
                case 'S' : printf("%.5f Swiss franc", 1.3 / 5.3);
                break;
            }
            break;
        case 'G' :
            printf("\n1 German mark = ");
            switch(*second){
                case 'B' : printf("%.5f British pound.", 0.65 / 1.5);
                break;
                case 'C' : printf("%.5f Canadian dollar.", 1.5 / 1.5);
                break;
                case 'D' : printf("%.5f Dutch guilder", 1.7 / 1.5);
                break;
                case 'F' : printf("%.5f French franc.", 5.3 / 1.5);
                break;
                case 'I' : printf("%.5f Italian lira.", 1570 / 1.5);
                break;
                case 'J' : printf("%.5f Japenese yen", 98 / 1.5);
                break;
                case 'M' : printf("%.5f Mexican peso.", 3.5 / 1.5);
                break;
                case 'S' : printf("%.5f Swiss franc", 1.3 / 1.5);
                break;
            }
            break;
        case 'I' :
            printf("\n1 Italian lira = ");
            switch(*second){
                case 'B' : printf("%.5f British pound.", 0.65 / 1570);
                break;
                case 'C' : printf("%.5f Canadian dollar.", 1.5 / 1570);
                break;
                case 'D' : printf("%.5f Dutch franc", 1.7 / 1570);
                break;
                case 'F' : printf("%.5f French franc.", 5.3 / 1570);
                break;
                case 'G' : printf("%.5f German mark.", 1.5 / 1570);
                break;
                case 'J' : printf("%.5f Japenese yen", 98 / 1570);
                break;
                case 'M' : printf("%.5f Mexican peso.", 3.5 / 1570);
                break;
                case 'S' : printf("%.5f Swiss franc", 1.3 / 1570);
                break;
            }
            break;
        case 'J' :
            printf("\n1 Japanese yen = ");
            switch(*second){
                case 'B' : printf("%.5f British pound.", 0.65 / 98);
                break;
                case 'C' : printf("%.5f Canadian dollar.", 1.5 / 98);
                break;
                case 'D' : printf("%.5f Dutch guilder", 1.7 / 98);
                break;
                case 'F' : printf("%.5f French franc.", 5.3 / 98);
                break;
                case 'G' : printf("%.5f German mark.", 1.5 / 98);
                break;
                case 'I' : printf("%.5f Italian lira.", 1570.0 / 98);
                break;
                case 'M' : printf("%.5f Mexican peso.", 3.5 / 98);
                break;
                case 'S' : printf("%.5f Swiss franc", 1.3 / 98);
                break;
            }
            break;
        case 'M' :
            printf("\n1 Mexico peso = ");
            switch(*second){
                case 'B' : printf("%.5f British pound.", 0.65 / 3.5);
                break;
                case 'C' : printf("%.5f Canadian dollar.", 1.5 / 3.5);
                break;
                case 'D' : printf("%.5f Dutch guilder", 1.7 / 3.5);
                break;
                case 'F' : printf("%.5f French franc.", 5.3 / 3.5);
                break;
                case 'G' : printf("%.5f German mark.", 1.5 / 3.5);
                break;
                case 'I' : printf("%.5f Italian lira", 1570 / 3.5);
                break;
                case 'J' : printf("%.5f Japanese yen.", 98 / 3.5);
                break;
                case 'S' : printf("%.5f Swiss franc", 1.3 / 3.5);
                break;
            }
            break;
        case 'S' :
            printf("\n1 Swiss franc = ");
            switch(*second){
                case 'B' : printf("%.5f British pound.", 0.65 / 1.3);
                break;
                case 'C' : printf("%.5f Canadian dollar.", 1.5 / 1.3);
                break;
                case 'D' : printf("%.5f Dutch guilder", 1.7 / 1.3);
                break;
                case 'F' : printf("%.5f French franc.", 5.3 / 1.3);
                break;
                case 'G' : printf("%.5f German mark.", 1.5 / 1.3);
                break;
                case 'I' : printf("%.5f Italian lira", 1570 / 1.3);
                break;
                case 'J' : printf("%.5f Japanese yen.", 98 / 1.3);
                break;
                case 'M' : printf("%.5f Mexican peso", 3.5 / 1.3);
                break;
            }
            break;
    }
}