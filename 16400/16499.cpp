#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	set<vector<int>> S;
	for(int i = 0; i < N; ++i){
		char word[11];
		scanf("%s", word);
		vector<int> v(26);
		for(int j = 0; word[j]; ++j)
			++v[word[j]-'a'];
		S.insert(v);
	}
	printf("%u\n", S.size());
}