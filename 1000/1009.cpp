#include <iostream>
using namespace std;
 
int main(){
 
    int mod[10][4] = {
        10, 10, 10, 10,
        1, 1, 1, 1,
        2, 4, 8, 6,
        3, 9, 7, 1,
        4, 6, 4, 6,
        5, 5, 5, 5,
        6, 6, 6, 6,
        7, 9, 3, 1,
        8, 4, 2, 6,
        9, 1, 9, 1
    };
    int T, a, b;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> a >> b;
        cout << mod[a%10][(b+3)%4] << endl;
    }
 
    return 0;
}