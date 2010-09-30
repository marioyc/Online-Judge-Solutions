#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <ctime>

using namespace std;

class DivisorInc
{
public:
	int countOperations(int N, int M)
	{
		bool visited[100001];
		fill(visited,visited+100001,false);
				
		queue< pair<int,int> > Q;
		Q.push(make_pair(N,0));
		visited[N]=true;
		
		while(!Q.empty()){
			int aux=Q.front().first;
			int cont=Q.front().second;
			Q.pop();
			
			if(aux==M) return cont;
			
			for(int i=2;i*i<=aux;i++)
				if(aux%i==0){
					if(aux+i<=M && !visited[aux+i]){
						Q.push(make_pair(aux+i,cont+1));
						visited[aux+i]=true;
					}
					if(aux+aux/i<=M && !visited[aux+aux/i]){
						Q.push(make_pair(aux+aux/i,cont+1));
						visited[aux+aux/i]=true;
					}
				}
		}
		
		return -1;
	}
};
