#include <iostream>

using namespace std;

int GCD(int a, int b);
int LCM(int a, int b);
 
int main(){
	int n[5];
	cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4];

	long long int min = 10000000000;
	int GCD2, GCD3;

	for(int i=0; i<3; i++){
		for(int j=i+1; j<4; j++){
			GCD2 = LCM(n[i], n[j]);
			for(int k=j+1; k<5; k++){
				GCD3 = LCM(GCD2, n[k]);
				if(min > GCD3) min = GCD3;
			}
		}
	}

	cout << min << endl;

    return 0;
}


int GCD(int a, int b){
	int temp;
	while(b){
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int LCM(int a, int b){
	return a * b / GCD(a, b);
}