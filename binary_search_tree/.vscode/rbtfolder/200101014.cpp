#include<bits/stdc++.h>
 using namespace std;
 pair<int, int> distance_of_max_node(int node, vector<int> List[],int n)
 {
     bool vis[n + 1];
     vis[0] = true;
     for (int i = 1; i <= n; i++)
     {
         vis[i] = false;
     }
     int dis[n + 1];
     dis[0] = 0;
     dis[node] = 0;
     queue<int> pending;
     pending.push(node);
     vis[node] = true;
     while (!pending.empty())
     {
         int start = pending.front();
         pending.pop();

         for (auto element : List[start])
         {
             if (vis[element] == true)
             {
                 continue;
             }
             vis[element] = true;
             dis[element] = dis[start] + 1;
             pending.push(element);
         }
     }
     pair<int, int> result;
     int max = 0;
     for (int i = 1; i <= n; i++)
     {
         if (dis[i] > max)
         {
             max = dis[i];
             result.first = max;
             result.second = i;
         }
     }
     return result;
 }

 int main(){
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<int> List[n+1];
    List[0].push_back(0);
    for (int i = 1; i <= e; i++){
        int first;
        cin >> first;
        int last;
        cin >> last;
        List[first].push_back(last);
        List[last].push_back(first);
    }
    if (n - 1 == e)
    {
        cout << "Y\n";
        pair<int, int> result_1 = distance_of_max_node(1,List,n);
        pair<int, int> result_2 = distance_of_max_node(result_1.second,List,n);
        cout<<result_2.first<<endl;
    }
    else
    {
        cout << "N\n0";
    }
 }