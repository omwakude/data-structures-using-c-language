
#include <stdio.h>

struct Stack {
    int items[100];
    int top;
};

void initialize(struct Stack *stack) {
    (*stack).top = -1; // Initialize the stack to be empty
}

void push(struct Stack *stack, int item) {
    if ((*stack).top == 99) {  // Maximum size is 100
        printf("Stack is full. Cannot push %d\n", item);
    } else {
        (*stack).top++; // Move top to the next position
        (*stack).items[(*stack).top] = item; // Insert the item at the top position
        printf("Pushed %d\n", item);
    }
}

int pop(struct Stack *stack) {
    if ((*stack).top == -1) {
        printf("Stack is empty. Cannot pop\n");
        return -1;
    } else {
        int poppedItem = (*stack).items[(*stack).top]; // Retrieve the top item
        (*stack).top--; // Move top to the previous position
        return poppedItem;
    }
}

void display(struct Stack *stack) {
    if ((*stack).top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        int i = (*stack).top;
        while (i >= 0) {
            printf("%d\n", (*stack).items[i]);
            i--;
        }
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    int poppedItem = pop(&stack);
    if (poppedItem != -1) {
        printf("Popped %d\n", poppedItem);
    }
    display(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);

    return 0;
}
