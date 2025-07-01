class TrieNode {
public:
    TrieNode *child[26];
    bool isWord = false;
    
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *t = root;
        for(char c: word){
            if(!t->child[c - 'a']){
                t->child[c - 'a'] = new TrieNode();
            }
            t = t->child[c - 'a'];
        }
        t->isWord = 1;
    }
    
    bool search(string word) {
        TrieNode *t = root;
        for(char c: word){
            if(!t->child[c - 'a']){
                return false;
            }
            t = t->child[c - 'a'];
        }
        return t->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *t = root;
        for(char c: prefix){
            if(!t->child[c - 'a']){
                return false;
            }
            t = t->child[c - 'a'];
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