#include <vector>
#include <iostream>

using namespace std;

// https://atcoder.jp/contests/atc001/submissions/70817243

struct UnionFind{
    vector<int> parent;
    UnionFind(int n) : parent(n,-1){ }

    int root(int x){
        if (parent[x] < 0) {
            return x;
        } else {
            parent[x] = root(parent[x]);
            return parent[x];
        }
    }

    int same(int x,int y){
        return root(x) == root(y);
    }

    int size(int x){
        return -parent[root(x)];
    }

    bool marge(int x,int y){
        int xr = root(x),yr = root(y);
        if (xr == yr){
            return false;
        }
        if (parent[xr] <= parent[yr]){
            parent[xr] += parent[yr];
            parent[yr] = xr;
        } else {
            parent[yr] += parent[xr];
            parent[xr] = yr;
        }
        return true;
    }

    void print(){
      cout << "{";
        for (int i = 0; i < parent.size(); i++){
            cout << parent[i] << ", ";
        }
      cout << "}" << "\n";
    }
};