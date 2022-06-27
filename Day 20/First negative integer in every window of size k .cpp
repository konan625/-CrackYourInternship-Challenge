Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
//Brute TC O(N*K)
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        int i=0,j=0;
        vector<long long> v;
        vector<long long > ans;
        while(j<N){
            v.push_back(A[j]);
            if(v.size()<K){
                j++;
            }
            else if(v.size()==K){
                for(long long l=0;l<K;l++){
                    if(v[l]<0){
                        ans.push_back(v[l]);
                        break;
                    }
                    if(l==K-1){
                        ans.push_back(0);
                    }
                }
                v.erase(v.begin());
                i++;
                j++;
            }
        }
        return ans;
                                                 
 }

 //Optimise TC- O(N) , SC O(K)
 vector<long long> printFirstNegativeInteger(long long int Arr[],
                                             long long int N, long long int K) {
        int i=0,j=0;
        vector<long long > ans;
        queue<long long> q;
        while(j<N){
            if(Arr[j]<0){
                q.push(Arr[j]);
            }
            if(j-i+1<K){
                j++;
            }
            else if(j-i+1==K){
                if(q.size()){
                    ans.push_back(q.front());
                    if(q.front()==Arr[i]){
                        q.pop();
                    }
                }else{
                    ans.push_back(0);
                }
                
                i++;
                j++;
            }
        }
        return ans;
 }