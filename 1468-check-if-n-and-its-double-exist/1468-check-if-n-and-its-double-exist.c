bool checkIfExist(int* arr, int arrSize) {
    bool map[4001] = {0};
    int temp;
    for (;arrSize;arrSize--, arr++) {
        temp = *arr;
        if (map[temp * 2 + 2000] || (temp % 2 == 0 && map[temp / 2 + 2000])) return true;
        map[temp + 2000] = true;
    }
    return false;
}