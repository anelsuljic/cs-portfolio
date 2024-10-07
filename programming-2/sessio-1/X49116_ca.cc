//#include "vectorIOint.hh"

#include<vector>
using namespace std;

struct parint {int prim, seg;};
 
parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
	parint res = {v[0], v[0]};
	int size = v.size();
	for (int i = 1; i < size; ++i) {
		if (v[i] > res.prim) res.prim = v[i];
		else if (v[i] < res.seg) res.seg = v[i];
	}
	
	return res;
}
 
pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
	pair<int, int> res = {v[0], v[0]};
	int size = v.size();
	for (int i = 1; i < size; ++i) {
		if (v[i] > res.first) res.first = v[i];
		else if (v[i] < res.second) res.second = v[i];
	}
	
	return res;
}
 
void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
	x = y = v[0];
	int size = v.size();
	for (int i = 1; i < size; ++i) {
		if (v[i] > x) x = v[i];
		else if (v[i] < y) y = v[i];
	}
}

/* int main() 
{
	vector<int> v;
	leer_vector_int(v);
	cout << "Funcion 1:" << endl;
	parint p = max_min1(v);
	cout << p.prim << ' ' << p.seg << endl << endl;
	cout << "Funcion 2:" << endl;
	pair<int, int> q = max_min2(v);
	cout << q.first << ' ' << q.second << endl << endl;
	cout << "Funcion 3:" << endl;
	int x, y;
	max_min3(v, x, y);
	cout << x << ' ' << y << endl;
} */
