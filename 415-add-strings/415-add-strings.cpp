class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int i=num1.size()-1;
        int j=num2.size()-1;
        // we iterate over both strings and add them and also have a carry
        int carry=0;
        // we iterate over them from end to start 
        // we do that till we either reach start or we dont have carry
        while(i>=0 || j>=0 || carry>0)
        {
            // if our num is there ie if i>=0 and j>=0 we add them up
            int first=0, second=0;
            if(i>=0) first=num1[i]-'0';
            if(j>=0) second=num2[j]-'0';
            // now we add both with carry
            int sum=first+second+carry;
            // now we grab the last digit of sum and add it to our ans string
            int last_digit=sum%10;
            ans.push_back(last_digit+'0');
            // and we also keep carry
            carry=sum/10;
            // we keep moving backward in both strings
            i--;
            j--;
        }
        // since we went from end to start our ans should be reversed
        reverse(ans.begin(), ans.end());
        return ans;
    }
};