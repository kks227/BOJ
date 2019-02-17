#include <cstdio>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
	int d[9], p[9], result = 998244353, r[8][3] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8,
		0, 3, 6, 1, 4, 7, 2, 5, 8,
		0, 4, 8, 2, 4, 6
	};
	for(int i = 0; i < 9; ++i)
		scanf("%d", d+i);
	iota(p, p+9, 1);
	do{
		bool flag = true;
		for(int i = 0; i < 8; ++i){
			if(p[r[i][0]]+p[r[i][1]]+p[r[i][2]] != 15){
				flag = false;
				break;
			}
		}
		if(flag){
			int temp = 0;
			for(int i = 0; i < 9; ++i)
				temp += abs(d[i]-p[i]);
			result = min(temp, result);
		}
	}while(next_permutation(p, p+9));
	printf("%d\n", result);
}