/****************************************************************************
 * credit.c
 *
 * Computer Science 50
 * Justin Chen
 *
 * Checks whether a credit card number is valid and returns type
 *
 * This version I need to revise, because it still make me confusing
 ********/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool CardLengthIsValid(long long n);
void CheckCardVender(long long n);

int main()
{
	long long ccn; // credit card number

	do
	{
	  ccn = get_long_long("Credit Card Number: ");
	} while (ccn < 0);

	if (CardLengthIsValid(ccn))
	{
	    CheckCardVender(ccn);
	}
	else
        {
    	    printf("INVALID\n");
  	    return 0;
        } 
    
	return 0;
}

bool CardLengthIsValid(long long ccn){
	int n = (int)log10(ccn)+1;
	if (n == 13 || n == 15 || n == 16)
	{
	   return true;
	}
	else
	    return false;
}

void CheckCardVender(long long n){
       
	int total_sum = 0, sum1 = 0, sum2 = 0;
	long long card_number, res1;

	for ( card_number = n; card_number > 0; card_number /= 100)
	{
	     sum1 += card_number%10;
	}

	for (res1 = n/10 ; res1 > 0; res1 /= 100)
	 {
	     if ((2 * (res1%10)) > 9)
	 	{
	           sum2 += (2 * (res1%10)) / 10;
	 	   sum2 += (2 * (res1%10)) % 10;
	 	}
	 	else
	 	    sum2 += (2 * (res1%10));
	 }

	total_sum = sum1 + sum2;
   
   // check the card number range
	if (total_sum % 10 == 0)
  	{
           if ( (n >= 340000000000000 && n < 350000000000000) || (n >= 370000000000000 && n < 380000000000000))
           {
              printf("AMERICA EXPRESS\n");
           }
           else if (n >= 5100000000000000 && n < 5600000000000000)
           {
              printf("MASTERCARD\n");
           }
           else if ((n >= 4000000000000 && n < 5000000000000)|| (n >= 4000000000000000 && n < 5000000000000000))
           {
              printf("VISA\n");
            }
           else
              printf("VALID\n");
		
  	 }
 	 else
  	    printf("INVALID\n");
}


// American Express uses 15-digit numbers,
// American Express numbers all start with 34 or 37; 

// MasterCard uses 16-digit numbers, 
// MasterCard numbers all start with 51, 52, 53, 54, or 55;

// Visa uses 13- and 16-digit numbers.
// Visa numbers all start with 4
