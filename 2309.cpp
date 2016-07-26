#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int height[9], e1, e2, spare=0;
	for(int i=0; i<9; i++){
		scanf("%d", height+i);
		spare += height[i];
	}
	sort(height, height+9);
	spare -= 100;

	bool flag = false;
	for(int i=0; i<9; i++){
		if(spare < height[i]) continue;
		e1 = i;
		for(int j=0; j<9; j++){
			if(i == j) continue;
			if(spare == height[i] + height[j]){
				e2 = j;
				flag = true;
				break;
			}
		}
		if(flag) break;
	}

	for(int i=0; i<9; i++){
		if(i==e1 || i==e2) continue;
		printf("%d\n", height[i]);
	}
}