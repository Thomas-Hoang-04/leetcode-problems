#define VOWELS_SIZE 5
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static const char vowels[VOWELS_SIZE + 1] = {1, 2, 4, 8, 16, 0};

bool Isvowels(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

int Find_pos(char c) {
    int idx = -1;
    switch (c) {
        case 'a':
            idx = 0;
            break;
        case 'e':
            idx = 1;
            break;
        case 'i':
            idx = 2;
            break;
        case 'o':
            idx = 3;
            break;
        case 'u':
            idx = 4;
            break;
        default:
            break;
    }
    return idx;
}
    
int findTheLongestSubstring(char* s) {
    int n = strlen(s), ans = 0, mask = 0;
    int arr[32];
    memset(arr, -1, sizeof(arr));
    for (int i = 0; i < n; i++) {
        mask ^= vowels[(Isvowels(s[i])) ? Find_pos(s[i]) : VOWELS_SIZE];
        if (mask != 0 && arr[mask] == -1) arr[mask] = i;
        ans = MAX(ans, i - arr[mask]);
    }
    return ans;
}