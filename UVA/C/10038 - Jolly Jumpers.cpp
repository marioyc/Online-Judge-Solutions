#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2;
    vector<int>::iterator it;
    int v;
    int q;
  
    while(cin>>q)
    {
        v1.clear();
        v2.clear();
        for(int i=0; i<q; ++i)
        {
            cin>>v;
            v1.push_back(v);
            v2.push_back(0);
        }
        v2[0]=1;
        for(int i=0; i<q-1; ++i)
        {
            v=abs(v1[i+1]-v1[i]);
            if(v>0&&v<q)
            v2[v]=1;
        }

        it=find(v2.begin(),v2.end(),0);
        if(it==v2.end())
            cout<<"Jolly"<<endl;
        else
        cout<<"Not jolly"<<endl;
    }
  
    return 0;
}
