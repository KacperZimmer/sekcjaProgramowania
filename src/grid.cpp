
#include <random>

#include "raylib.h"
#include "../include/grid.h"
#include <iostream>

int generateNumberInRange(int begin, int end) {
    /*
     * Generates number in given range starting from begin to end
     */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(begin, end);

    return distr(gen);
}

Grid::Grid(unsigned int height, unsigned int width) {

    this->cell_size = 1;
    this->width = width;
    this->height = height;
}

std::vector<std::vector<short>> Grid::grid_create(unsigned int cell_size) {

    /*
     * Generates representation of a board based on a cell size
     *
     */
    this->cell_size = cell_size;

    unsigned int rows = this->width / cell_size;
    unsigned int cols = this->height / cell_size;

    this->grid = std::vector<std::vector<short>> (cols, std::vector<short>(rows));


    for(size_t col = 0; col < cols; ++col){


        for(size_t row = 0; row < rows; ++row){

            this->grid[col][row] = generateNumberInRange(0,1);
        }

    }

    return grid;
}

Grid::~Grid() {

}

void Grid::render() const {
    int xPos{}, yPos{};

    for(auto rowIt = this->grid.begin(); rowIt != this->grid.end(); ++rowIt){
        xPos = 0;

        for(auto colIt = rowIt->begin(); colIt != rowIt->end(); ++colIt){

            if(*colIt == 1){
                DrawRectangle(xPos,yPos,this->cell_size,this->cell_size,BLUE);
            }
            xPos += this->cell_size;
        }
        yPos += this->cell_size;
    }

}
