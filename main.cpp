//Written by Miles Brown
#include<iostream>
#include<sstream>
#include<fstream>
#include "memorymap.hpp"
using namespace std;

int main(){

    MemoryMap MemoryMap;
    ifstream input;
    string baseRegister;
    string limitRegister;

    cout << "This program is a Memory Map Generator. A memory map is created based on given base and limit register values. From this information, current used and unused system memory areas will be generated." << endl;
    cout << endl;

    //Open input file
    input.open("23F_COP4610_Project1_InputFile.txt");

    //Check it successfully opens
    if(!input.is_open()){
        cout << "Failed to open file" << endl;
    }

    //Get data from file
    while(input >> baseRegister >> limitRegister){
        MemoryMap.AddPair(baseRegister, limitRegister);
    }
    MemoryMap.PrintTable();
    MemoryMap.PrintMap();

    input.close();
    return 0;
}