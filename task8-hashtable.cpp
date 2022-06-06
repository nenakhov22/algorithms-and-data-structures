#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int hashfunc(int key, int m) {
	return(key% m);
}

struct Node {
	int key;
	Node* left;
	Node* right;
};
class HashTable {
public:
	Node** array;
	
	int m;
	
	HashTable(int m1) {
		m = m1;
		array = new Node * [m1];
		for (int i = 0; i < m1; i++) {
			array[i] = nullptr;
		}
	}
	Node* check(int key) {
		Node* x = array[hashfunc(key,m)];
		if (x == nullptr) return nullptr;
		else {
			while (true) {
				if (x != nullptr) {
					if (x->key == key) return x;
					else x = x->right;
				}
				else return nullptr;
			}
		}
	}
	void insert(int key) {
		Node* x = check(key);
		if (x != nullptr) return;
		else {
			int h = hashfunc(key,m);
			Node* x1 = array[h];
			if (x1 == nullptr) {
				x1 = new Node;
				x1->key = key;
				x1->left = nullptr;
				x1->right = nullptr;
				array[h] = x1;
			}
			else {
				Node* temp = x1;
				x1 = new Node;
				x1->key = key;
				x1->left = nullptr;
				x1->right = temp;
				temp->left = x1;
				array[h] = x1;
			}
		}
	}
	void to_delete(int key) {
		Node* x = check(key);
		if (x == nullptr) return;
		else {
			if (x->left != nullptr) {
				x->left->right = x->right;
				if (x->right != nullptr) x->right->left = x->left;
			}
			else {
				array[hashfunc(key,m)] = x->right;
				if (x->right != nullptr) x->right->left = nullptr;
			}
			delete x;
		}
	}
	
	~HashTable() {
		for (int i = 0; i < m; ++i)
		{
			Node* x = array[i];
			if (array[i] == nullptr) {}
			else {
				while (x->right != nullptr) {
					x = x->right;
				}

				while (true) {
					if (x->left != nullptr) {
						x->left->right = nullptr;
						Node* x1 = x;
						x = x->left;
						delete x1;
						
					}
					else {
						array[i] = nullptr;
						delete x;
						break;
					}
				}
			}
		}
		delete[] array;
	}
};
int main(int argc, char* argv[]) {
	srand(time(NULL));
	if (argc < 3) {
        return -1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile) {
        return -2;
    }

    std::ofstream outFile(argv[2]);
    if (!outFile) {
        return -3;
    }
	int n;
	int begin = 0;
	inFile >> n;
	HashTable T = HashTable(n / 6);
	for (int i = 1; i <= n; ++i) {
		char s;
		int k;
		inFile >> s;
		if (s == '+') {
			inFile >> k;
			T.insert(k);
		}
		else if (s == '-') {
			inFile >> k;
			T.to_delete(k);
		}
		else if (s == '?') {
			
				inFile >> k;
				if (T.check(k) == nullptr) outFile << "false\n";
				else outFile << "true\n";
				
			
			
		}
	}
	inFile.close();
	outFile.close();
	return 0;
}
