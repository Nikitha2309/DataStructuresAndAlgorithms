#include <bits/stdc++.h>
using namespace std;

void addEdge_AdjMatrix(vector<vector<int>> &adjMatrix,int src, int dest)
{
     adjMatrix[src][dest] = 1;
     adjMatrix[dest][src] = 1;
}

void print_AdjMatrix(vector<vector<int>> adjMatrix, int V)
{
     cout<<"ADJACENCY MATRIX:\n";
     int i, j;

     for(i = 1; i <= V; i++)
     {
         for(j = 1; j <= V; j++)
         {
             cout<<adjMatrix[i][j]<<" ";
         }
         cout<<endl;
     }
     cout<<endl;
}

void addEdge_AdjList(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print_AdjList(vector<int> adj[], int V)
{
    cout<<"ADJACENCY LIST:\n";
    for (int v = 1; v <= V; ++v) {
        cout << "Adjacency list of vertex " << v << " :";
        for (auto x : adj[v])
            cout << " " << x;
        cout<<endl;
    }
    cout<<endl;
}

void bfs(int s,vector<int>adj[],int V)
{
  cout<<"BFS TRAVERSAL : ";
  queue<int>q;//queue in STL
  q.push(s);
  vector<bool> visit(V+1,false);
  visit[s]=true;
  while(!q.empty()){
    int u=q.front();
    cout<<u<<" ";
    q.pop();
    //loop for traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        q.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
  cout<<endl<<endl;
}

void dfs(int s,vector<int>adj[],int V)
{
  cout<<"DFS TRAVERSAL : ";
  stack<int>stk;//stack in STL
  stk.push(s);
  vector<bool> visit(V+1,false);
  visit[s]=true;
  while(!stk.empty()){
    int u=stk.top();
    cout<<u<<" ";
    stk.pop();
    //loop for traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        stk.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
  cout<<endl<<endl;
}

void compute_Distances(vector<int> adj[],int V, vector<vector<int>> &D)
{
    for(int i = 1; i<=V; i++)
    {
        D[i][i] = 0;
    }
    for(int i = 1; i<=V; i++)
    {
        for(int j:adj[i])
        {
            D[i][j] = 1;
            D[j][i] = 1;
        }
    }
    for(int k = 1; k<=V; k++)
    {
        for(int i = 1; i<=V; i++)
        {
            for(int j = 1; j<=V; j++)
            {
                D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
            }
        }
    }
}

void print_DistanceMatrix(vector<vector<int>> D, int V)
{
    cout<<"DISTANCES MATRIX :\n";
    for(int i = 1; i<=V; i++)
    {
        for(int j = 1; j<=V; j++)
        {
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void compute_Eccentricity( vector<vector<int>> D,int V, vector<int> &E)
{
    for(int i = 1; i<=V; i++)
    {
        int mx = D[i][1];
        for(int j = 1; j<=V; j++)
            mx = max(mx,D[i][j]);
        E[i] = mx;
    }
    return;
}

void print_Eccentricity(vector<int> E, int V)
{
    cout<<"ECCENTRICITIES : ";
    for(int i = 1; i<=V; i++)
    {
        cout<<E[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}

int compute_Radius(vector<int> E, int V)
{
    int radius = E[1];
    for(int i = 2; i<=V; i++)
        radius = min(radius,E[i]);
    return radius;
}

int compute_Diameter(vector<int> E, int V)
{
    int diameter = E[1];
    for(int i = 2; i<=V; i++)
        diameter = max(diameter,E[i]);
    return diameter;
}

void cycleDfs(vector<int> adj[], vector<bool> &vis, int currLen,int &maxLen,int node, int parent)
{
    for(int u:adj[node])
    {
        if(u==parent)
        {
            maxLen = max(maxLen,currLen+1);
        }
        else if(!vis[u])
        {
            vis[u] = true;
            cycleDfs(adj,vis,currLen+1,maxLen,u,parent);
            vis[u] = false;
        }
    }
}

int compute_Circumference(vector<int> adj[],int V, int node)
{
	vector<bool> vis1(V+1,false);
    int circumference = -1;
    for(int i = 1; i<=V; i++)
    {
        int maxLen = -1;
        vector<bool> vis(V+1,false);
        vis[i] = true;
        cycleDfs(adj,vis,0,maxLen,i,i);
        circumference = max(circumference,maxLen); 
    }
    return circumference;
}

int main()
{
    // Number of Vertices
    int V = 6;
  
    // 1. Represent the graph using Adjacency matrix.
    vector<vector<int>> adjMatrix(V+1,vector<int>(V+1,0));
    addEdge_AdjMatrix(adjMatrix, 1, 2);
    addEdge_AdjMatrix(adjMatrix, 1, 5);
    addEdge_AdjMatrix(adjMatrix, 2, 3);
    addEdge_AdjMatrix(adjMatrix, 2, 4);
    addEdge_AdjMatrix(adjMatrix, 2, 5);
    addEdge_AdjMatrix(adjMatrix, 3, 4);
    addEdge_AdjMatrix(adjMatrix, 3, 6);
    addEdge_AdjMatrix(adjMatrix, 4, 5);
    addEdge_AdjMatrix(adjMatrix, 4, 6);
    addEdge_AdjMatrix(adjMatrix, 5, 6);
    // Print the Adjacency Matrix.
    print_AdjMatrix(adjMatrix,V);

    // 2. Represent the graph using Adjacency list.
    vector<int> adjList[V+1];
    addEdge_AdjList(adjList, 1, 2);
    addEdge_AdjList(adjList, 1, 5);
    addEdge_AdjList(adjList, 2, 3);
    addEdge_AdjList(adjList, 2, 4);
    addEdge_AdjList(adjList, 2, 5);
    addEdge_AdjList(adjList, 3, 4);
    addEdge_AdjList(adjList, 3, 6);
    addEdge_AdjList(adjList, 4, 5);
    addEdge_AdjList(adjList, 4, 6);
    addEdge_AdjList(adjList, 5, 6);
    // Print the Adjacency List.
    print_AdjList(adjList, V);

    // 3. Implement the BFS to print all elements.
    bfs(1,adjList,V);

    // 4. Implement the DFS to print all elements.
    dfs(1,adjList,V);

    // 5. Print the radius, diameter and circumeference of the graph.
    vector<vector<int>> D(V+1,vector<int>(V+1,100000));
    vector<int> E(V+1,-1);
    compute_Distances(adjList,V,D);
    print_DistanceMatrix(D,V);
    compute_Eccentricity(D,V,E);
    print_Eccentricity(E,V);
    
    cout<<"RADIUS : "<<compute_Radius(E,V)<<endl<<endl;
    cout<<"DIAMETER : "<<compute_Diameter(E,V)<<endl<<endl;
    cout<<"CIRCUMFERENCE : "<<compute_Circumference(adjList,V, 1)<<endl<<endl;
    
    return 0;
}