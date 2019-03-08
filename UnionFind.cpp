//합집합 찾기 알고리즘
#include <stdio.h>
//부모 노드를 찾는 함수
int getParent(int *ap_parent, int x) {
    if (*(ap_parent + x) == x) return x;
    return *(ap_parent + x) = getParent(ap_parent, *(ap_parent + x));
    
}

//두 부모 노드를 합치는 함수
void unionParent(int *ap_parent, int a, int b) {
    a = getParent(ap_parent, a);
    b = getParent(ap_parent, b);
    if (a < b) *(ap_parent + b) = a;
    else *(ap_parent + a) = b;
    
}
// 같은 부모를 가지는지 확인(같은 그래프에  속하는지)
int findParent(int *ap_parent, int a, int b) {
    a = getParent(ap_parent, a);
    b = getParent(ap_parent, b);
    if (a == b) return 1;
    return 0;
}

int main(void) {
    int parent[11];
    for (int i = 1; i <= 10; i++) {
        parent[i] = i;
    }
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);
    
    printf("1 과 5는 연결되어  있나요?  %d\n", findParent(parent, 1, 5));
    unionParent(parent, 1, 5);
    printf("1 과 5는 연결되어  있나요?  %d\n", findParent(parent, 1, 5));
    return 0;
}
