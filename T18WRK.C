/* Belov Danil, 10-6, 26.10.2021 */ 

#include <stdio.h>
#include <conio.h>

#include "WRK.H"

#define MAX 10

/* program main function */
void main( void )
{

  
  FILE *F;
  int DBSize = 0, i = 0, n, run = 1, b, e, cost;
  static WORKER DB[MAX];
  char fname[100];

  printf("[0] - Exit         [1] - Add Worker [2] - Print Workers [3] - Delete Worker [4] - Sort Workers\n"
         "[5] - Flip Workers [6] - Save file  [7] - Load file     [8] - Edit Worker   [9] - Create Report\n\n");

  while (run)
  {
    switch (_getch())
    {
    case '\n':
        break;

    case '0':
      run = 0;
      break;

    case '1':
      if(DBSize < MAX)
      {
        ReadWorker(&DB[DBSize++]);
        printf("Worker was added\n");
      }
      else
        printf("Not enough room\a\n");
      break;

    case '2':
      for (i = 0; i < DBSize; i++)
      {
        printf("Worker #%d: ", i);
        WriteWorker(&DB[i]);
      }
      break;

    case '3':
      printf("Number of worker: ");
      scanf("%d", &n);
      GetStr(NULL, 0);
      if (n < DBSize - 1)
      {
        DBSize--;
        for (i = n; i < DBSize; i++)
          DB[i] = DB[i + 1];
        printf("Worker #%d was removed\n", n);
      }
      else
        printf("There isn't worker #%d\a\n", n);
      break;

    case '4':
      printf("Choise sort type: [A] - Alphabet, [D] - Date ");
      switch (_getch())
      {
      case 'a':
        Sort(DB, DBSize, IsNameLess);
        printf("\nWorker list was sorted by alphabet\n");
        break;
      case 'd':
        Sort(DB, DBSize, IsDateLess);
        printf("\nWorker list was sorted by date\n");
        break;
      default:
        printf("\nIncorrect choise\a\n");
      }
      break;

    case '5':
      b = 0; 
      e = DBSize - 1;
      while (b <= e)
        Swap(&DB[b++], &DB[e--]);
      printf("Workers list was flip\n");
      break;

    case '6':
      printf("Save file name: ");
      GetStr(fname, sizeof(fname));
      if (SaveDB(fname, DB, DBSize))
        printf("File was saved\n");
      else
        printf("Error\a\n");
      break;

    case '7':
      printf("Load file name: ");
      GetStr(fname, sizeof(fname));
      DBSize = LoadDB(fname, DB, MAX);
      printf("%d records were loaded\n", DBSize);
      break;

    case '8':
      printf("Number of worker: ");
      scanf("%d", &n);
      GetStr(NULL, 0);
      if (n < DBSize)
      {
        EditWorker(&DB[n]);
      }
      else
        printf("There isn't worker #%d\a\n", n);
      break;

    case '9':
      printf("Count of work days:\n");
      for (i = 0; i < 7; i++)
      {
        printf("  %s: ", WorkDays[i].Name);
        scanf("%d", &WorkDays[i].Count);
        GetStr(NULL, 0);
      }
      printf("\nCost: ");
      scanf("%d", &cost);
      F = fopen("Report.txt", "w");
      Report(F, DB, WorkDays, DBSize, cost);
      fclose(F);
      printf("Report file was saved\n");
      break;

    default:
      printf("Incorrect input, please retry\a\n");
    }
  }
  _getch();
} /* End of 'main' function */
/* END OF 'T18WRK.C' FILE */