class Solution {
public:
    bool checkValidString(string s) {
        // ( bracket waali char ke pos ko store karenge
        stack<int> brac;
        // * ko ek stack main karenge store
        stack<int> star;
        for(int i=0; i<s.length(); i++)
        {
            // agar open para hoga toh store
            if(s[i]=='(')
            {
                brac.push(i);
            }
            // star ko toh sidha star waali main push kardo
            else if(s[i]=='*')
            {
                star.push(i);
            }
            // agar close hua toh pop karna
            // agar brac main hain item toh pop that
            else if(!brac.empty())
            {
                brac.pop();
            }    
            // brac nhi hoga toh main star ka use karunga
            else if(!star.empty())
            {
                star.pop();
            }
            // agar dono khali hui toh false return karoge
            else
            {
                return false;
            }
        }
        // maan lo abhi bhi brac main item hain to dekho unki pairing hogi yaa nhi
        while(!brac.empty())
        {
            // agar star khali matlab return false
            if(star.empty())
            {
                return false;
            }
            // ( ki pos should be less than pos of star (given condition)
            if(brac.top()<star.top())
            {
                brac.pop();
                star.pop();
            }
            else
            {
                return false;
            }
        }
        // end main dekhlo agar brac waali stack khatam huyi ki nhi
        // star waali se lena dena nhi kyuki unko aapne empty consider kar sakte
        return brac.empty();
    }
};