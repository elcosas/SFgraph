#ifndef CSV_READER_HPP
#define CSV_READER_HPP

#include <string>
#include <vector>

class CSV_Reader {
private:
    std::vector<std::vector<std::string>> csv;

public:
    CSV_Reader(std::string);

    int getSize();
    std::string getIndex(int, int);
};

#endif