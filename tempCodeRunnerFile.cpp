#include <cstdio>
#include <cstring>
#include <set>
#include <cstdlib>
#include <vector>
using namespace std;



int main(){
    set<pair<int, int>> uset;
    int n, L, S;
    int i, j, k;
    int ans = 0;
    vector<pair<int,int>> vec; //the positions of trees on the treasure map
    scanf("%d%d%d", & n, & L, & S);
    for(i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", & a, & b);
        uset.insert(pair<int, int>(a, b));
    }
    for(i = S; i >= 0; i--){
        for(j = 0; j <= S; j++){
            int tmp;
            scanf("%d", & tmp);
            if(tmp == 1){
                vec.push_back(pair<int, int>(i, j));
            }
        }
    }
    for(i = L - S; i >= 0; i--){
        for(j = 0; j <= L - S; j++){
            for(k = 0; k < vec.size(); k++){
                if(uset.find(pair<int, int>(vec[k].first + i, vec[k].second + j)) == uset.end())
                    break;
            }
            if(k == vec.size())
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}