#include <cstdio>
using namespace std;

int N, seq[80];
bool success;

bool backtrack(int pos){
	if(pos == N){
		success = true;
		return true;
	}

	for(int i=1; i<=3; i++){
		seq[pos] = i;
		bool fail = false;
		for(int j=1; j<=(pos+1)/2; j++){
			bool same = true;
			for(int k=0; k<j; k++){
				if(seq[pos-k] != seq[pos-j-k]){
					same = false;
					break;
				}
			}
			if(same){
				fail = true;
				break;
			}
		}
		if(!fail && backtrack(pos+1)) return true;
		if(success) return true;
	}
	return false;
}

int main(){
	scanf("%d", &N);
	backtrack(0);
	for(int i=0; i<N; i++)
		printf("%d", seq[i]);
}