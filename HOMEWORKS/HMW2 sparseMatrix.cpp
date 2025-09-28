#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int row;
	int col;
	int value;
}SparseElement;

SparseElement* createSparseMatrix(int *matrix, int rows,int cols);
void printSparseMatrix(SparseElement *sMatrix);

SparseElement* createSparseMatrix(int *matrix,int rows,int cols){
	int count=0;
	int i,j;	
//matrixte sýfýr olmayanlarýn sayýsýný bulabilmek için ihtiyac olan bellek miktarýnýn hesabý	
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(*(matrix+i*cols+j)!=0){
				count++;
			}
		}
	}
//bellek ayýrma(header için+1)
	SparseElement *sparse_array=(SparseElement*)malloc((count+1)*sizeof(SparseElement));

	if(sparse_array==NULL){
		printf("Hata:Bellek tahsisi basarisiz\n");
		return NULL;
	}

	sparse_array[0].row=rows;
	sparse_array[0].col=cols;
	sparse_array[0].value=count;
	
	int index=1;//doldurmaya 1. indeksten baþlamasý için
	
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			int current_value=*(matrix+i*cols+j);
			
			if(current_value!=0){
				sparse_array[index].row=i;
				sparse_array[index].col=j;
				sparse_array[index].value=current_value;
				
				index++;
			}
		}
	}
	
	return sparse_array;
}

void printSparseMatrix(SparseElement *sMatrix){
	if(sMatrix==NULL)return;
	
	int count=sMatrix[0].value;
	int rows=sMatrix[0].row;
	int cols=sMatrix[0].col;
	
	printf("\n--Seyrek Matris Temsili(%d x %d)--\n\n",rows,cols);
	printf("Toplam Sifir Olmayan Eleman Sayisi: %d\n\n",count);
	printf("Satir\tSutun\tDeger\n");
	printf("---------------------\n");
	
	for(int i=1;i<=count;i++){
		printf("%d\t%d\t%d\n",
				sMatrix[i].row, sMatrix[i].col, sMatrix[i].value);
	}

}

int main(){
	const int R=4;
	const int C=5;
	
	int matrix[R*C]={
		0,0,3,0,4,
		0,0,5,7,0,
		0,0,0,0,0,
		0,2,6,0,0
	};
	
	SparseElement *sparse_representation=createSparseMatrix(matrix,R,C);	
	
	if(sparse_representation != NULL){
		printSparseMatrix(sparse_representation);
		
		free(sparse_representation);
	}
	
	return 0;
}


























