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
// int findfreq(vector<int>& v1,int num){
//   int count=0;
//   for(int x:v1){
//     if(x==num) count++;
//   }
//   return count;
// }
void solve() {
  // int n,k;cin>>n>>k;
  // vector<int> v1(n);
  // map<int,int> m;
  // for(int i=0;i<n;i+=5){
  //       v1[i]=i+1;
  //       if(i+1<n) v1[i+1]=i+1;m[i+1]++;
  //       if(i+2<n) v1[i+2]=i+1;m[i+1]++;
  //       if(i+3<n) v1[i+3]=i+1;m[i+1]++;
  //       if(i+4<n) v1[i+4]=i+1;m[i+1]++;
  // }
  // v1[k-1]=0;
  // int end=n/5;
  // if(n%5 != 0) end++;
  // int count=0;
  // int scale=0;
  // for(int i=1;i<=end;i++){
  //   int freq=findfreq(v1,i);
  //   if(m[i]-freq!=0) scale=i;
  //   count+=(m[i]-freq);
  // }
  // cout<<count*(end-scale)<<endl;
  int n,x;cin>>n>>x;
  vector<char> v1(n);
  if(n<=x && n!=1 && x!=1) cout<<-1<<endl;
  int start=1;
  int i=0;
  char t='a';
  while(start<=x){
    v1[i]=v1[n-i-1]=t-start-1;
    start++;
    i++;
  }
  string s="";
  for(char c:v1){
    s+=c;
  }
  cout<<s<<endl;
  
  
  
  
    
}

int32_t main() {

    c_p_c();
    tc
    solve();
    return 0;
}