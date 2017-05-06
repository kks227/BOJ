#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class BigInt{
public:
	BigInt(): BigInt("0"){}
	BigInt(const string &A): d(A){}
	friend BigInt operator +(const BigInt &A, const BigInt &B);
	friend bool operator <(const BigInt &A, const BigInt &B);
	friend bool operator ==(const BigInt &A, const BigInt &B);
	friend bool operator <=(const BigInt &A, const BigInt &B);
	friend istream& operator >>(istream &in, BigInt &A);
	friend ostream& operator <<(ostream &out, BigInt &A);
private:
	string d;
};

int main(){
	while(1){
		BigInt A, B;
		cin >> A >> B;
		if(B == BigInt()) break;

		int cnt = 0;
		BigInt f[3];
		f[0] = BigInt("0");
		f[1] = BigInt("1");
		f[2] = BigInt("1");
		while(f[2] < A){
			f[0] = f[1];
			f[1] = f[2];
			f[2] = f[0] + f[1];
		}
		while(f[2] <= B){
			cnt++;
			f[0] = f[1];
			f[1] = f[2];
			f[2] = f[0] + f[1];
		}
		cout << cnt << endl;
	}
}



BigInt operator +(const BigInt &A, const BigInt &B){
	BigInt C;
	int AL = A.d.size(), BL = B.d.size(), CL = max(AL, BL);
	C.d.resize(CL, '0');
	bool carry = false;
	for(int i=0; i<CL; i++){
		int val = carry;
		if(AL > i) val += A.d[AL-i-1]-'0';
		if(BL > i) val += B.d[BL-i-1]-'0';
		carry = (val >= 10);
		C.d[CL-i-1] += val%10;
	}
	if(carry) C.d.insert(C.d.begin(), '1');
	return C;
}

bool operator <(const BigInt &A, const BigInt &B){
	if(A.d.size() != B.d.size()) return A.d.size() < B.d.size();
	return A.d < B.d;
}

bool operator ==(const BigInt &A, const BigInt &B){
	return A.d == B.d;
}

bool operator <=(const BigInt &A, const BigInt &B){
	if(A.d.size() != B.d.size()) return A.d.size() < B.d.size();
	return A.d <= B.d;
}

istream& operator >>(istream &in, BigInt &A){
	in >> A.d;
	return in;
}

ostream& operator <<(ostream &out, BigInt &A){
	out << A.d;
	return out;
}