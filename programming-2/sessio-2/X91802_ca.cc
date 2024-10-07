//#include "vectorIOEstudiant.hh"
#include "Estudiant.hh"
#include <vector>

//versio 1

//pair<double,double> max_min(const vector<Estudiant> &vest)
/* Pre: vest no es buit i conte com a minim un estudiant amb nota */
/* Post: el resultat es un parell que conte, en aquest ordre, la nota maxima
   i minima de vest */
/*{
    double max = -1;
    double min = -1;
    
    int size = vest.size();
    for (int i = 0; i < size; ++i) {
        if (vest[i].te_nota()) {
            double nota = vest[i].consultar_nota();
            if (max == -1 and min == -1) {
                max = min = nota;
            }
            else if (nota > max) max = nota;
            else if (nota < min) min = nota;
        }
    }

    return {max, min};
}

int main() 
{
    int size;
    cin >> size;
    vector<Estudiant> vest(size);
    llegir(vest);
    pair<double,double> notes = max_min(vest);
    cout << "nota max: " << notes.first << endl;
    cout << "nota min: " << notes.second << endl;
}*/

//versio 2

/*pair<int,int> max_min(const vector<Estudiant> &vest) */
/* Pre: vest no es buit i conte com a minim un estudiant amb nota */
/* Post: el resultat es un parell que conte, en aquest ordre, la posicio de 
   l'estudiant amb nota maxima i la posicio de l'estudiant amb nota minima.
   En cas d'empat de notes, es te en compte l'estudiant amb dni mes petit */
/*{
    int pos_max = -1;
    int pos_min = -1;
    
    int size = vest.size();
    for (int i = 0; i < size; ++i) {
        if (vest[i].te_nota()) {
            if (pos_max == -1 and pos_min == -1) {
                pos_max = pos_min = i;
            }
            else {
                if (vest[pos_max].consultar_nota() == vest[i].consultar_nota()
                     and vest[pos_max].consultar_DNI() > 
                     vest[i].consultar_DNI()) {
                    pos_max = i;
                }
                if (vest[pos_min].consultar_nota() == vest[i].consultar_nota()
                     and vest[i].consultar_DNI() < vest[pos_min].consultar_DNI()) {
                    pos_min = i;
                }
                else if (vest[pos_min].consultar_nota() > vest[i].consultar_nota()) {
                   pos_min = i;
                }
                else if (vest[pos_max].consultar_nota() < vest[i].consultar_nota()) {
                    pos_max = i;
                }
            }
        }
    }

    return {pos_max, pos_min};
}

int main()
{
    int size;
    while (cin >> size) {
        vector<Estudiant> vest(size);
        llegir(vest);
        pair<int,int> pos = max_min(vest);
        cout << "estudiante con nota max: ";
        vest[pos.first].escriure();
        cout << "estudiante con nota min: ";
        vest[pos.second].escriure();
        cout << endl;
    }
} */

//versio 3

pair<int,int>  max_min_vest(const vector<Estudiant>& v)
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
{
    int pos_min = -1;
    int pos_max = -1;
    double max = -1;
    double min = -1;

    int size = v.size();
    for (int i = 0; i < size; ++i) {
        if (v[i].te_nota() and pos_max == -1 and pos_min == -1) {
            pos_max = pos_min = i;
            max = min = v[i].consultar_nota();
        }
        else if (v[i].te_nota()) {
            double nota_act = v[i].consultar_nota();
            //Les notes maximes i minimes poden ser iguals, per tant, es comproven les dues condicions
            if (max == nota_act and v[pos_max].consultar_DNI() > 
               v[i].consultar_DNI()) {
                pos_max = i;
            }
            if (min == nota_act and v[pos_min].consultar_DNI() > 
               v[i].consultar_DNI()) {
                pos_min = i;
            }
            else if (min > nota_act) {
                pos_min = i;
                min = nota_act;
            }
            else if (max < nota_act) {
                pos_max = i;
                max = nota_act;
            }
        }
    }

    return {pos_max, pos_min};
}

/* int main()
{
    int size;
    while (cin >> size) {
        vector<Estudiant> vest(size);
        llegir(vest);
        pair<int,int> pos = max_min_vest(vest);
        if (pos.first == -1 and pos.second == -1) {
            cout << "no hay ningun estudiante con nota" << endl << endl;
        }
        else {
            cout << "estudiante con nota max: ";
            vest[pos.first].escriure();
            cout << "estudiante con nota min: ";
            vest[pos.second].escriure();
            cout << endl;
        }
    }
} */