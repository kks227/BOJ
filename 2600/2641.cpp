#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N, M;
	scanf("%d", &N);
	vector<int> model(N), cur(N);
	for(int i=0; i<N; i++)
		scanf("%d", &model[i]);
	scanf("%d", &M);
	vector<vector<int>> result;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++)
			scanf("%d", &cur[j]);
		for(int j=0; j<N; j++){
			bool equal = true;
			for(int k=0; k<N; k++)
				if(model[k] != cur[(k+j)%N]){
					equal = false;
					break;
				}
			if(equal){
				result.push_back(cur);
				break;
			}
			equal = true;
			for(int k=0; k<N; k++)
				model[k] = (model[k]+1)%4+1;
			reverse(model.begin(), model.end());
			for(int k=0; k<N; k++)
				if(model[k] != cur[(k+j)%N]){
					equal = false;
					break;
				}
			if(equal){
				result.push_back(cur);
				break;
			}
		}
	}
	printf("%d\n", result.size());
	for(auto& r: result){
		for(int n: r) printf("%d ", n);
		puts("");
	}
}