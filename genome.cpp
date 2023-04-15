#include "genome.h"
#include<vector>
#include<iostream>
#include<string>
using namespace std;
Genome::Genome() {}
Genome::Genome(string rna, pair<string, string> dna): rna(rna), dna(dna) {}

string Genome::getRna() { return rna; }

pair<string, string> Genome::getDna(){ return dna; }
/*
 *This method sets the RNA and DNA content of the Genome object. It takes an RNA
 *string and a pair of DNA strings as arguments and assigns them to the Genome's
 *rna and dna fields.
*/
void Genome::receiveContent(string rna,pair<string, string> dna) {
  this->rna = rna;
  this->dna = dna;
  size_RNA=rna.length();
}

void Genome::createDnaFromRna() {
  string dna_complement;
  for (int i=0; i<rna.size(); i++) {
    dna_complement += complement(rna[i]);
  }

  cout << rna << ", " << dna_complement << endl;
}
/*
 *This method applies a subtle mutation to the Genome object by replacing a
 *certain number of occurrences of a nucleotide (n1) with another nucleotide
 *(n2). It takes the nucleotides and the number of replacements as arguments and
 *performs the replacements on the RNA and both DNA strands.
*/
void Genome::subtleMutationRNA(char n1, char n2, int n) {
     int count = 0;
    for (int i = 0; i < rna.size(); i++) {
        if (rna[i] == n1 && count<=n) {
            rna[i] = n2;
            count++;
    }
  }
    cout<<rna<<endl;
}
void Genome::subtleMutationDNA(char n1, char n2, int n) {
     int count = 0;
    for (int i = 0; i < dna.first.size() && count < n; i++) {
        if (dna.first[i] == n1) {
            dna.first[i] = n2;
            dna.second[i]=complement(n2);
            count++;
    }
        if (dna.second[i] == n1) {
            dna.first[i] = complement(n2);
            dna.second[i]=n2;
            count++;
    }
  }
    cout<<dna.first<<", "<<dna.second<<endl;
}
/*
 * This method applies a big mutation to the Genome object by replacing a DNA
 * segment (s1) with another segment (s2). It finds the occurrences of the
 * segment in the RNA and DNA strands and replaces them accordingly. 
*/
void Genome::bigMutationRNA(string s1,string s2) {
  bool ans = false;
   for(int i=0;i<rna.size();i++){
    string a="";
        for (int j=i; j<i+s1.size(); j++){
            a += rna[j];
        }
        int cou1 = i;
        if(s1 == a){
            ans = true;
            rna.replace(cou1, s1.size(), s2);
        }
   }
   if(ans== false){
    cout<<"NOT found\n";
   }
    cout<< rna <<endl;
}
void Genome::bigMutationDNA(string s1,string s2) {
    string s2Complement = "";
    bool ans = false;
    for (int i=0; i<s2.size(); i++){
        s2Complement += complement(s2[i]);
    }
    for (int i=0; i<dna.first.size(); i++){
        string a="";
        for (int j=i; j<i+s1.size(); j++){
            a += dna.first[j];
        }
        int cou1 = i;
        if(s1 == a){
            ans = true;
            dna.first.replace(cou1, s1.size(), s2);
            dna.second.replace(cou1, s1.size(), s2Complement);
            cout << dna.first <<", "<< dna.second << endl;
            break;
        }
        a="";
        for(int j=i; j<i+s1.size(); j++){
            a += dna.second[j];
        }
        if(s1 == a){
            ans=true;
            dna.second.replace(cou1, s1.size(), s2);
            dna.first.replace(cou1, s1.size(), s2Complement);
            cout << dna.first <<", "<< dna.second << endl;
            break;
            }
    }
    if(ans == false){
        cout << "Not found" << endl;
    }
}
/*
 *This method applies a reverse mutation to the Genome object by reversing a DNA
 *segment (s1). It first generates the reversed and complement reversed strings
 *from the segment. Then, it finds the occurrences of the segment in the RNA and
 *DNA strands and replaces them with the reversed strings.
*/
void Genome::reverseMutationRNA(string s1) 
{
  bool ans =false;
  string s1Reversed;
  for(int i=s1.size()-1;i>=0;i--){
    s1Reversed += s1[i];
    }
  for(int i=0;i<rna.size();i++){
    string a="";
    for (int j=i; j<i+s1.size(); j++){
       a += rna[j];
        }
      int cou1 = i;
      if(s1 == a){
        ans = true;
        rna.replace(cou1, s1.size(), s1Reversed);
        }
   }
   if(ans== false){
    cout<<"NOT found\n";
   }
    cout<< rna <<endl;
}
void Genome::reverseMutationDNA(string s1) 
{
    string s1Reversed;
    for(int i=s1.size()-1;i>=0;i--){
      s1Reversed += s1[i];
    }
    string s1ComplementReversed ="";
    for (int i=0; i<s1Reversed.size(); i++) {
        s1ComplementReversed += complement(s1Reversed[i]);
    }
    bool ans = false;
    for(int i=0; i<dna.first.size(); i++){
        string a = "";
        for(int j=i; j<i+s1.size(); j++){
            a += dna.first[j];
        }
        int cou1 = i;
        if(s1 == a){
            dna.first.replace(cou1,s1.size(),s1Reversed);
            dna.second.replace(cou1,s1.size(),s1ComplementReversed);
            ans = true;
            cout << dna.first <<", "<< dna.second<<endl;
            break;
         }
        a = "";
        for(int j=i; j<i+s1.size(); j++){
            a += dna.second[j];
        }
        if(s1 == a){
            dna.second.replace(cou1,s1.size(),s1Reversed);
            dna.first.replace(cou1,s1.size(),s1ComplementReversed);
            ans = true;
            cout << dna.first <<", "<< dna.second<<endl;
            break;
        }
    }
    if(ans == false){
       cout << "Not found" << endl;
    }
}

void Genome::display() {
    cout << "RNA: " << rna << endl;
    cout << "DNA: " << dna.first << ", " << dna.second << endl;
}
