#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class DataClass {
private:
    std::vector<std::string> data_;

public:
    DataClass(const std::vector<std::string> &data) : data_(data) {}

    std::string HashKey() const {
        // Your code here
        std::string res;
        for (const auto & i : data_) {
            res += i;
        }
        return res;
    }

    bool operator==(const DataClass &dc) const {
        // Your code here
        if (data_.size() != dc.data_.size())return false;
        for (int i = 0; i < data_.size(); i++) {
            if (data_[i] != dc.data_[i]) return false;
        }
        return true;
    }
};





//*******************************************************************************
//
//                               下面的内容不需要修改
//
//*******************************************************************************

struct DataClassHash {
    size_t operator()(const DataClass &dc) const {

        std::string str = dc.HashKey();

        return std::hash<std::string>()(str);
    }
};

void testInternal(const std::vector<std::vector<std::string>> input){
    std::vector<DataClass> data_classes;
    std::unordered_map<DataClass, int, DataClassHash> data_map;

    for(auto& params: input){
        data_classes.emplace_back(DataClass(params));
    }

    for(auto& data_class: data_classes){
        data_map[data_class]++;
    }

    for(auto& data_class: data_classes){
        std::cout << data_map[data_class] << std::endl;
    }
}

std::vector<std::string> parseLine(const std::string& line) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string item;

    while (std::getline(ss, item, ' ')) {
        if (!item.empty()) {
            result.push_back(item);
        }
    }

    return result;
}

int main() {
    std::unordered_map<DataClass, int, DataClassHash> data_map;
    DataClass d({"a", "b"});
    DataClass d2({"ab"}); // 请注意，d和d2并不相同！
    data_map[d]++;
    data_map[d2]++;

    DataClass test({"a", "b"});
    DataClass test2({"ab"});
    std::cout << data_map[test] << std::endl; // 1
    std::cout << data_map[test2] << std::endl; // 1
    return 0;
}