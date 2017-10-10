//
//  CPU Classes.cpp
//  Processes Algorithms
//
//  Created by Yang Li on 10/9/17.
//  Copyright © 2017 Yang Li. All rights reserved.
//

#include "CPU Classes.hpp"

Process::Process(std::string name, std::vector<int> &stats){
    name_ = name;
    proc_id_ = stats[0];
    CPU_burst_time_ = stats[1];
    num_burst_ = stats[2];
    io_time_ = stats[3];
}

void Process::print_process_info(){
    printf("Process Name: %s, ProcessID: %d, CPU Burst Time: %d, ", name_.c_str(), proc_id_, CPU_burst_time_);
    printf("Number of Bursts: %d, IO Time: %d\n", num_burst_, io_time_);
}
