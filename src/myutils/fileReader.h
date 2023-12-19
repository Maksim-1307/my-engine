#pragma once

#include <fstream>
#include <sstream>

#include <iostream>

namespace myutils{

    void readFile(std::string path, std::string* output);
    void setCurrentDirectory(char** argv);

}