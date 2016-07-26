#include <cstdio>
#include <algorithm>
using namespace std;

// way가 true면 수직선, false면 수평선
// a1, a2는 수직선의 경우 y좌표, 수평선의 경우 x좌표이며 a1 < a2
// b는 다른 좌표
int Hilbert(int n, bool way, int a1, int a2, int b){
	if(a1>=a2 || b==0 || b==1<<n) return 0;

	int N = 1<<n, H = 1<<n-1, result = 0;
	// 수직선
	if(way){
		// 기저 사례
		if(n == 1) return (a1==0 && a2>=1);
		if(b == H) return (a1<H);
		// 왼쪽
		if(b < H){
			if(a1 < H) result += Hilbert(n-1, true, a1, min(H, a2), b);
			if(a2 > H) result += Hilbert(n-1, false, max(a1-H, 0), a2-H, H-b);
		}
		// 오른쪽
		else{
			if(a1 < H) result += Hilbert(n-1, true, a1, min(H, a2), b-H);
			if(a2 > H) result += Hilbert(n-1, false, N-a2, min(H, N-a1), b-H);
		}
	}
	// 수평선
	else{
		// 기저 사례
		if(n == 1) return (a1==0) + (a2==2);
		if(b == H) return (a1==0) + (a2==N);
		// 왼쪽, 오른쪽에 걸쳐 있음: 좌우대칭인 부분을 잘라냄
		if(a1<H && a2>H){
			// 하단
			if(b < H){
				if(a1 <= N-a2){
					result += Hilbert(n-1, false, a1, N-a2, b);
					result += Hilbert(n-1, false, N-a2, H, b)*2;
				}
				else{
					result += Hilbert(n-1, false, N-a2, a1, b);
					result += Hilbert(n-1, false, a1, H, b)*2;
				}
			}
			// 상단
			else{
				if(a1 <= N-a2){
					result += Hilbert(n-1, true, a2-H, H-a1, b-H);
					result += Hilbert(n-1, true, 0, a2-H, b-H)*2;
				}
				else{
					result += Hilbert(n-1, true, H-a1, a2-H, b-H);
					result += Hilbert(n-1, true, 0, H-a1, b-H)*2;
				}
			}
		}
		// 왼쪽 혹은 오른쪽에만 존재
		else{
			// 하단
			if(b < H){
				if(a1 < H) result += Hilbert(n-1, false, a1, min(H, a2), b);
				else result += Hilbert(n-1, false, max(a1-H, 0), a2-H, b);
			}
			// 상단
			else{
				if(a1 < H) result += Hilbert(n-1, true, max(H-a2, 0), H-a1, b-H);
				else result += Hilbert(n-1, true, max(a1-H, 0), a2-H, N-b);
			}
		}
	}
	return result;
}

int main(){
	while(1){
		int n, x1, x2, y;
		scanf("%d", &n);
		if(n == 0) break;
		scanf("%d %d %d", &x1, &x2, &y);
		printf("%d\n", Hilbert(n, false, x1, x2, y));
	}
}