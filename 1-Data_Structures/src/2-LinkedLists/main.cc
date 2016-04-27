#include "LinkedList.hh"

using namespace datastructs;

int main(int argc, const char **argv)
{
    LinkedList<int> _list = LinkedList<int>();
    _list.push_back(10);
    _list.push_back(20);
    _list.push_front(0);
    _list.push_front(30);
    _list.push_back(40);
    _list.push_back(50);
    _list.push_front(60);

    for(auto iter = _list.begin(); iter != iter.end; ++iter){
        *iter = 0;
    }

    return 0;
}
