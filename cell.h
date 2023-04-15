#ifndef DNA_RNA_PROJECT_CELL_H
#define DNA_RNA_PROJECT_CELL_H
#pragma once

#include "genome.h"
#include "dna_utils.h"
using namespace std;
class Cell : protected Genome
{
private:
    int chromosomeCount;
    vector<Genome> chromosomes;
public:
    Cell(vector<Genome> chromosomes);

    Cell();

    void shouldApoptose();
    void setChromosome(vector<Genome> chromosomess);
    vector<Genome> getChromosome();
    int getChromosomeCount();
    void bigMutation(string S1, int n,string S2, int m);
    void subtleMutation(char n1, char n2, int n, int m);
    void reverseMutation(string S1, int n);
    void display();
    void findComplementPalindromes(int n);

};


#endif
