// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// we will sort arr and dep individually
    	// we dont see the order of their arr, dep
    	// its just matters which one is coming first and leaving first
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int plat=1; // curr req of platform
    	int max_plat=1; // max req of platform
    	int i=1, j=0; // 2 pointers
    	while(i<n && j<n)
    	{
    	    if(arr[i]<=dep[j]) // the first one will depaty after the next one arrives
    	    {
    	        // in that case we need a pltform
    	        plat++;
    	        i++; // keep traversing
    	    }
    	    else if(arr[i]>dep[j])// if the first one departs and now next comes
    	    {
    	        plat--; // we will decrease one plat since now one is free
    	        j++; // change dep
    	    }
    	    if(plat>max_plat)
    	    {
    	        max_plat=plat; // upate max
    	    }
    	}
    	return max_plat;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends