#include <stdlib.h>
#include <stdio.h>

typedef struct {
    double *data;
    int size;
    int top;
    int index;
} Queue;

void *mallocx(int size) {
    void *p = malloc(size);
    if (p == NULL) {
        fprintf(stderr, "malloc failed");
        exit(1);
    }

    return p;
}

Queue* create_queue(int size) {
    Queue *q = mallocx(sizeof(Queue));
    q->data = mallocx(sizeof(double) * size);
    q->size = size;
    q->top = 0;
    q->index = 0;
    return q;
}

void dispose_queue(Queue *q) {
    free(q->data);
    free(q);
}

void enqueue(Queue *q, double x) {
    if (q->top >= q->size) {
        fprintf(stderr, "queue overflow");
        exit(1);
    }
    q->data[(q->index + q->top) % q->size] = x;
    q->top++;
}

double dequeue(Queue *q) {
    if (q->top <= 0) {
        fprintf(stderr, "queue underflow");
        exit(1);
    }
    int index = q->index;
    q->top--;
    q->index = (q->index + 1) % q->size;
    return q->data[index];
}

void print_queue(Queue *q) {
    printf("queue: ");

    if (q->top == 0) {
        printf("(none)");
    } else {
        for (int i = q->index; i < q->index + q->top; i++) {
            printf("%.1f ", q->data[i % q->size]);
        }
    }

    printf("\n");
}

int main() {
    // (1) enqueue, (2) dequeue, (0) exit
    int op[] = { 1, 1, 2, 1, 2, 2, 0 };

    double input[] = { 6.0, 8.0, 1.0, 0.0 };
    int input_index = 0;
    Queue *q = create_queue(16);

    for (int i = 0; op[i] != 0; i++) {
        print_queue(q);

        printf("operation: ");
        switch (op[i]) {
            case 1: {
                double in = input[input_index];
                printf("enqueue %.1f\n", in);
                enqueue(q, in);
                input_index++;
                break;
            }
            case 2: {
                double output = dequeue(q);
                printf("dequeue %.1f\n", output);
                break;
            }
        }
    }

    printf("operation: exit\n");
    dispose_queue(q);

    return 0;
}
