#include<iostream>
#include<iomanip>

using namespace std;

int main(){    
    int n[]={6,35,204,1189,6930,40391,235416,1372105,7997214,46611179};
    int m[]={8,49,288,1681,9800,57121,332928,1940449,11309768,65918161};
    
    for(int i=0;i<10;i++)
        cout<<setw(10)<<n[i]<<setw(10)<<m[i]<<endl;
    
    return 0;
}
