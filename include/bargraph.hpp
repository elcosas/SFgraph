#ifndef BARGRAPH_HPP
#define BARGRAPH_HPP

#include "csv-reader.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Bargraph {
private:
    std::string graphTitle;
    std::vector<double> dataTable;
    std::vector<std::string> dataLabels;

    int getMax();
    void drawAxis(sf::RenderWindow&);
    void drawPlots(sf::RenderWindow&);
    void drawLabels(sf::RenderWindow&);

public:
    int getLength();
    void setData(CSV_Reader&);
    void render(sf::RenderWindow&);
};

#endif