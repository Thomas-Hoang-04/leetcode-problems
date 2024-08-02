int min(int a, int b) {
    return a < b ? a : b;
}

int minSwaps(int* nums, int numsSize) {
    int swap_cnt = INT_MAX;
    int tot_one = 0;
    for (int i = 0; i < numsSize; i++) tot_one += nums[i];

    int cnt_one = nums[0], e = 0;
    for (int st = 0; st < numsSize; st++) {
        if (st) cnt_one -= nums[st - 1];
        while (e - st + 1 < tot_one) {
            e++;
            cnt_one += nums[e % numsSize];
        }
        swap_cnt = min(swap_cnt, tot_one - cnt_one);
    }
    return swap_cnt;
}