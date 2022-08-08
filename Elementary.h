#ifndef PCALGORITHM_ELEMENTARY_H
#define PCALGORITHM_ELEMENTARY_H
#include <cstdio>
#include <iostream>
#include <vector>

#define DIM 5
#define LOWDIM 0
#define HIGHDIM 1

using namespace std;

class Rule5 {
public:
    int id;
    uint32_t range[5][2];
    int mask[5];
    int priority;

    void printRule();
};

class Rule12 {
public:
    int id;
    uint64_t range[12][2];
    int mask[12];
    int priority;
};

class Packet5 {
public:
    uint32_t range[5];
};

class Packet12 {
public:
    uint64_t range[12];
};

class Classifier {
public:
    virtual int buildTree5() = 0;
    virtual int buildTree12() = 0;
    virtual int classifiAPacket5(Packet5 *packet) = 0;
    virtual int classifiAPacket12(Packet12 *packet) = 0;
    virtual uint64_t calMemorySize() = 0;
};
#endif //PCALGORITHM_ELEMENTARY_H
