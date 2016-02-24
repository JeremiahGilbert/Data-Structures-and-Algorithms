#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// Setting the Constants
#define COL 20
#define ROW 20
// Function Declaration
void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max);
void DisplayArray2D(int A[][COL], unsigned int, unsigned int);
int FindLargest(int A[][COL], unsigned int, unsigned int);
int FindColSum(int A[][COL], unsigned int , unsigned int , unsigned int );
int Sort2DArray(int A[][COL], unsigned int , unsigned int );
int CopyArray2D(int [][COL], int [][COL], unsigned int , unsigned int);
int CopyArray2DSpiral(int [][COL], int [][COL], unsigned int, unsigned int );
int Spin(int, int, int, int);
/*
	The Main take in all of the intputed values 
	and calls all of the functions 
*/

int main ()
{
  int rowsize, colsize, min, max, col_to_sum;
  int A[ROW][COL];
  int B[ROW][COL];
  printf("Please enter the Row size:\n"); 
  scanf("%d",&rowsize);
  printf("Please enter the Column size:\n");
  scanf("%d",&colsize);
  printf("Please enter the min and the max numbers:\n");
  scanf("%d %d", &min, &max);
  printf("Please enter the column number that you would like the sum for:\n");
  scanf("%d",&col_to_sum);
  // Function Calls
  PopulateArray2DUnique(A,rowsize,colsize,min,max);
  DisplayArray2D(A,rowsize,colsize);
  FindLargest(A,rowsize,colsize);
  printf("%d \n",FindColSum(A, rowsize ,colsize ,col_to_sum ));
  Sort2DArray(A, rowsize, colsize);
  CopyArray2D(A, B, rowsize, colsize);
  CopyArray2DSpiral(A, B, rowsize, colsize);
  return 0;
}
/*
  PopulateArray2DUnique takes an empty array, rowsize, colsize, min, and max as inputs
  then fills the rowsize x colsize array with random intergers between min and max
*/

void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max)
{
  srand(time(NULL));
  int r;
  int i,j;
  for (i=0;i<rowsize;i++)
  {
    for (j=0;j<colsize;j++)
     {
      r = rand()%((max+1)-min)+min;
      A[i][j]= r;
     
     }
  }
}
/*
DisplayArray2D takes the A, rowsize, and colsize as inputs
and prints A
*/

void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize)
{  
int i,j;
 for (i=0;i<rowsize;i++)
  {
    for (j=0;j<colsize;j++)
     {
      printf("%3d", A[i][j]);
     }
    printf("\n");
  }
}
/*
FindLargest takes the A, rowsize, and colsize as inputs
and finds the larges values with in the array
and prints it
*/

int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize)
{

int i,j,largest=0;
 for (i=0;i<rowsize;i++)
  {
    for (j=0;j<colsize;j++)
     {
       if (A[i][j] > largest) 
       {
         largest = A[i][j];
       }
     }
  }
printf("%d \n",largest);
return 0;
}
/*
FindColSum takes the A, rowsize, and colsize, col_to_sum as inputs
and add the column that the user is asking for
returns the sum
*/

int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize , unsigned int col_to_sum)
{
int i,j,sum=0;
for (i=0;i<rowsize;i++)
  {
	  sum += A[i][col_to_sum - 1];
  }
return(sum);
}
/*
DisplayArray2D takes the A, rowsize, and colsize as inputs
pusts the 2d array into a  1d array, sorts it
Returns it into the 2d array
*/

int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize)
{
	int i, j,k, B[ROW * COL];
	for (i = 0; i < rowsize; i++)
	{
		for (j = 0; j < colsize; j++) 
		{
			int n = i * colsize + j;
			B[n] = A[i][j];
			while (n > 0 && B[n] < B[n - 1]) 
			{
				int temp = B[n];
				B[n] = B[n - 1];
				B[n - 1] = temp;
				--n;
			}
		}
	}
	for (i = 0; i < rowsize; i++)
	{
		for (j = 0; j < colsize; j++)
		{
			A[i][j] = B[i*colsize + j];
		}
	}
	DisplayArray2D(A, rowsize, colsize);
	return 0;
}
/*
CopyArray2D
*/

int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
	int i, j;
	for (i = 0; i < rowsize; i++)
	{
		for (j = 0; j < colsize; j++)
		{
			B[i][j] = A[i][j];
		}
	}

	DisplayArray2D(B, rowsize, colsize);


}
/*
The Main take in all of the intputed values
and calls all of the functions
*/

int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
	int i, j;
	for (i = 0; i < rowsize; i++)
	{
		for (j = 0; j < colsize; j++)
		{
			int index = spin(rowsize, colsize,i,j);
			B[i][j] = A[index / rowsize][index % rowsize];
		}
	}
	DisplayArray2D(B, rowsize, colsize);

}
int spin(int w, int h, int x, int y)
{
	if (y)
	
		return(w + spin(h - 1, w, y - 1, w - x - 1));
	
	else
		return x;


}