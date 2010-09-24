#include <vector>
#include <sstream>
#include <iostream>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T;
    cin>>T;
    
    string s;
    int ax,n1,n2;
    vector<int> v;
    vector<int> a;
    vector<int> b;
    
    getline(cin,s);
    for(int i=0;i<T;i++){
        getline(cin,s);
        istringstream is(s);
        
        v.clear();
        
        while(is>>ax) v.push_back(ax);
        
        for(int mask=1;mask<(1<<(v.size()));mask++){
            a.clear();
            b.clear();
            for(int j=0;j<v.size();j++){
                if((mask & (1<<j))!=0) a.push_back(v[j]);
                else b.push_back(v[j]);
            }
            
            sort(a.rbegin(),a.rend());
            sort(all(b));
                        
            n1=0;            
            for(int j=a.size()-1;j>=0;j--) n1=n1*10+a[j];
            
            n2=0;            
            for(int j=b.size()-1;j>=0;j--) n2=n2*10+b[j];
            
            cout<<n1<<" "<<n2<<" "<<abs(n1-n2)<<endl;
            
            reverse(a.begin(),a.end());
            
            n1=0;            
            for(int j=a.size()-1;j>=0;j--) n1=n1*10+a[j];
            
            n2=0;            
            for(int j=b.size()-1;j>=0;j--) n2=n2*10+b[j];
            
            cout<<n1<<" "<<n2<<" "<<abs(n1-n2)<<endl;
        }
    }
    

    return 0;
}
