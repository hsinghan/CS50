/****************************************************************************
 * credit.c
 *
 * Computer Science 50
 * Justin Chen
 *
 * Checks whether a credit card number is valid and returns type
 *
 ********/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool CardLengthIsValid(long long n);
void CheckCardVendor(long long n);
void PrintCardVendor(int n, long long ccn);

int main()
{
	long long ccn; // credit card number

	do
	{
	  ccn = get_long_long("Credit Card Number: ");
	} while (ccn < 0);
        
	if (CardLengthIsValid(ccn))
	{
	    // print card vendor
	    CheckCardVendor(ccn);
	}
	else
        {
    	    printf("INVALID\n");
	    return 0;
        }


	return 0;
}

bool CardLengthIsValid(long long ccn){
	// get the length of ccn
	int n = (int)log10(ccn)+1;
	if (n == 13 || n == 15 || n == 16)
	{
	   return true;
	}
	else
	   return false;
}

void CheckCardVendor(long long n){
       // test number : 378282246310005
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
	 PrintCardVender(total_sum, n);

}

void PrintCardVendor(int total_sum, long long n){

     if (total_sum % 10 == 0)
     {
          if ( (n >= 340000000000000 && n < 350000000000000) || (n >= 370000000000000 && n < 380000000000000))
          {
              printf("AMEX\n");
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
              printf("INVALID\n");

      }
      else
  	  printf("INVALID\n");
}

