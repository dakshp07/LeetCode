class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> m;
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};
        
        vector<string> ans;
        int len = digits.size();
        
        for(int i = 0; i<len; i++){
            char c = digits[i];
            vector<char> chars = m[c];
            
            vector<string> tmpAns;
            vector<string> tmp = ans;
            
            for(int j=0; j<chars.size(); j++) {
                if(i==0){
                    string s = "";
                    s += chars[j];
                    ans.push_back(s);
                }else {
                    for(int k=0; k<tmp.size(); k++) tmpAns.push_back(tmp[k]+chars[j]);
                    ans = tmpAns;
                }
            }
            
        }
        return ans;
    }
};