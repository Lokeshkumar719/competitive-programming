#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"

bool bfs(int sx,int sy,
         vector<vector<char>>&v,
         vector<vector<bool>>&vis,
         vector<vector<pii>>&par,
         vector<vector<char>>&dir,
         int &fx,
         int &fy){

  int n=v.size();
  int m=v[0].size();

  queue<pii>q;

  q.push({sx,sy});
  vis[sx][sy]=true;

  int dx[4]={1,-1,0,0};
  int dy[4]={0,0,1,-1};

  char move[4]={'D','U','R','L'};

  while(!q.empty()){

    int x=q.front().first;
    int y=q.front().second;
    q.pop();

    for(int d=0;d<4;d++){

      int nx=x+dx[d];
      int ny=y+dy[d];

      if(nx>=0 && nx<n &&
         ny>=0 && ny<m &&
         !vis[nx][ny] &&
         v[nx][ny]!='#'){

        vis[nx][ny]=true;

        par[nx][ny]={x,y};

        dir[nx][ny]=move[d];

        if(v[nx][ny]=='B'){
          fx=nx;
          fy=ny;
          return true;
        }

        q.push({nx,ny});
      }
    }
  }

  return false;
}

void solve(){

  int n,m;
  cin>>n>>m;

  vector<vector<char>>v(n,vector<char>(m));

  int sx,sy;
  int fx,fy;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

      cin>>v[i][j];

      if(v[i][j]=='A'){
        sx=i;
        sy=j;
      }

      if(v[i][j]=='B'){
        fx=i;
        fy=j;
      }
    }
  }

  vector<vector<bool>>vis(n,vector<bool>(m,false));

  vector<vector<pii>>par(n,vector<pii>(m));

  vector<vector<char>>dir(n,vector<char>(m));

  bool found=bfs(sx,sy,v,vis,par,dir,fx,fy);

  if(!found){
    cout<<"NO"<<endl;
    return;
  }

  string path;

  while(make_pair(fx,fy)!=make_pair(sx,sy)){

    path.push_back(dir[fx][fy]);

    pii p=par[fx][fy];

    fx=p.first;
    fy=p.second;
  }

  reverse(path.begin(),path.end());

  cout<<"YES"<<endl;
  cout<<path.size()<<endl;
  cout<<path<<endl;
}

int main(){

  fastio;

  int t=1;

  while(t--){
    solve();
  }

  return 0;
}