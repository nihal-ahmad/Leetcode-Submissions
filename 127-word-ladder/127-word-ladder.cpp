class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        bool present=false;
        for(auto i: wordList)
        {
            if(i==endWord) present=true;
            words.insert(i);
        }
        if(!present) return 0;
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty())
        {depth+=1;
         int lsize = q.size();
         while(lsize--)
         {
             string word = q.front();
             q.pop();
             for(int i=0;i<word.size();i++)
             {  string temp=word;
             for(char c='a';c<='z';c++)
             {
               temp[i]=c;
                 if(temp==word) continue;
                 else if(temp==endWord) return depth+1;
                 else if(words.find(temp)!=words.end())
                 {
                     q.push(temp);
                     words.erase(temp);
                 }
             }
         }
         }
            
        }
        return 0;
    }
};