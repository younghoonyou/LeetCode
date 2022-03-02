#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <queue>
using namespace std;
vector<int> arr[17575];
vector<string> answer;
vector<pair<int,int>> order(300);
bool check[300];
int cnt;
int make_hash(int n,string str,int ans){
    if(n==3){
        return ans;
    }
    return make_hash(n+1,str,ans+=str[2-n] - 'A');//+=pow(26,n)*(str[2-n] - 'A'));
}
string remake_hash(int n,int K,string ans){
    if(n==2){
        int tmp = K%26;
        ans+=tmp + 'A';
        char change = ans[0];
        ans[0] = ans[2];
        ans[2] = change;
        return ans;
    }
    int tmp = K%26;
    int div = K/26;
    return remake_hash(n+1,div,ans+=tmp + 'A');
}

void dfs(int go){
    for(int i=0;i<arr[go].size();++i){
        if(arr[arr[go][i]].empty()) continue;
        bool flag = false;
        int index = -1;
        for(int j=0;j<=cnt;++j){
            if(go == order[j].first && order[j].second == arr[go][i]){
                // if(check[j]){
                //     flag = true;
                //     continue;
                // }
                if(check[j]) continue;
                index = j;
                break;
                // continue;
            }
        }
        // if(flag) continue;
        if(index == -1) continue;
        // if(check[index]) continue;
        check[index] = true;
        string str = remake_hash(0,arr[go][i],"");
        answer.push_back(str);
        dfs(arr[go][i]);
    }
}

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.size()==1){
            return tickets[0];
        }
        answer.clear();
        order.clear();
        memset(check,0,sizeof(check));
        memset(arr,0,sizeof(arr));
        int tsize = tickets.size();
        int index = 0;
        cnt=0;
        int start = 987654321;
        for(int i=0;i<tsize;++i){
            int tmp = make_hash(0,tickets[i][1],0);
            int x = make_hash(0,tickets[i][0],0);
            arr[x].push_back(tmp);
            order[i].first = x;
            order[i].second = tmp;
            // if(x==6224){
            //     if(start>tmp) start = tmp,index = i;
            // }
            cnt++;
        }

        for(int i=0;i<=cnt;++i){
            int tar = order[i].first;
            sort(arr[tar].begin(),arr[tar].end());
        }
        // cout<<index;
        // check[index] = true;
        answer.push_back("JFK");
        // string temp = "";
        // temp = remake_hash(0,start,"");
        // answer.push_back(temp);
        dfs(6224);
        for(int i=0;i<tsize;++i){
            if(!check[i]){
                string tm = remake_hash(0,order[i].second,"");
                answer.push_back(tm);
                break;
            }
        }
        return answer;
    }
};

int main(){
    vector<vector<string> > tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};

    Solution s;
    for(auto i:s.findItinerary(tickets)) cout<<i<<" ";
    // cout<<make_hash(0,"AUA",0);
    // if("AUA" - 'A' <"ADL" - 'A') cout<<"ok";
    // cout<<"ADL" - 'A';
    return 0;
}