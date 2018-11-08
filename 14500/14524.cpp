#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;
const int MOD = 1000000007;
const int MAX = 101;
typedef vector<int> rowVec;

struct Matrix{
	int n;
	vector<rowVec> A;
	Matrix(): Matrix(0){}
	Matrix(int n1): n(n1){
		A = vector<rowVec>(n, rowVec(n, 0));
	}
	Matrix operator *(const Matrix &O)const{
		Matrix result(n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < n; ++k)
					result.A[i][j] = (result.A[i][j] + 1LL*A[i][k]*O.A[k][j]) % MOD;
		return result;
	}
};

Matrix power(Matrix M, int k){
	if(k == 0){
		Matrix result(M.n);
		for(int i = 0; i < M.n; ++i)
			result.A[i][i] = 1;
		return result;
	}
	if(k == 1) return M;

	Matrix result = power(M, k/2);
	result = result * result;
	if(k%2) result = result * M;
	return result;
}



int main(){
	int scnt = 0; // stack counter
	int N = 1; // 1st var is for constants
	unordered_map<string, int> S2I;
	int c[MAX][MAX][MAX] = {1,}; // expression
	int loop[MAX] = {0};

	while(1){
		string line, token, dummy;
		getline(cin, line);
		stringstream ss(line);

		ss >> token;
		if(token == "RETURN"){
			ss >> token;
			int var = S2I[token];
			cout << c[0][var][0] << '\n';
			break;
		}
		else if(isalpha(token[0])){
			if(S2I.find(token) == S2I.end()) S2I[token] = N++;
			int var = S2I[token];
			ss >> dummy;
			int c2[MAX] = {0,};
			while(ss >> token){
				if(isalpha(token[0])){
					int var2 = S2I[token];
					for(int i = 0; i < N; ++i)
						c2[i] = (c2[i] + c[scnt][var2][i]) % MOD;
				}
				else if(isdigit(token[0])) c2[0] = (c2[0] + stoi(token)) % MOD;
			}
			copy(c2, c2+MAX, c[scnt][var]);
		}
		else if(isdigit(token[0])){
			loop[scnt++] = stoi(token);
			for(int i = 0; i < N; ++i)
				for(int j = 0; j < N; ++j)
					c[scnt][i][j] = (i == j);
		}
		else{ // '}'
			Matrix M(N);
			M.A[0][0] = 1;
			for(int i = 0; i < N; ++i)
				copy(c[scnt][i], c[scnt][i]+N, M.A[i].begin());
			M = power(M, loop[scnt-1]);
			int c2[MAX][MAX] = {0};
			for(int i = 1; i < N; ++i) // 1st line is for constants, so ignore it
				for(int j = 0; j < N; ++j)
					for(int k = 0; k < N; ++k)
						c2[i][j] = (c2[i][j] + 1LL*M.A[i][k]*c[scnt-1][k][j]) % MOD;
			for(int i = 1; i < N; ++i)
				copy(c2[i], c2[i]+N, c[scnt-1][i]);
			--scnt;
		}
	}
}