#include "include/csv-reader.hpp"

#include <fstream>
#include <sstream>

CSV_Reader::CSV_Reader(std::string file) {
    // Opens and reads the *.csv file arg into the
    // object's 2d vector map
    std::ifstream CsvFile(file);

    std::string lBuffer;
    std::string buffer;
    while(std::getline(CsvFile, lBuffer)) {  
        std::vector<std::string> temp;
        std::stringstream bstream(lBuffer);
        while(std::getline(bstream, buffer, ',')) {
            temp.push_back(buffer);
        }
        this->csv.push_back(temp);
    }
}

int CSV_Reader::getSize() {
    return this->csv.size();
}

std::string CSV_Reader::getIndex(int x, int y) {
    // Gets the value from the csv at the specified cell
    return this->csv[x][y];
}