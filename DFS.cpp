/* Depth First Search*/

#include <iostream>
#include <stack>
#include <vector>


using namespace std;

void DFS(int a_start,int *ap_check, vector<int> *ap_node, stack<int> *ap_stack){
    if(ap_check[a_start]) {
        
        return;
    }
    ap_stack->push(a_start);
    
    ap_check[a_start] = true;
    
    cout << a_start << " ";
    
    for(int i = 0; i< ap_node[a_start].size() ; i++){
        int y = ap_node[a_start][i];
        
        DFS(y, ap_check, ap_node, ap_stack);
    }
    
}
void Connect_Node(int a_first, int a_second, vector<int> *ap_node){
    //ap_node[a_first].push_back(a_second);
    //ap_node[a_second].push_back(a_first);
    
    (*(ap_node + a_first)).push_back(a_second);
    (*(ap_node + a_second)).push_back(a_first);
    
}

int main(void){
    int number = 7;
    
    int c[7];
    
    stack<int> s;
    
    vector<int> a[8];
    
    
    Connect_Node(1,2,a);
    Connect_Node(1,3,a);
    Connect_Node(2,3,a);
    Connect_Node(2,4,a);
    Connect_Node(2,5,a);
    Connect_Node(3,6,a);
    Connect_Node(3,7,a);
    Connect_Node(6,7,a);
    
    DFS(1, c, a, &s);
    
    
}
