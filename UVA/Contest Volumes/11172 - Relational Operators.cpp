#include <iostream>

using namespace std;

int main()
{
    
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(a<b) cout<<"<"<<endl;
        else if(a>b) cout<<">"<<endl;
        else cout<<"="<<endl;
    }


    system("pause");
    return 0;
}
