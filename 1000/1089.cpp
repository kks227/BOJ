#include <cstdio>
using namespace std;

int main(){
	int N, dsum[9] = {0}, pb[9] = {0};
	scanf("%d", &N);
	char dc[5][36], original[5][31] = {
		"###..########.################",
		"#.#..#..#..##.##..#....##.##.#",
		"#.#..################..#######",
		"#.#..##....#..#..##.#..##.#..#",
		"###..#######..#######..#######"
	};
	for(int i=0; i<5; i++){
		getchar();
		for(int j=0; j<4*N-1; j++)
			dc[i][j] = getchar();
	}
	for(int i=0; i<5; i++){
		for(int j=1; j<N; j++){
			if(dc[i][4*j-1] == '#'){
				puts("-1");
				return 0;
			}
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<10; j++){
			bool flag = true;
			for(int r=0; r<5; r++){
				for(int c=0; c<3; c++){
					if(original[r][c+3*j]=='.' && dc[r][c+4*(N-i-1)]=='#'){
						flag = false;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag){
				pb[i]++;
				dsum[i] += j;
			}
		}
	}

	long long allpos = 1;
	for(int i=0; i<N; i++)
		allpos *= pb[i];
	if(allpos == 0){
		puts("-1");
		return 0;
	}

	long long p10 = 1, sum = 0;
	for(int i=0; i<N; i++){
		sum += allpos/pb[i] * p10*dsum[i];
		p10 *= 10;
	}
	printf("%.6lf\n", 1.0*sum/allpos);
}