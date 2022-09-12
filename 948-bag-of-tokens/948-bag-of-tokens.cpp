class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // my idea is that we can play the biggest token to get our power back and lose a score
        // and the smaller token can be used to give away our power and gain the score
        // so conclusion: play the bigger val token face down and smaller val tokens face up
        
        int n=tokens.size();
        // first sort the array
        sort(tokens.begin(), tokens.end());
        // now from starting we can reduce the power and from end we can gain power
        int left=0,  right=n-1;
        int score=0;
        int ans=0;
        while(left<=right)
        {
            // now we have two cases
            // case 1. the power is >= tokens[left], in this case we gain lose power and gain score
            // in this case we move left 
            if(power>=tokens[left])
            {
                // face up
                power-=tokens[left];
                score++;
                left++;
            }
            // case 2: lets say if the power<tokens[left] then we gain some power from right and move but we cant get score to -ve so we check if score>0
            else if(score>0)
            {
                power+=tokens[right];
                score--;
                right--;
            }
            else // for any other conditions ie score<0 we just break the loop
            {
                break;
            }
            // we pick max of all scores
            ans=max(score, ans);
        }
        return ans;
    }
};