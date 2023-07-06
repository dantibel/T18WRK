/* Belov Danil, 10-6, 26.10.2021 */ 

#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "WRK.H"
#define SPECIAL_KEYS 224

/* Edit string function */
void EditStr( char *Str )
{
  int i, run = 1, len = strlen(Str), pos = len, key;

  printf("%s", Str);
  while(run)
  {
	  key = _getch();
    switch (key)
    {
    /* [enter] */
    case '\r':
      run = 0; 
      break;

    /* [backspace] */
    case 8:
      if (pos > 0)
      {
        memmove(&Str[pos - 1], &Str[pos], len - pos + 1);
        pos--;
        len--;
        printf("\b");
        for (i = pos; i < len; i++)
          printf("%c", Str[i]);
        printf(" \b");
        for (i = pos; i < len; i++)
          printf("\b");
      }
      break;

    case SPECIAL_KEYS:
      switch(_getch())
      {
      /* [home] */
      case 71:
        for (i = 0; i < pos; i++)
          printf("\b");
        pos = 0; 
        break;

      /* [end] */
      case 79:
        for (i = pos; i < len; i++)
          printf("%c", Str[i]);
        pos = len;
        break;

      /* [left arrow] */
      case 75:
        if (pos > 0)
        {
          printf("\b");
          pos--;
        }
        break;

      /* [right arrow] */
      case 77:
        if (pos < len)
        {
          printf("%c", Str[pos]);
          pos++;
        }
        break;

      /* [delete] */
      case 83:
        if (pos < len)
        {
          memmove(&Str[pos], &Str[pos + 1], len - pos);
          len--;
          for (i = pos; i < len; i++)
            printf("%c", Str[i]);
          printf(" \b");
          for (i = pos; i < len; i++)
            printf("\b");
        }
        break;
      }
      break;

     /* [other keys] */
    default:
      if (key != ' ')
      {
        memmove(&Str[pos + 1], &Str[pos], len - pos + 1);
        Str[pos] = key;
        len++;
        for (i = pos; i < len; i++)
			    printf("%c", Str[i]);
        pos++;
        for (i = pos; i < len; i++)
          printf("\b");
      }
      break;
    }
  }
} /* End of 'EditLine' function */


/* Edit number function */
void EditNum( int Num )
{
  int run = 1, len = 1, pos, key, t = Num / 10;

  while (t > 0)
  {
    len++;
    t /= 10;
  }
  pos = len;
  printf("%d", Num);
  while (run)
  {
    key = _getch();
    switch (key)
    {
    /* [enter] */
    case '\r':
      run = 0;
      break;

    /* [backspace] */
    case 8:
      if (pos > 0)
      {
        pos--;
        len--;
        printf("\b");
      }
      break;

    /* [num keys] */
    default:
      if (key >= '0' && key <= '9')
      {
        len++;
        pos++;
        printf("%c", key);
      }
      break;
    }
  }
} /* End of 'EditNum' function */
/* END OF 'EDIT.C' FILE */