class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
   
    vector<vector<string>> answer;
        vector<string> temp;
        string current = "";
        sort(products.begin(),products.end());
        for(auto ch:searchWord)
        {
            current+=ch;
                       temp.clear();
            int n=current.size();
          for(auto x:products)
            {
           
                if(x.substr(0,n)==current) 
                    temp.push_back(x);
              if(temp.size()==3) break;
            
            }
            answer.push_back(temp);
 
        }
        return answer;
    }
};