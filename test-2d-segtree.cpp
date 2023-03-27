#include <iostream>
#include <cassert>
#include <cstring>
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
    for(int i=0;i<10000;i++){
        if(rand()%2==0){
            ll l = rand()%SZ;
            ll r = rand()%SZ;
            cout<<"querying "<<l<<" "<<r<<endl;
            ll st_sum = st->query(l,r);
            ll a_sum = sum(a,l,r);
            if(st_sum!=a_sum){
                cout<<"st sum: "<<st_sum<<endl;
                cout<<"a sum: "<<a_sum<<endl;
                cout<<"seg tree: "; st->print();
                return false;
            }
            cout<<l<<" "<<r<<" sum ok"<<endl;
        } else {
            ll j = rand()%SZ;
            cout<<"incrementing "<<j<<endl;
            a[j]++;
            st->increment(j);
            cout<<j<<" incremented"<<endl;
        }
    }
    return true;
}

bool test2DSegTree() {
    const ll SZ = 3;
    TwoDSegTree* st = new TwoDSegTree(0,SZ-1,0,SZ-1);
    ll matrix[SZ][SZ];
    memset(matrix,0,sizeof(matrix));
    for(int i=0;i<1000;i++){
        if(rand()%2==0){
            ll b = rand()%SZ;
            ll t = rand()%SZ;
            ll l = rand()%SZ;
            ll r = rand()%SZ;
            cout<<"querying "<<l<<" "<<r<<" "<<b<<" "<<t<<endl;
            ll st_sum = st->query(l,r,b,t);
            ll a_sum = 0;
            for(int j=l;j<=r;j++){
                for(int k=b;k<=t;k++){
                    a_sum += matrix[j][k];
                }
            }
            if(st_sum!=a_sum){
                cout<<"st sum: "<<st_sum<<endl;
                cout<<"a sum: "<<a_sum<<endl;
                cout<<"seg tree: "<<endl; st->print(); cout<<endl;
                assert(st_sum==a_sum);
            }
            cout<<l<<" "<<r<<" "<<b<<" "<<t<<" sum ok"<<endl;
        } else {
            ll x = rand()%SZ;
            ll y = rand()%SZ;
            cout<<"incrementing "<<x<<" "<<y<<endl;
            matrix[x][y]++;
            st->increment(x,y);
            cout<<x<<" "<<y<<" incremented"<<endl;
        }
    }
    return true;
}

int main() {
    assert(testSegTree());
    assert(test2DSegTree());
}