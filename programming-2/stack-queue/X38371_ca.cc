#include <iostream>
#include <queue>

using namespace std;

void rec_max_min(queue<int> Estad, int &max, int &min)
//Pre: cert
//Post: el resultat es el maxim i minim de Estad
{
    min = 1000;
    max = -1001;

    if (not Estad.empty()) {
        min = max = Estad.front();
        Estad.pop();
    }
    while (not Estad.empty()) {
        int front = Estad.front();
        if (front > max) max = front;
        else if (front < min) min = front;
        Estad.pop();
    }
}

void escriu_estad(int min, int max, double mitj)
// Pre: cert
// Post: son escrits al canal de sortida els paràmetres d'entrada
{      
    cout << "min " << min << ';' << " max " << max << ';' << " media " 
         << mitj << endl;
}

// El programa realitza un tractament d'una cua d'enters: calcula el maxim,
// minim i la mitjana de la cua en cada un dels estats d'aquesta.
int main()
// Entrada: una sequencia d'enters entre -1001 i 1000
// Sortida: escriu les estadistiques actuals de la cua en cada iteracio
{
    int num;
    cin >> num;

    queue<int> Estad;
    int max;
    int min;
    double sum = 0;
    while (num >= -1001 and num <= 1000) {
        if (num == -1001) {
            if (not Estad.empty()) {
                int front = Estad.front();
                Estad.pop();
                if (front == max or front == min) rec_max_min(Estad, max, min);
                sum -= front;
            }
        } else {
            Estad.push(num);
            if (Estad.size() == 1) max = min = num;
            else if (num > max) max = num;
            else if (num < min) min = num; 
            sum += num;
        }
        if (not Estad.empty()) escriu_estad(min, max, sum / Estad.size());
        else cout << 0 << endl;

        cin >> num;
    }
}