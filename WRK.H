/* Belov Danil, 10-6, 26.10.2021 */

typedef struct
{
 int Day, Month, Year;
} DATE;

typedef struct
{
  char Name[30], Surname[47];
  DATE Birthday;
  char Sex;
  int Hours[7];
} WORKER;

typedef struct
{
  char Name[8];
  int Count;
} DAY;

void GetStr( char *S, int L);
void Swap( WORKER *A, WORKER *B );
int IsNameLess( WORKER A, WORKER B );
int IsDateLess( WORKER A, WORKER B );

extern DAY WorkDays[7];

void ReadWorker( WORKER *W );
void WriteWorker( WORKER *W );
void EditWorker( WORKER *W );
int LoadDB( char *FileName, WORKER *Base, int MaxSize );
int SaveDB( char *FileName, WORKER *Base, int MaxSize );
void Sort( WORKER *A, int N, int (*IsLess)( WORKER A, WORKER B ) );
void Report( FILE *F, WORKER *Base, DAY *Days, int MaxSize, int Cost);
void EditStr( char *Str );
void EditNum( int Num );
/* END OF 'WRK.H' FILE */