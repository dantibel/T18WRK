/* Belov Danil, 10-6, 26.10.2021 */

#include <stdio.h>
#include <string.h>

#include "WRK.H"

DAY WorkDays[7] =
{
  {"Monday", 0}, {"Tuesday", 0}, {"Wensday", 0}, {"Thurday", 0},
  {"Friday", 0}, {"Saturday", 0}, {"Sunday", 0}
};

/* Input string function */
void GetStr( char *S, int L)
{
  int i = 0;
  char c;

  while ((c = getchar()) != '\n')
    if (S != NULL && i < L - 1)
      S[i++] = c;
  if (S != NULL && i < L)
    S[i] = 0;
} /* End of 'GetStr' function */

/* Input information about new worker */
void ReadWorker( WORKER *W )
{
  int i;

  printf("Surname: ");
  GetStr(W->Surname, sizeof(W->Surname));

  printf("Name: ");
  GetStr(W->Name, sizeof(W->Name));
  
  printf("Birthday:\n  Day: ");
  scanf("%d", &W->Birthday.Day);
  GetStr(NULL, 0);

  printf("  Month: ");
  scanf("%d", &W->Birthday.Month);
  GetStr(NULL, 0);
  
  printf("  Year: ");
  scanf("%d", &W->Birthday.Year);
  GetStr(NULL, 0);
  printf("Sex [m/f]: ");
  W->Sex = getchar();

  printf("Hours:\n");
  for (i = 0; i < 7; i++)
  {
    printf("  %s: ", WorkDays[i].Name);
    scanf("%d", &W->Hours[i]);
    GetStr(NULL, 0);
  }
} /* End of 'ReadWorker' function */


/* Output information about worker function */
void WriteWorker( WORKER *W )
{
  int i;

  printf("%s %s, %02d/%02d/%d, %c, ", W->Surname, W->Name, W->Birthday.Day, W->Birthday.Month, 
    W->Birthday.Year, W->Sex);
  for (i = 0; i < 7; i++)
    printf("%d ", W->Hours[i]);
  printf("\n");
} /* End of 'WriteWorker' function */


/* Save information about workers in file function */
int SaveDB( char *FileName, WORKER *Base, int N )
{
  FILE *F;
  
  if ((F = fopen(FileName, "wb")) == NULL)
    return 0;
  fwrite(Base, sizeof(WORKER), N, F);
  fclose(F);
  return 1;
} /* End of 'SaveDB' function */


/* Load information about workers from file function */
int LoadDB( char *FileName, WORKER *Base, int MaxSize )
{
  int N;
  FILE *F;

  if ((F = fopen(FileName, "rb")) == NULL)
    return 0;
  N = fread(Base, sizeof(WORKER), MaxSize, F);
  fclose(F);
  return N;
} /* End of 'LoadDB' function */


/* Swap two workers function */
void Swap( WORKER *A, WORKER *B )
{
  WORKER tmp = *B;

  *B = *A;
  *A = tmp;
 
} /* End of 'Swap' function */


/* Check is one worker's name less than oter one's function */
int IsNameLess( WORKER A, WORKER B )
{
  int n = strcmp(B.Surname, A.Surname);
  
  if (n == 0)
    return strcmp(B.Name, A.Name);
  if (n < 0)
    return 0;
  return n;
}  /* End of 'IsNameLess' function */


/* Check is one worker's birthday date less than oter one's function */
int IsDateLess( WORKER A, WORKER B )
{
  if (A.Birthday.Year == B.Birthday.Year)
    if (A.Birthday.Month == B.Birthday.Month)
      return A.Birthday.Day < B.Birthday.Day;
    else
      return A.Birthday.Month < B.Birthday.Month;
  else
      return A.Birthday.Year < B.Birthday.Year;
} /* End of 'IsDateLess' function */


/* Sort workers list function */
void Sort( WORKER *A, int N, int (*IsLess)( WORKER A, WORKER B ) )
{
  int i, j;

  for (j = 0; j < N - 1; j++)
    for (i = 0; i < N - 1; i++)
      if (IsLess(A[i + 1], A[i]))
        Swap(&A[i], &A[i + 1]);
} /* End of 'Sort' function */


/* Save file with salary report function */
void Report( FILE *F, WORKER *Base, DAY *Days, int MaxSize, int Cost)
{
  int i, j, sum;

  for (j = 0; j < MaxSize; j++)
  {
    sum = 0;
    for (i = 0; i < 7; i++)
      sum += Days[i].Count * Base[j].Hours[i];
    sum *= Cost;
    fprintf(F, "Worker #%d earned %d$\n", j, sum);
  }
} /* End of 'Report' function */


/* Edit information about worker function */
void EditWorker( WORKER *W )
{
  int i;

  printf("Surname: ");
  EditStr(W->Surname);
  printf("\nName: ");
  EditStr(W->Name);
  printf("\nBirthday:\n  Day: ");
  EditNum(W->Birthday.Day);
  printf("  \nMonth:  ");
  EditNum(W->Birthday.Month);
  printf("  \nYear: ");
  EditNum(W->Birthday.Year);
  printf("\nSex: ");
  EditNum(W->Sex);

  for (i = 0; i < 7; i++)
  {
    printf("  %s: %d", WorkDays[i].Name, W->Hours[i]);
    EditNum(i);
  }
} /* End of 'EditWorker' function */
/* END OF 'WRK.C' FILE */