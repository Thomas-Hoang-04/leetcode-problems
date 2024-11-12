bool primeSubOperation(int* nums, int numsSize) {
    int maxVal = INT_MIN;
    for (int i = 0; i < numsSize; i++) maxVal = maxVal > nums[i] ? maxVal : nums[i];

    bool* sieve = (bool*)malloc((maxVal + 1) * sizeof(bool));
    memset(sieve, 1, (maxVal + 1) * sizeof(bool));
    sieve[1] = false;
    for (int i = 2; i <= sqrt(maxVal + 1); i++) 
        if (sieve[i]) 
            for (int j = i * i; j <= maxVal; j += i) 
                sieve[j] = false;
    
    int curr = 1;
    int diff;
    while (numsSize) {
        diff = *nums - curr;

        if (diff < 0) return false;

        if (sieve[diff] || diff == 0) {
            nums++;
            numsSize--;
            curr++;
        } else curr++;
    }
    return true;
}