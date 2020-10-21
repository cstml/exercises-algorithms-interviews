#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
using namespace std;


class RandomizedSet {
private:
    //unordered_set<int> _elems;
    vector<int> numbersV;
    unordered_map<int, int> positionsV;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(positionsV.find(val) != positionsV.end())
            return false;
        numbersV.push_back(val);
        positionsV.insert({val, numbersV.size()-1});
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(positionsV.find(val) == positionsV.end())
            return false;
        int pos = positionsV[val];
        numbersV[pos] = numbersV[numbersV.size()-1];
        positionsV[numbersV[pos]] = pos;
        numbersV.pop_back();
        positionsV.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return numbersV[rand() % numbersV.size()];
    }
};
int main()
{
    //Your RandomizedSet object will be instantiated and called as such:
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(3);
    param_1 = obj->insert(4);
    std::cout<<param_1<<" "<<"\n";
    bool param_2 = obj->remove(2);
    std::cout<<param_2<<" "<<"\n";
    int param_3 = obj->getRandom();
    std::cout<<param_3<<" "<<"\n";
}
