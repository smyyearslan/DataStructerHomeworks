//k=l + m * 3 ifadesinin görüntüsü
//
//    =
//  /   \
// k     +
//     /   \
//    l     * 
//        /   \
//       m     3  
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dugum{
	char deger[3];
	struct Dugum *sol;
	struct Dugum *sag;
};

struct Dugum* yeniDugumOlustur(char *deger){
	struct Dugum* dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
	
	if(dugum == NULL){
		perror("Bellek ayýrma baþarýsýz");
		exit(EXIT_FAILURE);
	}
	
	strcpy(dugum->deger,deger);
	dugum->sol=NULL;
	dugum->sag=NULL;
	
	return dugum;
}

void inorder(struct Dugum* dugum){
	if(dugum){
		if (dugum->sol !=NULL && dugum->sag!=NULL){
			printf("(");
		}
		inorder(dugum->sol);
		printf("%s",dugum->deger);
		inorder(dugum->sag);
		
		if(dugum->sol!=NULL&&dugum->sag!=NULL){
			printf(")");
		}
		
	}
}

int main(){

	//m*4
	struct Dugum* kokCarpi=yeniDugumOlustur("*");
	kokCarpi->sol=yeniDugumOlustur("m");
	kokCarpi->sag=yeniDugumOlustur("4");
	//l+(m*4)
	struct Dugum* kokArti=yeniDugumOlustur("+");
	kokArti->sol=yeniDugumOlustur("l");
	kokArti->sag=kokCarpi;
	//k=l+(m*4))
	struct Dugum* kokEsittir=yeniDugumOlustur("=");
	kokEsittir->sol=yeniDugumOlustur("k");
	kokEsittir->sag=kokArti;
	
	inorder(kokEsittir);
	
}













