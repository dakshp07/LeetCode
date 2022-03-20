class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> face_a(7), face_b(7), same(7);
        for(int i=0; i<tops.size(); i++)
        {
            face_a[tops[i]]++;
            face_b[bottoms[i]]++;
            if(tops[i]==bottoms[i])
            {
                same[tops[i]]++;
            }
        }
        int minrotation=INT_MAX;
        for(int i=1; i<7; i++)
        {
            if(face_a[i]+face_b[i]-same[i]==tops.size())
            {
                minrotation=min(minrotation, min(face_a[i], face_b[i])-same[i]);
            }
        }
        return minrotation==INT_MAX ? -1 : minrotation; 
    }
};