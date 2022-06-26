// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(vector<int> &res,vector<int> &arr,int i,int N,int sum)
   {
       if(i==N)//if index is exceeding than the size of the array
       {

           //push the sum in the vector 
           res.push_back(sum);
           return ;
       }
       //picking the next element of the array
       solve(res,arr,i+1,N,sum+arr[i]);
       
       //not picking the next element
       solve(res,arr,i+1,N,sum);
   }
   vector<int> subsetSums(vector<int> arr, int N)
   {
       // Write Your Code here
       vector<int> res;
       solve(res,arr,0,N,0);

      //we have to sort the vector as defined in the question 
       sort(res.begin(),res.end());
       return res;
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends