/*
**AIRBNB**
Problem Description

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE:  if B > N, return an empty array.



Input Format
First argument is an integer array A

Second argument is an integer B.



Output Format
Return an integer array.



Example Input
Input 1:

 A = [1, 2, 1, 3, 4, 3]
 B = 3
Input 2:

 A = [1, 1, 2, 2]
 B = 1


Example Output
Output 1:

 [2, 3, 3, 2]
Output 2:

 [1, 1, 1, 1]


Example Explanation
Explanation 1:

 A=[1, 2, 1, 3, 4, 3] and B = 3
 All windows of size B are
 [1, 2, 1]
 [2, 1, 3]
 [1, 3, 4]
 [3, 4, 3]
 So, we return an array [2, 3, 3, 2].
Explanation 2:

 Window size is 1, so the output array is [1, 1, 1, 1].
*/

vector<int> Solution::dNums(vector<int> &A, int k) {
    // brute is to use 2 loops and return all the count distinct ele
    // tc: O(n-k+1)*k^2
    // n-k+1 is the no of window
    // and k^2 is the time we iterate in that window to count distinct ele
    
    // efficient way to do in one traversal is to use map
    // we use sliding window and a map to store the count
    // map size is the count of distinct ele in that window
    // as we update the window we remove one ele from left in map and add a new one from right
    // tc: O(k)
    unordered_map<int, int> mp;
    vector<int> res;
    for(int i=0; i<k; i++)
    {
        mp[A[i]]++; // for the first window
    }
    res.push_back(mp.size()); // push the map size for first window
    for(int i=k; i<A.size(); i++)
    {
        if(mp[A[i-k]]==1) // if left most ele of window in map has freq as 1 we remove it completly
        {
            mp.erase(A[i-k]);
        }
        else // if freq is >1 we decrease it by -1 because it can come in the updated window too
        {
            mp[A[i-k]]--;
        }
        // we add the new ele from right in map
        mp[A[i]]++;
        // push the size of map in res
        res.push_back(mp.size());
    }
    return res;
}
