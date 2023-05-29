#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6;
const int INF = 1e9;

int graph[MAXN][MAXN] = {
    {0, 1, 0, 3, 0,0},    //0
    {1, 0, 2, 0, 0,0},	//1
    {0, 2, 0, 0, 4,0},	//2
    {3, 0, 0, 0, 0,3},	//3
    {0, 0, 4, 0, 0,0},		//4
    {0, 0, 0, 3, 0,0}
};


void best_first_search(int baslangic, int hedef)
{
    vector<bool> visited(MAXN, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  

    
    pq.push(make_pair(0, baslangic));
    int s = baslangic;
    visited[s] = true;
    int cost = 0;
    int i=0;
    while (!pq.empty()) {
        int x = pq.top().second;
        cost += pq.top().first;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq_kopya= pq;
        cout<<"liste:";
        while (!pq_kopya.empty()) {
   		  cout<< pq_kopya.top().second<<"-"; 
  		  pq_kopya.pop();
		}	cout<<endl;
	
        pq.pop();
        if (x == hedef) {
            cout << x << " (toplam maliyet: " << cost << ")" << endl;
            break;
        }
        cout << x << " (maliyet: " << cost << ") -> ";
		
        for (int i = 0; i < MAXN; i++) {
            if (graph[x][i] != 0 && !visited[i]) {
                visited[i] = true;
                pq.push(make_pair(graph[x][i], i));
            }
        }
    }
}


int main()
{
    int baslangic = 0;
    int hedef = 5;

    best_first_search(baslangic, hedef);

    return 0;
}

