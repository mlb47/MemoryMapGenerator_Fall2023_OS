//Written by Miles Brown
#ifndef MEMORYMAP_H
#define MEMORYMAP_H
#include <string>
#include <vector>
#include "BaseLimitPair.hpp"

class MemoryMap{
    public:
    MemoryMap();
    ~MemoryMap();
    void AddPair(std::string base, std::string limit);
    void PrintTable();
    int CalculateMinUsedMemory(int base, int limit);
    int CalculateMaxUsedMemory(int base);
    int CalculateMaxUnusedMemory(int base, int limit);
    void PrintMap();

    private:
    BaseLimitPair pair;
    std::vector<BaseLimitPair> baseLimits;
};
#endif