class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t=s;
        s+=s;
        int n=s.size();        
        s[0]=' ';
        s[n-1]=' ';
        if(s.find(t)!=string::npos) return true;
        return false;
    }
};