#include "cell.cpp"
#include "genome.cpp"
#include "dna_utils.cpp"
#include "animal.cpp"
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n=1;
      cout << "\n1. Genome\n";
      cout << "2. Cell\n";
      cout << "3. Animal\n";
      cout << "0. Exit\n";
      cout<<"enter number\n";
    while(n != 0){
      cin>>n;
      if (n == 1) {
        cout << "11. Perform create DNA from RNA\n";
        cout << "12. Perform subtle mutation RNA\n";
        cout << "13. Perform big mutation RNA\n";
        cout << "14. Perform reverse mutation RNA\n";
        cout << "15. Perform subtle mutation DNA\n";
        cout << "16. Perform big mutation DNA\n";
        cout << "17. Perform reverse mutation DNa\n";
    } else if (n == 2) {
        cout << "21. Perform subtle mutation\n";
        cout << "22. Perform big mutation\n";
        cout << "23. Perform reverse mutation\n";
        cout << "24. Perform apoptosis\n";
        cout << "25. Perform palindrom \n";
    }  else if (n == 3) {
        cout << "31. Perform similarity\n";
        cout << "32. Perform are they same?\n";
        cout << "33. asexual Reproduction\n";
        cout << "34. Perform Reproduction\n";
        cout<<  "35.perform apoptosis\n";
    } else if(n == 0){
      return 0;
    }
      if(n == 11 || n == 12 || n == 13 || n == 14 || n==15 || n==16 || n==17){
        cout<<"create Genome"<<endl;
        string RNA;
        pair<string,string>DNA;
        cout<<"enter RNA\n";
        cin>>RNA;
        cout<<"enter first string of DNA\n";
        cin>>DNA.first;
        cout<<"enter second string of DNA\n";
        cin>>DNA.second;
        Genome genome;
        genome.receiveContent(RNA,DNA);
        genome.display();
        if(n == 11){
          genome.createDnaFromRna();
        }
        if(n == 12){
          char n1, n2;
          int m;
          cout << "Enter n1, n2, n (with spaces): ";
          cin >> n1 >> n2 >> m;
          genome.subtleMutationRNA(n1, n2, m);
       }
        if(n == 13){
          string s1, s2;
          cout << "Enter s1 and s2 (with space): ";
          cin >> s1 >> s2;
          genome.bigMutationRNA(s1, s2);
        }
        if(n == 14){
          string s1;
          cout << "Enter s1: ";
          cin >> s1;
          genome.reverseMutationRNA(s1);
        }
        if(n == 15){
          char n1, n2;
          int m;
          cout << "Enter n1, n2, n (with spaces): ";
          cin >> n1 >> n2 >> m;
          genome.subtleMutationDNA(n1, n2, m);
       }
        if(n == 16){
          string s1, s2;
          cout << "Enter s1 and s2 (with space): ";
          cin >> s1 >> s2;
          genome.bigMutationDNA(s1, s2);
        }
        if(n == 17){
          string s1;
          cout << "Enter s1: ";
          cin >> s1;
          genome.reverseMutationDNA(s1);
        }
       }

      if(n /10 == 2){
          cout<<"create Cell\n";
          cout<<"choose the number of chromosomes\n";
          int a;
          cin>>a;
          Cell c;
          vector<Genome> vg;
          Genome gen;
          for(int i=0; i<a; i++){
            pair<string,string>DNA;
            cout<<"enter first string of DNA\n";
            cin>>DNA.first;
            cout<<"enter second string of DNA\n";
            cin>>DNA.second;
            gen.receiveContent("NO RNA", DNA);
            vg.push_back(gen);
          }
          c.setChromosome(vg);
        if(n == 21){
          char n1, n2;
          int m1, m2;
          cout << "Enter n1, n2, m1, m2 (with spaces): ";
          cin >> n1 >> n2 >> m1>> m2;
          c.subtleMutation(n1, n2, m1, m2-1);
        }
        if(n == 22){
          string s1, s2;
          int number1, number2;
          cout<<"Which two chromosomes?(with space): ";
          cin >> number1>> number2;
          cout<<"Which two part?(with space)";
          cin>> s1>>s2;
          c.bigMutation(s1, number1-1, s2, number2-1);
        }
        if(n == 23){
          int number;
          string s;
          cout<< "Which chromosome?: ";
          cin>>number;
          cout<< "Which part?\n";
          cin >>s;
          c.reverseMutation(s, number-1);
        }
        if(n == 24){
          c.shouldApoptose();
        }
        if(n == 25){
          cout<<"Which chromosome?: ";
          int shomare;
          cin>>shomare;
          c.findComplementPalindromes(shomare-1);
        }
    }

      if(n==31 || n==32 || n==34){
        cout<<"create first Animal\n";
        cout<<"choose the number of chromosomes\n";
        int a;
        cin>>a;
        Cell c1;
        vector<Genome> vg;
        Genome gen1;
        Animal a1, a2, a3; 
        for(int i=0; i<a; i++){
          pair<string,string>DNA;
          cout<<"enter first string of DNA\n";
          cin>>DNA.first;
          cout<<"enter second string of DNA\n";
          cin>>DNA.second;
          gen1.receiveContent("No RNA", DNA);
          vg.push_back(gen1);
          }
        c1.setChromosome(vg);
        a1.setAnimalCell(c1);
        cout<<"create second Animal\n";
        cout<<"choose the number of chromosomes\n";
        cin>>a;
        Cell c2;
        vg.clear();
        Genome gen2;
        for(int i=0; i<a; i++){
          pair<string,string>DNA;
          cout<<"enter first string of DNA\n";
          cin>>DNA.first;
          cout<<"enter second string of DNA\n";
          cin>>DNA.second;
          gen2.receiveContent("No RNA", DNA);
          vg.push_back(gen2);
          }
        c2.setChromosome(vg);
        a2.setAnimalCell(c2);
        if(n == 31){
          cout<<a1.geneticDistance(a2)<<endl;
        }
        if(n == 32){
          if(a1==a2)
            cout<< "They are same";
          else 
            cout<<"They are different";
        }
        if(n == 34){
          a3=a1+a2;
          a3.display();
        }
  }
      if(n == 35 || n==33){
        cout<<"create  Animal\n";
        cout<<"choose the number of chromosomes\n";
        int a;
        cin>>a;
        Cell c1;
        vector<Genome> vg;
        Genome gen1;
        Animal a1,a3;
        for(int i=0; i<a; i++){
          pair<string,string>DNA;
          cout<<"enter first string of DNA\n";
          cin>>DNA.first;
          cout<<"enter second string of DNA\n";
          cin>>DNA.second;
          gen1.receiveContent("No RNA", DNA);
          vg.push_back(gen1);
          }
        c1.setChromosome(vg);
        a1.setAnimalCell(c1);
        if(n==35){
          a1.apoptosis();
        }
        if(n == 33){
          cout<<"asexual Reproduction of  animal";
          a3=a1.asexualReproduction();
          a3.display();
        }
}
}
}