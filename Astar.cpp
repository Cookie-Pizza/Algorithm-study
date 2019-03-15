#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

#define     NUMBEROFNODE    17
#define     INF             1000000.0

#define     A               'A'-65
#define     B               'B'-65
#define     C               'C'-65
#define     D               'D'-65
#define     E               'E'-65
#define     F               'F'-65
#define     G               'G'-65
#define     H               'H'-65
#define     I               'I'-65
#define     J               'J'-65
#define     K               'K'-65
#define     L               'L'-65
#define     M               'M'-65
#define     N               'N'-65
#define     O               'O'-65
#define     P               'P'-65
#define     Q               'Q'-65


using namespace std;
class SM_Point{
public:
    int m_x;
    int m_y;
    
    void SetCoordinate(int a_x, int a_y){
        this->m_x = a_x;
        this->m_y = a_y;
    }
    double GetDistance(SM_Point a_p){
        double distance = 0;
        distance = sqrt((this->m_x - a_p.m_x)*(this->m_x - a_p.m_x) + (this->m_y - a_p.m_y)*(this->m_y - a_p.m_y));
        
        return distance;
    }
    
};

class Vertex{
public:
    char m_name; //노드의 이름
    SM_Point m_point; //이 노드의 좌표
    double m_distance = INF; //이 노드 까지 오는데 걸린 거리
    double m_f_distance = INF; //목적지 까지의 거리 추정값
    char m_previous; //이 노드까지 최단경로상의 바로전 노드
    vector<Vertex> m_edge; //인접 노드의 집합
    Vertex(){
        
    }
    Vertex(char a_name, double a_f_distance){
        this->m_name = a_name;
        this->m_f_distance = a_f_distance;
    }
    void SetName(char a_node_name){
        this->m_name = a_node_name;
    }
    void SetDistance(int a_distance){
        this->m_distance = a_distance;
    }
    void AddEdge(Vertex a_vertex){
        this->m_edge.push_back(a_vertex);
    }
};
struct cmp{ //priority queue 의 우선순위 정해주는 function object
    bool operator()(const Vertex& e1, const Vertex& e2){
        return e1.m_f_distance >= e2.m_f_distance;
    } };

bool compare(pair<int, char> a, pair<int, char> b){
    return a.first > b.first;
}
void ShowPath(Vertex *ap_v, char a_start, char a_dst){
    vector<pair<int, char>> path;
    int weight = 0;
    path.push_back(make_pair(weight, a_dst)); //먼저 종착점 추가
    weight++; //추가 했으므로 증가시킴
    char key = ap_v[a_dst - 65].m_previous;
    while(key > a_start){
        path.push_back(make_pair(weight, key));
        weight++;
        key = ap_v[key - 65].m_previous;
    }
    path.push_back(make_pair(weight , key));
    
    sort(path.begin(), path.end() , compare);
    for(int i = 0; i < weight  ; i++){
        cout << path[i].second << " -> ";
    }
    cout << path[weight].second << endl;
    
}
void AStar(Vertex *ap_v,double a_wm[][NUMBEROFNODE], char a_start, char a_dst){
    vector<char> closedset;
    
    unsigned char openset[NUMBEROFNODE] = {0, };
    char came_from[NUMBEROFNODE] = {0,};
    int count = 0;
    
    ap_v[a_start - 65].m_distance = 0; //시작노드이므로 코스트 거리에 0 대입
    
    priority_queue<Vertex, vector<Vertex>,cmp> pq;
    
    pq.push(Vertex(a_start, 0.0 + ap_v[a_start - 65].m_point.GetDistance(ap_v[a_dst - 65].m_point)));
    openset[a_start - 65] = 1;
    
    while(!pq.empty()){
        char current = pq.top().m_name; //현재 노드의 이름
        if(current == a_dst){
            //종착점에 도착했으므로 최단경로 출력
            ShowPath(ap_v, a_start, a_dst);
            //지금 까지 들린 순서 출력
            came_from[count] = a_dst;
            cout << came_from << endl;
            return;
        }
        double distance = ap_v[current - 65].m_distance; //현재 노드까지 오는 최소거리
        pq.pop();
        openset[current -65] = 0;
        closedset.push_back(current);
        came_from[count] = current;
        count++;
        
        for(int i = 0; i< ap_v[current - 65].m_edge.size() ; i++){
            //선택된 노드의 인접 노드
            char next = ap_v[current - 65].m_edge[i].m_name;
            
            
            double nextDistance = distance + a_wm[current - 65][next - 65];
            //closedset 비교 구문 추가
            for(int k = 0; k< closedset.size() ; k++){
                if(closedset[k] == next){
                    if(nextDistance >= ap_v[next - 65].m_distance) continue;
                }
            }
            
            if(!openset[next - 65] || nextDistance < ap_v[next - 65].m_distance){
                ap_v[next - 65].m_previous = current;
                ap_v[next - 65].m_distance = nextDistance;
                ap_v[next - 65].m_f_distance = ap_v[next - 65].m_distance + ap_v[next - 65].m_point.GetDistance(ap_v[a_dst - 65].m_point) ;
                
                if(!openset[next - 65]){
                    openset[next - 65] = 1;
                    pq.push(Vertex(next, ap_v[next - 65].m_f_distance));
                }
            }
        }
    }
}
int main(void){
    double wm[NUMBEROFNODE][NUMBEROFNODE]; //WeightMatrix
    //자기 자신까지 거리는 모두 0
    for(int i = 0; i< NUMBEROFNODE ; i++){
        for(int j = 0; j<NUMBEROFNODE; j++){
            if(i == j) {
                wm[i][j] = 0;
            }
            else wm[i][j] = INF;
        }
    }
    
    
    
    Vertex v[17];
    
    
    //노드의 좌표를 지정
    v[A].m_point.SetCoordinate(1, 5);
    v[B].m_point.SetCoordinate(1, 2);
    v[C].m_point.SetCoordinate(3, 4);
    v[D].m_point.SetCoordinate(3, 6);
    v[E].m_point.SetCoordinate(2, 7);
    v[F].m_point.SetCoordinate(3, 1);
    v[G].m_point.SetCoordinate(4, 3);
    v[H].m_point.SetCoordinate(5, 5);
    v[I].m_point.SetCoordinate(6, 2);
    v[J].m_point.SetCoordinate(7, 0);
    v[K].m_point.SetCoordinate(8, 3);
    v[L].m_point.SetCoordinate(8, 5);
    v[M].m_point.SetCoordinate(7, 7);
    v[N].m_point.SetCoordinate(9, 7);
    v[O].m_point.SetCoordinate(10, 5);
    v[P].m_point.SetCoordinate(9, 1);
    v[Q].m_point.SetCoordinate(10, 3);
    
    
    //노드의 이름을 지정 A~Q
    for(int i = 0; i< 17; i++){
        v[i].SetName(65+i);
    }
    
    //A 인접 노드 추가
    v['A'-65].AddEdge(v['B'-65]);
    v['A'-65].AddEdge(v['C'-65]);
    v['A'-65].AddEdge(v['E'-65]);
    //B 인접 노드 추가
    v['B'-65].AddEdge(v['F'-65]);
    //C 인접 노드 추가
    v['C'-65].AddEdge(v['B'-65]);
    v['C'-65].AddEdge(v['G'-65]);
    v['C'-65].AddEdge(v['H'-65]);
    //D 인접 노드 추가
    v['D'-65].AddEdge(v['C'-65]);
    v['D'-65].AddEdge(v['H'-65]);
    v['D'-65].AddEdge(v['M'-65]);
    //E 인접 노드 추가
    v['E'-65].AddEdge(v['D'-65]);
    v['E'-65].AddEdge(v['M'-65]);
    //F 인접 노드 추가
    v['F'-65].AddEdge(v['J'-65]);
    v['F'-65].AddEdge(v['I'-65]);
    //G 인접 노드 추가
    v['G'-65].AddEdge(v['F'-65]);
    v['G'-65].AddEdge(v['I'-65]);
    //H 인접 노드 추가
    v['H'-65].AddEdge(v['I'-65]);
    v['H'-65].AddEdge(v['K'-65]);
    v['H'-65].AddEdge(v['L'-65]);
    //I 인접 노드 추가
    v['I'-65].AddEdge(v['P'-65]);
    v['I'-65].AddEdge(v['K'-65]);
    //J 인접 노드 추가
    v['J'-65].AddEdge(v['P'-65]);
    v['J'-65].AddEdge(v['K'-65]);
    //K 인접 노드 추가
    v['K'-65].AddEdge(v['P'-65]);
    v['K'-65].AddEdge(v['O'-65]);
    //L 인접 노드 추가
    v['L'-65].AddEdge(v['K'-65]);
    v['L'-65].AddEdge(v['Q'-65]);
    //M 인접 노드 추가
    v['M'-65].AddEdge(v['L'-65]);
    v['M'-65].AddEdge(v['N'-65]);
    //N 인접 노드 추가
    v['N'-65].AddEdge(v['L'-65]);
    v['M'-65].AddEdge(v['O'-65]);
    //O 인접 노드 추가
    v['O'-65].AddEdge(v['K'-65]);
    v['O'-65].AddEdge(v['Q'-65]);
    //P 인접 노드 추가
    v['P'-65].AddEdge(v['K'-65]);
    v['P'-65].AddEdge(v['Q'-65]);
    //Q 인접 노드 추가
    
    //각 노드에서 노드거리 저장
    for(int i = 0; i< NUMBEROFNODE ; i++){
        for(int j = 0; j< v[i].m_edge.size() ; j++){
            wm[i][v[i].m_edge[j].m_name - 65] = v[i].m_point.GetDistance(v[i].m_edge[j].m_point);
        }
    }
    
    
    
    /*for(int i = 0; i<17 ; i++){
        cout << v[i].m_name << " ";
    }
    cout <<endl;
    
    for(int i = 0; i< 17 ; i++){
        cout << v[i].m_name << "의 인접 노드는 " ;
        for(int j = 0; j< v[i].m_edge.size() ; j++){
            cout << v[i].m_edge[j].m_name <<" ";
            cout << wm[i][v[i].m_edge[j].m_name - 65] << " ";
        }
        cout << endl;
            
    }*/
    
    AStar(v, wm, 'A', 'Q');
    cout << "최단거리는 : " << v[Q].m_distance << endl;
    
    
    
    
    
    return 0;
}Last login: Fri Mar 15 00:20:07 on ttys000
 seon-minkim@Seon-Minui-MacBookPro  ~  ls
AndroidStudioProjects    Downloads                Pictures
Applications             Library                  Public
Applications (Parallels) Movies                   Samsung
Desktop                  Music                    eclipse
Documents                Parallels                zsh-syntax-highlighting
 seon-minkim@Seon-Minui-MacBookPro  ~  cd Desktop
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop  ls
$RECYCLE.BIN
3:6일_로봇네비.m4a
Algorithm
Sm_programming
Thumbs.db
Tutorial
Ubuntu 18.04

Entering Ex mode.  Type "visual" to go to Normal mode.
:visual





















"Astar.cpp" 0L, 0C
        cout << v[i].m_name << " ";
ctest
desktop.ini
study
test.cpp
내 Boot Camp
오디오 녹음 2019-03-06 위치 오후 1.32.05.m4a
스크린샷 2019-02-08 오후 1.26.36.png
스크린샷 2019-02-08 오전 10.07.15.png
스크린샷 2019-02-11 오전 9.46.49.png
스크린샷 2019-02-18 오전 9.54.03.png
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop  cd Algorithm
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm  Al
zsh: command not found: Al
 ✘ seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm  cd Algorithm-study
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master  touch Astar.cpp
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master  ls
Astar.cpp          DFS.cpp            Quick_Sort.cpp     UnionFind.cpp
BFS.cpp            Heap_Sort.cpp      Selection_Sort.cpp
Bubble_Sort.cpp    Insert_Sort.cpp    Sort()1.cpp
Counting_Sort.cpp  MergeSort.cpp      Sort()2.cpp
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master  ex Astar.cpp
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master  git add .
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master ✚  git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	new file:   Astar.cpp

 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master ✚  git commit -m "ADD Astar.cpp [NEW]"
[master 1533808] ADD Astar.cpp [NEW]
 1 file changed, 285 insertions(+)
 create mode 100644 Astar.cpp
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master  git push
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 2.58 KiB | 2.58 MiB/s, done.
Total 3 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/Cookie-Pizza/Algorithm-study.git
   d586970..1533808  master -> master
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master  git log
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master 
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Algorithm/Algorithm-study   master  cd
 seon-minkim@Seon-Minui-MacBookPro  ~  ls
AndroidStudioProjects    Downloads                Pictures
Applications             Library                  Public
Applications (Parallels) Movies                   Samsung
Desktop                  Music                    eclipse
Documents                Parallels                zsh-syntax-highlighting
 seon-minkim@Seon-Minui-MacBookPro  ~  pwd
/Users/seon-minkim
 seon-minkim@Seon-Minui-MacBookPro  ~  cd Desktop
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop  rmdir Sm_programming
rmdir: Sm_programming: Directory not empty
 ✘ seon-minkim@Seon-Minui-MacBookPro  ~/Desktop  cd Sm_programming
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Sm_programming  ls
test.cpp
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Sm_programming  rm test.cpp
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop/Sm_programming  cd ..
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop  rmdir Sm_programming
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop  ls
$RECYCLE.BIN
3:6일_로봇네비.m4a
Algorithm
Thumbs.db
Tutorial
Ubuntu 18.04
ctest
desktop.ini
study
test.cpp
내 Boot Camp
오디오 녹음 2019-03-06 위치 오후 1.32.05.m4a
스크린샷 2019-02-08 오후 1.26.36.png
스크린샷 2019-02-08 오전 10.07.15.png
스크린샷 2019-02-11 오전 9.46.49.png
스크린샷 2019-02-18 오전 9.54.03.png
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop  rm test.cpp
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop  ls
$RECYCLE.BIN
3:6일_로봇네비.m4a
Algorithm
Thumbs.db
Tutorial
Ubuntu 18.04
ctest
desktop.ini
study
내 Boot Camp
오디오 녹음 2019-03-06 위치 오후 1.32.05.m4a
스크린샷 2019-02-08 오후 1.26.36.png
스크린샷 2019-02-08 오전 10.07.15.png
스크린샷 2019-02-11 오전 9.46.49.png
스크린샷 2019-02-18 오전 9.54.03.png
 seon-minkim@Seon-Minui-MacBookPro  ~/Desktop  clear

Entering Ex mode.  Type "visual" to go to Normal mode.
:visual'





















"Astar.

Entering Ex mode.  Type "visual" to go to Normal mode.
:visual





















"Astar.cpp" 285L, 8766C
    }
    cout <<endl;

    for(int i = 0; i< 17 ; i++){
        cout << v[i].m_name << "의 인접 노드는 " ;
        for(int j = 0; j< v[i].m_edge.size() ; j++){
            cout << v[i].m_edge[j].m_name <<" ";
            cout << wm[i][v[i].m_edge[j].m_name - 65] << " ";
        }
        cout << endl;

    }*/

    AStar(v, wm, 'A', 'Q');
    cout << "최단거리는 : " << v[Q].m_distance << endl;





    return 0;
}

~
-- INSERT --


