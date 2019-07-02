#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

inline double distance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
}

int main(){
    int x[3], y[3];
    bool impossible = false;
    for(int i = 0; i < 3; ++i){
        scanf("%d %d", x+i, y+i);
        for(int j = 0; j < i; ++j)
            if(x[i] == x[j] && y[i] == y[j]) impossible = true;
    }
    if(!impossible){
        if(x[0] == x[1] && x[1] == x[2]) impossible = true;
        else if(y[0] == y[1] && y[1] == y[2]) impossible = true;
        else if((x[1]-x[0])*(y[2]-y[1]) == (x[2]-x[1])*(y[1]-y[0])) impossible = true;
    }
    if(impossible){
        puts("-1");
        return 0;
    }

    double r1 = 0, r2 = 1e18;
    for(int i = 0; i < 3; ++i){
        double temp = 0;
        for(int j = 0; j < 3; ++j)
            if(i != j) temp += 2*distance(x[i], y[i], x[j], y[j]);
        r1 = max(temp, r1);
        r2 = min(temp, r2);
    }
    printf("%.10lf\n", r1-r2);
}