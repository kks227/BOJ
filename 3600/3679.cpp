#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2000;

struct Point{
    int x, y, n;
    Point(): Point(0, 0, -1){}
    Point(int x1, int y1, int n1): x(x1), y(y1), n(n1){}
    bool operator <(const Point& O){
        if(y*O.x != x*O.y) return y*O.x < x*O.y;
        if(x != O.x) return x < O.x;
        return y < O.y;
    }
};

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        int N;
        scanf("%d", &N);
        Point p[MAX];
        for(int i = 0; i < N; ++i){
            scanf("%d %d", &p[i].x, &p[i].y);
            p[i].n = i;
        }

        sort(p, p+N, [](auto &a, auto &b){
            if(a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });
        for(int i = 1; i < N; ++i){
            p[i].x -= p[0].x;
            p[i].y -= p[0].y;
        }
        p[0].x = p[0].y = 0;
        sort(p+1, p+N);
        for(int i = N-1; i > 1; --i){
            if(p[i].x*p[i-1].y != p[i-1].x*p[i].y){
                reverse(p+i, p+N);
                break;
            }
        }

        for(int i = 0; i < N; ++i)
            printf("%d ", p[i].n);
        puts("");
    }
}