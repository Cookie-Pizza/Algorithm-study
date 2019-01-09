//
//  main.cpp
//  Algorithm_Test
//
//  Created by Seon-Min Kim on 04/01/2019.
//  Copyright © 2019 Seon-Min Kim. All rights reserved.
//

#include <iostream>

using namespace std;


int number = 15;

void MySwap(int *ap_a, int *ap_b){
    int temp = 0;
    
    temp = *ap_a;
    *ap_a = *ap_b;
    *ap_b = temp;
    
}

void Quick_Sort(int *ap_data, int a_start, int a_end){
    if(a_start >= a_end) return;
    
    for(int i = a_start ; i< a_end+1 ; i++) cout << *(ap_data+i) << " " ;
    cout <<  endl;
    
    int pivot = *(ap_data + a_start);
    int start_pointer = a_start+1, end_pointer = a_end;
    //엇갈릴 때 까지
    while(start_pointer <= end_pointer) {
        while(*(ap_data + start_pointer) < pivot && start_pointer <= a_end) start_pointer++;
        while(*(ap_data + end_pointer) >pivot && end_pointer > a_start) end_pointer--;
        
        if(start_pointer < end_pointer) MySwap(ap_data + start_pointer, ap_data + end_pointer);
        
        
    }
    //엇갈리면 end 포인터에 있는 값이 새로운 pivot
    MySwap(ap_data+ a_start, ap_data + end_pointer);
    Quick_Sort(ap_data, a_start , end_pointer -1);
    Quick_Sort(ap_data, end_pointer + 1, a_end);
    
}
//퀵 정렬
int main(void){
   
    int array[15] = {5,10,1,8,7,6,3,2,9,4,12,14,13,15,11};
        
    Quick_Sort(array, 0, number -1);
    
    for(int i = 0; i< number ; i++){
        cout << array[i] << " ";
    }
   
    
    
    return 0;
}

