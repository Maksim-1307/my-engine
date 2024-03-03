#include "version.h"
#include <iomanip>

string get_version(){
    char * version = new char(50);
    tm * curr_tm;
    time_t curr_time;
	time(&curr_time);
	curr_tm = localtime(&curr_time);
    strftime(version, 50, "VoxelGame indev-%d.%m.%y", curr_tm);// << "\n";
    return version;
    
}