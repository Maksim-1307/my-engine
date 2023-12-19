#include "fileReader.h"


void myutils::readFile(std::string path, std::string* output){

    std::ifstream stream;
    std::stringstream sbuffer;

    stream.open(path);

    if (stream.is_open() || !stream.good()){
        //std::cout << "File is successfully opened" << std::endl;
    } else {
        std::cerr << "OPEING ERROR: " << strerror(errno) << std::endl;
    }

    sbuffer << stream.rdbuf();

    *output = sbuffer.str();

}


void myutils::setCurrentDirectory(char** argv){

    std::string current_path(argv[0]);
	int slashid = current_path.find_last_of("/");
	current_path = current_path.substr(0, slashid+1);
	std::filesystem::current_path(current_path);

}