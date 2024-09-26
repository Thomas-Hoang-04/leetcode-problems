typedef struct {
    int event[1000][2];
    int ele_cnt;
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar *cal = (MyCalendar*)malloc(sizeof(MyCalendar));
    cal->ele_cnt = 0;
    return cal;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    int size = obj->ele_cnt;
    for (int i = 0; i < size; i++) 
        if (start < obj->event[i][1] && obj->event[i][0] < end) return false;
    obj->event[size][0] = start;   
    obj->event[size][1] = end;
    obj->ele_cnt++;
    return true;   
}

void myCalendarFree(MyCalendar* obj) {
    free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/