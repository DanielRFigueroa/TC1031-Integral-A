#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "phonebook.h"

using namespace std;

int main(int argc, char* argv[]) {
	List<int> d1;
	string ans;

	d1.insertion(35);
	ans = "[35]";
	cout << "\n" <<"1.- esperada " << ans << "\n programa " << d1.toString() << "\n";
	cout <<	(!ans.compare(d1.toString()) ? "success\n" : "fail\n");

	d1.insertion(33);
	d1.insertion(32);
	d1.insertion(37);
	ans = "[35, 33, 32, 37]";
	cout << "\n" <<"2.- esperada " << ans << "\n programa " << d1.toString() << "\n";
	cout <<	(!ans.compare(d1.toString()) ? "success\n" : "fail\n");

	cout << "\n" <<"3.- esperada " << 3 << " programa " << d1.search(37) << "\n";
	cout <<	(3 == d1.search(37) ? "success\n" : "fail\n");

	cout << "\n" <<"1.- esperada " << 1 << " programa " << d1.search(33) << "\n";
	cout <<	(1 == d1.search(33) ? "success\n" : "fail\n");

	d1.update(2,36);
	ans = "[35, 33, 36, 37]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << d1.toString() << "\n";
	cout <<	(!ans.compare(d1.toString()) ? "success\n" : "fail\n");

	d1.update(0,34);
	ans ="[34, 33, 36, 37]";
	cout << "\n" <<"6.- esperada " << ans << "\n programa " << d1.toString() << "\n";
	cout << (!ans.compare(d1.toString()) ? "success\n" : "fail\n");

	d1.deleteAt(3);
	ans = "[34, 33, 36]";
	cout << "\n" <<"7.- esperada " << ans << "\n programa " << d1.toString() << "\n";
	cout <<	(!ans.compare(d1.toString()) ? "success\n" : "fail\n");

	d1.deleteAt(0);
	ans = "[33, 36]";
	cout << "\n" <<"8.- esperada " << ans << "\n programa " << d1.toString() << "\n";
	cout <<	(!ans.compare(d1.toString()) ? "success\n" : "fail\n");

	d1.insertion(31);
    d1.insertion(34);
    d1.insertion(32);
    ans= "[33, 36, 31, 34, 32]";
    cout << "\n" <<"TEST 9. Esperada: " << ans << "\n Programa: " << d1.toString() << "\n";
	cout <<	(!ans.compare(d1.toString()) ? "SUCCESS\n" : "FAIL\n");

    d1.insertionSort(d1.head);
    ans = "[31, 32, 33, 34, 36]";
    cout << "\n" <<"TEST 10. Esperada: " << ans << "\n Programa: " << d1.toString() << "\n";
	cout <<	(!ans.compare(d1.toString()) ? "SUCCESS\n" : "FAIL\n");


	string in_ans = "", pre_ans = "";
	BST<int> my_splay;
	bool found = 0;

	my_splay.add(15);
	in_ans =	"[15]";
	cout << "\n" <<"1.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
	cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");

	my_splay.add(10);
	my_splay.add(17);
	my_splay.add(7);
	my_splay.add(13);
	my_splay.add(16);

	in_ans =	"[7 10 13 15 16 17]";
	cout << "\n" <<"2.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
	cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n"); 

	found = my_splay.find(15);
	in_ans =	"[7 10 13 15 16 17]"; 
	cout << "\n" <<"3.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
	cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
	
	cout << "\n" <<"3.- esperada " << 1 << " programa " << found << "\n";
	cout << " 3 " <<	(found == 1 ? "success\n" : "fail\n");

}