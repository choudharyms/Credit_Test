#include <stdio.h>
#include <cs50.h>
int know_len (long l);
void check_sum (long n);
void check_startn (long s);






int main (void)
{
    long cardn;

    // Get Card Number From User
    do
    {
        cardn = get_long ("Enter Card Number: ");
    }
    while (cardn<1);

    // Get Card lenght and check if length is valid
    int k = know_len (cardn);
    if (k != 13 && k != 15 && k != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Checksum Function Integration Based on Luhn's Algorithm
    check_sum (cardn);

    // Check For Starting Numbers
    check_startn (cardn);
}























void check_startn(long s)
{
    long n = s;
    do
    {
        s = s / 10;
    }
    while (s > 100);
    // Checking starting digits for the card type
    if ((s / 10 == 5) && (0 < s % 10 && s % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((s / 10 == 3) && (s % 10 == 4 || s % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (s / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}








int know_len (long l)
{
    int i=0;
    while (l>0)
    {
        l=l/10;
        i++;
    }
    return i;
}







void check_sum (long n)
{
    int sum1 = 0;
    int sum2 = 0;
    long x = n;
    int total = 0;
    int d1;
    int d2;
    int mod1;
    int mod2;
    do
    {
        // Remove last digit
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;
        // 2 times second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);
    total = sum1 + sum2;
    // Checking Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");

    }

}
