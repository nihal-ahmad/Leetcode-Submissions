class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     vector<vector<string>> res;

    map<array<int, 26>, vector<string>> mp;
    for (int i = 0; i < strs.size(); i++)
    {

        string z = strs[i];
        array<int, 26> m_p={0};
        for (int j = 0; j < z.size(); j++)
        {
            m_p[z.at(j) - 'a'] += 1;
        }

        auto k = mp.find(m_p);
        if (k != mp.end())
        {
            k->second.push_back(z);
            mp[m_p] = k->second;
        }
        else
        {
            mp[m_p] = vector<string>{z};
        }
    }
    for (auto t = mp.begin(); t != mp.end(); t++)
    {
        res.push_back(t->second);
    }
    return res;
    }
};