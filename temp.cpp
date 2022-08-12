#include<iostream>
using namespace std;
int r,c;
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};



void flood_fill(char graph[][50], int i, int j, char ch, char color){
  
  if(i<0|| j<0|| i>=r|| j>=c){         //graph boundaries
    return;
  }
  
  if(graph[i][j]!= ch){                      //figure boundary
    return;
  }
  
  graph[i][j]= color;                  //make that ch into color
  for(int k=0;k<4;k++){                 //then rec call for 4 directions
    flood_fill(graph,i+dx[k],j+dy[k],ch,color);
  }
  
}
int main(){
  

  cin>> r,c;
  
  char graph[15][50];
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin>> graph[i][j]; 
    }
  }
  
  flood_fill(graph,6,5,'.','@');             
    for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cout<< graph[i][j]; 
    }
    cout<<endl;
  }
  return 0;
}