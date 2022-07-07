#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int LETTER_NUM = 26;

class DictTree {
public:
    DictTree *children[LETTER_NUM];
    int num;

    DictTree() {
        num = 0;
        for(int i = 0; i < LETTER_NUM; ++i) {
            children[i] = nullptr;
        }
    }

    ~DictTree() {
        for(int i = 0; i < LETTER_NUM; ++i) {
            if(children[i] != nullptr) {
                delete children[i];
            }
        }
    }
};

class Solution {
private:
    DictTree *root;

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new DictTree();

        for(int i = 0; i < dictionary.size(); ++i) {
            add_word(root, dictionary[i]);
        }

        vector<string> src, dst;
        split(sentence, src);

        for(int i = 0; i < src.size(); ++i) {
            dst.push_back(find_root(root, src[i]));
        }

        string res = join(dst);
        delete root;

        return res;
    }

    void add_word(DictTree *root, const string &word) {
        DictTree *p = root;
        for(int i = 0; i < word.size(); ++i) {
            int idx = (word[i] - 'a');
            if(p->children[idx] == nullptr) {
                p->children[idx] = new DictTree();
            }
            p = p->children[idx];
        }

        p->num += 1;
    }

    string find_root(DictTree *root, string word) {
        string res;
        DictTree *p = root;
        for(int i = 0; i < word.length(); ++i) {
            int idx = (word[i] - 'a');
            if(p->children[idx] == nullptr) {
                return word;
            }

            res.push_back(word[i]);
            p = p->children[idx];

            if(p->num > 0) {
                break;
            }
        }

        return res;
    }

    void split(const string &s, vector<string> &v) {
        stringstream ss(s);
        string word;
        while(ss >> word) {
            v.push_back(word);
        }
    }

    string join(const vector<string> &word) {
        string res = word[0];
        for(int i = 1; i < word.size(); ++i) {
            res += (" " + word[i]);
        }

        return res;
    }
};