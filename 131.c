#include <stdio.h>
#include <stdlib.h>

void *mallocx(int size) {
    void *p = malloc(size);
    if (p == NULL) {
        fprintf(stderr, "malloc failed");
        exit(1);
    }

    return p;
}

typedef struct {
    double *data;
    int size;
    int top;
} Stack;

void* create_stack(int size) {
    Stack *s = mallocx(sizeof(Stack));
    s->data = mallocx(sizeof(double) * size);
    s->size = size;
    s->top = 0;
    return s;
}

void dispose_stack(Stack *s) {
    free(s->data);
    free(s);
}

void push_stack(Stack *s, double x) {
    if (s->top >= s->size) {
        fprintf(stderr, "stack overflow");
        exit(1);
    }
    s->data[s->top] = x;
    s->top++;
}

double pop_stack(Stack *s) {
    if (s->top <= 0) {
        fprintf(stderr, "stack underflow");
        exit(1);
    }
    s->top--;
    return s->data[s->top];
}

void print_stack(Stack *s) {
    printf("stack: ");

    if (s->top == 0) {
        printf("(none)");
    } else {
        for (int i = 0; i < s->top; i++) {
            printf("%.1f ", s->data[i]);
        }
    }

    printf("\n");
}

int main() {
    Stack *s = create_stack(4);

    int op[] = { 1, 1, 2, 1, 2, 2, 0 };
    double input[] = { 6.0, 8.0, 1.0 };
    int input_index = 0;

    for (int i = 0; i < sizeof(op) / sizeof(int); i++) {
        print_stack(s);
        printf("operation: ");

        if (op[i] == 1) {
            printf("push %.1f\n", input[input_index]);
            push_stack(s, input[input_index]);
            input_index++;
        } else if (op[i] == 2) {
            printf("pop %.1f\n", pop_stack(s));
        } else {
            printf("exit\n");
            break;
        }
    }
}
