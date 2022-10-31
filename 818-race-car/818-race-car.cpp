class Solution {
public:
    int racecar(int target) {
        // so at any point of time we have two options A,R
        // we can probably run recursion and then optimise it to memoization, tabulation
        
        // but what we see from test cases is we can reach any specific target thorugh many ways
        // to reach to 8 you can from 1->4->6->9->8 or 1->2->4->8
        // this shows that all these numbers are like nodes, and the ways are like networks connecting the nodes
        // so we can run a bfs to find the shortest path, as thats what bfs is used for
        queue<pair<pair<long long, long long>, long long>> q;
        // queue conatins {{no of moves, current position}, current speed}
        q.push({{0, 0}, 1}); // as we did 0 moves rn, we start from pos 0 with a speed of 1
        // a set will keep track if we reach {current position,current speed} again
        set<pair<long long, long long>> visited;
        // set contains {current position, current speed}long long
        // bfs
        while(!q.empty())
        {
            long long moves=q.front().first.first;
            long long current_position=q.front().first.second;
            long long current_speed=q.front().second;
            q.pop();
            // now if we have reached our target we return moves
            if(current_position==target) return moves;
            // if we reach current position with current speed before too then we skip
            // since we already visited this combination
            if(visited.find({current_position, current_speed})!=visited.end()) continue;
            // else we always try to accelarate (A) in forward direction
            else
            {
                // we first add the current position, speed in set
                visited.insert({current_position, current_speed});
                // now we move forward
                // position += speed and speed *= 2 and moves+=1
                q.push({{moves+1, current_position+current_speed}, current_speed*2});
                
                // now when we reverse (R)?
                // we do that in 2 cases
                // case 1: when current_position>target and speed>0 since we need to make speed=-1 so that we go back
                if(current_position+current_speed>target && current_speed>0)
                {
                    // we go back
                    // If your speed is positive then speed = -1 or otherwise speed = 1
                    q.push({{moves+1, current_position}, -1});
                }
                // case 2: when current_position<target and speed<0 since we need to make speed 1 as we should move forward
                else if(current_position+current_speed<target && current_speed<0)
                {
                    // we go back
                    // If your speed is positive then speed = -1 or otherwise speed = 1
                    q.push({{moves+1, current_position}, 1});
                }
            }
        }
        return -1; // if not possible to reach target we return -1
    }
};