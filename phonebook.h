/*  Integral A

    Author: Daniel Rodriguez Figueroa
    Matricula: A01612889
*/

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

template <class T> class List;

template <class T>
class Link{
    private:
        Link(T);
        Link(T, Link<T>*); 
        Link(const Link<T>&);
        T       value;
        Link<T> *next;
        friend class List<T>;
};


template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

template <class T>
class List{
    public: 
        List();
        List(const List<T>&);

        void insertion(T);
        void insertFirst(T);
        void insertionSort(Link<T> *headref);
        void sortedInsert(Link<T> *newnode);
        int search(T) const;
        void update(int, T); 
        T deleteFirst();
        T deleteAt(int);
        std::string toString() const;
        bool empty() const;
        Link<T> *head;

    private:
        Link<T> *sorted;
        int size;

};

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
List<T>::List() : head(0), size(0) {}


template <class T>
void List<T>::insertionSort(Link<T> *headref){

    if(empty()){
        std::cout<<"Aun no has registrado a ningun contacto en tu Phonebook."<<std::endl;
    } else{
        sorted = NULL;
        Link<T> *current = headref;

        while(current != NULL){
            Link<T> *next = current->next;
            sortedInsert(current);
            current = next;
        }
        head = sorted;
        std::cout<<"Tu lista de contactos ha sido ordenada!"<<std::endl;
    }
}

template <class T>
void List<T>::sortedInsert(Link<T> *newnode){
    if (sorted == NULL || sorted->value >= newnode->value){
        newnode ->next = sorted;
        sorted = newnode;
    } else{
        Link<T> *current = sorted;
        while (current->next != NULL && current->next->value < newnode->value){
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}


template <class T>
void List<T>::insertFirst(T val){
	Link<T> *newLink;

	newLink = new Link<T>(val);
	if (newLink == NULL) {
		std::cout<<"No hay espacio en memoria";
	}
	newLink->next = head;
	head = newLink;
	size++;
}


template <class T>
void List<T>::insertion(T val){
    Link<T> *newLink, *p;

    newLink = new Link<T>(val);
    if (newLink == NULL){
        std::cout<<"No hay espacio en memoria";
    }
    

    if (empty()){
        insertFirst(val);
        return;
    }


    p = head;
    while (p->next != 0){
        p = p->next;
    }

    newLink->next = 0;
    p->next = newLink;
    size++;
}

template <class T>
int List<T>::search(T val) const{
    Link<T> *p;

    p = head;
    int index = 0;
    while (p != 0){
        if(p->value == val){
            return index;
        }
        p = p->next;
        index++;
    }
	return -1;
} 


template <class T>
void List<T>::update(int index, T val){
    Link<T> *p;

    p = head;
    int pos = 0;
    while(pos != index){
        p = p->next;
        pos++;
    }
    p->value = val;
    cout<<"\nSe actualizo la lista de contactos!"<<endl;
}

template <class T>
T List<T>::deleteFirst(){
	T val;
	Link<T> *p;

	if (empty()) {
		std::cout<<"No existe dicho contacto";
	}

	p = head;

	head = p->next;
	val = p->value;

	delete p;
	size--;

	return val;
}


template <class T>
T List<T>::deleteAt(int index){
    Link<T> *p, *q;
    T val;
    int pos = 0;
    
    if (index < 0 || index >= size) {
        std::cout << "Esa posicion no existe en tu lista, esta fuera de rango";
    }
    
    if(index==0){
        return deleteFirst();
    }

    p = head;
    q = 0;
    while (pos != index) {
        q = p;
        p = p->next;
        pos++;
    }
    val = p->value;
    q->next = p->next;
    
    delete p;
    cout<<"El contacto seleccionado ha sido eliminado";
    size--;
	return 0;
} 


template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}









template <class T> class BST;

template <class T>
class Node {
    private:
        T value;
        Node *left, *right;

        Node<T>* succesor();

    public:
        Node(T);
        Node(T, Node<T>*, Node<T>*);
        void add(T);
        bool find(T);
        void remove(T);
        void removeChilds();
        void inorder(std::stringstream&) const;
        void preorder(std::stringstream&) const;

        friend class BST<T>;
		friend class List<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != NULL) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != NULL) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {

	if (val != value) {
        std::cout<<"No tienes contactos con la lada: "<<val<<std::endl;
		return false;
	}
	
	if (val == value) {
        std::cout<<"Si tienes contactos con la lada: "<<val<<std::endl;
		return true;
	} else if (val < value) {
		return (left != NULL && left->find(val));
	} else 
		return (right != NULL && right->find(val));
}

template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (right->left == NULL) {
		right = right->right;
		ri->right = NULL;
		return ri;
	}

	Node<T> *parent, *child;
	parent = right;
	child = right->left;
	while (child->left != NULL) {
		parent = child;
		child = child->left;
	}
	parent->left = child->right;
	child->right = NULL;
	return child;
}


template <class T>
void Node<T>::remove(T val) {
	Node<T> * succ, *old;

	if (val < value) {
		if (left != NULL) {
			if (left->value == val) {
				old = left;
				if(old->left != NULL && old->right != NULL){
					succ = left->succesor();
					if (succ != NULL) {
						succ->left = old->left;
						succ->right = old->right;
					}
					left = succ;
				} else if (old->right != NULL){ 
						left = old->right;
				} else if (old->left != NULL){ 
						left = old->left;
				} else {
						left = NULL;
				}
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != NULL) {
			if (right->value == val) {
				old = right;
				if(old->left != NULL && old->right != NULL){ 
					succ = right->succesor();
					if (succ != NULL) {
						succ->left = old->left;
						succ->right = old->right;
					}
					right = succ;
				} else if (old->right != NULL){ 
					right = old->right;
				} else if (old->left != NULL){ 
					right = old->left;
				} else { 
					right = NULL;
				}
					delete old;
			} else {
				right->remove(val);
			}
		}
	}
}

template <class T>
void Node<T>::removeChilds() {
	if (left != NULL) {
		left->removeChilds();
		delete left;
		left = NULL;
	}
	if (right != NULL) {
		right->removeChilds();
		delete right;
		right = NULL;
	}
}

/*template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != NULL) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != NULL) {
		aux << " ";
		right->preorder(aux);
	}
}*/

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}


template <class T>
class BST {
    private:
        Node<T> *root;

    public:
        BST();
        ~BST();
        bool empty() const;
        void add(T);
        bool find(T) const;
        void remove(T);
        void removeAll();
        std::string inorder() const;
		//std::string preorder() const;
		
		char *data;


        friend class List<T>;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {

	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
void BST<T>::remove(T val) {
	if (root != 0) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != 0) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		} else {
			root->remove(val);
		}
	}
}

template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	} else {
        std::cout<<"No existe ningun contacto con esa lada"<<std::endl;
		return false;
	}
}

/*template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}*/

template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

    if(empty()){
        aux << "No tienes ningun contacto agregado";
    }

	if (!empty()) {
        aux << "[";
		root->inorder(aux);
        aux << "]";
	}
	 
	return aux.str();
}