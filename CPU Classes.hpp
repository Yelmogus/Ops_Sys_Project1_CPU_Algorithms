//
//  CPU Classes.hpp
//  Processes Algorithms
//
//  Created by Yang Li on 10/9/17.
//  Copyright © 2017 Yang Li. All rights reserved.
//

#ifndef CPU_Classes_hpp
#define CPU_Classes_hpp

#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Process
{
public:
    //CONSTRUCTORS
    Process(string name, vector<int> &stats); //based on a vector
    
    //ACCESSORS
    const string get_name() const {return name_;}
    int get_arrival() const {return arrival_time_;}
    int get_CPU_burst() const {return CPU_burst_time_;}
    int get_proc_id() const {return proc_id_;}
    int get_num_burst() const {return num_burst_;}
    int get_iotime() const {return io_time_;}
    
    //MODIFIERS
    //REPRESENTATION
    void print_process_info();
private:
    string name_;
    int arrival_time_;
    int CPU_burst_time_;
    int proc_id_;
    int num_burst_;
    int io_time_;
    
};

#endif /* CPU_Classes_hpp */
