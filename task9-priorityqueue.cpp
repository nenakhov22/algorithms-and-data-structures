#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Node {
	int key;
	int pos;
};
class my_priority_queue {
public:
	Node* arr;
	int* pos;
	int size;
	int capacity;
	my_priority_queue() {
		size = 0;
		capacity = 0;
	}
	~my_priority_queue()
	{
		if(capacity>0) delete[] arr;
	}
	
	void decrease_key(int i, int key) {
		arr[i].key = key;
		while (i > 0 && arr[i].key < arr[(i - 1) / 2].key) {
			Node temp1 = arr[i];
			arr[i] = arr[(i - 1) / 2];
			arr[(i - 1) / 2] = temp1;
			pos[arr[i].pos]=i;
			i = (i - 1) / 2;
			pos[arr[i].pos]=i;
		}
		
	}
	void index_searching(int pos1, int key) {
		//int i = 0;

		//while (arr[i].pos != pos) ++i;

		decrease_key(pos[pos1], key);
	}
	void min_heapify(int i) {
		int lowest = i;
		int l = 2*i+1;
		int r = 2*i+2;

		if (l < size && arr[l].key < arr[lowest].key)
			lowest = l;
		if (r < size && arr[r].key < arr[lowest].key)
			lowest = r;

		if (lowest != i) {
			Node temp = arr[i];
			arr[i] = arr[lowest];
			arr[lowest] = temp;
			pos[arr[i].pos]=i;
			pos[arr[lowest].pos]=lowest;
			min_heapify(lowest);
		}
	}
	void insert(int key, int pos1,int k) {
		if (capacity == 0) {
			arr = new Node[1];
			arr[0].key = key;
			pos=new int[k+1];
			arr[0].pos = pos1;
			pos[pos1]=0;
			capacity = 1;
			size = 1;
		}
		else {
			if (capacity == size) {
				capacity = capacity * 2;
				Node* temp = new Node[capacity];
				for (int i = 0; i < size; ++i)
				{
					temp[i] = arr[i];
				}
				delete[] arr;
				arr = temp;
			}
			size++;
			arr[size - 1].key = 2147483647;
			arr[size - 1].pos = pos1;
			pos[pos1]=size-1;
			decrease_key(size - 1, key);
		}
	}
	void extract_min(ofstream& outFile) {

		if (size < 1) {
			outFile << "*\n";
			return;
		}

		int min = arr[0].key;
		arr[0] = arr[size - 1];
		pos[arr[0].pos]=0;
		size -= 1;
		min_heapify(0);

		outFile << min << "\n";
	}
};



int main(int argc, char* argv[]) {
	ifstream inFile1(argv[1]);
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
	my_priority_queue q;
	string str;
	int k = 0;
	while (getline(inFile1, str))k++;
	inFile1.close();
	for (int i = 1; i <= k; i++)
	{
		char s;
		
		inFile >> s;
		int key;
		if (s == 'p') {
			for (int j = 1; j <= 3; j++) inFile >> s;
			inFile >> key;
			q.insert(key, i,k);
		}
		else if (s == 'e') {
			for (int j = 1; j <= 10; j++) inFile >> s;
			q.extract_min(outFile);
		}
		else if (s == 'd') {
			int x, y;
			for (int j = 1; j <= 11; j++) inFile >> s;
			inFile >> x>>y;
			q.index_searching(x, y);
		}
	}
	inFile.close();
	outFile.close();
	return 0;
}
