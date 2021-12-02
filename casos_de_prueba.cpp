#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "phonebook.h"

using namespace std;

/*int main(int argc, char* argv[]) {
	List<int> b1;
	string ans;

	b1.insertion(2);
	ans = "[2]";
	cout << "\n" <<"1.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.insertion(3);
	b1.insertion(6);
	b1.insertion(10);
	ans = "[2, 3, 6, 10]";
	cout << "\n" <<"2.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	cout << "\n" <<"3.- esperada " << 3 << " programa " << b1.search(10) << "\n";
	cout <<	(3 == b1.search(10) ? "success\n" : "fail\n");

	cout << "\n" <<"4.- esperada " << -1 << " programa " << b1.search(1) << "\n";
	cout <<	(-1 == b1.search(1) ? "success\n" : "fail\n");

	b1.update(1,13);
	ans = "[2, 13, 6, 10]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.update(3,32);
	ans ="[2, 13, 6, 32]";
	cout << "\n" <<"6.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout << (!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.deleteAt(0);
	ans = "[13, 6, 32]";
	cout << "\n" <<"7.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.deleteAt(1);
	ans = "[13, 32]";
	cout << "\n" <<"8.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

}





template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
} */


int main(int argc, char* argv[]) {

	int array1[] = {58, 92, 75, 5, 21, 92, 84, 91, 64, 54, 3, 28, 11, 61, 65, 4, 1, 8, 52, 78};
	vector<int> original1 (array1, array1 + sizeof(array1) / sizeof(int) );

	int array2[] = {120, 10, 5, 897, 333, 68};
	vector<int> original2 (array2, array2 + sizeof(array2) / sizeof(int) );

	vector<int> prueba;
	List<int> sorts;
	string resp1 = "[1, 3, 4, 5, 8, 11, 21, 28, 52, 54, 58, 61, 64, 65, 75, 78, 84, 91, 92, 92]";
	string resp2 = "[5, 10, 68, 120, 333, 897]";

	prueba = original1;
	sorts.ordenaSeleccion(prueba);


	cout << "\n" <<"1.- esperada " << resp1 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaSeleccion(prueba);

	cout << "\n" <<"2.- esperada " << resp2 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original1;
	sorts.ordenaBurbuja(prueba);

	cout << "\n" <<"3.- esperada " << resp1 << "\n   programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaBurbuja(prueba);

	cout << "\n" <<"4.- esperada "  << resp2 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original1;
	sorts.ordenaMerge(prueba);

	cout << "\n" <<"5.- esperada "  << resp1 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaMerge(prueba);
	cout << "\n" <<"6.- esperada "  << resp2 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	sorts.ordenaMerge(prueba);

	cout << "\n" <<"7.- esperada "  << 5 << " programa " << sorts.busqSecuencial(prueba, 897) << "\n";
  cout <<	(5 == sorts.busqSecuencial(prueba, 897) ? "success\n" : "fail\n");

	cout << "\n" <<"8.- esperada "  << -1  << " programa " << sorts.busqSecuencial(prueba, 100) << "\n";
	cout <<	(-1 == sorts.busqSecuencial(prueba, 100) ? "success\n" : "fail\n");

	cout << "\n" <<"9.- esperada "  << 4 << " programa " << sorts.busqBinaria(prueba, 333)  << "\n";
	cout <<	(4 == sorts.busqBinaria(prueba, 333) ? "success\n" : "fail\n");

	cout << "\n" <<"10.- esperada "  << -1  << " programa " << sorts.busqBinaria(prueba, 197) << "\n";
	cout <<	(-1 == sorts.busqBinaria(prueba, 197) ? "success\n" : "fail\n");
}
