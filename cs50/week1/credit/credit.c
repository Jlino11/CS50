#include <cs50.h>
#include <stdio.h>

long removelastdigit(long n);
int getdigit(long n);
bool checksum(int n);
void thecompanyis(int d1, int d2, int count);
void invalid();

int main()
{
    int parcialsum = 0;
    int parcialmult = 0;
    int digit = 0;
    int d1 = 0;
    int d2 = 0;
    int count = 0;

    long creditcardnumber = get_long("Number: ");
    while (creditcardnumber > 9)
    {
        count += 2;
        d2 = getdigit(creditcardnumber);
        parcialsum += d2;
        creditcardnumber = removelastdigit(creditcardnumber);
        d1 = getdigit(creditcardnumber);
        parcialmult += getdigit(d1 * 2) + removelastdigit(d1 * 2);
        creditcardnumber = removelastdigit(creditcardnumber);
    }
    if (creditcardnumber > 0)
    {
        count++;
        int last = creditcardnumber % 10;
        parcialsum += last;
        d2 = d1;
        d1 = last;
    }
    int total = parcialsum + parcialmult;
    if (checksum(total))
    {
        thecompanyis(d1, d2, count);
    }
    else
    {
        invalid();
    }
}

long removelastdigit(long n)
{
    return n / 10;
}

int getdigit(long n)
{
    return n % 10;
}

bool checksum(int n)
{
    if (getdigit(n) == 0)
    {
        return true;
    }
    return false;
}

void thecompanyis(int d1, int d2, int count)
{
    if (d1 == 4 || d1 == 3 || d1 == 5)
    {
        if (d1 == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else if (d1 == 3 && (d2 == 7 || d2 == 4) && count == 15)
        {
            printf("AMEX\n");
        }
        else if (d1 == 5)
        {
            if ((d2 == 1 || d2 == 2 || d2 == 3 || d2 == 4 || d2 == 5) && count == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                invalid();
            }
        }
        else
        {
            invalid();
        }
    }
    else
    {
        invalid();
    }
}

void invalid()
{
    printf("INVALID\n");
}
