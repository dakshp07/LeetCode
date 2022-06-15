class Solution {
public:
    void sortColors(vector<int>& arr) {
        // one could be use sort
        // other could be store the numbers in freq array
        // third is to use dutch national flag algo, more on this algo:
        // we have three pointers, low=0, mid=0, high=size-1
        // assume:
        // ele in o to low-1 are 0s
        // ele in mid+1 to high are 2s
        // rest ele b/w low to mid are 1s
        // how to do:
        // if(mid==0) swap(mid, low) mid++ low++
        // mid==1 mid++
        // mid==2 swap(mid, high) high--
        int low=0, mid=0, high=arr.size()-1;
        while(mid<=high)
        {
            if(arr[mid]==0)
            {
                swap(arr[mid], arr[low]);
                mid++;
                low++;
            }
            else if(arr[mid]==1)
            {
                mid++;
            }
            else if(arr[mid]==2)
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};