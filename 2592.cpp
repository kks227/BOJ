#include <iostream>
using namespace std;

int main(){

	int n[10] = {0};
	int multi[10] = {0};
	
	int input;
	for(int i=0, j=0, k; i<10; i++){
		cin >> input;
		for(k=0; k<j; k++){
			if(n[k] == input){
				multi[k]++;
				break;
			}
		}
		if(k == j){
			n[j] = input;
			multi[j]++;
			j++;
		}
	}

	int sum=0, freq=0, freq_val=0;
	for(int i=0; i<10; i++){
		if(n[i] == 0) break;
		sum += n[i]*multi[i];
		if(freq < multi[i]){
			freq = multi[i];
			freq_val = i;
		}
	}
	cout << sum/10 << endl << n[freq_val] << endl;

    return 0;
}