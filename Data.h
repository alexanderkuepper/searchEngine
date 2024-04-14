//
// Created by alex on 05.04.2024.
//

#ifndef SEARCHENGINE_DATA_H
#define SEARCHENGINE_DATA_H


#include <vector>
#include <string>

class Data {
private:
    std::vector<std::string> names;
public:
    void insertData(std::string& name);
    void search(std::string& prefix);
};



#endif //SEARCHENGINE_DATA_H
