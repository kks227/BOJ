#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 100;

int main(){
    int N, k;
    double p[2][2], q[MAX+1][2] = {0};
    scanf("%d %d", &N, &k);
    q[0][k] = 1;
    scanf("%lf %lf %lf %lf", &p[0][0], &p[0][1], &p[1][0], &p[1][1]);
    for(int i = 1; i <= N; ++i){
        q[i][0] = q[i-1][0]*p[0][0] + q[i-1][1]*p[1][0];
        q[i][1] = q[i-1][0]*p[0][1] + q[i-1][1]*p[1][1];
    }
    printf("%.0lf\n%.0lf\n", round(q[N][0]*1000), round(q[N][1]*1000));
}