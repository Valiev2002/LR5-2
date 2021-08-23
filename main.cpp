#include <iostream>
#include "QueueList.h"
int main() {
    int i;
    QueueList<int>lab{};
    std::cout<<"Push back:"<<" ";
    lab.push_back(2);
    std::cout<<lab<<std::endl;
    lab.push_back( 3);
    std::cout<<lab<<std::endl;
    lab.push_back( 4);
    std::cout<<lab<<std::endl;
    std::cout<<"Getting index from front:"<<" ";
    lab.front();
    std::cout<<lab<<std::endl;
    std::cout<<"Getting index from back:"<<" ";
    lab.back();
    std::cout<<lab<<std::endl;
    std::cout<<"Pop front: "<<std::endl;
    lab.pop_front();
    std::cout<<lab<<std::endl;
    std::cout<<"Size: "<<lab.size()<<std::endl;
    std::cout<<lab<<std::endl;
    std::cout<<"Begin iterator: "<<std::endl;
    lab.begin();
    std::cout<<lab<<std::endl;
    std::cout<<"End iterator: "<<std::endl;
    lab.end();
    std::cout<<lab<<std::endl;
    std::cout<<"Checking if it is empty: "<<std::endl;
    lab.empty();
    std::cout<<lab<<std::endl;
    std::cout<<"Clear: "<<std::endl;
    lab.clear();
    std::cout<<lab<<std::endl;
    return 0;
}
