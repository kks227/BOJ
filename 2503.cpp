#include <cstdio>
#include <map>
using namespace std;

inline bool match(int x, int y, int b, int s){
	int d1[3], d2[3];
	for(int i=0; i<3; i++){
		d1[i] = x%10;
		d2[i] = y%10;
		x /= 10;
		y /= 10;
	}
	int b1 = 0, s1 = 0;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(d1[i]==d2[j]) (i==j ? s1 : b1)++;
	return b1==b && s1==s;
}

int main(){
	int N;
	scanf("%d", &N);
	map<int, bool> flag;
	for(int i=1; i<10; i++)
		for(int j=1; j<10; j++){
			if(i==j) continue;
			for(int k=1; k<10; k++){
				if(i==k || j==k) continue;
				flag[i*100+j*10+k] = true;
			}
		}
	int result = 504;
	for(int i=0; i<N; i++){
		int K, S, B;
		scanf("%d %d %d", &K, &S, &B);
		for(auto& p: flag){
			if(!p.second) continue;
			if(!match(p.first, K, B, S)){
				p.second = false;
				result--;
			}
		}
	}
	printf("%d\n", result);
}