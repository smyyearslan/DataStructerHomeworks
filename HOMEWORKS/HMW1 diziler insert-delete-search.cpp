#include<stdio.h>

void insert_(int arr[],int *size);
void delete_(int arr[],int *size);
void search_(int arr[],int size);
void print_(int arr[],int size);

int main(){
	int arr[100];
	int size=0;
	int choice; 
	
	while(1){
		
		printf("\nCHOICES\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Search\n");
		printf("4.Print\n");
		printf("5.Exit\n");
		printf("seciminizi giriniz\n");
		scanf("%d",&choice);

        if (choice == 1) insert_(arr, &size);
        else if (choice == 2) delete_(arr, &size);
        else if (choice == 3) search_(arr, size);
        else if (choice == 4) print_(arr, size);
        else if (choice == 5) {
            printf("Programdan cikiliyor\n");
            break;
        }
        else printf("Gecersiz secim!\n");
    }

    return 0;
}

void insert_(int arr[],int *size){
	int sayi,poz;
	
	printf("eklenecek sayiyi giriniz\n");
	scanf("%d",&sayi);
	printf("kaçýncý pozisyona eklemek istersiniz?\n");
	scanf("%d",&poz);
	
		if(poz<0||poz>*size){
			printf("geçersiz pozisyon\n");
			return;
		}
		
		for(int i=*size;i>poz;i--){
			arr[i]=arr[i-1];	
		}

	arr[poz]=sayi;
	(*size)++;
	
	printf("sayi eklendi");	

}

void delete_(int arr[],int *size){
	int poz;
	
	printf("silinecek pozisyonu giriniz");
	scanf("%d",&poz);
	
		if(*size==0){
			printf("liste boþ");
			return;
		}
		
		if(poz<0||poz>*size){
			printf("geçersiz pozisyon");
			return;
		}
		
		for(int i=poz;i<*size-1;i++){
			arr[i]=arr[i+1];
		}
	
	(*size)--;
	
	printf("sayi silindi");
	
}

void search_(int arr[],int size){
	int sayi;
	int i;
	int found;
	printf("aranacak sayiyi giriniz");
	scanf("%d",&sayi);
	
		if(size==0){
			printf("liste boþ");
			return;
		}
		
		for ( i = 0; i < size; i++) {
	        if (arr[i] == sayi){
	            break;
	        }
	    }
	    
	    if ( i == size) { 
	    printf("sayi bulunamadi\n");
		}else{
		printf("Eleman %d indexinde bulundu\n",found);
		}
}

void print_(int arr[], int size) {
    if (size == 0) {
        printf("Liste bos\n");
        return;
    }

    printf("Dizi: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}














