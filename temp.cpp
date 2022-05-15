#include<iostream>
#include<queue>
using namespace std;
class node{
  public:
    int data;
    node* left;
    node* right;
    node(int d){
    data=d;
    left= NULL;
    right =NULL;  
    }
};

node* buildtreearr(int *a,int s,int e){
  if(s>e){
    return NULL;
    
  }
  int mid= s+((e-s)/2);
  node*root = new node(a[mid]);
  root->left= buildtreearr(a,s,mid-1);
  root->right=buildtreearr(a,mid+1,e);
  
  return root;
}
int height(node* root){
  if(root==NULL){
    return 0;
  }
  int h1= height(root->left);
  int h2= height(root->right);
  return max(h1,h2)+1;
}
void printlevelk(node* root, int k){
  if(root==NULL){
    return;
  }
  if(k==0) return;
  if(k==1){
    cout<< root->data << " ";
  return;
  }
  printlevelk(root->left,k-1);
  printlevelk(root->right,k-1);
  return;
}
int printatdistk(node*root, node* target, int k){
  if(root==NULL){
    return -1;
  }
  
  if(root==target){
    printlevelk(target,k);
    return 0;
  }
  int DL= printatdistk(root->left,target,k);
  if(DL!=-1){
    if(DL+1==k){
      cout<<root->data<<" ";
    }else{
      printlevelk(root->right,k-DL-2);
      
    }
    return 1+DL;
  }
    int DR= printatdistk(root->right,target,k);
  if(DR!=-1){
    if(DR+1==k){
      cout<<root->data<<" ";
    
      
    }else{
      printlevelk(root->left,k-DR-2);
      
    }
    return 1+DR;
  }
  return -1;
}
void bfs(node*root){
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty( )){
    node* f= q.front();
    if(f==NULL){
      cout<<endl;
      q.pop();
      if(!q.empty()){
        q.push(NULL);
      }
    }else{
    
    cout<< f->data<< " ";
    q.pop();
    if(f->left){
      q.push(f->left);
    }
    if(f->right){
      q.push(f->right);
    }
  }
}
}
int main(){
int a[]={1,2,3,4,5,6,7};
int n= sizeof(a)/sizeof(int);
node*root=buildtreearr(a,0,n-1);

  bfs(root);
    node* target= root->left;
  cout<< printatdistk(root,target,3);
}