class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        // sorting nhi kar sakte because you have to pick one from end or from start
        // better rahega to use two pointers
        // one will add stuff from starting and the other one will minus stuff from end and vice versa
        int sum=accumulate(cards.begin(), cards.begin()+k, 0); // total sum for first k
        int ans=sum; // final max ans
        int i=k-1, j=cards.size()-1; // two pointers
        while(i>=0) // we will do this k becomes 0
        {
            sum-=cards[i]; // if i dont pick ith card and pick jth one
            sum+=cards[j];
            ans=max(ans, sum); // pick max
            i--; // aapne ko k cards hi chaiye at max
            j--; // peech waale ko bhi move karna
        }
        return ans;
    }
};