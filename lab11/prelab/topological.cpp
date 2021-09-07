/*
 * Filename: topological.cpp
 * Jinghui Tian
 * Date: 5.3.2021
 */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief topological sort
 *
 * @return sorted value
 * @todo Need to write acceptance tests for this function
 * @author Jinghui Tian
 * @file topological.cpp
 */


class TPS{
public:
    int v;
    int *visited;
    vector <int> ans;
    map <int, string> myMap;
    vector <int> *adj_list;
    TPS(int vert);
    void dfs(int vert);
    void topologicalSort();
};




TPS::TPS(int vert) {
    this -> v = vert;
    adj_list = new vector <int>[vert];
    
    visited = new int[vert];
    for (int i = 0; i < vert ; i++){
        visited[i] = 0;
    }
    
}



void TPS::dfs(int v) {
    visited[v] = 1;

    vector <int>::iterator i;
    for(i = adj_list[v].begin(); i != adj_list[v].end(); ++i) {
        if(visited[*i]==0) {
          dfs(*i);
        }
      }
    
    ans.push_back(v);
}


void TPS::topologicalSort() {
    ans.clear();

    for(int i = 0; i < v; i++) {
        if(visited[i] == 0)
        dfs(i);
    }

    reverse(ans.begin(), ans.end());
    
    vector<int>::iterator i;
    for (i = ans.begin(); i != ans.end(); ++i){
        cout << myMap[*i] << " ";
    }
    }



int main (int argc, char **argv) {

    ifstream file(argv[1], ifstream::binary);
    ifstream filee(argv[1], ifstream::binary);


    string s1, s2;
    vector <string> vx;

    while(file.good()) {
        file >> s1;
        file >> s2;
        if(s1 == "0") {
            break;
        }

        vx.push_back(s1);
        vx.push_back(s2);
    }
    
    TPS myTPS(vx.size());
    
    
    

    map<string, int> Map_here;
    int ct = 0;
    vector<string>::iterator i;
    for(i = vx.begin(); i != vx.end(); ++i) {
        Map_here[*i] = ct;
        ct++;
    }
    

    
    while(filee.good()) {
        filee >> s1;
        filee >> s2;
        if(s1 == "0") {
            break;
        }

        myTPS.myMap[Map_here[s1]] = s1;
        myTPS.myMap[Map_here[s2]] = s2;

        myTPS.adj_list[Map_here[s1]].push_back(Map_here[s2]);
    }
    
    
    myTPS.topologicalSort();
    cout<<endl;


    return 0;
}
