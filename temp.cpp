#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define f(i,n)          for(int i=0;i<(n);++i)
#define fa(i,a,n)       for(int i=a;i<=(n);++i)
#define fd(i,a,n)       for(int i=a;i>=(n);--i)
#define tc              int t;cin>>t;f(testcase,t)
#define ld              long double

#define pii             pair<int,int>
#define mem(a,i)        memset(a,i,sizeof(a))
#define all(x)          x.begin(),x.end()
#define PI 3.1415926535897932
#define M 1000000007
void c_p_c() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

}
void solve() {
    int n;cin>>n;
    int rem=n%7;
    if(rem%2==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
}

int32_t main() {

    c_p_c();
    tc
    solve();
    return 0;
}