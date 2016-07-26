#include <cstdio>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;
typedef function<double(int, int)> ftype;
const int MAX = 1000;
const int TMAX = 1024;

struct BIT{
	struct Fenwick{
		double arr[TMAX+1][TMAX+1];

		Fenwick(){
			for(int i=0; i<=TMAX; i++)
				for(int j=0; j<=TMAX; j++)
					arr[i][j] = 0;
		}
		void update(int r, int c, double val){
			int r0 = r;
			while(c <= TMAX){
				r = r0;
				while(r <= TMAX){
					arr[r][c] += val;
					r += r & -r;
				}
				c += c & -c;
			}
		}
		double sum(int r, int c){
			if(r == 0 || c == 0) return 0;
			double result = 0;
			int r0 = r;
			while(c > 0){
				r = r0;
				while(r > 0){
					result += arr[r][c];
					r -= r & -r;
				}
				c -= c & -c;
			}
			return result;
		}
	}tree;
	ftype func;

	BIT(ftype f): func(f){}
	void update(int a, int b){
		tree.update(a+1, b+1, func(a, b));
	}
	void update(int a1, int b1, int a2, int b2){
		tree.update(a1+1, b1+1, -func(a1, b1));
		tree.update(a2+1, b2+1, func(a2, b2));
	}
	double sum(int r1, int c1, int r2, int c2){
		if(r1 > r2 || c1 > c2) return 0;
		return tree.sum(r2+1, c2+1) - tree.sum(r2+1, c1) - tree.sum(r1, c2+1) + tree.sum(r1, c1);
	}
};

int main(){
	int N, M, H[100000] = {0};
	scanf("%d %d %d", &N, &M, H);
	BIT T[5] = {
		BIT([](int a, int b){ return (a+b)/2.0; }),
		BIT([](int a, int b){ return 1; }),
		BIT([](int a, int b){ return a==b ? 0 : 1/-2.0/abs(b-a); }),
		BIT([](int a, int b){ return a==b ? 0 : 1.0*max(a,b)/abs(b-a); }),
		BIT([](int a, int b){ return a==b ? 0 : pow(min(a,b),2)/-2.0/abs(b-a); })
	};
	for(int i=1; i<N; i++){
		scanf("%d", H+i);
		for(int j=0; j<5; j++)
			T[j].update(H[i-1], H[i]);
	}
	for(int i=0; i<M; i++){
		char op;
		scanf(" %c", &op);
		if(op == 'Q'){
			int h;
			scanf("%d", &h);
			double result = T[0].sum(0, 0, h-1, h-1) + T[1].sum(h, h, MAX, MAX) * h;
			for(int j=2; j<5; j++){
				result += T[j].sum(0, h, h-1, MAX) * pow(h, 4-j);
				result += T[j].sum(h, 0, MAX, h-1) * pow(h, 4-j);
			}
			printf("%.3lf\n", h*(N-1) - result);
		}
		else{
			int a, h;
			scanf("%d %d", &a, &h);
			for(int j=0; j<5; j++){
				if(a > 0) T[j].update(H[a-1], H[a], H[a-1], h);
				if(a<N-1) T[j].update(H[a], H[a+1], h, H[a+1]);
			}
			H[a] = h;
		}
	}
}