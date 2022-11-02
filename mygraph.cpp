#include<bits/stdc++.h>
#include "stdexcept"
#include <list>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph {


private:
    
    map<int, list<int>> adjList;
    map<int, int> keyIndex;
    vector<vector<int>*> AdjacencyList;

public:

Graph(const vector<int> &starts, const vector<int> &ends){

        if (starts.size() != ends.size())
         throw invalid_argument("the vectors size is different.");
        int i = 0;
        for (int j = 0; j < starts.size(); j++) {

            if(keyIndex.find(starts[j]) == keyIndex.end()){

                keyIndex[starts[j]] = i++;
                vector<int> *temp = new vector<int>;
                AdjacencyList.push_back(temp);
            }
        }
        for (int j = 0; j < ends.size(); ++j) {
            if(keyIndex.find(ends[j]) == keyIndex.end()) keyIndex[ends[j]] = i++;
        }
        for (int j = 0; j < starts.size(); ++j) {
            vector<int> *temp = AdjacencyList[keyIndex[starts[j]]];
            temp->push_back(keyIndex[ends[j]]);
        }

    };

int numOutgoing(const int nodeID) {

        if(keyIndex.find(nodeID) == keyIndex.end()) throw invalid_argument("invalid nodeID");
        if (keyIndex[nodeID] >= AdjacencyList.size())
            return 0;
        return AdjacencyList[keyIndex[nodeID]]->size();

    }

const vector< int > &adjacent(const int nodeID) {

        if(keyIndex.find(nodeID) == keyIndex.end()) throw invalid_argument("invalid nodeID");
        vector<int> *result = new vector<int>;
        if (keyIndex[nodeID] >= AdjacencyList.size())
            return *result;
        vector<int> temp = *(AdjacencyList[keyIndex[nodeID]]);
        for (int i = 0; i < temp.size(); ++i) {
            for(map<int,int>::iterator it = keyIndex.begin(); it != keyIndex.end(); ++it) {
                if (temp[i] == it->second) result->push_back(it->first);
            }
        }

        return *result;
    }
    bool hasCycle()
    {
        map<int, bool> visited;
        map<int, bool> inStack;

        for (auto i : adjList)
        {
            int vertex = i.first;
            if (!visited[vertex])
            {
                    return true;
            }
        }
        return false;
}
    
int main(){
    
}
};