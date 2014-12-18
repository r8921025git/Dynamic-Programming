#include <iostream>
#include <vector>
using namespace std;
using std::vector;

vector<int> longest(const vector<int>& A) {
    vector<int> R;
    const int N = A.size();
    R.resize(N);
    for (int i=0; i<N; ++i) {
        R[i]=1;
        for (int j=0; j<i; ++j) {
            if (A[j]<=A[i]) {
                if (R[j]+1>=R[i]) {
                    R[i] = R[j]+1;
                }
            }
        }
    }
    int maxLen = 0;
    for (int i=0; i<N; ++i) {
        if (R[i]>maxLen) {
            maxLen = R[i];
        }
    }
    printf("maxLen=%d\n",maxLen);
    return R;
}

int main()
{
   
   vector<int> A = {5,3,2,7,1,4,8};
   vector<int> R = longest(A);
   
   return 0;
}

