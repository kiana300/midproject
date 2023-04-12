#include "genome.h"
#include <algorithm>
#include <iostream>
using namespace std;
Genome::Genome() {}
Genome::Genome(string rna, pair<string, string> dna): rna(rna), dna(dna) {}
/*
 *This method is a getter that returns a reference to the rna field of the
 *Genome object.
*/
string Genome::getRna() { return rna; }

/*
 *This method is a getter that returns a reference to the dna field of the
 *Genome object, which is a pair of DNA strings.
*/
pair<string, string> Genome::getDna(){ return dna; }

/*
 *This method sets the RNA and DNA content of the Genome object. It takes an RNA
 *string and a pair of DNA strings as arguments and assigns them to the Genome's
 *rna and dna fields.
*/
void Genome::receiveContent(string rna,pair<string, string> dna) {
  this->rna = rna;
  this->dna = dna;
}

/*
 *This method generates the DNA content from the RNA content of the Genome
 *object. It first converts the RNA string to a DNA string by replacing 'U' with
 *'T', then generates the complementary DNA strand. The method then sets the dna
 *field with the DNA strands as a pair of strings and prints the DNA.
*/
void Genome::createDnaFromRna() {
  // Generate the complementary DNA 
  string dna_complement;
  for (int i=0; i<rna.size(); i++) {
    dna_complement += complement(rna[i]);
  }

  // Print the DNA
  cout << rna << ", " << dna_complement << endl;
}

/*
 *This method applies a subtle mutation to the Genome object by replacing a
 *certain number of occurrences of a nucleotide (n1) with another nucleotide
 *(n2). It takes the nucleotides and the number of replacements as arguments and
 *performs the replacements on the RNA and both DNA strands.
*/
void Genome::subtleMutation(char n1, char n2, int n) {
    int count = 0;
    for (int i = 0; i < rna.size(); i++) {
        if (rna[i] == n1 && count<=n) {
            rna[i] = n2;
            count++;
    }
  }
    cout<<rna<<endl;
    count = 0;
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
    cout<<dna.first<<", "<<dna.second;
}

/*
 * This method applies a big mutation to the Genome object by replacing a DNA
 * segment (s1) with another segment (s2). It finds the occurrences of the
 * segment in the RNA and DNA strands and replaces them accordingly. It also
 * finds the occurrences of the complement of the segment in the second DNA
 * strand and replaces them as well.
*/
void Genome::bigMutation(string s1,string s2) {
    size_t pos = rna.find(s1);
    if (pos != string::npos) {
        rna.replace(pos, s1.length(), s2);
    }
    cout<< rna <<endl;
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
void Genome::reverseMutation(string s1) {
    string s1Reversed(s1.rbegin(), s1.rend());
    string s1ComplementReversed ="";
    for (int i=0; i<s1Reversed.size(); i++) {
        s1ComplementReversed += complement(s1Reversed[i]);
    }
    int pos = rna.find(s1);
    while (pos != string::npos) {
        rna.replace(pos, s1.length(), s1Reversed);
    }
    cout << rna <<endl;
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
            cout << dna.first <<", "<< dna.second;
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
            cout << dna.first <<", "<< dna.second;
            break;
        }
    }
    if(ans == false){
       cout << "Not found" << endl;
    }
}

/*
 *This method displays the content of the Genome object by printing the RNA and
 *DNA strings.
*/
void Genome::display() {
    cout << "RNA: " << rna << endl;
    cout << "DNA: " << dna.first << ", " << dna.second << endl;
}
