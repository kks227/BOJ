#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 3000;
typedef pair<int, int> P;

int dcnt, SN, dfsn[MAX*2], sn[MAX*2];
vector<int> adj[MAX*2];
bool finished[MAX*2];
stack<int> S;

inline int cross(int x1, int y1, int x2, int y2){
	return x1*y2 - x2*y1;
}

inline int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	int temp = cross(x2-x1, y2-y1, x3-x1, y3-y1);
	if(temp == 0) return 0;
	return (temp > 0 ? 1 : -1);
}

inline bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int p = ccw(x1, y1, x2, y2, x3, y3);
	int q = ccw(x1, y1, x2, y2, x4, y4);
	if(p && q && p == q) return false;
	p = ccw(x3, y3, x4, y4, x1, y1);
	q = ccw(x3, y3, x4, y4, x2, y2);
	if(p && q && p == q) return false;
	return true;
}

inline int oppo(int n){
	return n%2 ? n-1 : n+1;
}

int dfs(int curr){
	dfsn[curr] = ++dcnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		sn[curr] = SN++;
		while(1){
			int family = S.top();
			S.pop();
			finished[family] = true;
			if(family == curr) break;
			sn[family] = sn[curr];
		}
	}
	return result;
}



int main(){
	int N, x1[3000], y1[3000], x2[3000], y2[3000];
	scanf("%d", &N);
	for(int i=0; i<N*3; i++){
		scanf("%d %d %d %d", x1+i, y1+i, x2+i, y2+i);
		int k1 = i/3, k2 = i%3;
		int p = k1*6 + k2*2, q = k1*6 + (k2+1)%3*2;
		adj[oppo(q)].push_back(p);
		adj[oppo(p)].push_back(q);
		for(int j=0; j<i; j++){
			if(intersect(x1[i], y1[i], x2[i], y2[i], x1[j], y1[j], x2[j], y2[j])){
				p = i*2 + 1; q = j*2 + 1;
				adj[oppo(q)].push_back(p);
				adj[oppo(p)].push_back(q);
			}
		}
	}

	for(int i=0; i<N*6; i++)
		if(dfsn[i] == 0) dfs(i);
	bool possible = true;
	for(int i=0; i<N*3; i++){
		if(sn[i*2] == sn[i*2+1]){
			possible = false;
			break;
		}
	}
	if(!possible) puts("-1");
	else{
        int result[MAX];
        P p[MAX*2];
        fill(result, result+N*3, -1);
        for(int i=0; i<N*6; i++)
			p[i] = P(sn[i], i);
		sort(p, p+N*6);
		for(int i=N*6-1; i>=0; i--){
			int val = p[i].second;
			if(result[val/2] == -1) result[val/2] = !(val%2);
		}
		vector<int> stick;
		for(int i=0; i<N*3; i++)
			if(result[i]) stick.push_back(i+1);
		printf("%d\n", stick.size());
		if(!stick.empty()){
			for(int s: stick)
				printf("%d ", s);
			puts("");
		}
    }
}