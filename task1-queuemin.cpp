#include <fstream>
#include<iostream>
using namespace std;
int** array_x_2(int** x,int myltiply,int size)
{
    
    int** x2 = new int*[size*myltiply];
    for (int i = 0; i < size; ++i)
    {
        x2[i] = new int[2];
        x2[i][0] = x[i][0];
        x2[i][1] = x[i][1];
    }
    for (int i = size; i < size * myltiply; i++) x2[i] = new int[2];
    return x2;
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
    int** stack1 = new int*[1];
    stack1[0] = new int[2];
    int size1 = 1;
    int end_index1 = -1;
    int** stack2 = new int*[1];
    stack2[0] = new int[2];
    int size2 = 1;
    int end_index2 = -1;
    int k = 0;
    inFile >> k;
    char symbol;
    int k1 = k;
    for (int i = 1; i <= k1; ++i)
    {
        inFile >> symbol;
        if (symbol == '+')
        {
            inFile >> k;
            if (end_index1 < size1 - 1)
            {
                end_index1++;
                stack1[end_index1][0] = k;
            }
            else {
                while (end_index1 >= size1 - 1) {
                    stack1 = array_x_2(stack1, 2, size1);
                    size1 *= 2;

                }
                ++end_index1;
                stack1[end_index1][0] = k;
            }
            if (i == 1 || end_index1 == 0) stack1[end_index1][1] = k;
            else {
                if (stack1[end_index1 - 1][1] > k) stack1[end_index1][1] = k;
                else stack1[end_index1][1] = stack1[end_index1 - 1][1];
            }
        }
        if (symbol == '-')
        {
            if (end_index2 == -1)
            {
                while (size2 < size1) {
                    stack2 = array_x_2(stack2, 2, size2);
                    size2 *= 2;
                }
                for (int j = end_index1; j >= 0; --j) {
                    stack2[end_index1 - j][0] = stack1[j][0];
                    if (j == end_index1) stack2[end_index1 - j][1] = stack1[j][0];
                    else {
                        if (stack2[end_index1 - j - 1][1] < stack1[j][0]) stack2[end_index1 - j][1] = stack2[end_index1 - j - 1][1];
                        else stack2[end_index1 - j][1] = stack1[j][0];
                    }
                    //stack2[end_index1 - j][1] = stack1[j][1];
                    ++end_index2;
                }
                //stack1 = array_x_2(stack1,1, 1);
                end_index1 = -1;
            }
            --end_index2;
            
        }
        if (symbol == '?') {
            if (end_index1 == -1) outFile << stack2[end_index2][1] <<'\n';
            else if (end_index2 == -1) outFile << stack1[end_index1][1]<<'\n';
            else {
                if (stack1[end_index1][1] < stack2[end_index2][1]) { outFile << stack1[end_index1][1]<<'\n'; }
                else {
                    outFile << stack2[end_index2][1]<<'\n'; 
                }
            }
        }
    }
    
    inFile.close();
    outFile.close();
    return 0;
}
