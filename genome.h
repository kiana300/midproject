#ifndef DNA_RNA_PROJECT_GENOME_H
#define DNA_RNA_PROJECT_GENOME_H

#include <string>
#include <vector>
using namespace std;
class Genome {
    string rna;
    pair<string, string> dna;
public:
    Genome();
    Genome(string rna, pair<string, string> dna);
    void receiveContent(string rna, pair<string, string> dna);
    void createDnaFromRna();
    void subtleMutation(char n1, char n2, int n);
    void bigMutation(string s1, string s2);
    void reverseMutation(string s1);
    virtual void display() ;
    string getRna();
    pair<string, string> getDna();

};

#endif //DNA_RNA_PROJECT_GENOME_H
