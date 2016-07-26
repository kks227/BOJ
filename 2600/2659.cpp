#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[4];
vector<int> clocks;

int getClock(){
	int m = 9999;
	for(int i=0; i<4; i++)
		m = min(m, a[i]*1000+a[(i+1)%4]*100+a[(i+2)%4]*10+a[(i+3)%4]);
	return m;
}

void DFS(int pos){
	if(pos==4){
		clocks.push_back(getClock());
		return;
	}
	for(int i=1; i<10; i++){
		a[pos] = i;
		DFS(pos+1);
	}
}

int main(){
	DFS(0);
	for(int i=0; i<4; i++)
		scanf("%d", a+i);
	sort(clocks.begin(), clocks.end());
	clocks.resize(unique(clocks.begin(), clocks.end())-clocks.begin());
	printf("%d\n", lower_bound(clocks.begin(), clocks.end(), getClock())-clocks.begin()+1);
}