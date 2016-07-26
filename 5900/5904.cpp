#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> moo;

void Moo(int k, int pos){
	if(k==0){
		putchar(pos?'o':'m');
		return;
	}
	if(pos < moo[k-1]) Moo(k-1, pos);
	else if(pos >= moo[k]-moo[k-1]) Moo(k-1, pos-moo[k]+moo[k-1]);
	else Moo(0, pos-moo[k-1]);
}

int main(){

	scanf("%d", &N);
	N--;
	moo.push_back(3);
	for(int i=0; moo[i]<=N; i++)
		moo.push_back(moo[i]*2+i+4);
	Moo(moo.size(), N);

    return 0;
}