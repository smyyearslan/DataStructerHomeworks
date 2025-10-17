#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char *exp) {
    char output[MAX];
    int j = 0; 

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isalpha(c)) {  // Harf (operand)
            output[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                output[j++] = pop();
            pop();
        }
        else { 
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                output[j++] = pop();
            push(c);
        }
    }

    while (!isEmpty())
        output[j++] = pop();

    output[j] = '\0';
    printf("Postfix: %s\n", output);
}

int main() {
    char exp[MAX];
    printf("Infix ifadeyi giriniz: ");
    scanf("%s", exp);

    infixToPostfix(exp);
    return 0;
}

