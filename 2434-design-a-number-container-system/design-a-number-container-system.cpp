class NumberContainers {
public:
    unordered_map<int,set<int>>numbers;
    unordered_map<int,int>indexs;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(indexs.find(index)!=indexs.end()){
            int oldnum=indexs[index];
            numbers[oldnum].erase(index);
            if(numbers[oldnum].empty()){
                numbers.erase(oldnum);
            }
        }
        indexs[index]=number;
        numbers[number].insert(index);
    }
    
    int find(int number) {
        if(numbers.find(number)!=numbers.end()){
            return *numbers[number].begin();
        }
        return -1;
    }
};