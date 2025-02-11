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
std::vector<std::string> fileLines;

int printLinesWithWords() {
    return 0;
}

int Tflag() {
    std::vector<std::string> lastlines;
    int g = 0;
    for (int i = fileLines.size() - numberOfLines; g < numberOfLines ; i++) {
        lastlines.push_back(fileLines[i]);
        g++;
    }
    fileLines = lastlines;
    return 0;
}

int Sflag() {
    int run = 0;
    std::map<int, std::string> indexCount;
    for (int i = 0; i < numberOfLines; i++) {
        if (fileLines[i].find(target) != std::string::npos) {
            for (int g = i - numberOfLines; g < i + contextDown; g++) {
                std::cout << g << std::endl;
                if (g < 0) g = 0;
                if (indexCount.find(g) == indexCount.end()) {
                    indexCount.insert(std::pair<int, std::string>(g, fileLines[g]));
                    if (!run++) std::cout << indexCount.find(g)->second;
                    else std::cout << "\n" << indexCount.find(g)->second;
                }
            }
        }

    }
    return 0;
}

int catFile() {
    int run = 0;
    std::string data;
    std::ifstream inputFile(fileName);
    while (std::getline(inputFile, data)) {
        fileLines.push_back(data);
    }
    if (sFlag) {
        Sflag();
        return 0;
    }
    if (tFlag and numberOfLines > 0) Tflag();
    if (numberOfLines > 0) {
        for (int i = 0; i < numberOfLines; i++) {
            if (!sFlag) {
                if (!run++) std::cout << fileLines[i];
                else std::cout << "\n" << fileLines[i];
            }
            if (fileLines[i].find(target) != std::string::npos and sFlag) {
                if (!run++) std::cout << fileLines[i];
                else std::cout << "\n" << fileLines[i];
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
