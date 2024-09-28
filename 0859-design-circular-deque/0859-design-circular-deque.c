typedef struct {
    int* queue;
    int front, rear, size, cap;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* deque = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    deque->queue = (int*)malloc(k * sizeof(int));
    deque->front = 0;
    deque->rear = k - 1;
    deque->size = 0;
    deque->cap = k;
    return deque;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return !obj->size;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->cap;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->front = (obj->front - 1 + obj->cap) % (obj->cap);
    obj->queue[obj->front] = value;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->rear = (obj->rear + 1) % (obj->cap);
    obj->queue[obj->rear] = value;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->front = (obj->front + 1) % (obj->cap);
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->rear = (obj->rear - 1 + obj->cap) % (obj->cap);
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) { 
    return myCircularDequeIsEmpty(obj) ? -1 : obj->queue[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    return myCircularDequeIsEmpty(obj) ? -1 : obj->queue[obj->rear];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/