#include <iostream>
using namespace std;

/* int main()
{
  cout << "Entra dos nombres enters: ";
  int x,y;
  cin >> x >> y;
  int sum = x+y;
  cout << "La suma de " << x << " i " << y << " es " << sum <<endl;
} */


// prueba
// otra prueba

/* int main() {
	int num;
	cin >> num;
	
	int suma = 0;
	while (num != 0) {
		suma += num;
		cin >> num;
	}
	
	cout << suma << endl;
} */

int main() {
	int n, x;	//n > 0
	cin >> n >> x;
	
	for (int i = 0; i < n; ++i) {
		int num; 
		cin >> num;
		
		int suma = 0;
		while (num != x) {
			suma += num;
			cin >> num;
		}
		
		cout << "La suma de la secuencia " << i + 1 << " es " << suma << endl;
		string rest;
		getline(cin, rest);
	}
}
		
