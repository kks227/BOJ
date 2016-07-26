#include <iostream>
using namespace std;
 
int gcd(int a, int b){
    int temp;
    while(b){
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
 
int main(){
 
    int N, a, b;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        cout << a/gcd(a, b)*b << endl;
    }
 
    return 0;
}