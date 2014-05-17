#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    int n = A.size();
    int sum = 0;
    
    for(int i = 0;i < n;++i)
        sum += A[i];
    
    int ans = abs(2 * A[0] - sum);
    
    for(int i = 0,aux = 0;i < n - 1;++i){
        aux += A[i];
        ans = min(ans,abs(2 * aux - sum));
    }
    
    return ans;
}
