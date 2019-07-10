#include <cstdio>
#include <queue>
using namespace std;

inline bool check(int n, int b){
	int a = n, m = 0;
	while(a > 0){
		m = m*b + a%b;
		a /= b;
	}
	return (n == m);
}

int main(){
	int a, b, k;
	queue<int> Q[2];
	bool turn = false;
	scanf("%d %d %d", &a, &b, &k);
	for(int i = a; i <= b; ++i)
		if(check(i, 2)) Q[0].push(i);
	for(int i = 3; i <= k; ++i){
		while(!Q[turn].empty()){
			int j = Q[turn].front();
			Q[turn].pop();
			if(check(j, i)) Q[!turn].push(j);
		}
		turn = !turn;
	}
	printf("%d\n", Q[turn].size());
}