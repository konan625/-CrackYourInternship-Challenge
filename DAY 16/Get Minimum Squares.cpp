Given a number N. Find the minimum number of squares of any number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).
int MinSquares(int n)
	{
	    // Code here
	    if(n==0 || n==1 || n==2 || n==3) return n;
	    int ans=INT_MAX;
	    for(int i=1;i*i<=n;i++){
	        ans=min(ans,1+MinSquares(n-(i*i)));
	    }
	    return ans;
	   
	}

//Memoization
	int helper(int n,vector<int>& t){
	    //base casae
	    if(n==0 || n==1 || n==2 || n==3) return n;
	    if(t[n]!=-1) return t[n];
	    int ans=INT_MAX;
	    for(int i=1;i*i<=n;i++){
	        t[n]=ans=min(ans,1+helper(n-(i*i),t));
	    }
	    return t[n]=ans;
	}
	int MinSquares(int n)
	{
	   vector<int> t(n+1,-1);
	   return helper(n,t);
	   
	}

//Tabulisation
int MinSquares(int n)
	{
	   vector<int> t(n+1,INT_MAX);
	   t[0]=0;
	   t[1]=1;
	   t[2]=2;
	   t[3]=3;
	   for(int i=4;i<=n;i++){
	       //int ans=INT_MAX;
	       for(int j=1;j*j<=i;j++){
	           t[i]=min(t[i],1+t[i-(j*j)]);
	       }
	   }
	   return t[n];
	}