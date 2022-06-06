#include <fstream>
#include <string>

using namespace std;

int* buildP(string t) {
	int* p = new int[t.length() + 1];
	p[1] = 0;
	int i = 1; int j = 0;
	while (i < t.length()) {
		if (t[i] == t[j]) {
			p[i + 1] = j + 1;
			++i;++j;
		}
		else {
			if (j > 0) j = p[j];
			else {
				p[i + 1] = 0;
				++i;
			}
		}
	}
	return p;
}


int find(string s, string t)
{
	int* p = buildP(t);
	int i = 0, j = 0;
	while (i < s.length() && j < t.length())
	{
		if (s[i] == t[j])
		{
			++i; ++j;
		}
		else 
			if (j > 0)
			j = p[j];
		else
			i++;
	}
	delete[] p;
	if (j == t.length())
		return i - t.length();
	else
		return -1;
}

int main(int argc, char* argv[]) {
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
	string X;
	string Y;
	inFile >> X;
	inFile >> Y;
	int count = 0;
	string result="";
	int pos = find(Y, X);
	int pos1 = 0;
	int kk = 0;
	while (pos != -1)
	{
		pos1 = pos1 + pos + 1;
		if (kk != 0) {
			result = result + " " + to_string(pos1);
		}
		else {
			result = to_string(pos1);
			++kk;
		}
		Y.erase(0, pos + 1);
		pos = find(Y, X);
		++count;
	}

	outFile << count << std::endl;
	if (count > 0) outFile << result;
	
	inFile.close();
	outFile.close();
	return 0;
}
