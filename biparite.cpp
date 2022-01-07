#include <bits/stdc++.h>
using namespace std;

bool checkBipartiteBFS(int i, int color, vector<int> &visting, vector<int> adjList[]){
	
	queue<int> q; q.push(i); visting[i] = color;
	while(!q.empty()){
		int node = q.front(); q.pop();
		for(auto it : adjList[node]){
			if(visting[it] == -1){
				visting[it] = !color;
				q.push(it);
			} 
			else{
				if(visting[it] == color) return false;
			}
		}
		color = !color;
	}
	return true;
}


bool checkBipartiteDFS(int i, int color, vector<int> &visting, vector<int> adjList[]){
	
	visting[i] = color;

	for(auto it : adjList[i]){
		if(visting[it] == -1){
			if(checkBipartiteDFS(it, !color, visting, adjList) == false) return false;
		} 
		else{
			if(visting[it] == color) return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]){
	
	int N, E; cin >> N >> E;
	
	vector<int> adjList[N]; // again assuming 0 based indexing
	
	for(int i=0; i<E; i++){
		int u, v; cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	vector<int> visting(N,-1);

	bool flag = true;
	for(int i=0; i<N; i++){
		if(visting[i] == -1){
			if(checkBipartiteDFS(i, 0, visting, adjList) == false) flag = false; 
		}
	}
	if(flag){
		cout << "Bipartite check returns positive.";
	}
	else{
		cout << "Not a Bipartite." << "\n";
	}

	return 0;
}