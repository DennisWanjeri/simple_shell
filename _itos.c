#include "holberton.h"

/**
 * numlen - counts number of 0s in a tens power number
 * @n: number
 * Return: returns count of digits
 */
int numlen(int n)
{
  int count = 0;
  int num = n;

  while (num > 9 || num < -9)
    {
      num /= 10;
      count++;
    }
  return (count);
}
/**
 * _itos - turns an int into a string
 * @num: int
 * Return: returns the int as a string. returns NULL if failed
 */

char *_itos(int num)
{
  int digits, tens, i = 0, t = 0, x;
  char *res;

  digits = num;
  tens = 1;

  if (num < 0)
    t = 1;
  res = malloc(sizeof(char) * (numlen(digits) + 2 + t));
  if (res == NULL)
    return (NULL);
  if (num < 0)
    {
      res[i] = '-';
      i++;
    }
  for (x = 0; digits > 9 || digits < -9; x++)
    {
      digits /= 10;
      tens *= 10;
    }
  for (digits = num; x >= 0; x--)
    {
      if (digits < 0)
	{
	  res[i] = (digits / tens) * -1 + '0';
	  i++;
	}
      else
	{
	  res[i] = (digits / tens) + '0';
	  i++;
	}
      digits %= tens;
      tens /= 10;
    }
  res[i] = '\0';
  return (res);
}
