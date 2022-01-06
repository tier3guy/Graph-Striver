#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){

  int N, E; cin >> N >> E; 
  int adjMatrix[N][N]; // Assuming 0 based indexing

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      adjMatrix[i][j] = 0;
    }
  }

  for(int i=0; i<E; i++){
    int u, v; cin >> u >> v;
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
  }

  cout << endl << "Matrix" << endl;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout << adjMatrix[i][j] << " ";
    } cout << endl;
  }

  return 0;
}