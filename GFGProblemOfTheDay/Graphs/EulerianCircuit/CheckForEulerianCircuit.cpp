// Time  Complexity : O(V)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1

class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    int evenCount = 0;
	    for(int i = 0; i < v; i++) {
	        if(adj[i].size() % 2 == 0)
	            evenCount++;
	    }
	    
	    return evenCount == v;
	}

};