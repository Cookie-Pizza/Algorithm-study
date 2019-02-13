//계수 정렬

#include <iostream>



using namespace std;

int main(void){
    int array[30] = {1,3,2,4,3,2,5,3,1,2,3,4,4,3,5,1,2,3,5,2,3,1,4,3,5,1,2,1,1,1};
    int boundary = 0;
    cout << "범위 입력";
    
    cin  >> boundary;
    //메모리 할당
    int **pp_count_array;
    pp_count_array = new int*[boundary];
    
    for(int i = 0; i < boundary ; i++){
        *(pp_count_array + i) = new int;
    }
    
    //카운팅
    for(int i = 0; i< 30 ; i++){
        int value = array[i] - 1;
        
        **(pp_count_array + value) += 1;
    }
    
    //출력
    for(int i = 0 ; i< boundary ; i++){
        
        int count = **(pp_count_array + i);
        
        for(int j = 0; j< count ; j++){
            cout << i + 1 << " ";
        
        }
        
        //cout << *(*(pp_count_array + i)) <<" ";
    }
    
    
    //메모리 해제
    for(int i = 0; i< boundary ; i++){
        delete *(pp_count_array + i);
    }
    
    
    delete[] pp_count_array;
    
  
    return 0;
    
}
