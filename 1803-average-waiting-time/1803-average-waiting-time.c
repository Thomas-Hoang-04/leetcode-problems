double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
    int curr = -1;
    double wait = 0;
    int size = customersSize;
    while (customersSize--) {
        if (curr < **customers) {
            wait += *(*customers + 1);
            curr = *(*customers + 1) + **customers;
        } else {
            curr += *(*customers + 1);
            wait += curr - **customers;
        }
        customers++;
    }
    return wait / size;
}