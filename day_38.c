#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Initialize
void init(Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// Check empty
int empty(Deque* dq) {
    return dq->size == 0;
}

// Check full
int full(Deque* dq) {
    return dq->size == MAX;
}

// push_front
void push_front(Deque* dq, int val) {
    if (full(dq)) return;

    if (empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }

    dq->arr[dq->front] = val;
    dq->size++;
}

// push_back
void push_back(Deque* dq, int val) {
    if (full(dq)) return;

    if (empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }

    dq->arr[dq->rear] = val;
    dq->size++;
}

// pop_front
int pop_front(Deque* dq) {
    if (empty(dq)) return -1;

    int val = dq->arr[dq->front];

    if (dq->size == 1) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }

    dq->size--;
    return val;
}

// pop_back
int pop_back(Deque* dq) {
    if (empty(dq)) return -1;

    int val = dq->arr[dq->rear];

    if (dq->size == 1) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }

    dq->size--;
    return val;
}

// front element
int front_val(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->front];
}

// back element
int back_val(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->rear];
}

// size
int size(Deque* dq) {
    return dq->size;
}

// clear
void clear(Deque* dq) {
    dq->front = dq->rear = -1;
    dq->size = 0;
}

// reverse
void reverse(Deque* dq) {
    int i = 0, j = dq->size - 1;

    while (i < j) {
        int a = (dq->front + i) % MAX;
        int b = (dq->front + j) % MAX;

        int temp = dq->arr[a];
        dq->arr[a] = dq->arr[b];
        dq->arr[b] = temp;

        i++;
        j--;
    }
}

// display (for testing)
void display(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = 0; i < dq->size; i++) {
        printf("%d ", dq->arr[(dq->front + i) % MAX]);
    }
    printf("\n");
}