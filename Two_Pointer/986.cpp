#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int first_size = firstList.size();
        int second_size = secondList.size();
        int first,second;
        first = second = 0;
        if(first_size == 0 || second_size == 0) return {};
        vector<vector<int> > answer;
        while(first!=first_size - 1 || second!=second_size - 1){
            if(first > first_size - 1) first = first_size - 1;
            if(second > second_size - 1) second = second_size - 1;
            if(firstList[first][0]>=secondList[second][0]){//front,front
                if(firstList[first][0]>=secondList[second][1]){//front,back
                    if(firstList[first][0]==secondList[second][1]) answer.push_back({secondList[second][1],secondList[second][1]});
                }
                else{//back,back
                    if(firstList[first][1]>=secondList[second][1]) answer.push_back({firstList[first][0],firstList[first][1]});
                    else answer.push_back({firstList[first][0],secondList[second][1]});
                    first++;
                    continue;
                }
                second++;
            }
            else{
                if(firstList[first][1] > secondList[second][0]){//back front
                    if(firstList[first][1] >= secondList[second][1]) answer.push_back({secondList[second][0],secondList[second][1]});
                    else answer.push_back({secondList[second][0],firstList[first][1]});

                }
                else{
                    if(firstList[first][1] == secondList[second][0]) answer.push_back({secondList[second][0],firstList[second][0]});
                }
                first++;
            }
        }


        if(firstList[first][0]>=secondList[second][0]){//front,front
                if(firstList[first][0]>=secondList[second][1]){//front,back
                    if(firstList[first][0]==secondList[second][1]) answer.push_back({secondList[second][1],secondList[second][1]});
                }
                else{//back,back
                    if(firstList[first][1]>=secondList[second][1]) answer.push_back({secondList[second][0],secondList[second][1]});
                    else answer.push_back({secondList[second][0],firstList[second][1]});
                }
            }
            else{
                if(firstList[first][1] > secondList[second][0]){//back front
                    if(firstList[first][1] >= secondList[second][1]) answer.push_back({firstList[first][0],firstList[first][1]});
                    else answer.push_back({secondList[second][0],firstList[first][1]});
                }
                else{
                    if(firstList[first][1] == secondList[second][0]) answer.push_back({secondList[second][0],firstList[second][0]});
                }
            }

        return answer;
    }
};

int main(){}