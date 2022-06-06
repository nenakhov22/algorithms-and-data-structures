#include <fstream>
#include <iostream>
using namespace std;
void Merge(long long* M, int first, int middle, int last, int size){
    long long* temp = new long long[last - first + 1];
    int start1 = first;
    int start2 = middle + 1;
    int end1 = middle; 
    int end2 = last;
    int index = 0;
    while (start1 <= end1 && start2 <= end2){
        if (M[start1] <= M[start2]) temp[index++] = M[start1++];
        else {
            M[size] += end1 - start1;
            M[size]++;
            temp[index++] = M[start2++];
        }
    }
    while (start1 <= end1) temp[index++] = M[start1++];
    while (start2 <= end2) temp[index++] = M[start2++];
    index = 0;
    while (first <= last) M[first++] = temp[index++];
    delete[] temp;
}
void Split(long long* M, int first, int last, int size){
    if (first<last){
        int middle = (last - first + 1)/2+first-1;
        Split(M, middle + 1, last, size);
        Split(M, first, middle, size);
        Merge(M, first, middle, last, size);
    }
}

int main(int argc, char* argv[]) {
    if (argc<3) return 1;
    ifstream inFile(argv[1]);
    if (!inFile)  return 2;
    ofstream outFile(argv[2]);
    if (!outFile) return 3;
    int n;
    inFile>>n;
    long long* M = new long long[n + 1];
    for (int i = 0; i<n; i++) inFile>>M[i];
    M[n] = 0;
    Split(M, 0, n - 1, n);
    outFile<<M[n];
    inFile.close();
    outFile.close();
}
