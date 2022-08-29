#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Role{
private:
    vector<string> ops;
    vector<string> resource_classes;
    vector<string> resource_names;
public:
    bool checkOp(string op){
        if(find(ops.begin(), ops.end(), "*") != ops.end())
            return true;
        if(find(ops.begin(), ops.end(), op) != ops.end())
            return true;
        return false;
    }

    bool checkReClass(string resourceClass){
        if(find(resource_classes.begin(), resource_classes.end(), resourceClass) != resource_classes.end())
            return true;
        if(find(resource_classes.begin(), resource_classes.end(), "*") != resource_classes.end())
            return true;
        return false;
    }

    bool checkReNames(string resourceName){
        if(resource_names.empty() == true)
            return true;
        if(find(resource_names.begin(), resource_names.end(), resourceName) != resource_names.end())
            return true;
        return false;
    }
    
};


class UserOrGroup{
private:
    vector<string> roles;
public:
    bool checkPre(map<string, Role> roleMap, string op, string resourceClass, string resourceName){
        for(int i = 0; i < roles.size(); i++){
            map<string, Role>::iterator it;
            if((it = roleMap.find(roles[i])) != roleMap.end()){
                if((*it).second.checkOp(op) && (*it).second.checkReClass(resourceClass) && (*it).second.checkReNames(resourceName))
                    return true;
            }
        }
        return false;
    }
};


map<string, Role> roleMap;
map<string, UserOrGroup> groupMap;
map<string, UserOrGroup> userMap;


int main(){
    //读入并记录roleMap

    //读入并记录userMap和groupMap

    //读入操作并通过UserOrGroup中的checkPre查找
    
}

