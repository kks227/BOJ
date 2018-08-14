#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	int N, result = 0;
	bool isP[200000] = {0};
	stack<int> S;
	scanf("%d\n", &N);
	for(int i=0; i<N; i++){
		if(getchar() == '(') S.push(i);
		else{
			if(!S.empty()){
				isP[S.top()] = isP[i] = true;
				S.pop();
			}
		}
	}
	int temp = 0;
	for(int i=0; i<N; i++){
		if(isP[i]) temp++;
		else{
			result = max(temp, result);
			temp = 0;
		}
	}
	printf("%d\n", max(result, temp));
}