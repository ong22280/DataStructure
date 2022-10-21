#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

    private:
        vector<int> parent;
        vector<int> size;

    public:
    
        DisjointSet(int n) {
            parent.resize(n);   // parent[i] = i
            size.resize(n); // size[i] = 1
            for (int i = 0; i < n; i++) {
                parent[i] = i;  // Initially, all elements are in their own set
                size[i] = 1;    // Initially, all sets have size 1
            }
        }

        void makeSet(int x) {
            parent[x] = x;
            size[x] = 1;
        }

        int find(int x) {
            if (x != parent[x]) // If x is not the parent of itself
                parent[x] = find(parent[x]);
            return x;
        }

        void unite(int x, int y) {
            int r = find(x);
            int s = find(y);
            if (r == s) return;
            else if (size[r] > size[s]) {
                parent[s] = r;  // Make r the parent of s
                size[r] = size[r] + size[s];
            } else {
                parent[r] = s;  // Make s the parent of r
                size[s] = size[r] + size[s];
            }
        }
        
        bool same(int x, int y) {
            return find(x) == find(y);  // If x and y have the same parent, they are in the same set
        }
};