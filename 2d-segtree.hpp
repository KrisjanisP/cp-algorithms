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
        if(right==nullptr) right = new SegTreeNode(m+1,r,0);
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
        root->increment(x);
    }
    ll query(ll x_min, ll x_max) {
        return root->query(x_min,x_max);
    }
};

struct TwoDSegTreeNode {
    ll x_min, x_max, y_min, y_max;
    SegmentTree* st;
    TwoDSegTreeNode *left, *right;
    TwoDSegTreeNode(ll x_min, ll x_max, ll y_min, ll y_max) {
        st = new SegmentTree(x_min, x_max);
        left = nullptr;
        right = nullptr;
    }
    ~TwoDSegTreeNode(){
        delete left;
        delete right;
        delete st;
    }
    void spread() {
        if(left==nullptr) left = new TwoDSegTreeNode(x_min,x_max,y_min,(y_min+y_max)/2);
        if(right==nullptr) right = new TwoDSegTreeNode(x_min,x_max,(y_min+y_max)/2+1,y_max);
    }
    void increment(ll x, ll y) {
        if(y_min>y||y_max<y) return;
        st->increment(x);
        if(y_min==y_max) return;
        spread();
    }
    ll query(ll q_x_min, ll q_x_max, ll q_y_min, ll q_y_max){
        if(y_min>q_y_max||y_max<q_y_min) return 0;
        if(y_min>=q_y_min&&y_max<=q_y_max) return st->query(q_x_min,q_x_max);
        ll m = (y_min+y_max)/2;
        spread();
        ll l_res = left->query(q_x_min, q_x_max, q_y_min, m);
        ll r_res = left->query(q_x_min, q_x_max, m+1, q_y_max);
        return l_res + r_res;
    }
};

class TwoDSegTree {
    TwoDSegTreeNode* root;
public:
    TwoDSegTree(ll x_min, ll x_max, ll y_min, ll y_max) {
        root = new TwoDSegTreeNode(x_min,x_max,y_min,y_max);
    }
    ~TwoDSegTree(){
        delete root;
    }
    void increment(ll x,ll y){
        root->increment(x,y);
    }
    ll query(ll x_min, ll x_max, ll y_min, ll y_max){
        return root->query(x_min,x_max,y_min,y_max);
    }
};