#ifndef DNA_RNA_PROJECT_ANIMAL_H
#define DNA_RNA_PROJECT_ANIMAL_H
#pragma once
#include <time.h>
#include <random>
#include "cell.h"
class Animal: protected Cell{
private:
    Cell animalCell;
public:
    Animal();
    Cell getCell();
    void setAnimalCell(Cell animalCelll);
    double geneticDistance(Animal second);
    bool operator==(Animal second);
    Animal asexualReproduction();
    Animal operator+(Animal second);
    void apoptosis();
    void display();
    
};
#endif 