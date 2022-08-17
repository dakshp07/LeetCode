class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // put all 26 mrose code in the vector to access them
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> seen; // insert the string of morse here
        for(int i=0; i<words.size(); i++)
        {
            string temp="";
            for(int j=0; j<words[i].size(); j++)
            {
                temp+=(morse[words[i][j]-'a']); // make the morse code for all words
            }
            seen.insert(temp); // set will handle duplicates
        }
        return seen.size(); // return size
    }
};