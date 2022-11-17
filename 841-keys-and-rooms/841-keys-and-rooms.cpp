class Solution {
public:
    void dfs(int room, int n, vector<vector<int>>& rooms, vector<int>& seen)
    {
        // base case: if we have already seen this room
        if(seen[room]==1) return;
        // mark current room as visited
        seen[room]=1;
        // and visit adj rooms
        for(auto it: rooms[room])
        {
            if(!seen[it])
            {
                dfs(it, n, rooms, seen);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // so we can just peform a normal bfs or dfs
        // to see if we can visit all rooms or not
        // in my previous solution i did bfs, we try dfs here
        vector<int> seen(rooms.size(), 0);
        // runover a dfs for all nodes
        dfs(0, rooms.size(), rooms, seen);
        for(int i=0; i<seen.size(); i++)
        {
            if(seen[i]==0) return false; // as we were unable to visit that room
        }
        return true; // return true in other cases
    }
};