
#include <fstream>
#include <iostream>
int split(int* a, int left, int right)
{
    int x = a[(left + right) / 2];
    int left_index = left, right_index = right, buff;

    while (left_index <= right_index) {
        while (a[left_index] < x) left_index++;
        while (a[right_index] > x) right_index--;
        if (left_index < right_index) {
            buff = a[left_index];
            a[left_index] = a[right_index];
            a[right_index] = buff;
            left_index++;
            right_index--;
        }
        else if(left_index==right_index){
            ++left_index;--right_index;
        }
    }

    return left_index;
}

void quicksort(int* a, int left, int right, int k1, int k2)
{
    if (left == right || left > k2 || right < k1) return;
    int m = split(a, left, right);

    quicksort(a, left, m - 1, k1, k2);
    quicksort(a, m, right, k1, k2);
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
    
    int n, k1, k2;
    inFile >> n >> k1 >> k2;
    int* array = new int[n + 1];
    int A, B, C;
    inFile >> A >> B >> C >> array[1] >> array[2];
    for (int i = 3; i <= n; ++i) array[i] = A * array[i - 2] + B * array[i - 1] + C;
    quicksort(array, 1, n, k1, k2);
    for (int i = k1; i < k2; ++i) outFile << array[i] << ' ';
    outFile<<array[k2];
    delete[] array;
    inFile.close();
    outFile.close();
    return 0;
}
