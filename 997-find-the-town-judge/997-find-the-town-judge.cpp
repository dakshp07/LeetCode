class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // so we just have to find the n which satisfies both conditions
        vector<int> trusts(n+1, 0);
        for(int i=0; i<trust.size(); i++)
        {
            // so increment someone who is trusted, and decrement who is not trusted
            trusts[trust[i][0]]--;
            trusts[trust[i][1]]++;
        }
        // now i iterate over my trusts array if at any index i get n-1, i return that
        // eg: n = 2, trust = [[1,2]]
        // trusts vector: 0->0, 1->-1, 2->1
        // as 2 has 1 which is basically n-1 so i return that
        for(int i=1; i<n+1; i++)
        {
            if(trusts[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};