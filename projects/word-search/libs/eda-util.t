#include <iostream>
#include <random>
using std::cin;
using std::cout;
using std::endl;




template <typename elem>
void util::leer_lista(list<elem>& l) noexcept {
    nat num_elems;
    cin >> num_elems;
    for (nat i = 0; i < num_elems; ++i) {
        // Inv: 0 <= i <= num_elems; l[l.begin(), l.end()) contiene 'i-1' 
        //      elementos leídos del canal estándar de entrada.

        elem e;
        cin >> e;
        l.insert(l.end(), e);
    }
}



template <typename elem>
void util::restar_lista(list<elem>& a, const list<elem>& b) noexcept {
    typename list<elem>::iterator it1 = a.begin();
    typename list<elem>::const_iterator it2 = b.begin();

    while (it1 != a.end() and it2 != b.end()) {
        // Inv: todos los elementos de a[a.begin(), it1) que forman parte de
        //      b[b.begin(), it2) han sido elminados de 'a'.

        if (*it1 < *it2) ++it1;
        else if (*it1 > *it2) ++it2;
        else {
            it1 = a.erase(it1);
            ++it2;
        }
    }
}



template <typename elem>
void util::imprimir_lista(const list<elem>& l) noexcept {
    for (const elem& x : l) cout << x << endl;
}



template <typename elem>
elem util::min(const elem& a, const elem& b) noexcept {
    elem res = a;
    if (b < a) res = b;

    return res;
}



template <typename elem>
elem util::valor_aleatorio(elem a, elem b) noexcept {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(a, b);

    return dis(gen);
}