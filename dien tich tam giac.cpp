#include <iostream> 
#include <math.h>
using namespace std; 
struct point {
float x,y; 
};
struct triangle{
point p[3];
};
void read_point(point &p) {
cin >> p.x >> p.y;
}
void read_triangle(triangle &t) {
read_point(t.p[0]);
read_point(t.p[1]);
read_point(t.p[2]);
}
float area(triangle t) {
	return 0.5*abs((t.p[1].x-t.p[0].x)*(t.p[2].y- t.p[0].y)-(t.p[2].x-t.p[0].x)*(t.p[1].y-t.p[0].y));
}
int main() {
triangle t;
read_triangle(t);
cout << area(t) << endl;
return 0;
}
