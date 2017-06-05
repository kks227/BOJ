#include <cstdio>
using namespace std;

struct Time{
	int h, m, s;
	Time(): h(0), m(0), s(0){}
	Time(int h1): h(h1), m(0), s(0){}
	void get(){ scanf("%02d:%02d:%02d", &h, &m, &s); }
	void print(){ printf("%02d:%02d:%02d", h, m, s); }
	bool operator <(const Time& O)const{
		if(h != O.h) return h < O.h;
		if(m != O.m) return m < O.m;
		return s < O.s;
	}
	Time operator -(const Time& O)const{
		Time result;
		int temp = s - O.s;
		bool carry = (temp < 0);
		result.s = (temp + 60) % 60;
		temp = m - O.m - carry;
		carry = (temp < 0);
		result.m = (temp + 60) % 60;
		result.h = h - O.h - carry;
		return result;
	}
};

int main(){
	Time A, B;
	A.get(); B.get();
	(A<B ? B-A : Time(24)-(A-B)).print();
}