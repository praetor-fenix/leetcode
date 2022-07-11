#include <string>
#include <vector>

using namespace std;

const int LETTER_NUM = 26;

class DictTree {
public:
    DictTree *children[LETTER_NUM];
    int num;

    DictTree() {
        for(int i = 0; i < LETTER_NUM; ++i) {
            children[i] = nullptr;
        }

        num = 0;
    }

    ~DictTree() {
        for(int i = 0; i < LETTER_NUM; ++i) {
            delete children[i];
        }
    }
};

class MagicDictionary {
private:
    DictTree *root;

public:
    MagicDictionary() {
        root = new DictTree();
    }

    ~MagicDictionary() {
        delete root;
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i = 0; i < dictionary.size(); ++i) {
            addWord(dictionary[i]);
        }
    }
    
    bool search(string searchWord) {
        DictTree *p = root;
        for(int i = 0; i < searchWord.length(); ++i) {
            int idx = (searchWord[i] - 'a');

            bool ok = false;
            for(int j = 0; j < LETTER_NUM; ++j) {
                if(j != idx && p->children[j] != nullptr) {
                    ok = ok || searchPostfix(searchWord, i + 1, p->children[j]);
                }
            }

            if(ok) {
                return true;
            }
            
            if(p->children[idx] == nullptr) {
                return false;
            }

            p = p->children[idx];
        }

        return false;
    }

    bool searchPostfix(const string &word, int idx, DictTree *node) {
        DictTree *p = node;
        for(int i = idx; i < word.length(); ++i) {
            int idx = (word[i] - 'a');
            if(p->children[idx] == nullptr) {
                return false;
            }

            p = p->children[idx];
        }

        return p->num > 0;
    }

    void addWord(const string &s) {
        DictTree *p = root;
        for(int i = 0; i < s.length(); ++i) {
            int idx = (s[i] - 'a');
            if(p->children[idx] == nullptr) {
                p->children[idx] = new DictTree();
            }
            p = p->children[idx];
        }

        p->num += 1;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */