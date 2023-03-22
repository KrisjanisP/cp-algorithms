#include <iostream>
#include <cassert>
#include "2d-segtree.hpp"

using namespace std;
using ll = long long;

ll sum(ll a[], ll l, ll r) {
    ll result = 0;
    for(int i=l;i<=r;i++)
        result += a[i];
    return result;
}

bool testSegTree() {
    const ll SZ = 23;
    SegmentTree* st = new SegmentTree(0,SZ-1);
    ll a[SZ] = {};
    for(int i=0;i<1000;i++){
        if(rand()%2==0){
            ll l = rand()%SZ;
            ll r = rand()%SZ;
            cout<<"querying "<<l<<" "<<r<<endl;
            ll st_sum = st->query(l,r);
            ll a_sum = sum(a,l,r);
            assert(st_sum==a_sum);
            cout<<l<<" "<<r<<" sum ok"<<endl;
        } else {
            ll j = rand()%SZ;
            cout<<"incrementing "<<j<<endl;
            st->increment(j);
            cout<<j<<" incremented"<<endl;
        }
    }
    return true;
}

int main() {
    assert(testSegTree());
}