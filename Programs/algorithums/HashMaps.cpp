

#include <iostream>
#include <map>
#include <ostream>
#include <string>

bool hasVoted(std::map<std::string, int> hashMap, std::string name) {
    if (hashMap.find(name) != hashMap.end()) {
        std::cout << "get out you already voted " << name << std::endl;
        return true;
    }
    std::cout << "thanks for voting " <<  name << std::endl;
    return false;
}

int main() {
    std::map<std::string, int> dict;
    hasVoted(dict, "John");
}
