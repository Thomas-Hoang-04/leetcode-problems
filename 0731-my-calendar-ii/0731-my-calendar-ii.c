typedef struct {
    int event[1000][2];
    int state[1000][2];
    int size, state_size;
} MyCalendarTwo;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}


MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo *cal = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    cal->size = 0;
    cal->state_size = 0;
    return cal;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    int size = obj->size;
    for (int i = 0; i < obj->state_size; i++) 
        if (max(start, obj->state[i][0]) < min(end, obj->state[i][1])) return false;
    for (int i = 0; i < size; i++)
        if (max(start, obj->event[i][0]) < min(end, obj->event[i][1])) {
            obj->state[obj->state_size][0] = max(start, obj->event[i][0]);
            obj->state[obj->state_size][1] = min(end, obj->event[i][1]);
            obj->state_size++;
        }
    obj->event[size][0] = start;   
    obj->event[size][1] = end;
    obj->size++;
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 
 * myCalendarTwoFree(obj);
*/