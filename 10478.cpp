#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N==0) break;
		char name[10][6];
		for(int i=0; i<N; i++)
			scanf("%s", name[i]);
		vector<P> adj[10];
		bool prexist[10] = {false};
		for(int i=0; i<N-1; i++){
			char tname[6];
			scanf("%s", tname);
			int in, out;
			for(int i=0; i<N; i++)
				if(strcmp(tname, name[i])==0){
					in = i;
					break;
				}
			getchar();
			getchar();
			int tk;
			scanf("%d %s", &tk, tname);
			for(int i=0; i<N; i++)
				if(strcmp(tname, name[i])==0){
					out = i;
					break;
				}
			adj[in].push_back(P(tk, out));
			adj[out].push_back(P(-tk, in));
			prexist[out] = true;
		}

		for(int i=0; i<N; i++){
			if(prexist[i]) continue;
			bool visited[10] = {0};
			int cur = i, val[10];
			val[cur] = 1;
			stack<int> s;
			s.push(cur);
			bool success = true;
			while(!s.empty()){
				do{
					cur = s.top();
					s.pop();
				}while(visited[cur] && !s.empty());
				visited[cur] = true;
				for(auto& e: adj[cur]){
					if(visited[e.second]) continue;
					if(e.first > 0){
						val[e.second] = val[cur] * e.first;
						s.push(e.second);
					}
					else{
						if(val[cur] < -e.first){
							success = false;
							break;
						}
						val[e.second] = val[cur] / -e.first;
						s.push(e.second);
					}
				}
				if(!success) break;
			}
			if(success){
				P result[10];
				for(int i=0; i<N; i++)
					result[i] = P(val[i], i);
				sort(result, result+N);
				for(int i=0; i<N; i++)
					printf("%d%s%s", result[i].first, name[result[i].second], i==N-1?"\n":" = ");
				break;
			}
		}
	}
}