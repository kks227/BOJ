#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159265358979323846;
const double ERROR = 0.000001;

int main(){
	while(1){
		char c = cin.peek();
		if(c == 'E') break;

		double x[3], y[3], len[3];
		for(int i=0; i<3; i++)
			cin >> x[i] >> y[i];
		for(int i=0; i<3; i++)
			len[i] = sqrt(pow(x[i]-x[(i+1)%3], 2.0) + pow(y[i]-y[(i+1)%3], 2.0));
		double s = (len[0]+len[1]+len[2])/2;
		double S = sqrt(s*(s-len[0])*(s-len[1])*(s-len[2]));
		// 헤론의 공식, 외접원의 반지름 공식 등을 사용해 외접원의 반지름 구함
		double R = len[0]*len[1]*len[2]/4/S;
		double xi[3];
		for(int i=0; i<3; i++){
			double cosval = len[i]/2.0/R;
			if(abs(cosval-1) < ERROR) xi[i] = PI;
			else{
				double theta = acos(len[i]/2.0/R);
				xi[i] = PI - 2*theta;
			}
		}

		// 그냥 3부터 다 시도해서 일정 실수오차 내의 결과를 내면 정답으로 제출
		for(int result=3; ; result++){
			double unit = PI*2/result;
			bool success = true;
			for(int i=0; i<3; i++){
				double q = xi[i] / unit;
				if(abs(q-round(q)) > ERROR){
					success = false;
					break;
				}
			}
			if(success){
				cout << result << endl;
				break;
			}
		}
		cin.ignore(1024, '\n');
	}
}