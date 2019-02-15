#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

struct Trie{
    int cnt;
    bool id;
    Trie* go[26];
    Trie(): cnt(0), id(false){ fill(go, go+26, nullptr); }
    ~Trie(){
        for(int i = 0; i < 26; ++i)
            if(go[i]) delete go[i];
    }
    void insert(char *s, int pos){
        id = true;
        if(s[pos] == '\0'){
            if(cnt > 0) printf("%s%d\n", s, cnt+1);
            else puts(s);
            ++cnt;
            return;
        }

        int k = s[pos] - 'a';
        if(!go[k]) go[k] = new Trie;
        if(!go[k]->id){
            for(int i = 0; i < pos+1; ++i)
                putchar(s[i]);
            puts("");
            go[k]->insertOnly(s, pos+1);
        }
        else go[k]->insert(s, pos+1);
    }
    void insertOnly(char *s, int pos){
        id = true;
        if(s[pos] == '\0'){
            ++cnt;
            return;
        }

        int k = s[pos] - 'a';
        if(!go[k]) go[k] = new Trie;
        go[k]->insertOnly(s, pos+1);
    }
};

int main(){
    int N;
    scanf("%d", &N);
    Trie *root = new Trie;
    for(int i = 0; i < N; ++i){
        char S[11];
        scanf("%s", S);
        root->insert(S, 0);
    }
    delete root;
}