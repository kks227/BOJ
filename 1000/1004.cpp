// [Geometry]

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
double dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
}
 
class Circle{
public:
    int num;
    int cx, cy, r;
    Circle():cx(0),cy(0),r(0),num(0){}
    Circle(int cx1, int cy1, int r1, int n):cx(cx1),cy(cy1),r(r1),num(n){}
    bool isInside(int x, int y){
        return dist(cx, cy, x, y) <= r;
    }
    bool operator <(const Circle& other)const{
        return r<other.r;
    }
    bool operator >(const Circle& other)const{
        return r>other.r;
    }
    bool operator <=(const Circle& other)const{
        return r<=other.r;
    }
    bool operator >=(const Circle& other)const{
        return r>=other.r;
    }
    bool operator ==(const Circle& other)const{
        return r==other.r;
    }
    bool operator !=(const Circle& other)const{
        return r!=other.r;
    }
};
  
int main(){
 
    int T, N, x1, x2, y1, y2;
    int cx, cy, r;
    Circle carr[50];
    int start_arr[50];
    int dest_arr[50];
    int start_size, dest_size, result;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> N;
        for(int j=0; j<N; j++){
            cin >> cx >> cy >> r;
            carr[j] = Circle(cx, cy, r, j);
        }
        sort(carr, carr+N);
        start_size = dest_size = 0;
        for(int i=N-1; i>=0; i--){
            if(carr[i].isInside(x1, y1))
                start_arr[start_size++] = carr[i].num;
            if(carr[i].isInside(x2, y2))
                dest_arr[dest_size++] = carr[i].num;
        }
 
        result = 0;
        while(1){
            if(result >= start_size || result >= dest_size){
                result = (start_size + dest_size - 2*result);
                break;
            }
            if(start_arr[result] != dest_arr[result]){
                result = (start_size + dest_size - 2*result);
                break;
            }
            result++;
        }
        cout << result << endl;
    }
 
    return 0;
}