#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
 
int main(){

	int K;
	cin >> K;
	int size = (int)pow(2.0, K);
	int *tree = new int[size];
	memset(tree, 0, sizeof(int)*size);

	int current_node = size/2;
	for(int i=1; i<size; i++){
		cin >> tree[current_node];
		if(current_node*2 >= size){
			while(tree[current_node] != 0) current_node /= 2;
		}
		else if(tree[current_node*2] != 0){
			if(tree[current_node*2+1] != 0){
				while(tree[current_node] != 0) current_node /= 2;
			}
			else{
				current_node = 2*current_node+1;
				while(current_node*2 < size && tree[current_node*2] == 0) current_node *= 2;
			}
		}
	}

	int power = 2;
	for(int i=1; i<size; i++){
		cout << tree[i];
		if(i == power-1){
			cout << endl;
			power *= 2;
		}
		else cout << ' ';
	}

	delete[] tree;

    return 0;
}