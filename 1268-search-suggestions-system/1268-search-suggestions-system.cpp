class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // 2 pointers dekhenge
        // sort karo taaki order rahe
        // start at 0 and end at size()-1
        // agar start and end chars are similar to first char of serch word means everything in b/w them is also starting with same char
        // so we will return first 3 in those cases
        // check next word in searchword and increment the start etc etc
        sort(products.begin(), products.end()); // sort to make sure that we have all the words in order
        vector<vector<string>> ans; // return vec
        int start=0; // 2 pointers
        int end=products.size()-1;
        for(int i=0; i<searchWord.size(); i++) // iterate char by char on our products
        {
            char c=searchWord[i];
            // start searching 
            // if product doesnt has i char or the i char isnt equal to char we looking at
            while(start<=end && (products[start].length()<=i || products[start][i]!=c)) start++;
            // start searching
            // // if product doesnt has i char or the i char isnt equal to char we looking at
            while(start<=end && (products[end].length()<=i || products[end][i]!=c)) end--;
            
            // now we know that the start and end have the range of strings which has the word we looking for
            vector<string> res;
            // we want 3 words, so we will take min(3, end-start+1)
            for(int j = 0; j < 3 && start + j <= end; j++)
            {
                res.push_back(products[start+j]); // pick the char and putting in res
            }
            ans.push_back(res); // put in ans vector
        }
        return ans;
    }
};