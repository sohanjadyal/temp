#include <stdio.h>
#include <time.h>

#define MAX 10

void addition(int A[MAX][MAX],
              int B[MAX][MAX],
              int C[MAX][MAX],
              int size)
{
 for (int i = 0; i < size; i++)
 {
  for (int j = 0; j < size; j++)
  {
   C[i][j] = A[i][j] + B[i][j];
  }
 }
}

void subtraction(int A[MAX][MAX],
                 int B[MAX][MAX],
                 int C[MAX][MAX],
                 int size)
{
 for (int i = 0; i < size; i++)
 {
  for (int j = 0; j < size; j++)
  {
   C[i][j] = A[i][j] - B[i][j];
  }
 }
}

void strassen(int A[MAX][MAX],
              int B[MAX][MAX],
              int C[MAX][MAX],
              int size)
{
 if (size == 1)
 {
  C[0][0] = A[0][0] * B[0][0];
  return;
 }

 int newSize = size / 2;

 int A11[MAX][MAX], A12[MAX][MAX],
     A21[MAX][MAX], A22[MAX][MAX];

 int B11[MAX][MAX], B12[MAX][MAX],
     B21[MAX][MAX], B22[MAX][MAX];

 int M1[MAX][MAX], M2[MAX][MAX],
     M3[MAX][MAX], M4[MAX][MAX],
     M5[MAX][MAX], M6[MAX][MAX],
     M7[MAX][MAX];

 int T1[MAX][MAX], T2[MAX][MAX];

 int C11[MAX][MAX], C12[MAX][MAX],
     C21[MAX][MAX], C22[MAX][MAX];

 for (int i = 0; i < newSize; i++)
 {
  for (int j = 0; j < newSize; j++)
  {
   A11[i][j] = A[i][j];
   A12[i][j] = A[i][j + newSize];
   A21[i][j] = A[i + newSize][j];
   A22[i][j] = A[i + newSize][j + newSize];

   B11[i][j] = B[i][j];
   B12[i][j] = B[i][j + newSize];
   B21[i][j] = B[i + newSize][j];
   B22[i][j] = B[i + newSize][j + newSize];
  }
 }

 // M1 = (A11 + A22)(B11 + B22)
 addition(A11, A22, T1, newSize);
 addition(B11, B22, T2, newSize);
 strassen(T1, T2, M1, newSize);

 // M2 = (A21 + A22)B11
 addition(A21, A22, T1, newSize);
 strassen(T1, B11, M2, newSize);

 // M3 = A11(B12 - B22)
 subtraction(B12, B22, T2, newSize);
 strassen(A11, T2, M3, newSize);

 // M4 = A22(B21 - B11)
 subtraction(B21, B11, T2, newSize);
 strassen(A22, T2, M4, newSize);

 // M5 = (A11 + A12)B22
 addition(A11, A12, T1, newSize);
 strassen(T1, B22, M5, newSize);

 // M6 = (A21 - A11)(B11 + B12)
 subtraction(A21, A11, T1, newSize);
 addition(B11, B12, T2, newSize);
 strassen(T1, T2, M6, newSize);

 // M7 = (A12 - A22)(B21 + B22)
 subtraction(A12, A22, T1, newSize);
 addition(B21, B22, T2, newSize);
 strassen(T1, T2, M7, newSize);

 // C11 = M1 + M4 - M5 + M7
 addition(M1, M4, T1, newSize);
 subtraction(T1, M5, T2, newSize);
 addition(T2, M7, C11, newSize);

 // C12 = M3 + M5
 addition(M3, M5, C12, newSize);

 // C21 = M2 + M4
 addition(M2, M4, C21, newSize);

 // C22 = M1 - M2 + M3 + M6
 subtraction(M1, M2, T1, newSize);
 addition(T1, M3, T2, newSize);
 addition(T2, M6, C22, newSize);

 for (int i = 0; i < newSize; i++)
 {
  for (int j = 0; j < newSize; j++)
  {
   C[i][j] = C11[i][j];
   C[i][j + newSize] = C12[i][j];
   C[i + newSize][j] = C21[i][j];
   C[i + newSize][j + newSize] = C22[i][j];
  }
 }
}

int main()
{
 int n;

 int A[MAX][MAX],
     B[MAX][MAX],
     C[MAX][MAX];

 printf("Enter size of matrix (power of 2): ");
 scanf("%d", &n);

 printf("\nEnter Matrix A:\n");

 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
  {
   scanf("%d", &A[i][j]);
  }
 }

 printf("\nEnter Matrix B:\n");

 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
  {
   scanf("%d", &B[i][j]);
  }
 }

 time_t start, end;

 start = time(NULL);

 strassen(A, B, C, n);

 end = time(NULL);

 printf("\nResult Matrix:\n");

 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
  {
   printf("%4d ", C[i][j]);
  }

  printf("\n");
 }

 printf("\nRunning Time = %ld seconds\n",
        end - start);

 return 0;
}