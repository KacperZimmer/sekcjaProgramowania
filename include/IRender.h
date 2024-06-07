#ifndef EXAMPLE_IRENDER_H
#define EXAMPLE_IRENDER_H


class IRender {

public:
    virtual void render() const = 0;


    virtual ~IRender() = default;

};


#endif //EXAMPLE_IRENDER_H
