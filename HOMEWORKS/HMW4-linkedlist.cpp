#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

node *addfront( node *head,int key)
{
	struct node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->next=head;
	head=temp;
	
	return head;	
}

node *addlast(node *head,int key)
{
	struct node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->next=NULL;
		
		if(head==NULL){
			head=temp;
		}else{
			node *last=head;//tanýmlanmazsa while'a giremez
			while(last->next!=NULL){
				last=last->next;
		    }
			last->next=temp;
		}
	return head;	
}

struct node *del(node *head,int key)
{
	node *temp=head;
	if(head!=NULL){
		if(head->data==key){
			head=head->next;
			free(temp);
		}else{
			while(temp->next->data!=key)
				temp=temp->next;
			if(temp->next==NULL)
				return head;
			node *del=temp->next;
			temp->next=del->next;
			free(del);
		}
	}
	return head;
}

struct node *addmiddle(node *head, int key, int after)
{
    struct node *temp, *newNode;
    temp = head;

    if (head == NULL) {
        newNode = (node*)malloc(sizeof(node));
        newNode->data = key;
        newNode->next = NULL;
        head = newNode;
        return head;
    }

    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Eleman bulunamadi, sayi sona eklendi.\n");
        return addlast(head, key);
    }

    newNode = (node*)malloc(sizeof(node));
    newNode->data = key;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}


void print(node *head)
{
	if(head==NULL){
		printf("list is empty");
	}else{
		while(head!=NULL)
		{
			printf("%d\t",head->data);
			head=head->next;
		}
		printf("\n");
	}
}

main(){
	node *head=NULL;
	int n;
	
	head=addlast(head,4);
	head=addfront(head,2);
	head=addlast(head,5);
	
	printf("liste: ");
    print(head);
	
	int basaeklenecek_sayi;
    printf("\nbasa sayi eklemek isterseniz sayiyi girin: ");
    scanf("%d", &basaeklenecek_sayi);
	head = addfront(head, basaeklenecek_sayi);

	printf("liste: ");
    print(head);
	    
	int arayaeklenecek_sayi, hangisindensonra;
	printf("\naraya sayi eklemek isterseniz hangi sayidan sonra eklenecegini yazin: ");
	scanf("%d", &hangisindensonra);
	printf("eklenecek sayiyi girin: ");
	scanf("%d", &arayaeklenecek_sayi);
	head = addmiddle(head, arayaeklenecek_sayi, hangisindensonra);

	printf("liste: ");
	print(head);
	
	int sonaeklenecek_sayi;
    printf("\nsona sayi eklemek isterseniz sayiyi girin: ");
    scanf("%d", &sonaeklenecek_sayi);
	head = addlast(head, sonaeklenecek_sayi);
	
	printf("liste: ");
    print(head);

	printf("bir sayi silmek isterseniz seciniz:");
	scanf("%d",&n);

    head = del(head, n);

    printf("yeni liste: ");
    print(head); 

    return 0;
}












































