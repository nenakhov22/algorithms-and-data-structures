#include <iostream>
#include <fstream>

void my_swap(float& x, float& y)
{
    float temp = x;
    x = y;
    y = temp;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        return 1;
    }
    std::ifstream inFile(argv[1]);
    if (!inFile) {
        return 2;
    }
    int number = 0;
    inFile >> number;
    float* a=new float[number];
    float* a1 = new float[number];
    for (int i = 0; i < number; ++i) {
        inFile >> a[i];
        a1[i] = a[i];
    }
    int s = 0; 
    bool b;
    do
    {
        b = false;
        for (int i = 0; i < number; ++i)
        {
            if (i * 2 + 2 + s < number)
            {
                if ((a[i + s] > a[i * 2 + 2 + s])||(a[i + s] > a[i * 2 + 1 + s]))
                {
                    if (a[i * 2 + 1 + s] < a[i * 2 + 2 + s])
                    {
                        my_swap(a[i + s], a[i * 2 + 1 + s]);
                        b = true;
                    }
                    else if (a[i * 2 + 2 + s] < a[i * 2 + 1 + s])
                    {
                        my_swap(a[i + s], a[i * 2 + 2 + s]);
                        b = true;
                    }
                }
                if (a[i * 2 + 2 + s] < a[i * 2 + 1 + s])
                {
                    my_swap(a[i * 2 + 1 + s], a[i * 2 + 2 + s]);
                    b = true;
                }
            }
            else if (i * 2 + 1 + s < number)
            {
                if (a[i + s] > a[i * 2 + 1 + s])
                {
                    my_swap(a[i + s], a[i * 2 + 1 + s]);
                    b = true;
                }
            }
        }
        if (b==false) ++s; 
    } while (s + 2 < number); 
    int worst;
    int best;
    int medium;
    for (int i = 0; i < number; i++) {
        if (a[0] == a1[i]) worst = i + 1;
        if (a[number-1] == a1[i]) best = i + 1;
        if (a[(number - 1) / 2] == a1[i]) medium = i + 1;
    }
    std::cout << worst << ' ' << medium << ' ' << best;
    inFile.close();
    return 0;
}
