// Matrix Multiplication using pointers.
// Author: jatin arora.

//------------------------------------------------------------------Beginning-----------------------------------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>


void Input(int COL, float matrix[][COL],int ROW){
	int row, col;
	for(row = 0; row < ROW; row++){
		for(col = 0; col < COL; col++)
			scanf("%f", (*(matrix + row) + col));
		printf("\n");
	}
}

void Output(int COL, float matrix[][COL], int ROW){
	int row, col;
	for(row = 0; row < ROW; row++){
		for(col = 0; col < COL; col++)
			printf("%f\t", *(*(matrix+row) + col));
		printf("\n");
	}
}


void Matmul(int COL1,float m1[][COL1],int COL2, float m2[][COL2], float result[][COL2], int ROW ){
	int row, col, i;
       	float sum;
	for(row=0; row <= ROW; row++){
		for(col=0; col <= COL1; col++){
			sum =0.0;
			for(i=0; i<=COL2;i++)
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
	int ROW1, COL1, ROW2, COL2, i;
	char again = 'y';
	while(again == 'y'){
		printf("Enter the row size of first matrix:");
		scanf("%d", &ROW1);
		printf("Enter the column size of first matrix:");
		scanf("%d", &COL1);
		printf("Enter the row size of second matrix:");
		scanf("%d", &ROW2);
		printf("Enter the column size of second matrix:");
		scanf("%d", &COL2);
		if(COL1 == ROW2){
			float **m1,**m2,**prod; 

			m1 = (float **)malloc(ROW1*sizeof(float *));
			if(m1 == NULL){
				printf("Memory not allocated\n");
				exit(1);
			}

			for(i =0; i<COL1; i++){
				m1[i] = (float *)malloc(COL1*sizeof(float *));
				if(m1[i] == NULL){
				printf("Memory not allocated\n");
				exit(1);
				}
			}

			m2 = (float **)malloc(ROW2*sizeof(float *));
			if(m2 == NULL){
				printf("Memory not allocated\n");
				exit(1);
			}

			for(i=0; i<COL1; i++){
				m2[i] = (float *)malloc(COL1*sizeof(float *));
				if(m2[i] == NULL){
				printf("Memory not allocated\n");
				exit(1);
				}
			}
			
			prod = (float **)malloc(ROW1*sizeof(float *));
			if(prod == NULL){
				printf("Memory not allocated\n");
				exit(1);
			}
			
			for(i=0; i<COL2; i++){
				prod[i] = (float *)malloc(COL2*sizeof(float *));
				if(prod[i] == NULL){
				printf("Memory not allocated\n");
				exit(1);
				}
			}

			printf("Enter the elements of first matrix of size %dx%d:\n", ROW1,COL1);
			Input(COL1, m1, ROW1);
			printf("Enter the elements of the second matrix of size %dx%d:\n", ROW2,COL2);
			Input(COL2, m2, ROW2);
			Matmul(COL1,m1,COL2, m2, prod,ROW1);
			printf("The product of two matrices is:\n");
			Output(COL2, prod,ROW1);
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


