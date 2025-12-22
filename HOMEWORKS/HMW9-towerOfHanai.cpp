#include <stdio.h>
#include <math.h>

int step = 0;

void hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        step++;
        printf("Adim %d: %c -> %c\n", step, source, target);
        return;
    }

    hanoi(n - 1, source, target, auxiliary);

    step++;
    printf("Adim %d: %c -> %c\n", step, source, target);

    hanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n;

    printf("Disk sayisini gir: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    printf("\nToplam adim sayisi: %.0f\n", pow(2, n) - 1);

    return 0;
}

