#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> A[8];
	A[0].push_back(0);
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < A[i].size(); ++j){
			int s = A[i][j], e = (j+1 < A[i].size() ? A[i][j+1] : N);
			if(s+1 == e){
				putchar('A' + j%2);
				A[i+1].push_back(s);
			}
			else{
				int mid = (s+e)/2;
				for(int k = s; k < mid; ++k) putchar('A');
				for(int k = mid; k < e; ++k) putchar('B');
				A[i+1].push_back(s);
				A[i+1].push_back(mid);
			}
		}
		puts("");
	}
}