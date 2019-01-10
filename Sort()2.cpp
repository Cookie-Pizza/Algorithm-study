#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b){
    if(a.second.first == b.second.first){
        return a.second.second > b.second.second;
    }else {
        return a.second.first >  b.second.first;
    }
}

int main(void){
    /*vector<pair<int, string>> v;
    v.push_back(pair<int, string>(90, "seon_min"));
    v.push_back(pair<int, string>(85, "Yebin"));
    v.push_back(pair<int, string>(82, "dongbin"));
    v.push_back(pair<int, string>(98, "jong gu"));


    sort(v.begin(), v.end());
    */

    vector<pair<string, pair<int, int>>> v;
    v.push_back(pair<string, pair<int, int>>("seonmin", pair<int, int>(90, 19940318)));
    v.push_back(pair<string, pair<int, int>>("yebin", pair<int, int>(85, 19970819)));
    v.push_back(pair<string, pair<int, int>>("dongbin", pair<int, int>(87, 19930318)));
    v.push_back(pair<string, pair<int, int>>("hyungjung", pair<int, int>(9, 19960318)));
    v.push_back(pair<string, pair<int, int>>("zuki", pair<int, int>(90, 19980318)));

    sort(v.begin(), v.end(), compare);

    for(int i = 0 ; i< v.size() ; i++){
        cout << v[i].first << ' ';
    }
    return 0;
}
