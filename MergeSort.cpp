//
//  main.cpp
//  Algorithm_Test
//
//  Created by Seon-Min Kim on 04/01/2019.
//  Copyright © 2019 Seon-Min Kim. All rights reserved.
//

#include <iostream>

using namespace std;


int number = 8;
int sorted[8];


void MySwap(int *ap_a, int *ap_b){
    int temp = 0;
    
    temp = *ap_a;
    *ap_a = *ap_b;
    *ap_b = temp;
    
}
void Merge(int *ap_data, int start, int middle, int end){
    int i = start;
    int j = middle + 1;
    int k = start;
    
    //작은 순서대로 배열에 삽입
    while(i<=middle && j <= end){
        if(*(ap_data + i) <= *(ap_data + j)){
            sorted[k] = *(ap_data + i);
            i++;
        }else {
            sorted[k] = *(ap_data + j);
            j++;
        }
        k++;
    }
    //남은 데이터도 삽입
    if(i > middle) {
        for(int t = j; t <= end ; t++){
            sorted[k] = ap_data[t];
            k++; //주의!
        }
    }else {
        for(int t = i ; t <= middle ; t++){
            sorted[k] = ap_data[t];
            k++; //주의!
        }
    }
    //정렬된 배열을 삽입
    for(int t = start ; t<= end ; t++){
        *(ap_data + t) = sorted[t];
    }
}
void MergeSort(int *ap_data, int start, int end){
    //크기가 1보다 큰경우만 분할
    if(start < end){
        int middle  = (start + end) / 2;
        MergeSort(ap_data, start, middle);
        MergeSort(ap_data, middle + 1, end);
        Merge(ap_data, start, middle, end);
        
    }
}
//병합 정렬
int main(void){
    
    int array[8] = {7, 6, 5, 8, 3, 5, 9, 1};
    MergeSort(array, 0, number - 1);
    
    
    
    for(int i = 0; i< number ; i++){
        cout << array[i] << " ";
    }
    
    
    
    return 0;
}

