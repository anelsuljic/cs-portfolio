#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<pair<int, int> > filesParEnt;
typedef vector<filesParEnt> matriuParEnt;
typedef vector<int> filesEnt;
typedef vector<filesEnt> matriuEnt;

void llegir_matriu_parells(matriuParEnt &data);
bool cmp(const filesEnt &f1, const filesEnt &f2);
matriuEnt classificacio(const matriuParEnt &data);
void escriure_matriu_enters(const matriuEnt &data);

int main()
{
	matriuParEnt data;
	llegir_matriu_parells(data);
	matriuEnt classif = classificacio(data);
	escriure_matriu_enters(classif);	
}

void llegir_matriu_parells(matriuParEnt &data)
/* Pre: hi ha preparats al canal estàndard d'entrada un enter N, seguit d'N 
   seqüències amb 2*N elements cada una */
/* Post: data es una matriu de parells d'enters de mida N x N que conté els
   elements llegits al canal estàndard d'entrada */
{
	int N;		//mida de la matriu
	cin >> N;
	data = matriuParEnt(N, filesParEnt(N));
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> data[i][j].first >> data[i][j].second;
		}
	}
}

bool cmp(const filesEnt &f1, const filesEnt &f2)
/* Pre: f1 i f2 son vectors d'enters no buits */
/* Post: el resultat es cert si f1 i f2 compleixen els criteris d'ordenacio
   establerts. En cas contrari, el resultat es fals */
{
	bool res = false;
	//nombre de punts totals
	if (f1[1] == f2[1]) {
		//diferència entre gols a favor i gols en contra	
		if (f1[2] - f1[3] == f2[2] - f2[3]) {
			//número d'equip
			res = f1[0] < f2[0];
		}
		else res = f1[2] - f1[3] > f2[2] - f2[3]; 		
	}
	else res = f1[1] > f2[1];
	
	return res;
}

matriuEnt classificacio(const matriuParEnt &data)
/* Pre: data es una matriu de parells d'enters, on cada parell conté el nombre 
   de gols de cada equip */
/* Post: el resultat es una matriu de mida N x 4, on N es el nombre d'equips,
   que conté a cada fila el nombre de l'equip, la puntuació total, el nombre
   total de gols marcats i el nombre total de gols rebuts */
{
	int size = data.size();
	matriuEnt classif(size, filesEnt(4, 0));
	
	//calcula puntuacions
	for (int i = 0; i < size; ++i) {
		classif[i][0] = i + 1;
		for (int j = 0; j < size; ++j) {
			if (i != j) {
				//suma de puntuacions
				if (data[i][j].first > data[i][j].second) classif[i][1] += 3;
				else if (data[i][j].first < data[i][j].second) classif[j][1] += 3;
				else {
					++classif[i][1];
					++classif[j][1];
				}
				//gols marcats i rebuts
				classif[i][2] += data[i][j].first;
				classif[i][3] += data[i][j].second;
				classif[j][2] += data[i][j].second;
				classif[j][3] += data[i][j].first;
			}
		}
	}
	
	//classificacio
	sort(classif.begin(), classif.end(), cmp);
	
	return classif;
}

void escriure_matriu_enters(const matriuEnt &data)
/* Pre: data es una matriu d'enters no buida */
/* Post: els elements de data son escrits al canal estàndard de sortida amb una
   separació entre cada element i un salt de linia per a cada fila */
{
	int files = data.size();
	int cols = data[0].size();
	
	for (int i = 0; i < files; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (j != 0) cout << ' ' << data[i][j];
			else cout << data[i][j];
		}
		cout << endl;
	}
}
