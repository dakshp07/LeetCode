class Solution {
public:
    int find(vector<int>& arr, int x, int l, int r) {
        int n = arr.size();
        while(l<=r) {
            int mid = (l+r)/2;
            if(arr[mid]==x) return mid;
            if(arr[mid] < x && (mid==n-1 || x<arr[mid+1])) return mid;
            else if(arr[mid] < x) {
                l = mid+1;
            } else if(arr[mid] > x) {
                r = mid-1;
            }
        }
        return -1;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = find(arr,x,0,n-1);
        vector<int> res;
        if(idx == -1) {
            for(int i=0; i<k; i++) res.push_back(arr[i]);
            return res;
        }
        int l=idx, r=idx+1;
        while(k>0 && l>=0 && r<n) {
            if(abs(x-arr[l]) <= abs(x-arr[r])) {
                res.push_back(arr[l]);
                l--;
            } else {
                res.push_back(arr[r]);
                r++;
            }
            k--;
        }
        while(k>0 && l>=0) {
            res.push_back(arr[l]);
            l--;
            k--;
        }
        while(k>0 && r<n) {
            res.push_back(arr[r]);
            r++;
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};