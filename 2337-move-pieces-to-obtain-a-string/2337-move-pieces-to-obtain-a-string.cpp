class Solution {
public:
    bool canChange(string start, string target) {
        int Ls=0, Rs=0;
        
        for(int i=0;i<start.size();i++) {
            // count Ls and Rs 
            if(start[i]=='L') Ls++;
            else if(start[i]=='R') Rs++;
            
            // dono zero nhi huye toh
            if(Ls!=0 && Rs!=0) return false;
            
            // agar traget main Ls yaa Rs aaye toh decrement
            if(target[i]=='L') Ls--;
            else if(target[i]=='R') Rs--;
            
            // again check kon zero nhi
            if(Ls!=0 && Rs!=0) return false;
            
            if(Ls>0) return false;
            if(Rs<0) return false;
        }
        return (Ls==0 && Rs==0);
    }
};