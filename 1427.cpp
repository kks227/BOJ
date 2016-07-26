#include <iostream>
#include <cmath>
using namespace std;
  
int main(){

    int *arr, N;
    cin >> N;
	int max = (int)log10((double)N)+1;
    arr = new int[max];
    for(int i=0; i<max; i++){
		arr[i] = N%10;
		N /= 10;
	}
  
    int temp;
    for(int i=0; i<max; i++){
        for(int j=i+1; j<max; j++){
            if(arr[i] < arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
  
    for(int i=0; i<max; i++)
        cout << arr[i];
	cout << endl;
  
    return 0;
}