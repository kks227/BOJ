#include <iostream>
using namespace std;
 
int main(){
 
	const int N = 3;
    int arr[N];
	for(int i=0; i<N; i++)
		cin >> arr[i];
 
    int temp;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(arr[i] > arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
 
    for(int i=0; i<N; i++){
		cout << arr[i];
		if(i < N-1) cout << ' ';
		else cout << endl;
	}
 
    return 0;
}