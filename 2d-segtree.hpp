#pragma once

using ll = long long;

struct SegTreeNode {
    ll l, r, val;
    SegTreeNode *left, *right;
    SegTreeNode(ll l, ll r, ll val){
        this->l = l;
        this->r = r;
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
    ~SegTreeNode(){
        delete left;
        delete right;
    }
    void spread() {
        if(l==r) return;
        ll m = (l+r)/2;
        if(left==nullptr) left = new SegTreeNode(l, m, 0);
        else right = new SegTreeNode(m+1,r,0);
    }
    ll query(ll ql, ll qr) {
        if(l>=ql&&r<=qr) return val;
        if(l>qr||r<ql) return 0;
        ll m = (l+r)/2; spread();
        return left->query(ql,m) + right->query(m+1,qr);
    }
    void increment(ll i) {
        if(l>i||r<i) return;
        val++;
        if(l==r) return;
        ll m = (l+r)/2; spread();
        left->increment(i);
        right->increment(i);
    }
};

struct SegmentTree {
    SegTreeNode* root;
    SegmentTree(ll x_min, ll x_max){
        root = new SegTreeNode(x_min, x_max, 0);
    }
    ~SegmentTree(){
        delete root;
    }
    void increment(ll x) {

    }
    ll query(ll x_min, ll x_max) {
        return 0;
    }
};

struct TwoDSegTreeNode {
    ll x_min, x_max, y_min, y_max;
    SegmentTree* st;
    TwoDSegTreeNode(ll x_min, ll x_max, ll y_min, ll y_max) {
        st = new SegmentTree(x_min, x_max);
    }
    ~TwoDSegTreeNode(){
        delete st;
    }
};

class TwoDSegTree {
    TwoDSegTreeNode* root;
public:
    TwoDSegTree(ll x_min, ll x_max, ll y_min, ll y_max) {

    }
    void increment(ll x,ll y){

    }
    ll query(ll x_min, ll x_max, ll y_min, ll y_max){

    }
};