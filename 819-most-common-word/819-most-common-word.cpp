class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> ban;
        string answer = "";
        for(auto i:banned)
            ban[i]++;
        unordered_map<string,int> countFrequency;
        int max_freq = 0;
        for(int i=0;i<paragraph.size();i++)
        {
            string word = "";
            while(i<paragraph.size() and isalpha(paragraph[i]))
            {
                paragraph[i] = tolower(paragraph[i]);
                word+=paragraph[i];
                i++;
                
            }
            if(ban.find(word)==ban.end() and word!="")
            {
                countFrequency[word]++;
                if(countFrequency[word]>max_freq)
                {
                    max_freq = countFrequency[word];
                    answer = word;
                }
            }
        }
        return answer;
    }
};