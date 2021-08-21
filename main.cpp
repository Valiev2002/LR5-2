#include <iostream>
#include "QueueList.h"
int main() {
    QueueList<int>lab{};
    std::cout<<"Getting index from front: "<<std::endl;
   lab.front();
   std::cout<<"Getting index from back: "<<std::endl;
   lab.back();
   std::cout<<"Pop front: "<<std::endl;
lab.pop_front();
std::cout<<"Push back: "<<std::endl;
lab.push_back(lab,3);
std::cout<<"Size: "<<std::endl;
lab.size();
std::cout<<"Begin iterator: "<<std::endl;
lab.begin();
std::cout<<"End iterator: "<<std::endl;
lab.end();
std::cout<<"Checking if it is empty: "<<std::endl;
lab.empty();
std::cout<<"Clear: "<<std::endl;
lab.clear();
    return 0;
}
