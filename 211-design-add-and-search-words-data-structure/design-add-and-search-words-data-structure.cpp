class TrieNode {
public:
    TrieNode* child[26] = {nullptr};
    bool isWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* t = root;
        for (char c : word) {
            if (!t->child[c - 'a']) {
                t->child[c - 'a'] = new TrieNode();
            }
            t = t->child[c - 'a'];
        }
        t->isWord = true;
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }

private:
    bool searchHelper(TrieNode* node, const string& word, int i) {
        if (!node) return false;
        if (i == word.size()) return node->isWord;

        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->child[j] && searchHelper(node->child[j], word, i + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = word[i] - 'a';
            return searchHelper(node->child[idx], word, i + 1);
        }
    }
};
