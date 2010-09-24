/*
ID:zion_ba1
LANG:C++
TASK:frac1
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct fraction{
    int num,dem;
    
    fraction(const int _num, const int _dem){
        num=_num;
        dem=_dem;
    }
    
    bool operator < (const fraction &X) const{
        return num*X.dem<dem*X.num;
    }
};

int main(){
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    
    int N;
    vector<fraction> v;
    
    scanf("%d",&N);
    
    v.push_back(fraction(0,1));
    v.push_back(fraction(1,1));
    
    for(int i=2;i<=N;i++)
        for(int j=1;j<i;j++)
            if(__gcd(i,j)==1)
                v.push_back(fraction(j,i));
    
    sort(v.rbegin(),v.rend());
    
    for(int i=v.size()-1;i>=0;i--) printf("%d/%d\n",v[i].num,v[i].dem);
    
    return 0;
}
