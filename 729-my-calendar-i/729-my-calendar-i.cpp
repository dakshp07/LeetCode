class MyCalendar {
public:
    // we will use a map
    map<int, int> mp; // start, end
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            // case 1 if the given event starts b/w any of the map event
            if(start>=it->first && start<it->second) return false;
            // case 2 if the given event ends b/w any of the map event
            if(end>it->first && end<=it->second) return false;
            // case 3 if the given event overlaps any of the map event ie starts before and ends later
            if(start<=it->first && end>it->second) return false;
        }
        mp[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */