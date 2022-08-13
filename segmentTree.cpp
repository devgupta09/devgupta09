#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
const int M = 1e9+7;

class SGTree{
public: 
    vector<ll>seg;

    SGTree(ll n){
        seg.resize(4*n +1);
    }

    void build(ll idx,ll start,ll end,vector<ll>&arr){
    if(start==end){
        seg[idx]=arr[start];
        return ;
    }
    ll mid=(end + start)/2;
    build(2*idx +1,start,mid,arr);
    build(2*idx +2,mid+1,end,arr);
    seg[idx]=min(seg[2*idx +1],seg[2*idx +2]);
    }

    ll query(ll idx,ll start,ll end,ll l,ll r){
        if(r<start || l>end){
            return INT_MAX;
        }
        if(l<=start and r>=end){
            return seg[idx];
        }
        ll mid=(start+end)>>1;
        ll left = query(2*idx + 1,start,mid,l,r);
        ll right = query(2*idx + 2,mid+1,end,l,r);
        return min(left,right); 
    }

    void update(ll idx,ll start,ll end,ll i,ll val){
        if(start==end){
            seg[idx]=val;
            return;
        }
        ll mid=(start+end)/2;
        if(i<=mid) update(2*idx +1,start,mid,i,val);
        else       update(2*idx +2,mid+1,end,i,val);
        seg[idx] = min(seg[2*idx +1],seg[2*idx +2]);
    }

};

void ans(){
    ll n,q;
    cin>>n;
    SGTree sg1(n);
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sg1.build(0,0,n-1,arr);
    cin>>q;
    while(q--){
        ll type;
        cin>>type;
        if(type==2){
            ll i,val;
            cin>>i>>val;
            sg1.update(0,0,n-1,i,val);
            arr[i]=val;
        }
        else{
            ll l,r;
            cin>>l>>r;
            cout<<sg1.query(0,0,n-1,l,r)<<"\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--){
        ans();
        cout<<'\n';
    }
}
