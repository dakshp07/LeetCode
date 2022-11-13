class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // i will store the words of dictinoary in map
        // now i remove spaces from sentence and check if any word is there in my map
        map<string, int> mp;
        for(int i=0; i<dictionary.size(); i++)
        {
            // add words of dictionary to map
            mp[dictionary[i]]++;
        }
        // now we remove spaces from sentence
        stringstream st(sentence);
        string words;
        vector<string> sen;
        while(st>>words)
        {
            sen.push_back(words);
        }
        // now iterate over sen vector
        for(int i=0; i<sen.size(); i++)
        {
            string temp=sen[i];
            // now check if the prefix is there or not
            string check="";
            for(int j=0; j<temp.size(); j++)
            {
                // we need smallest one
                // so we check all possible chars. eg: cattled
                // we check c first, ca next and cat next etc etc
                check+=temp[j];
                if(mp.find(check)!=mp.end())
                {
                    // if we find a root, we replace it in our original sen vector
                    // since words like the by are also supposed to be there
                    sen[i]=check;
                    // once we get match, we break since we need smallest one
                    // and in first go we get smallest one, as we move c, ca, cat, catt etc
                    break;
                }
            }
        }
        // create ans string
        string ans="";
        for(int i=0; i<sen.size(); i++)
        {
            ans+=sen[i];
            ans+=" ";
        }
        // remove last space
        ans.pop_back();
        return ans;
    }
};