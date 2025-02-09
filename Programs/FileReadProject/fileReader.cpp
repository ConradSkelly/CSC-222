#include <fstream>
#include <iostream>
#include <string>

int catFile(int run, std::string fileName) {
    std::string data;
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cout << "could not open file " << fileName << std::endl;
        return 1;
    }

    while (std::getline(inputFile, data)) {
        if (!run++) std::cout << data;
        else std::cout << "\n" << data;
    }
    inputFile.close();
    return 0;
}

int catFileNLines(int run, std::string fileName, int nLines) {
    std::string data;
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cout << "could not open file " << fileName << std::endl;
        return 1;
    }

    while (nLines-- && std::getline(inputFile, data)) {

        if (!run++) std::cout << data << std::endl;
        else std::cout << data << std::endl;
    }
    inputFile.close();
    return 0;
}

int main(int argc, char *argv[]) {
    int thirdParametervaid = 0;
    int numberOfLines;
    if (argc < 2) {
        std::cerr << "Usage: fileReader <filename> <number of lines: optional>" << std::endl;
        return 1;
    }
    if (argc > 2) {
        try {
            numberOfLines = std::stoi(argv[2]);
            thirdParametervaid = 1;
        }
        catch (...) {
            std::cout << "invalid third argument\n" << std::endl;
        }
    }

    int run = 0;
    std::string fileName = argv[1];

    if (thirdParametervaid) {
        catFileNLines(run, fileName, numberOfLines);
    }
    else catFile(run, fileName);

    return 0;
}
