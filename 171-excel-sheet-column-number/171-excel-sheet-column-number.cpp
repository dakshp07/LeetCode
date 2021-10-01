class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int index = columnTitle.length()-1;
        long long int num = 1;
        
        while(index >= 0) {
            
    
            ans += num*(columnTitle[index]-'A'+1);
            num *= 26;
            index--;
        }
        
        return ans;
    }
};