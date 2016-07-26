#include <cstdio>
#include <vector>
#include <set>
using namespace std;

void topologicalSort(bool flag, vector<int> pre, vector<set<int>> suc){
	int K = pre.size(), result[10];
	int N = flag ? 9 : K-1;
	for(int i=0; i<K; i++)
		for(int j=0; j<K; j++){
			int j1 = flag ? j : K-j-1;
			if(pre[j1] == 0){
				result[j1] = N--;
				pre[j1] = -1;
				for(int k: suc[j1]) pre[k]--;
				break;
			}
		}

	for(int i=0; i<K; i++)
		printf("%d", result[i]);
	puts("");
}

int main(){
	int K;
	scanf("%d", &K);
	vector<int> pre(K+1, 0);
	vector<set<int>> suc(K+1);
	for(int i=0; i<K; i++){
		getchar();
		if(getchar() == '<'){
			suc[i+1].insert(i);
			pre[i]++;
		}
		else{
			suc[i].insert(i+1);
			pre[i+1]++;
		}
	}
	topologicalSort(true, pre, suc);
	topologicalSort(false, pre, suc);
}