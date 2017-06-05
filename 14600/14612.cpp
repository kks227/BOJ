#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, M;
	vector<P> order;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		char comm[9];
		int m, t;
		scanf("%s", comm);
		if(comm[0] == 'o'){
			scanf("%d %d", &m, &t);
			order.push_back(P(t, m));
		}
		else if(comm[0] == 's'){
			sort(order.begin(), order.end());
		}
		else{
			scanf("%d", &m);
			for(int i=0; ; i++){
				if(order[i].second == m){
					order.erase(order.begin()+i);
					break;
				}
			}
		}
		if(order.empty()) puts("sleep");
		else{
			for(int i=0; i<order.size(); i++)
				printf("%d ", order[i].second);
			puts("");
		}
	}
}