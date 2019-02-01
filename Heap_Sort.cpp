//
//  main.cpp
//  Algorithm_Test
//
//  Created by Seon-Min Kim on 04/01/2019.
//  Copyright © 2019 Seon-Min Kim. All rights reserved.
//

#include <iostream>

using namespace std;


int g_number = 9;
int g_heap[9] = {7, 6, 5, 8, 4, 5, 9, 1, 6};


void MySwap(int *ap_a, int *ap_b){
    int temp = 0;
    
    temp = *ap_a;
    *ap_a = *ap_b;
    *ap_b = temp;
    
}

//힙 정렬
int main(void){
    //힙을 생성( 상향식 )
    for(int i = 1 ; i< g_number ; i++){
        int c = i;
        
        do {
            int root = ( c - 1) / 2;
            
            if(g_heap[root] < g_heap[c]) MySwap(g_heap + root, g_heap + c);
            
            c = root;
            
        }while(c != 0);
        
        
    }
    //정렬을 수행
    for(int i = g_number -1 ; i>=0; i--){
        MySwap(g_heap + i, g_heap);
        
        int root = 0;
        int c = 1;
        do{
            c = root* 2 + 1;
            
            if(c < i -1 && g_heap[c] < g_heap[c + 1]) c++;
            
            if(c < i && g_heap[root] < g_heap[c]) MySwap(g_heap + root, g_heap + c);
            
            root = c;
        }while ( c < i);
        
      
    }
    
    for(int i = 0 ; i < g_number ; i++){
        cout << g_heap[i] << " ";
    }
    
    return 0;
}

