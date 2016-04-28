#include "List.hh"
#include <iostream>

using namespace datastructs;

int main(int argc, const char **argv)
{
    auto _list = List<int, doubly>();
    _list.push_back(10);
    _list.push_back(20);
    _list.push_front(0);
    _list.push_front(30);
    _list.push_back(40);
    _list.push_back(50);
    _list.push_front(60);

    for(auto iter = _list.begin(); iter != _list.end(); ++iter){
        *iter = 0;
    }

    for (auto riter = _list.rbegin(); riter != _list.rend(); ++riter)
        std::cout<<*riter<<std::endl;
    
    //for (auto citer = _list.cbegin(); citer != _list.cend(); ++citer)
    //    *citer;

    return 0;
}
