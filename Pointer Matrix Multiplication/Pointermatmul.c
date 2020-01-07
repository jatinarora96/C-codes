// Matrix Multiplication using pointers.
// Author: jatin arora.

//------------------------------------------------------------------Beginning-----------------------------------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>


void Input(int number_of_cols, float matrix[][number_of_cols],int number_of_rows){
	int row, col;
	for(row = 0; row < number_of_rows; row++){
		for(col = 0; col < number_of_cols; col++)
			scanf("%f", (*(matrix + row) + col));
		printf("\n");
	}
}

void Output(int number_of_cols, float matrix[][number_of_cols], int number_of_rows){
	int row, col;
	for(row = 0; row < number_of_rows; row++){
		for(col = 0; col < number_of_cols; col++)
			printf("%f\t", *(*(matrix+row) + col));
		printf("\n");
	}
}


void Matmul(int number_of_cols1,float m1[][number_of_cols1],int number_of_cols2, float m2[][number_of_cols2], float result[][number_of_cols2], int number_of_rows ){
	int row, col, i;
       	float sum;
	for(row=0; row <= number_of_rows; row++){
		for(col=0; col <= number_of_cols1; col++){
			sum =0.0;
			for(i=0; i<=number_of_cols2;i++)
				sum+=(*(*(m1+row)+i))*(*(*(m2+i)+col));
			*(*(result+row)+col) = sum;
		}
	}
}


char loop(){
	char choice;
	printf("\nDo you want to Continue.\nPress y/Y to continue.\nPress n/N to exit.\n");
	scanf("%c", &choice);
	scanf("%c", &choice);
	if (choice == 'y' || choice == 'Y')
		return 'y';
	else{
		return 'n';
	}
}


//------------------------------------------------------------------------Main Function----------------------------------------------------------------------------//


int main()
{
	int number_of_rows1, number_of_cols1, number_of_rows2, number_of_cols2, i;
	char again = 'y';
	while(again == 'y'){
		printf("Enter the row size of first matrix:");
		scanf("%d", &number_of_rows1);
		printf("Enter the column size of first matrix:");
		scanf("%d", &number_of_cols1);
		printf("Enter the row size of second matrix:");
		scanf("%d", &number_of_rows2);
		printf("Enter the column size of second matrix:");
		scanf("%d", &number_of_cols2);
		if(number_of_cols1 == number_of_rows2){
			float **m1,**m2,**prod; 

			m1 = (float **)malloc(number_of_rows1*sizeof(float *));
			if(m1 == NULL){
				printf("Memory not allocated\n");
				exit(1);
			}

			for(i =0; i<number_of_cols1; i++){
				m1[i] = (float *)malloc(number_of_cols1*sizeof(float *));
				if(m1[i] == NULL){
				printf("Memory not allocated\n");
				exit(1);
				}
			}

			m2 = (float **)malloc(number_of_rows2*sizeof(float *));
			if(m2 == NULL){
				printf("Memory not allocated\n");
				exit(1);
			}

			for(i=0; i<number_of_cols2; i++){
				m2[i] = (float *)malloc(number_of_cols2*sizeof(float *));
				if(m2[i] == NULL){
				printf("Memory not allocated\n");
				exit(1);
				}
			}
			
			prod = (float **)malloc(number_of_rows1*sizeof(float *));
			if(prod == NULL){
				printf("Memory not allocated\n");
				exit(1);
			}
			
			for(i=0; i<number_of_cols2; i++){
				prod[i] = (float *)malloc(number_of_cols2*sizeof(float *));
				if(prod[i] == NULL){
				printf("Memory not allocated\n");
				exit(1);
				}
			}

			printf("Enter the elements of first matrix of size %dx%d:\n", number_of_rows1,number_of_cols1);
			Input(number_of_cols1, m1, number_of_rows1);
			printf("Enter the elements of the second matrix of size %dx%d:\n", number_of_rows2,number_of_cols2);
			Input(number_of_cols2, m2, number_of_rows2);
			Matmul(number_of_cols1,m1,number_of_cols2, m2, prod,number_of_rows1);
			printf("The product of two matrices is:\n");
			Output(number_of_cols2, prod,number_of_rows1);
			free(m1);
			free(m2);
			free(prod);

		
		}
		else
			printf("Wrong dimensions, try again");
		again = loop();
	}
	return 0;
}

//---------------------------------------------------------------------End-----------------------------------------------------------------------------------------//


