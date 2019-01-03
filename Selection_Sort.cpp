//
//  main.cpp
//  Algorithm_Test
//
//  Created by Seon-Min Kim on 04/01/2019.
//  Copyright © 2019 Seon-Min Kim. All rights reserved.
//

#include <iostream>
using namespace std;

//선택 정렬
int main(void){
    int array[10] = {5,10,1,8,7,6,3,2,9,4};
    int min, i, j, temp, index = 0;
    
    for(i = 0; i< 10 ; i++){
        min = 9999; //그냥 어느정도 큰값을 대입해놓는다.
        
        for(j = i ; j< 10 ; j++){
            if(min>array[j]) {
                min = array[j];
                index = j;
            }
        }
        
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
        
        
    }
    for(int k = 0 ; k< 10 ; k++){
        cout << array[k] << " ";
    }
    
    
    return 0;
}
