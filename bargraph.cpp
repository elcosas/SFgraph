#include "include/bargraph.hpp"
#include <cmath>

int Bargraph::getMax() {
    int maxValue = static_cast<int>(*max_element(this->dataTable.begin(), this->dataTable.end())); 
    return std::ceil(maxValue / 5) * 5; // set axis to multiple of 5
}

int Bargraph::getLength() {
    return 500 + (this->dataTable.size() * 200);
}

void Bargraph::drawAxis(sf::RenderWindow &window) {
    for (int i=1; i <= 6; i++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(80.f, i * 100.f), sf::Color::Black), 
            sf::Vertex(sf::Vector2f(this->getLength() - 80, i * 100.f), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);
    }
}

void Bargraph::drawPlots(sf::RenderWindow &window) {
    for (int i=0; i < this->dataTable.size(); i++) {
        // need to get what percent the data value is of the max value
        // then use that percent to find height off 500
        double difference = this->dataTable[i]/this->getMax();
        double boxHeight = 500 * difference;
        sf::RectangleShape plot(sf::Vector2f(100.f, -boxHeight));
        plot.setFillColor(sf::Color::Blue);
        plot.setPosition(sf::Vector2f((i + 1) * 200.f, 600.f));
        window.draw(plot);
    }
}

void Bargraph::drawLabels(sf::RenderWindow &window) {
    sf::Font font;
    if(!font.loadFromFile("fonts/Roboto-Regular.ttf")) {
        return;
    }

    // render axis labels
    for (int i=0; i < 6; i++) {
        sf::Text label; // for some reason sf::Text constructor isn't working
        label.setFont(font);
        label.setString(std::to_string(static_cast<int>(this->getMax() * (1 - (0.2 * i)))));
        label.setCharacterSize(15);
        label.setFillColor(sf::Color::Black);
        label.setPosition(40.f, ((i + 1) * 100.f) - 10.f);
        window.draw(label);
    }

    // render graph labels
    for (int i=0; i < this->dataLabels.size(); ++i) {
        sf::Text groupLabel;
        groupLabel.setFont(font);
        groupLabel.setString(this->dataLabels[i]);
        groupLabel.setCharacterSize(15);
        groupLabel.setFillColor(sf::Color::Black);
        groupLabel.setPosition(sf::Vector2f((i + 1) * 200.f, 600.f));
        window.draw(groupLabel);
    }
}

void Bargraph::setData(CSV_Reader &data) {
    for (int i=1; i < data.getSize(); i++) {
        this->dataLabels.push_back(data.getIndex(i, 0));
        this->dataTable.push_back(std::stod(data.getIndex(i, 1)));
    }
}

void Bargraph::render(sf::RenderWindow &window) {
    window.clear(sf::Color::White);
    drawAxis(window);
    drawPlots(window);
    drawLabels(window);
    window.display();
}