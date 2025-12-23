//MAX HEAP

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);

    printf("Max Heap: ");
    printArray(arr, n);
    return 0;
}

//MIN HEAP

#include <stdio.h>

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleUp(MinHeap *h, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && h->data[index] < h->data[parent]) {
        swap(&h->data[index], &h->data[parent]);
        bubbleUp(h, parent);
    }
}

void minHeapify(MinHeap *h, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->data[left] < h->data[smallest])
        smallest = left;
    
    if (right < h->size && h->data[right] < h->data[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&h->data[index], &h->data[smallest]);
        minHeapify(h, smallest);
    }
}

void insert(MinHeap *h, int val) {
    if (h->size >= MAX_SIZE) {
        printf("Heap dolu\n");
        return;
    }
    h->data[h->size] = val;
    h->size++;
    bubbleUp(h, h->size - 1);
}

int extractMin(MinHeap *h) {
    if (h->size <= 0) return -1;
    
    int root = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    minHeapify(h, 0);
    
    return root;
}

void printHeap(MinHeap *h) {
    printf("Min Heap: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

int main() {
    MinHeap h = {.size = 0};

    insert(&h, 15);
    insert(&h, 10);
    insert(&h, 20);
    insert(&h, 5);
    insert(&h, 30);

    printHeap(&h);

    printf("Çikarilan en kucuk eleman: %d\n", extractMin(&h));
    printHeap(&h);

    return 0;
}
