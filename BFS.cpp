/*Breath First Search*/


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;


void bfs(int start, int *ap_check, vector<int> *ap_node){
    queue<int> q;
    q.push(start);
    ap_check[start] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for(int i = 0; i< ap_node[x].size(); i++){
            int y = ap_node[x][i];
            if(!ap_check[y]){
                q.push(y);
                ap_check[y] = true;
            }
        }
    }
}
void Connect_Node(int a_first, int a_second, vector<int> *ap_node){
    //ap_node[a_first].push_back(a_second);
    //ap_node[a_second].push_back(a_first);
    
    (*(ap_node + a_first)).push_back(a_second);
    (*(ap_node + a_second)).push_back(a_first);
    
}

int main(void){
    int c[7];
    
    vector<int> a[8];
    
    
    Connect_Node(1,2,a);
    Connect_Node(1,3,a);
    Connect_Node(2,3,a);
    Connect_Node(2,4,a);
    Connect_Node(2,5,a);
    Connect_Node(3,6,a);
    Connect_Node(3,7,a);
    Connect_Node(6,7,a);
    
    bfs(1, c, a);
    
    return 0;
    
    
}
