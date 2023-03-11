# SFgraph: Simple and Fast Graphing Program Using SFML
## Intro
SFgraph is a simple and fast graphing program that can create simplistic bar-chart graphs from csv files.
It makes use of the SFML library to display a window of the completed graph, including labelled axes and data.
This project was a really early project I made while I was learning cpp, and thus is written like a "C with Classes"
architecture instead of using modern cpp principles. However, I decided to spruce up the project slightly and open source it 
under the MIT license to make the project avalible to anyone sane enough to work with it, and to look back on this as a benchmark
in 5 years to see how far I have come.

## Installation
The latest version can be installed from the releases tab [here](https://github.com/elcosas/SFgraph/releases/tag/v0.1.0)\
Additionally, you can just download/clone the project and build from scratch using
`make build`

## Issues
As stated prior, this project was made when I was just learning programming, so there a couple of issues surrounding it's implementation:
- The program only works with 2 column csv files, and doesn't throw an error otherwise
- The program does not scale the data properly on the y-axis, and doesn't scale the window properly on the x-axis
