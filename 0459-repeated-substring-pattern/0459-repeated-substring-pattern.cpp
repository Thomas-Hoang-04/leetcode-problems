class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string init=s;
        s+=s;
        int n=s.size();        
        s[0]=' ';
        s[n-1]=' ';
        if(s.find(init)!=string::npos) return true;
        return false;
    }
};