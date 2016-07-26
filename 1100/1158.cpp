#include <cstdio>
#include <vector>
#include <numeric>
using namespace std;
 
int main(){
 
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> josephus(N);
	iota(josephus.begin(), josephus.end(), 1);
     
    int current = M-1;
    int vSize = N;
    printf("<");
    for(int i=0; i<N; i++){
        printf("%d", josephus[current]);
        if(i==N-1) printf(">\n");
        else printf(", ");
 
        josephus.erase(josephus.begin()+current);
        vSize--;
        current += (M-1);
        if(vSize>0) current %= vSize;
    }
 
    return 0;
}