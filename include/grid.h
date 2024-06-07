
#ifndef EXAMPLE_GRID_H
#define EXAMPLE_GRID_H

#include <vector>
#include "IRender.h"

class Grid : public IRender{

public:
    std::vector<std::vector<short>> grid_create(unsigned int cell_size);
    void render() const override;

public:
    Grid(unsigned int height, unsigned int width);
    ~Grid();


private:

    int cell_size;
    unsigned int width;
    unsigned int height;
    std::vector<std::vector<short>> grid;
};


#endif //EXAMPLE_GRID_H
