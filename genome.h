#ifndef DNA_RNA_PROJECT_GENOME_H
#define DNA_RNA_PROJECT_GENOME_H
#pragma once
#include<vector>
#include<iostream>
#include<string>
#include <time.h>
#include <random>
#include <algorithm>
#include "dna_utils.h"
using namespace std;
class Genome {
private:
    string rna;
    pair<string, string> dna;
    int size_RNA;
public:
    Genome();
    Genome(string rna, pair<string, string> dna);
    void receiveContent(string rna, pair<string, string> dna);
    void createDnaFromRna();
    void subtleMutationRNA(char n1, char n2, int n);
    void bigMutationRNA(string s1, string s2);
    void reverseMutationRNA(string s1);
    void subtleMutationDNA(char n1, char n2, int n);
    void bigMutationDNA(string s1, string s2);
    void reverseMutationDNA(string s1);
    void display() ;
    string getRna();
    pair<string, string> getDna();

};

#endif //DNA_RNA_PROJECT_GENOME_H
