#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    vector<int>segmentTree;
    int n;
public:
    SegmentTree(int sz){
        n = sz; 
        segmentTree.resize(4*n,0);
    }

    void build(vector<int> &v){
        buildSegmentTree(0, 0, n-1, v);
    }

    int query(int l, int r){
       return querySegmentTree(0, 0, n-1, l, r);
    }

    void update(int idx, int val){
        updateSegmentTree(0, 0, n-1, idx, val);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& v){
        if(l == r){
            segmentTree[i] = v[l];
            return;
        }

        int mid = (l + r)/2;
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;

        buildSegmentTree(leftChild, l, mid, v);
        buildSegmentTree(rightChild, mid+1, r, v);
        
        segmentTree[i] = segmentTree[leftChild] + segmentTree[rightChild];
    }

    int querySegmentTree(int i, int l, int r, int ql, int qr){
        if(ql > r || qr < l) 
            return 0; // identitfy element
        
        if(ql <= l && qr >= r)
            return segmentTree[i];

        int mid = (l+r)/2;
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;
 
        return querySegmentTree(leftChild, l, mid, ql, qr) + querySegmentTree(rightChild, mid+1, r, ql, qr);
    }

    void updateSegmentTree(int i, int l, int r, int qidx, int qVal){

        if(l == r){
            segmentTree[i] = qVal;
            return;
        }

        int mid = (l + r)/2;
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;

        if(qidx <= mid)
            updateSegmentTree(leftChild, l, mid, qidx, qVal);
        else
            updateSegmentTree(rightChild, mid+1, r, qidx, qVal);

        segmentTree[i] = segmentTree[leftChild] + segmentTree[rightChild];
    }
};


int main(){
    vector<int> v = {1, 2, 3, 4, 5};

    SegmentTree st((int)v.size());
    st.build(v);

    cout << st.query(1, 3) << '\n';
    cout << st.query(0,4) << '\n';

    st.update(2, 10);

    cout << st.query(1, 3) << '\n';   
    cout << st.query(0, 4) << '\n';   
}