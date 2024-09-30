


typedef struct {
    int* st;
    int size;
    int cap;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack* cus_st = (CustomStack*)malloc(sizeof(CustomStack));
    cus_st->st = (int*)malloc(maxSize * sizeof(int));
    cus_st->size = 0;
    cus_st->cap = maxSize;
    return cus_st;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->size == obj->cap) return;
    obj->st[obj->size++] = x;
}

int customStackPop(CustomStack* obj) {
    if (!obj->size) return -1;
    obj->size--;
    return obj->st[obj->size];
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    int size = obj->size;
    for (int i = 0; i < size && i < k; i++) obj->st[i] += val;
}

void customStackFree(CustomStack* obj) {
    free(obj->st);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/