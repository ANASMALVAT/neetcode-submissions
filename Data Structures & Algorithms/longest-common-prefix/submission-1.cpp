
class TrieNode {
public:
    TrieNode *child[26];
    bool endOfWord;

    TrieNode(){
        endOfWord = false;
        for(int i = 0;i < 26; i ++){
            child[i] = nullptr;
        }
    }
};

class Solution {

TrieNode *root = new TrieNode();

void insert(string word){
    TrieNode *node = root;
    for(char c: word){
        int ind = c - 'a';
        if(node->child[ind] == nullptr){
            node->child[ind] = new TrieNode();
        }
        node = node->child[ind];
    }
    node->endOfWord = true;
}

bool search(string word){
    TrieNode* node = root;
    for(char c: word){
        int ind = c - 'a';
        if(node->child[ind] == nullptr){
            return false;
        }
        node = node->child[ind];
    }
    return true;
}

string findCommonPrefix(){
    string prefix = "";
    TrieNode *node = root;

    while(!node->endOfWord){
        int childCount = 0;
        int nextInd =  -1;

        for(int i = 0; i < 26; i ++){
            if(node->child[i] != nullptr){
                childCount++;
                nextInd = i;
            }
        }
        if(childCount == 1){
            char c = 'a' + nextInd;
            prefix+= c;
            node = node->child[nextInd];
        }
        if(childCount != 1){
            break;
        }
    }

    return prefix;

}






public:
    string longestCommonPrefix(vector<string>& strs) {
        for(string w: strs){
            insert(w);
        }
        return findCommonPrefix();
    }

};