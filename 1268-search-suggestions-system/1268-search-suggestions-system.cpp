class Node {
    private:
    Node* links[26];
    vector<string> suggestions;
    public:
    bool containsKey(char ch) {
        return links[ch-'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    Node* get(char ch) {
        return links[ch-'a'];
    }
    int suggestionsSize() {
        return suggestions.size();
    }
    void addSuggestion(string &word) {
        suggestions.push_back(word);
    }
    vector<string> getSuggestions() {
        return suggestions;
    }
};

class Trie {
    private:
    Node* root;
    public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            if(node->suggestionsSize() < 3) {
                node->addSuggestion(word);
            }
        }
    }
    vector<string> search(string &word) {
        Node* node = root;
        vector<string> suggest;
        for(char ch : word) {
            if(!node->containsKey(ch)) return suggest;
            node = node->get(ch);
        }
        return node->getSuggestions();
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie trie;
        for(auto word : products) trie.insert(word);
        vector<vector<string>> ans;
        string tmp = "";
        for(char ch : searchWord) {
            tmp += ch;
            ans.push_back(trie.search(tmp));
        }
        return ans;
    }
};