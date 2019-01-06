//
//  main.cpp
//  Algorithm_Test
//
//  Created by Seon-Min Kim on 04/01/2019.
//  Copyright © 2019 Seon-Min Kim. All rights reserved.
//

#include <iostream>
using namespace std;
void MySwap(int *ap_a, int *ap_b){
    int temp = 0;
    
    temp = *ap_a;
    *ap_a = *ap_b;
    *ap_b = temp;
    
}
//삽입 정렬
int main(void){
    int array[10] = {5,10,1,8,7,6,3,2,9,4};
    int min, i, j, temp, index = 0;
    
    for(i = 0; i<9 ; i++){
        j = i;
        while(array[j]>array[j+1]){
            MySwap(array + j , array + j +1);
            j--;
        }
    }
    for(int k = 0 ; k< 10 ; k++){
        cout << array[k] << " ";
    }
    
    
    return 0;
}
