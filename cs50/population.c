#include <stdio.h>
#include <cs50.h>

int born(int a);
int pass_away(int a);
int print_years(int years_main);
int check_start(void);
int check_end(int start);
int check_equal(int start, int end);
int process(int start, int end);
int process(int start, int end);

int main(void)
{
    int start_main = check_start();
    int end_main = check_end(start_main);
    check_equal(start_main, end_main);

}

int born(int a)
{
    return a / 3;
}

int pass_away(int a)
{
    return a / 4;
}

int check_start(void)
{
    int start1;
    do
    {
        start1 = get_int("\nStart size: ");

    }while(start1 < 8);

    return start1;
}

int check_end(int start2)
{
    int end2;
    do
    {
        end2 = get_int("\nEnd size: ");

    }while(end2 <= start2);

    return end2;
}

int check_equal(int start3, int end3)
{
    if (start3 == end3)
    {
        int zero = 0;
        return print_years(zero);
    }
    else
    {
        return process(start3, end3);
    }
}

int process(int start4, int end4)
{
    int year = 0;

    while (start4 < end4)
    {
        int add = born(start4);
        int less = pass_away(start4);
        start4 = start4 + add - less;
        year ++;
    }
    return print_years(year);
}

int print_years(int years_main)
{
    return printf("\nYears: %i\n", years_main);
}
