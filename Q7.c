//Header
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Function prototype
int validNumber(char*);//character array
int validName(char*);//character array
int valid_id(char*);//character array
int valid_age(char*);//character array
int validGrossSalary(char*);//character array
float determineInsurance(int*);//pointer of element in int array
float determineIncomeTaxRate(float*);//pointer of element in float array
float determineAverageValue(float*, int*);//float array & pointer of int variable
void lower(char*);//character array
void capitalized(char*);//character array

//Main function
int main(){

  char number[5], id[5], age[3], grossSalary[8];//declaration of 1-dimensional character array
  int result, numberOfEmployee, repeatedName, t;
  float averageInsurance, averageGrossSalary, averageIncomeTax, averageIncomeTaxRate, averageNetSalary;

  do{
    printf("\nNumber of Employee: ");
    scanf("\n%[^\n]", number);//store the user input into a char array
    result = validNumber(number);//determine the validity of the user input

    //If the user input is not valid, the error message will be printed
    if(result == 0){
      printf("Letters or symbols are not allowed.\n");
    }else if(result == 2){
      printf("You shouldn't input the number starting from 0.\n");
    }else if(result == 3){
      printf("The number should be a positive value.\n");
    }else if(result == 4){
      printf("You shouldn't leave a space at the end of the number.\n");
    }else if(result == 5){
      printf("Invalid number, please input again.\n");
    }else{
      numberOfEmployee = atoi(number);//convert the character array to an int variable
      if(numberOfEmployee > 100){//determine if the number of employee is in the specified range
        printf("The maximum number is 100.\n");
      }
    }
  }while(numberOfEmployee > 100 || result != 1);

  //Used to store the information for each employee
  char name[numberOfEmployee][51];//declaration of 2-dimensional character array
  int idNumber[numberOfEmployee], realAge[numberOfEmployee];    
  float salary[numberOfEmployee], insurance_cost[numberOfEmployee], incometax_rate[numberOfEmployee], incomeTax[numberOfEmployee], netSalary[numberOfEmployee];

  for(int i = 0; i < numberOfEmployee; i++){
    do{
      printf("\nEmployee %d's name: ", i + 1);
      scanf("\n%[^\n]", name[i]);//store the user input into a 2-dimensional character array
      lower(name[i]);     
      result = validName(name[i]);//determine the validity of the user input
      if(result == 0){
        printf("Invalid name, please input again.\n");
      }else if (result == 2){
        printf("The name shouldn't less than 3 characters, please input again.\n");
      }else if (result == 3){
        printf("The name shouldn't more than 50 characters, please input again.\n");
      }else if(result == 4){
        printf("You shouln't leave a space at the end of the name.\n");
      }else if(result == 5){
        printf("You shouldn't space more than once between words of the name.\n");
      }else{
        capitalized(name[i]);
        for (t = 0; t < i; t++){//Determine if the name is repeated
          repeatedName = strcmp(name[i], name[t]);
          if(repeatedName == 0){
            printf("The name is repeated.\n");
            result = -1;//rerun the loop
            break;
          }
        }
      }
    }while(result != 1);

    do{
      printf("\nEmployee's ID(Exp:XXXX): ");
      scanf("\n%[^\n]", id);//store the user input into a character array
      result = valid_id(id);//determine the validity of the user input
      if(result == 0){
        printf("Invalid ID number, only digit is allowed.\n");
      }else if(result == 2){
        printf("You shouln't leave a space at the end of the ID.\n");
      }else if(result == 3){
        printf("Invalid ID number. (1000 < id < 9999)\n");
      }else if(result == 4){
        printf("You shouldn't put a space between the digits.\n");
      }else{
        idNumber[i] = atoi(id);//convert the character array to an integer variable
        if(idNumber[i] <= 1000 || idNumber[i] >= 9999){//Determine if the ID is in the specified range
          printf("Invalid ID number. (1000 < id < 9999)\n");
        }else{
          for(t = 0; t < i; t++){//determine if the ID is repeated
            if(idNumber[i] == idNumber[t]){
              printf("The ID number is repeated.\n");
              result = -1;//rerun the loop
              break;
            }
          }
        }
      }
    }while(idNumber[i] <= 1000 || idNumber[i] >= 9999 || result != 1);

    do{
      printf("\nEmployee's age: ");
      scanf("\n%[^\n]", age); //store the user input into a character array 
      result = valid_age(age);//determine the validity of the user input
      if(result == 0){
        printf("Invalid age, please input again.\n");   
      }else if(result == 2){
        printf("You shouldn't input the age starting from 0.\n");
      }else if (result == 3){
        printf("You shouldn't leave a space at the end of the age.\n"); 
      }else if (result == 4){
        printf("The age should be a positive value.\n");
      }else{
        realAge[i] = atoi(age);//convert the character array to a float variable
        if(realAge[i] <= 18 || realAge[i] >= 99){//determine if the age is in the specified range
          printf("The age should be in the range between 18 and 99.\n");
        }else{
          insurance_cost[i] = determineInsurance(&realAge[i]);//determine the insurance cost based on
                                                              //the age of the employee
        }
      }
    }while(realAge[i] <= 18 || realAge[i] >= 99 || result != 1);

    do{
      printf("\nEmployee's grossy salary (RM): ");
      scanf("\n%[^\n]", grossSalary);//store the user input into a character array
      result = validGrossSalary(grossSalary);//determine the validity of the user input
      if(result == 0){
        printf("Invalid value.\n");
      }else if(result == 2){
        printf("The gross salary should be a positive value.\n");
      }else if(result == 3){
        printf("You shouldn't leave a space at the end of the salary.\n");
      }else if(result == 4){
        printf("The salary should have only two decimal places.\n");
      }else{
        salary[i] = atof(grossSalary);//convert the character array to a float variable
        if(salary[i] <= 0.0 || salary[i] >= 9999.99){//determine if the gross salary is in the specified range
          printf("The salary should be in the range between RM 0.0 and RM 9999.99.\n");
        }else{
          incometax_rate[i] = determineIncomeTaxRate(&salary[i]);//determine the income tax rate of the
                                                                 //employee based on his gross salary
        }
      }
    }while(result != 1 || salary[i] <= 0.0 || salary[i] >= 9999.99);

    incomeTax[i] = salary[i] * incometax_rate[i];//Calculate the income tax
    netSalary[i] = salary[i] - incomeTax[i] - insurance_cost[i];//Calculate the netSalary
  }
  
//Calculate the average value
averageInsurance = determineAverageValue(insurance_cost, &numberOfEmployee);
averageGrossSalary = determineAverageValue(salary, &numberOfEmployee);
averageIncomeTax = determineAverageValue(incomeTax, &numberOfEmployee); 
averageIncomeTaxRate = determineAverageValue(incometax_rate, &numberOfEmployee);
averageNetSalary = determineAverageValue(netSalary, &numberOfEmployee);

//Print the payroll table
  printf ("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
  printf("| No. | Name\t\t\t\t\t\t   |   ID   |  Age  |  Insurance  |  GrossSalary  | IncomeTaxRate | IncomeTax  |  NetSalary  |\n");
  printf("|-----|----------------------------------------------------|--------|-------|-------------|---------------|---------------|------------|-------------|\n");

  for(int i = 0; i < numberOfEmployee; i++){
    printf("|%3d  | %-51s|%6d  |%5d  |  RM %-8.2f|  RM %-10.2f|%9.1f%%     |  RM %-7.2f|  RM %-8.2f|\n", i + 1, name[i], idNumber[i], realAge[i], insurance_cost[i], salary[i],incometax_rate[i] * 100, incomeTax[i], netSalary[i]);
    if(i == numberOfEmployee - 1){
        printf("|-----|---------------------------------------------------------------------|-------------|---------------|---------------|------------|-------------|\n");
    }else{
        printf("|-----|----------------------------------------------------|--------|-------|-------------|---------------|---------------|------------|-------------|\n");
    }
  }

  printf("|     |\t\t\tAverage\t\t\t\t\t\t    |  RM %-8.2f|  RM %-10.2f|%11.3f%%   |  RM %-7.2f|  RM %-8.2f|\n", averageInsurance, averageGrossSalary, averageIncomeTaxRate * 100, averageIncomeTax , averageNetSalary);
  printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

//Function definition
int validNumber(char* number){
  //Several conditions for invalid user input
  if(number[0] == 48){//First char is 0
    return 2;
  }else if(number[0] == 45){//First char is negative sign
    return 3;
  }else if(number[strlen(number) - 1] == 32){//Last char is space
    return 4;
  }
  for(int i = 0; i < strlen(number); i++){//Check for every character of the user input
    if(number[i] == 32){//if there is space in the user input
      return 5;
    }else if(number[i] < 48 || number[i] > 57){//Not a digit
      return 0;
    }else if(i == strlen(number) - 1){//Final loop
      return 1;
    }
  }
}

int validName(char* name){
  if(strlen(name) < 3){//Length of name less than 3 characters
    return 2;
  }else if(strlen(name) > 50){//Length of name greater than 50 characters
    return 3;
  }else if(name[strlen(name) - 1] == 32){//Last char is space
    return 4;
  }
  for(int i = 0; i < strlen(name); i++)
  {
    if(name[i+1] == 32 && name[i] == 32){//Space more than once between words of name
      return 5;
    }else if((name[i] < 97 || name[i] > 122) && name[i] != 32){//Not a lowercase letter & not a space
      return 0;
    }else if(i == strlen(name) - 1){//Final loop
      return 1;
    }
  }
}  

int valid_id(char* id){
  if(id[strlen(id) - 1] == 32){//Last char is space
    return 2;
  }else if(id[0] == 48){//First char is 0
    return 3;
  }
  for(int i = 0; i < strlen(id); i++){
    if(id[i] == 32){//If there is a space in the id
      return 4;
    }else if(id[i] < 48 || id[i] > 57){//not a digit
      return 0;
    }else if(i == strlen(id) - 1){//final loop
      return 1;
    }
  }
}

int valid_age(char* age){
  if(age[0] == 48){//First char is 0
    return 2;
  }else if(age[strlen(age) - 1] == 32){//Last char is space
    return 3;
  }else if(age[0] == 45){//First char is negative sign
    return 4;
  }
  for(int i = 0; i < strlen(age); i++){
    if(age[i] < 48 || age[i] > 57){//not a digit
      return 0;
    }else if(i == strlen(age) - 1){//final loop
      return 1;
    }
  }
}

int validGrossSalary(char* salary){
  int numberOfPeriod = 0;
  if (salary[0] == 46){//First char is period
    return 0;
  }else if(salary[0] == 48){//First char is 0
    if(salary[1] != 46){//Second char is not period
      return 0;
    }
  }else if(salary[0] == 45){//First char is negative sign
    return 2;
  }else if(salary[strlen(salary) - 1] == 32){//Last char is space
    return 3;
  }
  for(int i = 0; i < strlen(salary); i++){
    if(salary[i] == 46){//If there is a peiod in the salary
      numberOfPeriod++;
      if(salary[i + 3] <= 57 && salary[i + 3] >= 48){//having three decimal places
        return 4;
      }
    }
    if(numberOfPeriod > 1){//more than one period
      return 0;
    }
    if((salary[i] < 48 || salary[i] > 57) && salary[i] != 46){//not a digit & not a period
        return 0; 
    }else if(i == strlen(salary) - 1){//final loop  
      return 1;
    }
  }
}

float determineInsurance(int* realAge){
  float result;
  if(*realAge <= 35){//dereference to get the value of realAge
    result = 110;
  }else if(*realAge >= 36 && *realAge <= 65){ 
    result = 160;
  }else if(*realAge > 65){
    result = 250;
  }
  return result;
}

float determineIncomeTaxRate(float* salary){
  float result;
  if(*salary < 1000){//dereference to get the value of the salary
    result = 0.0;
  }else if(*salary >= 1000 && *salary <= 2999.99){
    result = 0.025;
  }else if(*salary >= 3000){
    result = 0.05;
  }
  return result;
}

float determineAverageValue(float* value, int* number){
  float average;
  float total = 0.0;
  for(int i = 0; i < *number; i++){//dereference to get the value of number of employee
    total += value[i]; 
  }
  average = total / *number; 
  return average;
}

void lower(char* name){
  for(int i = 0; i < strlen(name); i++){    
    name[i] = tolower(name[i]);//Make all the letter to become lowercase letter
  }
}

void capitalized(char* name){
  name[0] = toupper(name[0]);//Capitalize first letter of the name
  for(int i = 0; i < strlen(name); i++){
    if(name[i] == 32){//If there is a space between words of name
      name[i+1] = toupper(name[i+1]);//The char next to the space should be capitalized
    }
  }
}