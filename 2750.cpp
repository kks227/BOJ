#include <iostream>
using namespace std;
 
int main(){
 
    int *arr, N;
	cin >> N;
	arr = new int[N];
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
 
    for(int i=0; i<N; i++)
		cout << arr[i] << endl;
 
    return 0;
}