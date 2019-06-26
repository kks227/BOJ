#include <cstdio>
using namespace std;

int main(){
    int result = 5000, val, cost[4] = {0, 500, 800, 1000};
    while(scanf("%d", &val) > 0) result -= cost[val];
    printf("%d\n", result);
}