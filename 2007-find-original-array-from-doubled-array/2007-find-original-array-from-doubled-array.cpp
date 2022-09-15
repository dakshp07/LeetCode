class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // lets first see if the array has even no of ele or not
        vector<int> ans;
        int n=changed.size();
        if(n%2!=0) return {};
        // we now store the ele with freq in map
        // for every ele we check if its double is there in map
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            mp[changed[i]]++;
        }
        // we need to sort in order to avoid the cases of 0
        sort(changed.begin(), changed.end());
        for(int i=0; i<n; i++)
        {
            // we check if the changed[i] is there anymore in freq map or not
            if(mp[changed[i]]==0) continue;
            // if 2*changed[i] is not there then we return empty array
            if(mp[2*changed[i]]==0)
            {
                return {};
            }
            // if changed[i] there we check if its double is there
            if(mp[2*changed[i]]!=0 && mp[changed[i]]!=0)
            {
                ans.push_back(changed[i]); // we push the curr as its a part of og array
                mp[2*changed[i]]--; // we decrement the freq
                mp[changed[i]]--; // we decrement the freq
            }
        }
        return ans;
    }
};