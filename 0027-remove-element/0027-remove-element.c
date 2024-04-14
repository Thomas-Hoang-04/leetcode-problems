int removeElement(int* nums, int numsSize, int val) {
    int i = 0, l = numsSize - 1, temp;
    while (i <= l) {
        while (nums[l] == val && l > i) l--;
        if (nums[i] == val) {
            nums[i] = temp;
            nums[i] = nums[l];
            nums[l] = temp;
            l--;
        }
        i++;
    } 
    return l + 1;
}