#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char W[31];

struct Trie{
	Trie *go[128];
	int cnt;
	Trie(): cnt(0){ fill(go, go+128, nullptr); }
	void insert(char *str){
		if(*str == '\0'){
			N++;
			cnt++;
		}
		else{
			int next = *str - ' ';
			if(!go[next]) go[next] = new Trie;
			go[next]->insert(str+1);
		}
	}
	void print(int pos=0){
		if(cnt > 0){
			W[pos] = '\0';
			printf("%s %.4lf\n", W, 100.0*cnt/N);
		}
		for(int i=0; i<128; i++){
			if(go[i]){
				W[pos] = i + ' ';
				go[i]->print(pos+1);
			}
		}
	}
};

int main(){
	Trie *root = new Trie;
	while(gets(W)) root->insert(W);
	root->print();
}