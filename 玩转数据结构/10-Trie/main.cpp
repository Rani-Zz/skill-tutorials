class Trie {
private:
    struct Node{
        map<char,int> next;
        bool end = false;
    };
    vector<Node> trie;
public:
    /** Initialize your data structure here. */
    Trie() {
        trie.push_back(Node());
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        int treeID = 0;
        for(char c: word)
        {
            if(trie[treeID].next.find(c)==trie[treeID].next.end())
            {
                trie[treeID].next[c] = trie.size();
                trie.push_back(Node());
            }
            
            treeID = trie[treeID].next[c];
        }
        
        trie[treeID].end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int treeID = 0;
        for(auto c:word)
        {
            if(trie[treeID].next.find(c)==trie[treeID].next.end())
                return false;
            treeID = trie[treeID].next[c];
        }
        return trie[treeID].end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int treeID = 0;
        for(auto c:prefix)
        {
            if(trie[treeID].next.find(c)==trie[treeID].next.end())
                return false;
             treeID = trie[treeID].next[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
