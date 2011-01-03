#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[50][50];
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};
int x;
int y;
vector<string> v;

int dfs(int a,int b)
{
    visited[a][b]=true;
    int cont=1;
    int I,J;
    for(int i=0;i<4;i++)
    {
        I=a+di[i];
        J=b+dj[i];
        
        if(I>=0 && J>=0 && I<x && J<y && v[a][b]==v[I][J] && !visited[I][J]) cont+=dfs(I,J);
        
    }
    
    return cont;
}

int main()
{    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    
    vector<char> v1;
    vector<int> v2;
    
    int cont=1;
    
    while(true)
    {
        cin>>x>>y;
        if(x==0 && y==0) break;
        
        cout<<"Problem "<<cont<<":"<<endl;
        cont++;
                
        v.clear();
        
        for(int i=0;i<x;i++)
        {
            cin>>s;
            v.push_back(s);
        }
        memset(visited,false,sizeof(visited));
        
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(v[i][j]=='.') visited[i][j]=true;
            }
        }
        v1.clear();
        v2.clear();
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(!visited[i][j])
                {
                    v1.push_back(v[i][j]);
                    v2.push_back(dfs(i,j));
                }
            }
        }
        int n=v1.size();
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(v2[i]<v2[j])
                {
                    swap(v2[i],v2[j]);
                    swap(v1[i],v1[j]);
                }else if(v2[i]==v2[j])
                {
                    if(v1[i]>v1[j])
                    {
                        swap(v1[i],v1[j]);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
            cout<<v1[i]<<" "<<v2[i]<<endl;
        
    }


    return 0;
}
