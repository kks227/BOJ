#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int M, val, mid;
		scanf("%d %d", &M, &val);
		printf("%d\n%d ", M/2+1, val);
		mid = val;

		priority_queue<int> L;
		priority_queue<int, vector<int>, greater<int>> R;
		for(int i=0; i<M/2; i++){
			scanf("%d", &val);
			if(val <= mid){
				L.push(val);
				R.push(mid);
			}
			else{
				L.push(mid);
				R.push(val);
			}

			scanf("%d", &val);
			if(val <= R.top()){
				L.push(val);
				mid = L.top();
				L.pop();
			}
			else{
				R.push(val);
				mid = R.top();
				R.pop();
			}
			
			printf("%d", mid);
			putchar(i%10==8 ? '\n' : ' ');
		}
		if(M/2%10 != 9) puts("");
	}
}