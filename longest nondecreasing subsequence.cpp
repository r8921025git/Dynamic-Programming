#include <iostream>
#include <vector>
#include <algorithm> //!!!!!!!!!!!

using namespace std;
using std::vector;

vector<int> longest(const vector<int>& A) {
    vector<int> R, From;
    const int N = A.size();
    R.resize(N);
    From.resize(N);
    for (int i=0; i<N; ++i) {
        R[i]=1;
        From[i]=-1;
        for (int j=0; j<i; ++j) {
            if (A[j]<=A[i]) {
                if (R[j]+1>=R[i]) {
                    R[i] = R[j]+1;
                    From[i] = j;
                }
            }
        }
    }
    int maxLen = 0;
    int last_i = -1;
    for (int i=0; i<N; ++i) {
        if (R[i]>maxLen) {
            last_i = i;
            maxLen = R[i];
        }
    }
    vector<int> longest_seq;
    longest_seq.push_back(A[last_i]);
    int prev_i = From[last_i];
    while(prev_i >=0) {
        longest_seq.push_back(A[prev_i]);
        prev_i = From[prev_i];
    }
    std::reverse(longest_seq.begin(),longest_seq.end());
    printf("maxLen=%d, last_i=%d\n",maxLen, last_i);
    return longest_seq;
}

int main()
{
   
   vector<int> A = {5,3,2,7,3,4,8};
   vector<int> longest_seq = longest(A);
   printf("longest subseq:\n");
   for (auto &i:longest_seq) {
       printf("%d ",i);
   }
   printf("\n");
   return 0;
}

