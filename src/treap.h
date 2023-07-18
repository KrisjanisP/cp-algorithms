#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct Node
{
    ll k, o; // key and order
    ll sz; // size of the subtree
    Node *l, *r; // left and right
    bool flip;
    Node(ll x)
    {
        k = x;
        o = rnd();
        sz = 1;
        l = r = nullptr;
        flip = false; 
    }
};

ll size(Node* n)
{
    if(n) return n->sz;
    else return 0;
}

void push(Node *n)
{
    if(n==nullptr) return;
    if(n->flip)
    {
        if(n->l) n->l->flip = !n->l->flip;
        if(n->r) n->r->flip = !n->r->flip;
        swap(n->l, n->r);
        n->flip = 0;
    }
}

// x belongs to [1;n]
pair<Node*, Node*> split(Node* t, ll x)
{
    if(t==nullptr) return {nullptr,nullptr};
    push(t);
    ll szl = size(t->l), szr = size(t->r);
    if(szl>=x)
    {
        auto [a,b] = split(t->l,x);
        t->l = b;
        t->sz = size(t->l) + size(t->r) + 1;
        return {a,t};
    }
    else
    {
        auto [a,b] = split(t->r,x-szl-1);
        t->r = a;
        t->sz = size(t->l) + size(t->r) + 1;
        return {t,b};
    }
}

Node* merge(Node *a, Node *b)
{
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    push(a);
    push(b);
    if((a->o)>(b->o))
    {
        a->r = merge(a->r,b);
        a->sz = size(a->l)+size(a->r)+1;
        return a;
    }
    else
    {
        b->l = merge(a,b->l);
        b->sz = size(b->l)+size(b->r)+1;
        return b;
    }
}

void reverse(Node *t)
{
    if(t==nullptr) return;
    t->flip = !t->flip;
}