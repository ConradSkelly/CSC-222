#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int hFlag = 0;
int tFlag = 0;
int sFlag = 0;
int numberOfLines;
int contextDown;
int globalArgc;
char **globalArgv;
std::string fileName;
std::string target;
std::vector<std::string> fileLine;

int printLinesWithWords() {
    return 0;
}

int Tflag() {
    std::vector<std::string> lastlines;
    int g = 0;
    for (int i = fileLine.size() - numberOfLines; g < numberOfLines ; i++) {
        lastlines.push_back(fileLine[i]);
        g++;
    }
    fileLine = lastlines;
    return 0;
}

int Sflag() {
    int run = 0;
    int beginingContext = 0;
    std::map<int, std::string> indexCount;
    for (int i = 0; i < fileLine.size(); i++) {
            if (fileLine[i].find(target) != std::string::npos) {
            if (i > 0 and !beginingContext++) std::cout << "...\n";
            for (int g = i - numberOfLines; g <= i + contextDown; g++) {
                if (g < 0) g = 0;
                if (indexCount.find(g) == indexCount.end()) {
                    indexCount.insert(std::pair<int, std::string>(g, fileLine[g]));
                    if (!run++) std::cout << indexCount.find(g) -> second;
                    else std::cout << "\n" << indexCount.find(g) -> second;
                }
                beginingContext = 1;
                if (g == fileLine.size() - 1) break;
            }
            if (indexCount.find(fileLine.size() - 1) == indexCount.end() or !run) std::cout << "\n...";
        }
    }
    for (const auto pair : indexCount) {
        std::cout << "key: " << pair.first << " value: " << pair.second << std::endl;
    }
    return 0;
}

int catFile() {
    int run = 0;
    std::string data;
    std::ifstream inputFile(fileName);
    while (std::getline(inputFile, data)) {
        fileLine.push_back(data);
    }
    if (sFlag) {
        Sflag();
        return 0;
    }
    if (tFlag and numberOfLines > 0) {
        Sflag();
        inputFile.close();
        return 0;
    }
    if (numberOfLines > 0) {
        for (int i = 0; i < numberOfLines; i++) {
            if (!sFlag) {
                if (!run++) std::cout << fileLine[i];
                else std::cout << "\n" << fileLine[i];
            }
            if (fileLine[i].find(target) != std::string::npos and sFlag) {
                if (!run++) std::cout << fileLine[i];
                else std::cout << "\n" << fileLine[i];
            }
        }
    }
    inputFile.close();
    return 0;
}

int catchArgumentError() {
    if (globalArgc < 2) {
        std::cerr << "Usage: fileReader <filename> <number of lines: optional>" << std::endl;
        return 1;
    }
    return 0;
}

int setFlags() {
    int i = 0;
    while (++i < (globalArgc)) {
        std::string flag = std::string(globalArgv[i]).substr(0,2);
        if (flag == "-h") numberOfLines = std::stoi(std::string(globalArgv[i]).substr(2)), hFlag = 1;
        else if (flag == "-t") contextDown = std::stoi(std::string(globalArgv[i]).substr(2)), tFlag = 1;
        else if (flag == "-s") target = std::string(globalArgv[i]).substr(2), sFlag = 1;
        else fileName = globalArgv[i];
    }
    return 0;
}

int fileExists() {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cout << "could not open file " << fileName << std::endl;
        return 1;
    }
    return 0;
}

int numberOfLinesInFile() {
    std::ifstream inputFile(fileName);
    std::string line;
    int numLines = 0;
    while (std::getline(inputFile, line)) {
        numLines++;
    }
    return numLines;
}

int setNumberOfLinesToMax() {
    int numLines = numberOfLinesInFile();
    if (numberOfLines > numLines) numberOfLines = numLines;
    return 0;
}

int main(int argc, char *argv[]) {
    globalArgc = argc;
    globalArgv = argv;
    if (catchArgumentError()) return 1;
    setFlags();
    if (fileExists()) return 2;
    if (hFlag == 0)  numberOfLines = numberOfLinesInFile();
    if (hFlag == 1) setNumberOfLinesToMax();
    catFile();
    return 0;
}
