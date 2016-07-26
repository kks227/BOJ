#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int N, arr[100], cnt, result[100];
bool started[100], ended[100];
stack<int> s;

void DFS(int current){
	started[current] = true;
	s.push(current);
	int next = arr[current]-1;
	if(!started[next]) DFS(next);
	else if(!ended[next]){
		while(1){
			int t = s.top();
			s.pop();
			result[cnt++] = t+1;
			if(t == next) break;
		}
	}
	ended[current] = true;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	for(int i=0; i<N; i++){
		if(!started[i]) DFS(i);
		while(!s.empty()) s.pop();
	}
	sort(result, result+cnt);
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++)
		printf("%d\n", result[i]);
}