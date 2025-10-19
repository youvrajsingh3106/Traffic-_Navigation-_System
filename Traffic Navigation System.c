#include <stdio.h>
#include <stdlib.h>

typedef struct Vehicle {
    int id;
    int isEmergency;  
    struct Vehicle* next;
} Vehicle;


typedef struct Queue {
    Vehicle* front;
    Vehicle* rear;
    int size;
} Queue;


#define MAX 50
typedef struct Stack {
    int data[MAX];
    int top;
} Stack;


void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}


void enqueue(Queue* q, int id, int isEmergency) {
    Vehicle* newV = (Vehicle*)malloc(sizeof(Vehicle));
    newV->id = id;
    newV->isEmergency = isEmergency;
    newV->next = NULL;


    if (q->front == NULL) {
        q->front = q->rear = newV;
    }

    else if (isEmergency == 1) {
        newV->next = q->front;
        q->front = newV;
    }

    else {
        q->rear->next = newV;
        q->rear = newV;
    }
    q->size++;
}


Vehicle* dequeue(Queue* q) {
    if (q->front == NULL)
        return NULL;

    Vehicle* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    q->size--;
    return temp;
}


void initStack(Stack* s) { s->top = -1; }

void push(Stack* s, int id) {
    if (s->top < MAX - 1)
        s->data[++(s->top)] = id;
}

void displayStack(Stack s) {
    printf("\nVehicles that have crossed:\n");
    for (int i = s.top; i >= 0; i--)
        printf("Vehicle %d\n", s.data[i]);
}


int getGreenTime(int queueSize) {
    if (queueSize > 10)
        return 60;
    else if (queueSize > 5)
        return 40;
    else
        return 20;
}


void simulateSignal(Queue* q, Stack* passed) {
    if (q->size == 0) {
        printf("No vehicles waiting.\n");
        return;
    }

    int greenTime = getGreenTime(q->size);
    printf("\n🚦 Signal turned GREEN for %d seconds (queue size: %d)\n", greenTime, q->size);


    int vehiclesAllowed = greenTime / 10; 
    for (int i = 0; i < vehiclesAllowed && q->size > 0; i++) {
        Vehicle* v = dequeue(q);
        if (v->isEmergency)
            printf(" Emergency Vehicle %d passed immediately!\n", v->id);
        else
            printf(" Vehicle %d passed normally.\n", v->id);
        push(passed, v->id);
        free(v);
    }

    printf("Signal turned RED again.\n");
}


int main() {
    Queue signal;
    Stack passed;
    initQueue(&signal);
    initStack(&passed);
    enqueue(&signal, 1, 0);
    enqueue(&signal, 2, 0);
    enqueue(&signal, 3, 1);
    enqueue(&signal, 4, 0);
    enqueue(&signal, 5, 1);
    enqueue(&signal, 6, 0);

    simulateSignal(&signal, &passed);
    simulateSignal(&signal, &passed); 

    displayStack(passed);
    return 0;
}
