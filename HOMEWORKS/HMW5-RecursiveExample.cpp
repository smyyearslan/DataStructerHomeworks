#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        perror("Bellek ayýrma hatasý");
        exit(EXIT_FAILURE);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printReverseRecursive(Node* head) {
    if (head == NULL) {
        return;
    }

    printReverseRecursive(head->next);
.
    printf("%d ", head->data);
}

int main() {
    Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);

    printf("Liste (Baþtan Sona): 10 20 30\n");
    printf("Liste (Sondan Baþa): ");
    
    printReverseRecursive(head);
    printf("\n");

    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        perror("Bellek ayýrma hatasý");
        exit(EXIT_FAILURE);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node* deleteListRecursive(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    head->next = deleteListRecursive(head->next);

    printf("Siliniyor: %d\n", head->data);
    free(head);
    
    return NULL;
}

int main() {
    Node* head = newNode(100);
    head->next = newNode(200);
    head->next->next = newNode(300);

    printf("Liste oluþturuldu. Baþlangýç adresi: %p\n", (void*)head);

    head = deleteListRecursive(head);
    
    printf("\nSilme iþlemi tamamlandý.\n");
    printf("Listenin yeni baþý (Head): %p (NULL olmalý)\n", (void*)head);
    

    return 0;
}
