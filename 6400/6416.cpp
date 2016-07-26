#include <cstdio>
#include <set>
using namespace std;

int main(){

	int u, v, tSize, cnt = 1;
	bool flag;
	set<int> pointed;
	set<int> nodes;
	while(1){
		tSize = 0;
		pointed.clear();
		nodes.clear();
		flag = true;
		while(1){
			scanf("%d %d", &u, &v);
			if(u < 0) return 0;
			if(u == 0) break;
			tSize++;
			if(pointed.count(v)) flag = false;
			else pointed.insert(v);
			nodes.insert(u);
			nodes.insert(v);
		}
		if(tSize>0 && nodes.size() != tSize+1) flag = false;
		printf("Case %d is %sa tree.\n", cnt++, flag?"":"not ");
	}

	return 0;
}