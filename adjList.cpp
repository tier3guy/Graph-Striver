#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){

  int N, E; cin >> N >> E;
  vector<int> adjList[N]; // creating the adj list 

  for(int i=0; i<E; i++){
    int u, v; cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  for(int i=0; i<N; i++){
    cout << i << " -> ";
    for(int j=0; j<adjList[i].size(); j++){
      cout << adjList[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}