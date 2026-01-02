/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:

    Employee* getEmployee(vector<Employee*>& employees, int& id){
        for(auto x : employees){
            if(x->id == id){
                return x;
            }
        }
        return nullptr;
    }

    void bfs(vector<Employee*>& employees, int& total, int idE){
        Employee* child = getEmployee(employees, idE);
        // cout<<"CH"
        if (child == nullptr) return;
        total+=child->importance;       
        for(int x :child->subordinates){
            bfs(employees,total, x);
        }
    }

    int getImportance(vector<Employee*> employees, int id) {
        Employee* root = getEmployee(employees, id);
        if(root->subordinates.size() == 0) return root->importance;
        
        int resu = root->importance;
        for(auto x : root->subordinates){
            bfs(employees, resu, x);
        }

        return resu;
    }
};