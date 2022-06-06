#include <iostream>
long long partition(int n, int k);

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << partition(n, k);
}

long long partition(int n, int k) {
    long long** arr=new long long*[2];
    for(int i=0;i<2;++i){
        arr[i]=new long long[n];
    }
    for(int i=0;i<n;++i){
        arr[0][i]=1;
    }
    int swap=0; int kk=1;
    for(int i=0;i<k-1;++i){
        if(swap==1) swap=0;
        else swap=1;
        for(int j=0;j<n;++j){
            if(j==kk) arr[swap][j]=1;
            else if(kk>j) arr[swap][j]=0;
            else arr[swap][j]=arr[swap][j-kk-1]+arr[abs(swap-1)][j-1];
        }
        ++kk;
    }
    long long res=arr[swap][n-1];
    for(int i=0;i<2;++i) delete[] arr[i];
    delete[] arr;
    return res;
}
