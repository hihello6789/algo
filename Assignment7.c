/*Write a programe to input a string and check if it is a palindrome. The programe must be robust enough for differet kinds of input, 
eleminating junk input and showing error message for invalid input*/
#include<stdio.h>
int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d",a);
    int num = 0;
    int digit = num % 10;
    int reversed = reversed*10 + digit;
    num = num/10;

    printf("Reversed: %d", reversed);
    
}
