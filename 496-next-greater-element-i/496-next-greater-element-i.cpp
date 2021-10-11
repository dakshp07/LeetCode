class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stack;
        map<int,int>map;
        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            while(!stack.empty()){
                if(stack.top()<nums2[i]){
                    map.insert(pair<int,int>(stack.top(),nums2[i]));
                    stack.pop();
                }else break;
            }
            stack.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++){
            int val = map[nums1[i]];
            if(val==0)ans.push_back(-1);
            else ans.push_back(val);
        }
        return ans;
    }
};