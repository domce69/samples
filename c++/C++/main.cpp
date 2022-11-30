//
//  main.cpp
//  ta952-a1
//
//  Created by Thomas Andraos on 4/8/21.
//

#include <iostream>
#include <fstream>
#define max 50000
using std::string;

class Stack{
    int index;
    string wrds[max];
    int counts[max];
    bool isUnique = true;
    string alphabet = "acbdefghijklmnopqrstuvwxyz";
    string compWord = "";
    
public:
    int readTextFile(std::string txtFile);
    void printFirstFifteen();
    void printLastFifteen(int n);
    void sortDesending(int n);
    void sortAlphabet(int n);
    void printList(int n);
};

int Stack::readTextFile(std::string txtFile){
    
    std::ifstream inData;
    std::string word;
    int totalWords = 0;
    int j = 0;
    
    inData.open(txtFile);
    
    if(!inData){
        std::cerr << "Error opening file: " + txtFile + ". Please check the file path and try again." << std::endl;
        exit(0);
    }
    
    while(inData.good()) {
        while(inData >> word){

            for(char &c : word){
                
                c = char(tolower(c));
                
                for(char const &d : alphabet){
                    
                    if (c == d) {
                        compWord += c;
                    }
                }
            }
            
            for(int i = 0; i < j; i++){
                
                if(compWord == wrds[i]){
                    counts[i]+=1;
                    compWord = "";
                    isUnique = false;
                    totalWords++;
                }
            }
            
            if(isUnique){
                wrds[j] = compWord;
                counts[j] = 1;
                compWord = "";
                totalWords++;
                j++;
            }
            isUnique = true;
        }
    }
    std::cout << "Total word count: " << totalWords << std::endl;
    std::cout << "Total unique word count: " << j << std::endl;
    return j;
}

void Stack::printFirstFifteen(){
    std::cout << "\nFirst Fifteen" << std::endl;
    for(int i = 0; i < 15; i ++){
        std::cout << wrds[i] << " " << counts[i] << std::endl;
    }
}

void Stack::printLastFifteen(int n){
    std::cout << "\nLast Fifteen" << std::endl;
    for(int i = n - 1; i > n - 16; i--){
        std::cout << wrds[i] << " " << counts[i] << std::endl;
    }
}

void Stack::sortDesending(int n){
    
    for (int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++){
            if(counts[j] > counts[i]){
                string word = wrds[j];
                int numb = counts[j];
                
                wrds[j] = wrds[i];
                wrds[i] = word;
                
                counts[j] = counts[i];
                counts[i] = numb;
            }
        }
    }
}

void Stack::sortAlphabet(int n){

    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j++) {
            if (counts[i] == counts[j]) {
                if (wrds[i].compare(wrds[j])>0) {
                    string word = wrds[i];
                    wrds[i] = wrds[j];
                    wrds[j] = word;
                }
            }
        }
    }
}
    

void Stack::printList(int n){
    for(int i = 0; i < n; i++){
        std::cout << wrds[i] << " " << counts[i] << std::endl;
    }
}

int main(int argc, const char * argv[]) {

    Stack st1;
    std::string txtFile;
    std::cout << "Enter file path of text file including .txt extention: " << std::endl;
    std::cin >> txtFile;
    int n = st1.readTextFile(txtFile);
    st1.sortDesending(n);
    st1.sortAlphabet(n);
    st1.printFirstFifteen();
    st1.printLastFifteen(n);
    
    
    return 0;
}
