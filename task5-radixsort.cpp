#include <fstream>
#include <iostream>

int** radixsort(int** a, int n, int m)
{
    int** B = new int* [n + 1];
    int P[256];
    for (int i = 0; i < 256; ++i) P[i] = 0;

    for (int i = 1; i < n + 1; ++i) P[a[i][m]]++;
    for (int i = 1; i < 256; ++i) P[i] += P[i - 1];
    int P_copy[256];
    for(int i=0;i<256;++i) P_copy[i] = P[i];
    P[0] = 1;
    for (int i = 1; i < 256; ++i) P[i] = P_copy[i - 1]+1;
    
    
    for (int i = 1; i < n+1; ++i) {
        B[P[a[i][m]]] = a[i];
        P[a[i][m]]++;
    }

    return B;
}


int main(int argc, char* argv[]) {
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
    int n, m, k;
    inFile >> n >> m >> k;
    int** array = new int* [n + 1];

    for (int i = 1; i < n+1; ++i) {
        array[i] = new int[m + 1];
        array[i][0] = i;
    }

    char temp;
    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            inFile >> temp;
            array[j][i] = temp;
           
        }
    }
   
    for (int t = 1; t <= k; ++t) {
        array=radixsort(array, n, m - t + 1);
    }

    for (int i = 1; i < n; ++i)
        outFile << array[i][0] << ' ';
    outFile << array[n][0];
    for (int i = 1; i < n + 1; ++i)
        delete[] array[i];
    delete[] array;

    inFile.close();
    outFile.close();
    return 0;
}
