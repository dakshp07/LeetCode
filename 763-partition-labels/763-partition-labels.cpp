class Solution {
public:
    vector<int> partitionLabels(string s) {
        // so every char should appear in only one part
        // so for any ith char we need to split it into a part till its last occurence
        // eg: "ababcbacadefegdehijhklij"
        // from first a we need to split till we see last a, because a can be in just one part
        // for all those chars we see where they occur last, and pick the max one
        // as we need to make as many parts as possible
        
        // so we store the last ocurrence
        vector<int> last_occurence(26, 0);
        for(int i=0; i<s.size(); i++)
        {
            last_occurence[s[i]-'a']=i; // getting last occurence
        }
        vector<int> res;
        // so we denote our substring by start, end var
        int start=0, end=0;
        for(int i=0; i<s.size(); i++)
        {
            // now end can be max of all the last occurence of a specific char
            end=max(end, last_occurence[s[i]-'a']);
            // eg: abcab
            // in this case we want end to take the last occurence of b and not a
            // since then only we will get a max length parttion
            // so we update end till we get the max one
            
            // if we reach the index which is equal to end
            // then we got our substring
            if(i==end)
            {
                // we got a perfect substring
                // we add to our array
                res.push_back(end-start+1);
                // we move to new partition
                start=end+1;
            }
        }
        return res;
    }
};