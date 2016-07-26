#include <iostream>
#include <queue>
using namespace std;
 
void bridge(int n1, int n2){
    long long int val = 1;
    int dif = n2-n1;
    if(n1 < n2-n1) dif = n1;
    if(dif==0){
        cout << '1' << endl;
        return;
    }
 
    int *div = new int[dif-1];
    int t;
     
    for(int i=2; i<=dif; i++)
        div[i-2] = i;
 
    for(int i=n2; i>n2-dif; i--){
        val *= i;
        for(int j=0; j<dif-1; j++){
            t = div[j];
            if(t == 0) continue;
            if(val%t == 0){
                val /= t;
                div[j] = 0;
            }
        }
    }
    cout << val << endl;
}
 
int main(){
 
    int n, m;
    queue<int> input;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        input.push(m);
        cin >> m;
        input.push(m);
    }
    for(int i=0; i<n; i++){
        int n1 = input.front();
        input.pop();
        int n2 = input.front();
        input.pop();
        bridge(n1, n2);
    }
 
    return 0;
}