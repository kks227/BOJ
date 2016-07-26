#include <iostream>
using namespace std;
 
int main(){
 
    cin.sync_with_stdio(true);
    cout.sync_with_stdio(true);
 
    int T, a, b, x, y, z;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> a >> b;
        x = a;
        y = b;
        while(y){
            z = x%y;
            x = y;
            y = z;
        }
        cout << a*b/x << ' ' << x << endl;
    }
 
    return 0;
}