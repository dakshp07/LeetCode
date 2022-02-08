class Solution {
public:
    int addDigits(int num) {
        // string str=to_string(num);
        // string temp=str;
        // int sum=0;
        // while(temp.size()!=1)
        // {
        //     for(int i=0; i<temp.size(); i++)
        //     {
        //         sum+=(str[i]-'0');
        //     }
        //     temp+=to_string(sum);
        // }
        // return stoi(temp);
        string str=to_string(num);
        while(str.size()!=1)
        {
            int sum=0;
            for(int i=0; i<str.size(); i++)
            {
                sum+=(str[i]-'0');
            }
            str=to_string(sum);
        }
        return stoi(str);
    }
};