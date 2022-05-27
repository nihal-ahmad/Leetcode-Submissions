class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
   
    vector<vector<string>> answer;
        vector<string> temp;
        sort(products.begin(),products.end());
        string current="";
        for(auto ch:searchWord)
        {
            current+=ch;
            temp.clear();
            vector<string>::iterator itr = lower_bound(products.begin(),products.end(),current);
            for(int i=0;i<3 and itr+i!=products.end();i++)
            {
                string now = *(itr+i);
                if(now.find(current)) break;
                temp.push_back(now);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};