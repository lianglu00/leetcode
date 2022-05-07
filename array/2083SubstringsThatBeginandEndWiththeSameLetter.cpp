class Solution {
public:
    
    long long numberOfSubstrings(string s) {
        long long ans = 0;
        long long nums[26] = {};
        for (char & c: s) 
            nums[c-'a']++;
        
        ans += s.size();
        for (int i = 0; i<26; i++) {
            if (nums[i] <=1)
                continue;
            ans += nums[i]*(nums[i]-1)>>1;
        }
        
        return ans;
        
    }
};
