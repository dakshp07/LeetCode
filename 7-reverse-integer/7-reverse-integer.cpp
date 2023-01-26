class Solution {
public:
    int reverse(int x) {
        // convert int to string
        string temp=to_string(x);
        // reverse string
        std::reverse(temp.begin(), temp.end());
        // convert back to int
        // we generally use stoi() to make string int, but since we might have long long int we use stoll()
        long long int ans=stoll(temp);
        if(x<0) ans*=-1;
        if(ans>INT_MAX || ans<INT_MIN) return 0;
        return ans;
    }
};
