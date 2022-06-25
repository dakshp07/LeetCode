// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool cmpr(Item a, Item b)
    {
        return ((double)a.value/(double)a.weight)>((double)b.value/(double)b.weight);
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // greddy karenge
        // sort karo v/w ko
        // because here we have weight for given value
        sort(arr, arr+n, cmpr);
        int curr=0; // curr weight
        double fin=0.0; // final value
        for(int i=0; i<n; i++)
        {
            if(curr+arr[i].weight<=W) // if the new weight is less than our given max weight
            {
                // add value, weight
                fin+=arr[i].value;
                curr+=arr[i].weight;
            }
            else
            {
                int remain=W-curr; // check what is remaing weight
                fin+=((double)arr[i].value/(double)arr[i].weight)*(double)remain; // we take in fraction
                break; // we break out
            }
        }
        return fin;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends