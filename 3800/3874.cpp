#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MOD = 32768;
const int INF = 1e9;
typedef vector<int> MatRow;
typedef vector<MatRow> Mat;

enum NodeType {Matrix, Selector, Operator};

struct Node{
	NodeType type;
	Mat X, Y;
	char op; // '=' is unary minus
	Node(): Node('@'){}
	Node(const Mat &X1): type(Matrix), X(X1){}
	Node(const Mat &X1, const Mat &Y1): type(Selector), X(X1), Y(Y1){}
	Node(char op1): type(Operator), op(op1){}
};

Mat A[26];
char E[81];
int oppPos[80], comPos[80];

inline int row(const Mat &M){ return M.size(); }
inline int col(const Mat &M){ return M.empty() ? 0 : M[0].size(); }
inline Mat all0(int r, int c){ return Mat(r, MatRow(c, 0)); }
inline Mat singular(int n){ return Mat(1, MatRow(1, n%MOD)); }

Mat parse(int s, int e);
Mat parseMatrix(int s, int e);

int main(){
	while(1){
		int N;
		scanf("%d\n", &N);
		if(N == 0) break;

		for(int k = 0; k < N; ++k){
			gets(E);
			stack<int> S;
			for(int i = 2; E[i] != '.'; ++i){
				if(E[i] == '[' || E[i] == '(') S.push(i);
				else if(E[i] == ']' || E[i] == ')'){
					oppPos[S.top()] = i;
					S.pop();
				}
				else if(E[i] == ',') comPos[S.top()] = i;
			}

			int m = E[0] - 'A';
			A[m] = parse(2, strlen(E)-1);
			for(int i = 0; i < row(A[m]); ++i){
				for(int j = 0; j < col(A[m]); ++j)
					printf("%d ", A[m][i][j]);
				puts("");
			}
		}
		puts("-----");
	}
}



Mat parse(int s, int e = INF){
	stack<char> S1;
	vector<Node> P;
	bool recentVal = false;
	for(int p = s; p < e; ++p){
		if(isdigit(E[p])){
			int val = 0;
			for(; isdigit(E[p]); ++p)
				val = (val*10 + E[p]-'0') % MOD;
			P.push_back(singular(val));
			--p;
			recentVal = true;
		}
		else if(isupper(E[p])){
			P.push_back(A[E[p]-'A']);
			recentVal = true;
		}
		else if(E[p] == '['){
			P.push_back(parseMatrix(p+1, oppPos[p]));
			p = oppPos[p];
			recentVal = true;
		}
		else if(E[p] == '('){
			if(recentVal){
				while(!S1.empty() && S1.top() == '\''){
					P.push_back(S1.top());
					S1.pop();
				}
				Mat M1 = parse(p+1, comPos[p]), M2 = parse(comPos[p]+1, oppPos[p]);
				P.push_back(Node(M1, M2));
				p = oppPos[p];
				recentVal = true;
			}
			else{
				S1.push('(');
				recentVal = false;
			}
		}
		else if(E[p] == ')'){
			while(S1.top() != '('){
				P.push_back(S1.top());
				S1.pop();
			}
			S1.pop();
			recentVal = true;
		}

		else if(E[p] == '+'){
			while(!S1.empty() && S1.top() != '('){
				P.push_back(S1.top());
				S1.pop();
			}
			S1.push('+');
			recentVal = false;
		}
		else if(E[p] == '-'){
			if(recentVal){
				while(!S1.empty() && S1.top() != '('){
					P.push_back(S1.top());
					S1.pop();
				}
				S1.push('-');
			}
			else S1.push('=');
			recentVal = false;
		}
		else if(E[p] == '*'){
			while(!S1.empty() && (S1.top() == '=' || S1.top() == '\'' || S1.top() == '*')){
				P.push_back(S1.top());
				S1.pop();
			}
			S1.push('*');
			recentVal = false;
		}
		else{ // '\'', transpose
			S1.push('\'');
			recentVal = true;
		}
	}
	while(!S1.empty()){
		P.push_back(S1.top());
		S1.pop();
	}

	// calculate postfix
	stack<Mat> S2;
	for(auto &p: P){
		if(p.type == Matrix) S2.push(p.X);
		else if(p.type == Selector){
			Mat &M1 = p.X, &M2 = p.Y;
			Mat oldM = S2.top(); S2.pop();
			Mat newM = all0(col(M1), col(M2));
			for(int i = 0; i < col(M1); ++i)
				for(int j = 0; j < col(M2); ++j)
					newM[i][j] = oldM[ M1[0][i]-1 ][ M2[0][j]-1 ];
			S2.push(newM);
		}
		else{
			Mat M1, M2, M3;
			int singularMultiply = -1;
			switch(p.op){
			case '=':
				M3 = S2.top(); S2.pop();
				for(int i = 0; i < row(M3); ++i)
					for(int j = 0; j < col(M3); ++j)
						M3[i][j] = MOD - M3[i][j];
				break;

			case '\'':
				M1 = S2.top(); S2.pop();
				M3 = all0(col(M1), row(M1));
				for(int i = 0; i < col(M1); ++i)
					for(int j = 0; j < row(M1); ++j)
						M3[i][j] = M1[j][i];
				break;

			case '+':
				M2 = S2.top(); S2.pop();
				M3 = S2.top(); S2.pop();
				for(int i = 0; i < row(M3); ++i)
					for(int j = 0; j < col(M3); ++j)
						M3[i][j] = (M3[i][j] + M2[i][j]) % MOD;
				break;

			case '-':
				M2 = S2.top(); S2.pop();
				M3 = S2.top(); S2.pop();
				for(int i = 0; i < row(M3); ++i)
					for(int j = 0; j < col(M3); ++j)
						M3[i][j] = (M3[i][j] + MOD - M2[i][j]) % MOD;
				break;

			case '*':
				M2 = S2.top(); S2.pop();
				M1 = S2.top(); S2.pop();
				if(row(M1) == 1 && col(M1) == 1){
					M3 = M2;
					for(int i = 0; i < row(M3); ++i)
						for(int j = 0; j < col(M3); ++j)
							M3[i][j] = M3[i][j]*M1[0][0] % MOD;
				}
				else if(row(M2) == 1 && col(M2) == 1){
					M3 = M1;
					for(int i = 0; i < row(M3); ++i)
						for(int j = 0; j < col(M3); ++j)
							M3[i][j] = M3[i][j]*M2[0][0] % MOD;
				}
				else{
					M3 = all0(row(M1), col(M2));
					for(int i = 0; i < row(M1); ++i)
						for(int j = 0; j < col(M2); ++j)
							for(int k = 0; k < col(M1); ++k)
								M3[i][j] = (M3[i][j] + M1[i][k]*M2[k][j]) % MOD;
				}
				break;
			}
			S2.push(M3);
		}
	}
	return S2.top();
}

Mat parseMatrix(int s, int e){
	Mat M;
	for(int i = s, j = s, r = 0, c = 0; i < e; ++i){
		int cnt = 0;
		for(j = i; j < e; ++j){
			if(E[j] == '[' || E[j] == '(') ++cnt;
			else if(E[j] == ']' || E[j] == ')') --cnt;
			else if((E[j] == ' ' || E[j] == ';') && cnt == 0) break;
		}

		Mat a = parse(i, j);
		if(c == 0){
			for(int k = 0; k < row(a); ++k)
				M.push_back(MatRow(col(M), 0));
		}
		if(r == 0){
			for(int k = 0; k < row(M); ++k)
				M[k].resize(col(M) + col(a));
		}

		for(int r1 = 0; r1 < row(a); ++r1)
			for(int c1 = 0; c1 < col(a); ++c1)
				M[r+r1][c+c1] = a[r1][c1];

		if(E[j] == ';'){
			r = row(M);
			c = 0;
		}
		else if(E[j] == ' '){
			c += col(a);
		}
		else break;
		i = j;
	}
	return M;
}