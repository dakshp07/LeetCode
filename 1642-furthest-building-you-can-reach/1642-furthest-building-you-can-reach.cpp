class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // ladder can be used for larger difference of heights
        // bricks can be used for smaller difference of heights till they get exhausted
        // for k largest climbs we use ladders
        priority_queue<int> pq; // priority queue will put all stuffs in order
        int i=0;
        for(i=0; i<heights.size()-1; i++)
        {
            // compare with prev height and see if you cn see bricks or height
            int diff=heights[i+1]-heights[i];
            if(diff<=0) // no need to use our resources
            {
                continue;
            }
            bricks-=diff; // lets say we use bricks
            pq.push(diff); // add the no of bricks use to queue
            if(bricks<0) // lets say we dont have any more bricks, we use ladders
            {
                bricks+=pq.top(); // take bricks back from last one
                pq.pop(); // taking back
                ladders--; //using one ladder instead
            }
            if(ladders<0) break; // if ladder is negetive then the ladder was not provided to go to next building. So we can't proceed.
        }
        return i;
    }
};