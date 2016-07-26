#include <iostream>
using namespace std;

int find_root(int* arr, int size, int a){
	if(arr[a] < 0) return a;
	int parent = find_root(arr, size, arr[a]);
	arr[a] = parent;
	return parent;
}

void union_find(int* arr, int size, int a_root, int b_root){
	if(-a_root >= -b_root){
		arr[a_root] += arr[b_root];
		arr[b_root] = a_root;
	}
	else{
		arr[b_root] += arr[a_root];
		arr[a_root] = b_root;
	}
}

int main(){

	int N, M, *arr;
	cin >> N >> M;
	arr = new int[N+1];
	for(int i=0; i<N+1; i++)
		arr[i] = -1;
	
	int operator_type, a, b;
	int a_root, b_root;
	for(int i=0; i<M; i++){
		cin >> operator_type >> a >> b;

		if(operator_type == 0){
			if(a == b) continue;

			a_root = find_root(arr, N+1, a);
			b_root = find_root(arr, N+1, b);
			if(a_root == b_root) continue;
			union_find(arr, N+1, a_root, b_root);
		}
		else{
			if(a == b){
				cout << "YES" << endl;
				continue;
			}
			
			a_root = find_root(arr, N+1, a);
			b_root = find_root(arr, N+1, b);
			if(a_root == b_root) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}

	delete[] arr;

	return 0;
}