// simple code to print the length of lis
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> dp(n,1);
    
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            if(arr[prev_index]<arr[i] && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
            }
        }
    }
    
    int ans = -1;
    for(int i=0; i<=n-1; i++){
        if(dp[i]> ans){
            ans = dp[i];
        }
    }
    return ans;
}

int main() {
	
	int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<longestIncreasingSubsequence(arr,n);
	return 0;
}
