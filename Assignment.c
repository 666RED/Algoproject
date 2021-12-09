#include <stdio.h>
// determine the first rational zero
int firstRationalZero(int* b, int* c, int* d, int* number){
    for(int i = 1; i <= *number; i++){
        int negative = -i;
        // for positive value of p/q
        int positiveRationalZero = (i * i * i) + (*b * i * i) + (*c * i) + *d;
        //for negative value of p/q
        int negativeRationalZero = (negative * negative * negative) + (*b * negative * negative) + (*c * negative) + *d;
        if(positiveRationalZero == 0){
            return i;
            break;
        }else if(negativeRationalZero == 0){
            return negative;
            break;
        }else if(i == *number){
            return 0; // no rational zero is found
        }
    }
}   
//print out the possible value of p/q
int rationalZero(int* number, int* i){
    if(*number % *i == 0){
        return *i;
    }else{
        return 0;
    }
}
///////////////////////////////////MAIN///////////////////////////////////////////////
int main(){
    const int A = 1;
    int b, c, d, number, p, q;
    //get the user input
    printf("Insert value of b, c and d:\n");
    printf("b:");
    scanf("%d",&b);
    printf("c:");
    scanf("%d",&c);
    printf("d:");
    scanf("%d",&d);
    //print the equation 
    printf("\nThe polynomial is %dx^3 + %dx^2 + %dx + %d\n",A, b, c, d);
    printf("--------------------------------------------------\n\n");
    p = d;
    q = A;
    //print the value of p and q
    printf("p = %d\nq = %d\n\n",p, q);
    //if constant = 0
    if(d == 0){
        printf("Possible rational zero are:\n---\n\n%d\n\nThe first rational zero = %d",d, d);
        return 0;
    }
    printf("Possible rational zero are:\n---\n\n");
    //make sure the for loop can run
    if(d < 0){
        number = -d;
    }else{
        number = d;
    }
    //print the possible value of p/q
    for(int i = 1; i <= number; i++){
        int answer = rationalZero(&number, &i);
        if(answer != 0){
            printf("%d\n%d\n",answer, -answer);
        }
    }
    //determine the rational zero
    int answer = firstRationalZero(&b, &c, &d, &number);
    if(answer != 0){
        printf("\nThe first rational zero = %d",answer);
    }else{
        printf("\nNo rational zero found!"); // no rational number is found
    }
}
   