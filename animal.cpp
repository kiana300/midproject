#include"animal.h"
#include <time.h>
#include <random>
#include <algorithm>
using namespace std;

Animal::Animal() {}

void Animal::setAnimalCell(Cell animalCelll){
  animalCell=animalCelll;
}
Cell Animal::getCell()
{
  return animalCell;
}
/*check genetic distance between two animal .
*if size of chromosomes are diffrent return 0 else check each character of animals chromosomes
*if two characters are the same  add to same_count.
*AT end division same_count to size of chromosomes.
*/
double Animal::geneticDistance(Animal other){
    if(animalCell.getChromosome().size()!=other.animalCell.getChromosome().size()){
        return 0.0;
    }
    int same_count = 0;
    int all_count = 0;
    for (int i = 0; i < animalCell.getChromosome().size(); i++) {
      for (int j = 0; j < animalCell.getChromosome()[i].getDna().first.size(); j++) {
        if (animalCell.getChromosome()[i].getDna().first[j] == other.animalCell.getChromosome()[i].getDna().first[j]) {
          same_count++;
      }
        if (animalCell.getChromosome()[i].getDna().second[j] == other.animalCell.getChromosome()[i].getDna().second[j]) {
          same_count++;
      }
        all_count += 1;
    }
      all_count = all_count *2;
  }
  return same_count * 100/all_count; 
}
/*if return number of genticdistance more than 70 return true.
*else return false.
*/
bool Animal::operator==(Animal other) {
  return geneticDistance(other) > 70;
}
/*Doubles the number of chromosomes to randomly select.
*/
Animal Animal::asexualReproduction(){
  int n= animalCell.getChromosomeCount();
  vector<Genome>duplicated_chromosomes = animalCell.getChromosome();
  vector<Genome>child;
  Cell cellChild;
  Animal animalChild;
  while(true){
   for(int i=0; i<n; i++){
    duplicated_chromosomes.push_back(animalCell.getChromosome()[i]);
  }
    random_shuffle(duplicated_chromosomes.begin(), duplicated_chromosomes.end());
    for (int i=0; i<n; i++){
      child.push_back(duplicated_chromosomes[i]);
  }
    cellChild.setChromosome(child);
    animalChild.setAnimalCell(cellChild);
    if(geneticDistance(animalChild)>70){
      break;
    }
    duplicated_chromosomes.clear();
    child.clear();
    //cout<<"killed";
  }
  return animalChild;
}

/*Used to reproduce sex random is taken from two animal and puts it to the animalchild*/
Animal Animal::operator+(Animal second) {
  if (animalCell.getChromosome().size() != second.animalCell.getChromosome().size()) {
    cout<<"Animals have different numbers of chromosomes";
  }
  if (animalCell.getChromosome().size() % 2 != 0 ||second.getChromosome().size() % 2 != 0 ) {
    cout<<"Odd number of chromosomes, sexual reproduction not possible";
  }
  int n= animalCell.getChromosomeCount();
  Animal firstChild = asexualReproduction();
  Animal secondChild = second.asexualReproduction();
  Cell cellChild;
  Animal animalChild;
  vector<Genome>child;
  vector<Genome>chromosomes;
  while(true){
    chromosomes = firstChild.getCell().getChromosome();
    random_shuffle(chromosomes.begin(), chromosomes.end());
    for (int i=0; i<n/2; i++){
      child.push_back(chromosomes[i]);
  }
    chromosomes = secondChild.getCell().getChromosome();
    random_shuffle(chromosomes.begin(), chromosomes.end());
    for (int i=0; i<n/2; i++)
  {
      child.push_back(chromosomes[i]);
  }
    cellChild.setChromosome(child);
    animalChild.setAnimalCell(cellChild);
    if(geneticDistance(animalChild)>70){
      break;
    }
    chromosomes.clear();
    child.clear();
    //cout<<"DEATH";
}
  return animalChild;
}
/*This method checks each chromosomes and removes the chromosomes that does not
*have the necessary conditions.
*/
void Animal::apoptosis() {
  animalCell.shouldApoptose();
}

void Animal::display(){
  animalCell.display();
}

