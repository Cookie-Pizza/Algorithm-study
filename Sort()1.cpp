//
//  main.cpp
//  Algorithm_Test
//
//  Created by Seon-Min Kim on 04/01/2019.
//  Copyright © 2019 Seon-Min Kim. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
    string m_name;
    int m_score;

    Student(string a_name, int a_score){
        this -> m_name = a_name;
        this -> m_score = a_score;
    }

    //정렬 기준은 '점수가 작은 순서'
    bool operator <(Student &a_student){
        return this->m_score < a_student.m_score;
    }
};


bool compare(int a, int b){
    return a > b;
}


//Sort() 사용법
int main(void){

    Student students[] = {
        Student("seonmin 1" , 90),
        Student("seonmin 2" , 80),
        Student("seonmin 3" , 70),
        Student("seonmin 4" , 60),
        Student("seonmin 5" , 50)
    };

    sort(students, students + 5);

    for(int i = 0; i< 5; i++){
        cout << students[i].m_name << ' ';

    }



    return 0;
}

