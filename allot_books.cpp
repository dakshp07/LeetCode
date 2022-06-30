// google, flipkart asked
bool allocationPossible(int barrier, vector<int>&A, int maxStudents)
{
    int allocatedStudents=0; // we will start with student
    int pagesAllocated=0; // not yet allocated any pages
    for(int i=0; i<A.size(); i++)
    {
        // if(A[i]>barrier) return false; // if individually the books are big then we cant do them collectively too so return false
        if(pagesAllocated+A[i]>barrier)
        {
            allocatedStudents++; // if it exceeds then we call in our new student
            pagesAllocated=A[i]; // and allocate him this page
            if(pagesAllocated>barrier) return false; // if we execeed barrier
        }
        else
        {
            pagesAllocated+=A[i]; // if it doesnt exceeds barrier we add it
        }
    }
    if(allocatedStudents<maxStudents) // if we were able to allot the students
    {
        return true; // then we return true
    }
    return false; // else we return false
}
int Solution::books(vector<int> &A, int B) {
    // we will use binary search here
    // our low will be at minimum value of arr
    // high will be the sum of all ele in our arr
    // our ans will lie b/w them
    if(B>A.size()) return -1;
    int low=A[0], high=0;
    for(int i=0; i<A.size(); i++)
    {
        // low will be minimum in array and high is the sum of all ele in array
        low=min(low, A[i]);
        high+=A[i];
    }
    int res=-1;
    while(low<=high)
    {
        int mid=(high+low)/2;
        // if we are able to allocate one student books with pages whose sum doesnt exceeds mid
        // then we update res, and update boundary because we are looking for minimum ans
        if(allocationPossible(mid, A, B))
        {
            res=mid; // update res
            high=mid-1; // update high to find more min
        }
        else
        {
            low=mid+1; // update low in other cases
        }
    }
    return res;
}
