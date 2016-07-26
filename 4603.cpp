#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
// const int JUNCTION_MAX = 230;
const double INF = 10000;
const double PI = 3.14159265;
enum FigureType{LINE, CIRCLE};
typedef vector<double> DistanceList;
typedef vector<DistanceList> DistanceTable;

class Point{
public:
	Point(){}
	Point(double x1, double y1): x(x1), y(y1){}
	bool operator ==(const Point& P){ return (x==P.x && y==P.y); }

	// member variables
	double x, y;
};

typedef vector<Point> Points;

double dist(Point P){
	return sqrt(P.x*P.x + P.y*P.y);
}

double dist(Point P, Point Q){
	return sqrt(pow(P.x-Q.x, 2.0) + pow(P.y-Q.y, 2.0));
}

double dot(Point P, Point Q){
	return P.x*Q.x + P.y*Q.y;
}

double cross(Point P, Point Q){
	return P.x*Q.y - P.y*Q.x;
}

Point vadd(Point P, Point Q){
	return Point(P.x+Q.x, P.y+Q.y);
}

Point vmake(Point P, Point Q){
	return Point(Q.x-P.x, Q.y-P.y);
}

Point norm(Point P){
	double s = dist(P);
	return Point(P.x/s, P.y/s);
}

Point coeff(Point P, double k){
	return Point(P.x*k, P.y*k);
}

Point resize(Point P, double k){
	return coeff(norm(P), k);
}

int sign(int n){
	if(n == 0) return n;
	else return (n>0 ? 1 : -1);
}



class Figure{
public:
	virtual void fillDistanceTable(DistanceTable &w, Points &p) = 0;

	// member variables
	FigureType type;
	vector<int> pts;
};

class Line: public Figure{
public:
	Line(){ type = LINE; }
	Line(Point &p1, Point &q1): P(p1), Q(q1){ type = LINE; }
	Line(double x1, double y1, double x2, double y2): P(x1, y1), Q(x2, y2){ type = LINE; }
	
	void fillDistanceTable(DistanceTable &w, Points &p){
		for(int a=0; a<pts.size(); a++)
			for(int b=0; b<pts.size(); b++){
				int i = pts[a], j = pts[b];
				w[i][j] = w[j][i] = dist(p[i], p[j]);
			}
	}

	// member variables
	Point P, Q;
};

class Circle: public Figure{
public:
	Circle(){ type = CIRCLE; }
	Circle(Point &p1, double r1): O(p1), r(r1){ type = CIRCLE; }
	Circle(double x1, double y1, double r1): O(x1, y1), r(r1){ type = CIRCLE; }
	
	void fillDistanceTable(DistanceTable &w, Points &p){
		for(int a=0; a<pts.size(); a++)
			for(int b=0; b<pts.size(); b++){
				int i = pts[a], j = pts[b];
				if(i == j) w[i][i] = 0;
				else{
					double dp = dot(vmake(O, p[i]), vmake(O, p[j])) / (r*r);
					w[i][j] = w[j][i] = acos(dp) * r;
				}
			}
	}

	// member variables
	Point O;
	double r;
};



Points LineToLine(Line *A, Line *B){
	// one of endpoint is an intersection
	if(A->P==B->P || A->P==B->Q) return Points(1, A->P);
	if(A->Q==B->P || A->Q==B->Q) return Points(1, A->Q);

	// get an intersection and return it
	double x1 = A->P.x, y1 = A->P.y, x2 = A->Q.x, y2 = A->Q.y;
	double x3 = B->P.x, y3 = B->P.y, x4 = B->Q.x, y4 = B->Q.y;
	double r = (y4-y3)*(x2-x1) - (x4-x3)*(y2-y1);
	// two lines are parallel
	if(r == 0) return Points();

	double p = (x4-x3)*(y1-y3) - (y4-y3)*(x1-x3);
	double q = (x2-x1)*(y1-y3) - (y2-y1)*(x1-x3);
	double t = p/r;
	double s = q/r;
	// intersection is not on A and B
	if(t<0 || t>1 || s<0 || s>1) return Points();

	return Points(1, Point(x1 + (x2-x1)*t, y1 + (y2-y1)*t));
}

Points CircleToCircle(const Circle *A, const Circle *B){
	double d = dist(A->O, B->O);
	double a = A->r, b = B->r;
	// no intersections
	if(d>a+b || d<abs(a-b)) return Points();

	Points result;
	double c = (a*a - b*b + d*d) / (2*d);
	double h = sqrt(a*a - c*c);
	Point v1 = resize(vmake(A->O, B->O), c);
	Point v2 = resize(Point(v1.y, -v1.x), h);
	v1 = vadd(v1, A->O);
	result.push_back(vadd(v1, v2));
	result.push_back(vadd(v1, coeff(v2, -1)));

	return result;
}

Points LineToCircle(const Line *A, const Circle *B){
	double x1 = A->P.x, y1 = A->P.y, x2 = A->Q.x, y2 = A->Q.y;
	double x0 = B->O.x, y0 = B->O.y, r = B->r;
	double p1 = x2-x1, q1 = x1-x0, p2 = y2-y1, q2 = y1-y0;
	double a = p1*p1 + p2*p2;
	double b = 2*(p1*q1 + p2*q2);
	double c = q1*q1 + q2*q2 - r*r;
	double D = b*b - 4*a*c;
	// no solutions for equation
	if(D < 0) return Points();

	Points result;
	double d = sqrt(D);
	double s = (-b-d) / (2*a), t = (-b+d) / (2*a);
	Point v = vmake(A->P, A->Q);
	if(0<s && s<1) result.push_back(vadd(A->P, coeff(v, s)));
	if(0<t && t<1) result.push_back(vadd(A->P, coeff(v, t)));

	return result;
}



int main(){
	for(int t=1; ; t++){
		vector<Figure*> figure;
		Points junction;
		int J = 0;
		while(1){
			char c;
			scanf(" %c", &c);
			if(c == '*') break;
			else if(c == 'L'){
				int x1, y1, x2, y2;
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				Line *L = new Line(x1, y1, x2, y2);
				L->pts.push_back(J);
				junction.push_back(L->P);
				J++;
				L->pts.push_back(J);
				junction.push_back(L->Q);
				J++;
				figure.push_back(L);
			}
			else{
				int x, y, r;
				scanf("%d %d %d", &x, &y, &r);
				figure.push_back(new Circle(x, y, r));
			}
		}
		int F = figure.size();
		if(F == 0) break;

		for(int i=0; i<F-1; i++){
			for(int j=i+1; j<F; j++){
				Points newPts;
				if(figure[i]->type == LINE){
					if(figure[j]->type == LINE)
						newPts = LineToLine((Line*)figure[i], (Line*)figure[j]);
					else
						newPts = LineToCircle((Line*)figure[i], (Circle*)figure[j]);
				}
				else{
					if(figure[j]->type == LINE)
						newPts = LineToCircle((Line*)figure[j], (Circle*)figure[i]);
					else
						newPts = CircleToCircle((Circle*)figure[i], (Circle*)figure[j]);
				}

				for(int k=0; k<newPts.size(); k++){
					figure[i]->pts.push_back(J);
					figure[j]->pts.push_back(J);
					junction.push_back(newPts[k]);
					J++;
				}
			}
		}

		DistanceTable W(J);
		for(int i=0; i<J; i++)
			W[i] = DistanceList(J, INF);
		for(int i=0; i<F; i++)
			figure[i]->fillDistanceTable(W, junction);

		for(int k=0; k<J; k++)
			for(int i=0; i<J; i++)
				for(int j=0; j<J; j++)
					W[i][j] = min(W[i][j], W[i][k] + W[k][j]);

		double result = 0;
		for(int i=0; i<J; i++)
			for(int j=0; j<J; j++)
				if(W[i][j] != INF) result = max(result, W[i][j]);
		printf("Case %d: %.1lf\n", t, result);
	}
}