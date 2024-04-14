//
// Created by alex on 05.04.2024.
//

#include <algorithm>
#include "Data.h"

void Data::insertData(std::string &name) {
    this->names.push_back(name);
    std::sort(names.begin(), names.end());
}

void Data::search(std::string &prefix) {

}
