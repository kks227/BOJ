#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int uf[20000], len[20000];

P rootLen(int a){
	if(uf[a] < 0) return P(a, 0);
	P temp = rootLen(uf[a]);
	uf[a] = temp.first;
	len[a] += temp.second;
	return P(uf[a], len[a]);
}

void link(int a, int b){
	int aCenter = rootLen(a).first;
	int bCenter = rootLen(b).first;
	if(aCenter != bCenter){
		len[aCenter] = (int)(abs(a-b)) % 1000;
		uf[aCenter] = b;
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		memset(uf, -1, sizeof(uf));
		memset(len, 0, sizeof(len));
		while(1){
			char op;
			scanf(" %c", &op);
			if(op == 'O') break;
			else if(op == 'E'){
				int I;
				scanf("%d", &I);
				printf("%d\n", rootLen(I-1).second);
			}
			else{
				int I, J;
				scanf("%d %d", &I, &J);
				link(I-1, J-1);
			}
		}
	}
}