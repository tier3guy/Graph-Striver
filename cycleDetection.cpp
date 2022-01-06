#include <bits/stdc++.h>
using namespace std;

// Detection using BFS 
bool cycleBFS(int i, vector<int> &visting, vector<int> adjList[]){
  queue<pair<int,int>> q;
  q.push(make_pair(i,-1)); visting[i] = 1;

  while(!q.empty()){
    pair<int,int> node = q.front(); q.pop();
    int value = node.first; int parent = node.second;

    for(auto it : adjList[value]){
      if(visting[it] == 1){
        if(it == parent) continue; 
        else return true;
      }
      else{
        q.push(make_pair(it, value));
        visting[it] = 1;
      }
    }
  }

  return false;
}


// Detection using DFS 
bool cycleDFS(int i, int parent, vector<int> &visting, vector<int> adjList[]){
  visting[i] = 1;
  for(auto it : adjList[i]){
    if(visting[it] == 1){
      if(it == parent) continue;
      return true;
    }
    else{
      if(cycleDFS(it, i, visting, adjList)) return true;
    }
  }
  return false;
}

int main(void){

  int N, E; cin >> N >> E;
  vector<int> adjList[N]; // creating the adj list 
  vector<int> visting(N,0); // visting array

  for(int i=0; i<E; i++){
    int u, v; cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  bool flag = true;
  for(int i=0; i<N; i++){
    if(!visting[i]){
      if(cycleDFS(i, -1, visting, adjList)){
        flag = false;
        cout << "Cycle detected" << endl;
        break;
      }
    }
  }
  if(flag){
    cout << "Cycle not found" << endl;
  }

  return 0;
}