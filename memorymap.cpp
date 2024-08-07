//Written by Miles Brown
#include "memorymap.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor
MemoryMap::MemoryMap(){
    pair.base = 0;
    pair.limit = 0;
    baseLimits.push_back(pair);
}

//Destructor
MemoryMap::~MemoryMap(){
    for(auto& e : baseLimits)
        baseLimits.pop_back();
}

void MemoryMap::AddPair(string base, string limit){
    int baseInt = stoi(base);
    int limitInt = stoi(limit);

    pair.base = baseInt;
    pair.limit = limitInt;
    baseLimits.push_back(pair);
}

void MemoryMap::PrintTable(){
    cout << "Table of unused memory: " << endl;
    cout << "------------------------------------" << endl;
    cout << "Base Register    -    Limit Register" << endl;
    //for loop that goes through array values
    for(int i = 1; i < baseLimits.size(); ++i){
        cout << left << setw(22) << baseLimits.at(i).base << baseLimits.at(i).limit << endl;
    }
    cout << "------------------------------------" << endl;
}

int MemoryMap::CalculateMinUsedMemory(int base, int limit){return base+limit;}

int MemoryMap::CalculateMaxUsedMemory(int base){return base-1;}

int MemoryMap::CalculateMaxUnusedMemory(int base, int limit){return(base+limit)-1;}

void MemoryMap::PrintMap(){
    cout << "Memory Map Table: " << endl;
    int max = 15999;

    for(int i = 1; i < baseLimits.size(); ++i){
        cout << right << setw(30) << "----------" << '\n'
             << left << setw(10) << "Used:" << CalculateMinUsedMemory(baseLimits.at(i-1).base, baseLimits.at(i-1).limit) << '\n'
             << right << setw(20) << "|" << setw(11) << "|" << '\n'
             << left << setw(10) << " " << CalculateMaxUsedMemory(baseLimits.at(i).base) << '\n'
             << right << setw(30) << "----------" << '\n'
             << '\n'
             << right << setw(30) << "----------" << '\n'
             << left << setw(10) << "Unused:" << baseLimits.at(i).base << '\n'
             << right << setw(20) << "|" << setw(11) << "|" << '\n'
             << setw(10) << " " << CalculateMaxUnusedMemory(baseLimits.at(i).base, baseLimits.at(i).limit) << '\n'
             << right << setw(30) << "----------" << '\n'
             << endl;
    }
    cout << right << setw(30) << "----------" << '\n'
         << left << setw(10) << "Used:" << CalculateMinUsedMemory(baseLimits.at(baseLimits.size()-1).base, baseLimits.at(baseLimits.size()-1).limit) << '\n'
         << right << setw(20) << "|" << setw(11) << "|" << '\n'
         << setw(10) << " " << max << '\n'
         << right << setw(30) << "----------" << endl;
}

