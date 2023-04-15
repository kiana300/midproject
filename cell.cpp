#include "cell.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
Cell::Cell() {}

void Cell::setChromosome(vector<Genome> chromosomess)
{
  chromosomes=chromosomess;
  chromosomeCount=chromosomes.size();
}
vector<Genome> Cell::getChromosome()
{
  return chromosomes;
}
int Cell::getChromosomeCount()
{
  return chromosomeCount;
}
/*
 *This method determines whether the cell should undergo apoptosis (cell death)
 *based on the content of its chromosomes. It checks if the conditons are true or not.
 *If yes,delete the object.
*/
void Cell::shouldApoptose() {
  int count1=0,count2 =0,count3=0;
  for(int i=0;i<chromosomeCount;i++){
    pair<string,string>dna=chromosomes[i].getDna();
    for(int j=0; j< dna.first.size();j++){ 
      if(dna.first[j] != complement(dna.second[j])){
        count1++;
      }
      if(dna.first[j] == 'A' || dna.first[j] == 'T' || dna.second[j]=='A' || dna.second[j]=='T'){
        count2++;
      }
      if(dna.first[j] == 'C' || dna.first[j] == 'G' || dna.second[j]=='C' || dna.second[j]=='G'){
        count3++;
      }
    }
    if(count1>5 || count2>6*count3){
      cout<< "Chromosomes number "<< i+1<< " is dead\n";
      delete this;
    }
    else
    {
      cout<< "Chromosomes number "<< i+1<< " is alive\n";
    }
    count1=0;
    count2=0;
    count3=0;
  }
}
/*
 *This method applies a big mutation to two chromosomes in the cell, identified
 *by indices n and m. It swaps the specified DNA segments S1 and S2 in the
 *respective chromosomes. The method checks if the indices are within the valid
 *range before applying the mutation.
*/
void Cell::bigMutation(string S1, int n, string S2,int m) {
  if (n >= 0 && n < chromosomeCount && m >= 0 && m < chromosomeCount) {
    chromosomes[n].bigMutationDNA(S1, S2);
    chromosomes[m].bigMutationDNA(S2, S1);
  }
}
/*
 *This method applies a subtle mutation to a single chromosome in the cell,
 *identified by index n. It replaces the n1 nucleotide with the n2 nucleotide at
 *position m in the chromosome. The method checks if the index is within the
 *valid range before applying the mutation.
*/
void Cell::subtleMutation(char n1, char n2, int m, int n) {
  if (n >= 0 && n < chromosomeCount) {
    chromosomes[n].subtleMutationDNA(n1, n2, m);
  }
}
/*
 *This method applies a reverse mutation to a single chromosome in the cell,
 *identified by index n. It reverses the specified DNA segment S1 in the
 *chromosome. The method checks if the index is within the valid range before
 *applying the mutation.
*/
void Cell::reverseMutation(string S1, int n) {
  if (n >= 0 && n < chromosomeCount) {
    chromosomes[n].reverseMutationDNA(S1);
  }
}
/*
This function takes string as input and then check .if the string is palindrom 
*return true else return false
*/

void Cell::findComplementPalindromes(int n) {
  if (n >= 0 && n < chromosomeCount) {
    string DNA1 = chromosomes[n].getDna().first;
    string DNA2 = chromosomes[n].getDna().second;
    for (int i = 0; i < DNA1.size()-4; i++) {
      for (int j = i + 4; j <= DNA1.size(); j++) {
        string substr = DNA1.substr(i, j-i);
        if(substr.size()%2 != 0){
          continue;
        }
        if (isPalindrom(substr)) {
          cout<<substr<<endl;
        }
      }
    }
    cout<<endl;

    for (int i = 0; i < DNA2.size()-4; i++) {
      for (int j = i + 4; j <= DNA2.size(); j++) {
        string substr = DNA2.substr(i, j-i);
        if(substr.size()%2 != 0){
          continue;
        }
        if (isPalindrom(substr)) {
          cout<<substr<<endl;
        }
      }
    }
  }
  cout<<endl;
}

void Cell::display(){
  cout << "Cell content:" << endl;
  for (auto chromosome : chromosomes) {
    chromosome.display();
  }
}