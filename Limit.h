#ifndef LIMITER_H
#define LIMITER_H

#include "Processor.h"
#include <cstdint>
#include <cmath>

class Limiter: public Processor {
public:
    void processBuffer(unsigned char* buffer, int bufferSize);
    Limiter();
    virtual ~Limiter();
};


#endif //LIMITER_H
