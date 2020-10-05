/************************************************************
 *  name : Youngwoo Park
 *  date : 10-05-2020
 *  level: l3
 *  problem source: programmers
 *  lang: C++
 *  skill:  bfs
 * *********************************************************/
#include <queue>
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int arr[N+1][N+1];
    
    for(int i = 1 ; i <= N ; i++){
        for(int j  = 1 ; j <= N ; j++){
            arr[i][j] = 0;
        }
    }
    
    for(int i = 0 ; i < road.size() ; i++){
        if(arr[road[i][0]][road[i][1]]  == 0 || arr[road[i][0]][road[i][1]] > road[i][2]){
            arr[road[i][0]][road[i][1]] = road[i][2];     
            arr[road[i][1]][road[i][0]] = road[i][2];                 
        }
    }
    
    queue<int> q;
    bool visited[N+1];
    int dist[N+1];
    int first;
    
    q.push(1);
    dist[1] = 0;
    
    for(int i = 2 ; i < N+1 ; i++){
        visited[i] = false;
        dist[i] = 0;
    }    
    
    while(!q.empty()){
        first = q.front();
        //cout << "<" << first << " >" << endl;
        q.pop();
        for(int i = 2; i <= N ; i++){
            if(visited[i] && arr[first][i] != 0 && arr[first][i] + dist[first] < dist[i]){
                dist[i] = arr[first][i]+dist[first];
                //cout << "Update " << i << " with " << dist[i] << endl;
                q.push(i);
            }
            else if(arr[first][i] != 0 && !visited[i]){
                //cout << "Check " << i << " with " << arr[first][i]+dist[first] << endl;
                visited[i] = true;
                dist[i] = arr[first][i]+dist[first];
                q.push(i);
            }
            
        }
    }
    for(int i = 1 ; i <= N; i++){
        cout << i << ":" << dist[i] << endl;
        if(dist[i] <= K)
            answer++;
    }
    return answer;
}