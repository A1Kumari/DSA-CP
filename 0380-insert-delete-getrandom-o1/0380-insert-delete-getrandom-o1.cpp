class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int, int> valToIndex;

public:
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(valToIndex.find(val) != valToIndex.end()){
                return false;
        }
        arr.push_back(val);
        valToIndex[val] = arr.size()-1;

        return true;
    }
    
    bool remove(int val) {
        if(valToIndex.find(val) == valToIndex.end()){
                return false;
        }
        int index = valToIndex[val];
        int lastElement = arr.back();
        arr[index] = lastElement;
        valToIndex[lastElement] = index;

        arr.pop_back();
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % arr.size();
        return arr[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */