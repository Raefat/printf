#include "main.h"

/**
 * print_number - Prints an integer to stdout
 * @num: The integer to be printed
 *
 * Return: Number of characters printed
 */

int print_number(int num)
{

        int i, isNegative = 0, numDigits = 0;
	int temp = num;
        char *str;

        if (num == 0)
         {
                write(1, "0", 1);
                return 1;
         }
         if (num < 0)
         {
                 isNegative = 1;
                 num = -num;
         }
         while (temp != 0)
         {
                 temp /= 10;
                 numDigits++;
         }
	 str = (char *)malloc(numDigits + isNegative);
	 if (str == NULL)
		 return (-1);
	 for (i = numDigits + isNegative - 1; i >= isNegative; i--)
	 {
		 str[i] = '0' + num % 10;
		 num /= 10;
	 }
	 if (isNegative)
		 str[0] = '-';
	 write(1, str, numDigits + isNegative);
	 free(str);
	 return numDigits + isNegative - 1;
}
