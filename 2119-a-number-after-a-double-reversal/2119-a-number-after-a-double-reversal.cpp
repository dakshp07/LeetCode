class Solution {
public:
    bool isSameAfterReversals(int num) {
        string realnum=to_string(num);
        string str=to_string(num);
        while(str.back()=='0' && str.size()>1)
        {
            str.pop_back();
        }
        string rev1=str;
        reverse(rev1.begin(), rev1.end());
        string rev2=rev1;
        reverse(rev2.begin(), rev2.end());
        if(rev2==realnum)
        {
            return true;
        }
        return false;
    }
};