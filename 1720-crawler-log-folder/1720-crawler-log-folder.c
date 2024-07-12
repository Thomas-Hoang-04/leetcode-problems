int ops;

int pos(char* log) {
    return *(log + 1) == '.' ? (ops > 0 ? -1 : 0) : *log == '.' ? 0 : 1; 
}

int minOperations(char** logs, int logsSize) {
    ops = 0;
    while (logsSize--) {
        ops += pos(*logs);
        logs++;
    }
    return ops;
}