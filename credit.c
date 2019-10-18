#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long card = get_long_long("Number: ");
    int digit;

    // for getting number of digits
    int count = 0;

    // two copies of the card
    long long card_num = card;
    long long card_num1 = card_num;

    // getting number of digits in the card
    while(((float)card)/10 > 0)
    {
        digit = card % 10;
        card /= 10;
        count ++;
    }

    // vaue of counts for the two arrays of digits
    int count1, count2;
    if(count % 2 == 0)
    {
        count1 = count2 = count / 2;
    }
    else
    {
        count1 = (count + 1) / 2;
        count2 = count - count1;
    }

    // the two arrays of digits
    int num1[count1];
    int num2[count2];

    // getting array of every other digits staring from the last
    for(int i = 0; i < count1; i++)
    {
        num1[i] = card_num % 10;
        card_num /= 100;
        // printf("%i  ", num1[i]);
    }
    // printf("\n");

    // removing the last digit from the card
    card_num1 /= 10;

    // getting the array of every other digits staring from the second-last
    for(int i = 0; i < count2; i++)
    {
        num2[i] = card_num1 % 10;
        card_num1 /= 100;
        // printf("%i  ", num2[i]);
    }
    // printf("\n");

    int num3[count2];

    for(int i = 0; i < count2; i++)
    {
        num3[i] = num2[i];
    }

    // multiplying each digit of num3 array by 2
    for(int i=0; i<count2; i++)
    {
        num3[i] *= 2;
        // printf("%i  ", num3[i]);
    }
    // printf("\n");

    // the two sums
    int sum1 = 0;
    int sum2 = 0;

    // calculating the 2 sums
    for(int i = 0; i < count1; i++)
    {
        sum1 += num1[i];
    }
    // printf("%i\n", sum1);

    for(int i = 0; i < count2; i++)
    {
        if(num3[i] > 9)
        {
            sum2 = sum2 + num3[i]/10 + num3[i]%10;
        }
        else
        {
            sum2 += num3[i];
        }

    }
    // printf("%i\n", sum2);

    // calculating the final sum
    int sum = sum1 + sum2;
    // printf("%i\n", sum);

    // validating the card
    if(sum % 10 == 0)
    {
        if(count % 2 == 0)
        {
            if(num2[count2-1] == 4)
            {
                printf("Visa\n");
            }
            else if(num2[count2-1] == 5 && (num1[count1-1] == 1 || num1[count1-1] == 2 || num1[count1-1] == 3 || num1[count1-1] == 4 || num1[count1-1] == 5))
            {
                printf("Master Card\n");
            }
            else if(num2[count2-1] == 3 && (num1[count1-1] == 4 || num1[count1-1] == 7))
            {
            printf("American Express\n");
            }
        }
        else
        {
            if(num1[count1-1] == 4)
            {
                printf("Visa\n");
            }
            else if(num1[count1-1] == 5 && (num2[count2-1] == 1 || num2[count2-1] == 2 || num2[count2-1] == 3 || num2[count2-1] == 4 || num2[count2-1] == 5))
            {
                printf("Master Card\n");
            }
            else if(num1[count1-1] == 3 && (num2[count2-1] == 4 || num2[count2-1] == 7))
            {
            printf("American Express\n");
            }
        }
    }
    else
    {
        printf("card is invalid\n");
    }
}