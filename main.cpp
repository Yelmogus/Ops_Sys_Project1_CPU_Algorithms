//
//  main.cpp
//  Processes Algorithms
//
//  Created by Yang Li on 10/9/17.
//  Copyright © 2017 Yang Li. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "CPU Classes.hpp"

using std::string;
using std::vector;

void run_FCFS(){
    ;
}

void run_RR(){
    ;
}

void run_SRT(){
    ;
}

void split(string my_str, char delimiter, vector<string> &my_words){
    if(my_str[0] == '#'){
        return;
    }
    string token = "";
    for(int i = 0; i < my_str.size(); i++){
        if(my_str[i] == delimiter or my_str[i] == '\n'){
            my_words.push_back(token);
            token = "";
        }
        else{
            token += my_str[i];
        }
    }
    my_words.push_back(token);
}

void convert_int(vector<string> &my_words, vector<int> &my_stats){
    for(int i = 1; i < 5; i++){
        my_stats.push_back(stoi(my_words[i]));
    }
}

template <typename T>
void print_container(const T &container) {
    for(typename T::const_iterator iter = container.begin(); iter != container.end(); iter++){
        std::cout << *iter << std::endl;
    }
}


int main(int argc, const char * argv[]) {
    
    if(argc != 3){
        std::cerr << "ERROR: Invalid arguments" << std::endl;
        std::cerr << "USAGE: ./a.out <input-file> <stats-output-file>" << std::endl;
        return EXIT_FAILURE;
    }
    else{
        //Initializes the input and output files
        std::ifstream inputfile(argv[1]);
        std::ofstream outputfile(argv[2]);
        std::string text;
        
        //Error Checking if the output and input files are openable or not
        if (!inputfile.good())
        {
            std::cout << "Cannot open file => " << argv[1] << std::endl;
            return EXIT_FAILURE;
        }
        if (!outputfile.good())
        {
            std::cout << "Cannot open file => " << argv[2] << std::endl;
            return EXIT_FAILURE;
        }
        
        while(inputfile >> text){
            vector<string> CPU_strings;
            vector<int> CPU_stats;
            split(text, '|', CPU_strings);
            //print_container(CPU_strings);
            convert_int(CPU_strings, CPU_stats);
            Process my_process(CPU_strings[0], CPU_stats);
            my_process.print_process_info();
        }
    }
    return EXIT_SUCCESS;
}
