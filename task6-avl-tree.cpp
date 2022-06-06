#include <iostream>
#include <fstream>

using namespace std;

struct AVLTreeNode {
	AVLTreeNode(int data=0)
		:_pLeft(nullptr),
		_pRight(nullptr),
		_pParent(nullptr),
		_data(data),
		_bf(0)
	{}

	AVLTreeNode* _pLeft; // Левый потомок узла
	AVLTreeNode* _pRight; // правый дочерний элемент узла
	AVLTreeNode* _pParent; // Родитель этого узла 
	int _data;
	int _bf; // Коэффициент баланса этого узла
};
typedef AVLTreeNode Node;
class AVLTree {
public:
	AVLTree() {
		_pRoot = new Node(1000000001);
	}
	AVLTree(int value) {
		_pRoot = new Node(value);
	}
	Node* check(int value)
	{
		Node* child = _pRoot;
		while (true)
		{
			if (value > (*child)._data) {
				if ((*child)._pRight == nullptr) {
					return nullptr;
				}
				child = (*child)._pRight;
			}
			else if (value < child->_data) {
				if (child->_pLeft == nullptr) {
					return nullptr;
				}
				child = child->_pLeft;
			}
			else if (value == child->_data)
			{
				return child;
			}
		}
	}
	Node* minimum_right_tree(Node* value) {
		Node* child = value;
		while (true) {
			if (child->_pLeft == nullptr) return child;
			else child = child->_pLeft;
		}
	}
	void go_upp(Node* child, int q) {
		int side = q;
		while (true) {
			if (side == 0) child->_bf++;
			else if (side == 1) child->_bf--;
			if (child->_bf == 1 || child->_bf == -1) break;
			if (child->_bf == 0) {
				if (child->_pParent != nullptr) {
					if (child->_pParent->_pRight!=nullptr && child->_pParent->_pRight == child) side = 1;
					if (child->_pParent->_pLeft!=nullptr && child->_pParent->_pLeft == child) side = 0;
					child = child->_pParent;
				}
				else break;
			}
			else {
				if (child->_bf == 2) {
					bool x = false;
					if (child->_pParent == nullptr) x = true;
					Node* temp2 = AVLTree::LeftRotate(child, child->_pRight);
					if (x == true) _pRoot = temp2;
					if (temp2->_bf == 1 || temp2->_bf == -1) break;
					if (temp2->_bf == 0) {
						if (temp2->_pParent != nullptr) {
							if (temp2->_pParent->_pRight!=nullptr && temp2->_pParent->_pRight == temp2) side = 1;
							if (temp2->_pParent->_pLeft!=nullptr && temp2->_pParent->_pLeft == temp2) side = 0;
							child = temp2->_pParent;
						}
						else break;
					}
				}
				else if (child->_bf == -2) {
					bool x = false;
					if (child->_pParent == nullptr) x = true;
					Node* temp2 = AVLTree::RightRotate(child);
					if (x == true) _pRoot = temp2;
					if (temp2->_bf == 1 || temp2->_bf == -1) break;
					if (temp2->_bf == 0) {
						if (temp2->_pParent != nullptr) {
							if (temp2->_pParent->_pRight != nullptr && temp2->_pParent->_pRight == temp2) side = 1;
							if (temp2->_pParent->_pLeft != nullptr && temp2->_pParent->_pLeft == temp2) side = 0;
							child = temp2->_pParent;
						}
						else break;
					}
				}
			}

		}
	}
	int to_delete1(Node* temp) {
		int q = -1;
		if (temp->_pLeft == nullptr && temp->_pRight == nullptr) {
			if (temp->_pParent != nullptr) {
				if (temp->_pParent->_pLeft == temp) {
					q = 0;
					temp->_pParent->_pLeft = nullptr;
				}
				else if (temp->_pParent->_pRight == temp) {
					q = 1;
					temp->_pParent->_pRight = nullptr;
				}
			}
			else {
				temp->_data = 1000000001;
				temp->_bf = 0;
			}
		
		}
		else if (temp->_pLeft == nullptr && temp->_pRight != nullptr) {
			if (temp->_pParent != nullptr) {
				if (temp->_pParent->_pLeft == temp) {
					q = 0;
					temp->_pParent->_pLeft = temp->_pRight;
					temp->_pRight->_pParent = temp->_pParent;
				}
				else if (temp->_pParent->_pRight == temp) {
					q = 1;
					temp->_pParent->_pRight = temp->_pRight;
					temp->_pRight->_pParent = temp->_pParent;
				}
			}
			else {
				_pRoot = temp->_pRight;
				_pRoot->_pParent = nullptr;
				q = 1;
			}
		}
		else if (temp->_pLeft != nullptr && temp->_pRight == nullptr) {
			if (temp->_pParent != nullptr) {
				if (temp->_pParent->_pLeft == temp) {
					q = 0;
					temp->_pParent->_pLeft = temp->_pLeft;
					temp->_pLeft->_pParent = temp->_pParent;
				}
				else if (temp->_pParent->_pRight == temp) {
					q = 1;
					temp->_pParent->_pRight = temp->_pLeft;
					temp->_pLeft->_pParent = temp->_pParent;
				}
			}
			else {
				_pRoot = temp->_pLeft;
				_pRoot->_pParent = nullptr;
				q = 0;
			}
		}
		return q;
	}
	int to_delete(int value) {
		Node* temp = check(value);
		int q = -1;
		if (temp == nullptr) return _pRoot->_bf;
		if (temp->_pLeft == nullptr && temp->_pRight==nullptr) {
			if (temp->_pParent != nullptr) {
				Node* child = temp->_pParent;
				if (temp->_pParent->_pLeft == temp) {
					q = 0;
					temp->_pParent->_pLeft = nullptr;
				}
				else if (temp->_pParent->_pRight == temp) {
					q = 1;
					temp->_pParent->_pRight = nullptr;
				}
				go_upp(child, q);
			}
			else {
				temp->_data = 1000000001;
			}
		}
		else if (temp->_pLeft == nullptr && temp->_pRight != nullptr) {
			if (temp->_pParent != nullptr) {
				Node* child = temp->_pParent;
				if (temp->_pParent->_pLeft == temp) {
					q = 0;
					temp->_pParent->_pLeft = temp->_pRight;
					temp->_pRight->_pParent = temp->_pParent;
				}
				else if (temp->_pParent->_pRight == temp) {
					q = 1;
					temp->_pParent->_pRight = temp->_pRight;
					temp->_pRight->_pParent = temp->_pParent;
				}
				go_upp(child, q);
			}
			else {
				_pRoot = temp->_pRight;
				_pRoot->_pParent = nullptr;
			}
		}
		else if (temp->_pLeft != nullptr && temp->_pRight == nullptr) {
			if (temp->_pParent != nullptr) {
				Node* child = temp->_pParent;
				if (temp->_pParent->_pLeft == temp) {
					q = 0;
					temp->_pParent->_pLeft = temp->_pLeft;
					temp->_pLeft->_pParent = temp->_pParent;
				}
				else if (temp->_pParent->_pRight == temp) {
					q = 1;
					temp->_pParent->_pRight = temp->_pLeft;
					temp->_pLeft->_pParent = temp->_pParent;
				}
				go_upp(child, q);
			}
			else {
				_pRoot = temp->_pLeft;
				_pRoot->_pParent = nullptr;
			}
		}
		else {
			Node* temp1 = minimum_right_tree(temp->_pRight);
			Node* child = temp1->_pParent;
			int temp_value = temp1->_data;
			int side=to_delete1(temp1);
			temp->_data = temp_value;
			go_upp(child, side);
			
		}
		return _pRoot->_bf;
	}
	int insert(int value)
	{
		if (_pRoot->_data == 1000000001) {
			_pRoot->_data = value; return 0;
		}
		Node* child = _pRoot;
		int side = -1;
		while (true)
		{
			if (value > (*child)._data) {
				if ((*child)._pRight == nullptr) {
					(*child)._pRight = new Node(value);
					(*child)._pRight->_pParent = child;
					side = 1;
					break;
				}
				child = (*child)._pRight;
			}
			else if (value < child->_data) {
				if (child->_pLeft == nullptr) {
					child->_pLeft = new Node(value);
					child->_pLeft->_pParent = child;
					side = 0;
					break;
				}
				child = child->_pLeft;
			}
			else if (value == child->_data)
			{
				return _pRoot->_bf;
			}
		}
		while (true) {
			if (side == 0) child->_bf--;
			else if (side == 1) child->_bf++;
			    if (child->_bf == 0) break;
				if (child->_bf == 1 || child->_bf == -1) {
					if (child->_pParent != nullptr) {
						if (child->_pParent->_pRight!=nullptr && child->_pParent->_pRight == child) side = 1;
						if (child->_pParent->_pLeft!=nullptr && child->_pParent->_pLeft == child) side = 0;
						child = child->_pParent;
					}
					else break;
				}
				else {
					if (child->_bf == 2) {
						bool x = false;
						if (child->_pParent == nullptr) x = true;
						Node* temp=AVLTree::LeftRotate(child,child->_pRight);
						if (x == true) _pRoot = temp;
						if (temp->_bf == 0) break;
						if (temp->_bf == 1 || temp->_bf == -1) {
							if (temp->_pParent != nullptr) {
								if (temp->_pParent->_pRight!=nullptr && temp->_pParent->_pRight == temp) side = 1;
								if (temp->_pParent->_pLeft!=nullptr && temp->_pParent->_pLeft == temp) side = 0;
								child = temp->_pParent;
							}
							else break;
						}
					}
					else if (child->_bf == -2) {
						bool x = false;
						if (child->_pParent == nullptr) x = true;
						Node* temp = AVLTree::RightRotate(child);
						if (x == true) _pRoot = temp;
						if (temp->_bf == 0) break;
						if (temp->_bf == 1 || temp->_bf == -1) {
							if (temp->_pParent != nullptr) {
								if (temp->_pParent->_pRight != nullptr && temp->_pParent->_pRight == temp) side = 1;
								if (temp->_pParent->_pLeft != nullptr && temp->_pParent->_pLeft == temp) side = 0;
								child = temp->_pParent;
							}
							else break;
						}
					}
				}
			
		}
		return _pRoot->_bf;
	}
	static Node* LeftRotate(Node* data, Node* tempp,int kk=0)
	{
		if (!(data->_bf==2 && data->_pRight->_bf==-1)||kk==1) {
			if (data->_bf != 1) {
				if (data->_pRight->_bf == 0) { data->_bf = 1; data->_pRight->_bf = -1; }
				if (data->_pRight->_bf == 1) { data->_bf = 0; data->_pRight->_bf = 0; }
			}
			if (data->_pParent!=nullptr) {
				int z = -1;
				if (data->_pParent->_pLeft == data) {
					z = 0; data->_pParent->_pLeft = data->_pRight;
				}
				if (data->_pParent->_pRight == data) {
					z = 1; data->_pParent->_pRight = data->_pRight;
				}
				data->_pRight->_pParent = data->_pParent;
				if(data->_pRight->_pLeft!=nullptr) data->_pRight->_pLeft->_pParent = data;
				data->_pRight = data->_pRight->_pLeft;
				if(z==0) data->_pParent = data->_pParent->_pLeft;
				else if (z == 1) data->_pParent = data->_pParent->_pRight;
				data->_pParent->_pLeft = data;
			}
			else {
				
				data->_pRight->_pParent = nullptr;
				if(data->_pRight->_pLeft!=nullptr) data->_pRight->_pLeft->_pParent = data;
				data->_pRight = data->_pRight->_pLeft;
				data->_pParent = tempp;
				data->_pParent->_pLeft = data;
			}
			return data->_pParent;
		}
		else {
			int temp = data->_pRight->_pLeft->_bf;
			AVLTree::RightRotate(data->_pRight);
			AVLTree::LeftRotate(data,data->_pRight,1);
			data->_pParent->_bf = 0;
			if (temp == -1) { data->_bf = 0; data->_pParent->_pRight->_bf = 1; }
			if (temp == 0) { data->_bf = 0; data->_pParent->_pRight->_bf = 0; }
			if (temp == 1) { data->_bf = -1; data->_pParent->_pRight->_bf = 0; }
			return data->_pParent;
		}
	}
	static Node* RightRotate(Node* data,int kk=0)
	{
		if (!(data->_bf == -2 && data->_pLeft->_bf == 1)||kk==1) {
			if (data->_bf != -1) {
				if (data->_pLeft->_bf == 0) { data->_bf = -1; data->_pLeft->_bf = 1; }
				if (data->_pLeft->_bf == -1) { data->_bf = 0; data->_pLeft->_bf = 0; }
			}
			if (data->_pParent != nullptr) {
				int z = -1;
				if (data->_pParent->_pLeft == data) {
					z = 0; data->_pParent->_pLeft = data->_pLeft;
				}
				if (data->_pParent->_pRight == data) {
					z = 1; data->_pParent->_pRight = data->_pLeft;
				}
				data->_pLeft->_pParent = data->_pParent;
				if (data->_pLeft->_pRight != nullptr) data->_pLeft->_pRight->_pParent = data;
				data->_pLeft = data-> _pLeft->_pRight;
				if(z==0) data->_pParent = data->_pParent->_pLeft;
				else if (z == 1) data->_pParent = data->_pParent->_pRight;
				data->_pParent->_pRight = data;
			}
			else {
				Node* temp = data->_pLeft;
				data->_pLeft->_pParent = nullptr;
				if (data->_pLeft->_pRight != nullptr) data->_pLeft->_pRight->_pParent = data;
				data->_pLeft = data->_pLeft->_pRight;
				data->_pParent = temp;
				data->_pParent->_pRight = data;
			}
			return data->_pParent;
		}
		else {
			int temp = data->_pLeft->_pRight->_bf;
			AVLTree::LeftRotate(data->_pLeft,data->_pLeft->_pRight);
			AVLTree::RightRotate(data,1);
			data->_pParent->_bf = 0;
			if (temp == -1) { data->_bf = 1; data->_pParent->_pLeft->_bf = 0; }
			if (temp == 0) { data->_bf = 0; data->_pParent->_pLeft->_bf = 0; }
			if (temp == 1) { data->_bf = 0; data->_pParent->_pLeft->_bf = -1; }
			return data->_pParent;
		}
	}

	Node* _pRoot;
};

int main(int argc, char* argv[]) {
	AVLTree example(1000000001);
	
	if (argc < 3) {
        return 1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile) {
        return 2;
    }

    std::ofstream outFile(argv[2]);
    if (!outFile) {
        return 3;
    }

	int n;
	inFile >> n;
	char s;
	int c;
	for (int i = 1; i <= n; ++i) {
		inFile >> s;
		if (s == '+') {
			inFile >> c;
			outFile << example.insert(c)<<"\n";
		}
		if(s=='-'){
			inFile >> c;
			outFile << example.to_delete(c) << "\n";
		}
		if (s == '?') {
			inFile >> c;
			if (example.check(c) == nullptr) outFile << "false\n";
			else outFile << "true\n";
		}
	}
	inFile.close();
	outFile.close();
	return 0;
}
