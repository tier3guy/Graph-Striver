#include <bits/stdc++.h>
using namespace std;

map<int, bool> visted_map;

void bfs(int i, vector<int> adjList[]){
  queue<int> helper_q;
  helper_q.push(i); visted_map[i] = true;

  while(!helper_q.empty()){
    int node = helper_q.front();
    helper_q.pop();

    cout << node << " "; 
    for(auto it : adjList[node]){
      if(!visted_map[it]){
        helper_q.push(it); 
        visted_map[it] = true;
      }
    }
  }
  cout << endl;
}

int main(int argc, char** argv){

  // taking the inputs - 0 based indexing
  int N, E; cin >> N >> E;
  vector<int> adjList[N]; // creating the adj list 

  for(int i=0; i<E; i++){
    int u, v; cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  for(int i =0; i < N; i++) visted_map.insert({i, false});

  // bfs traversal - assuming disconnected graph
  for(int i=0; i<N; i++){
    if(!visted_map[i]){
      bfs(i, adjList);
    }
  }

  return 0;
}