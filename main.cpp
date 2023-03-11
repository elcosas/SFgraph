#include "include/csv-reader.hpp"
#include "include/bargraph.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./sfgraph [FILENAME].csv";
        return 1;
    }

    std::cout << R"(
********************************************************
Welcome to SFgraph! (0.1.0)
Built by: Elcosas
Source available at 
Licensed under MIT
********************************************************
)";

    CSV_Reader data(argv[1]);

    Bargraph graph;
    graph.setData(data);

    sf::RenderWindow window(sf::VideoMode(graph.getLength(), 700), "Graph");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        graph.render(window);
    }

    return 0;
}