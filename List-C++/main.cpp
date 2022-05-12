#include <iostream>
#include <list>

#include "list.hpp"
#include "list.cpp"

/*
file created for testing the List 

Version: BETA

Method Tested:

    appendStart();

    appendEnd();

    lenght();

    getItem();

    remove();

    begin();

    end();

    next();

    find();

    getItem();

Developing Phase:
    
    removeAll();

Founder: Vincenzo Caliendo

Third Part Programs:

    valgrind: used to test if the list make leaks during the usage

Last Update: 11 / 05 / 2022
*/

/*class used for testing the list*/
class Test {
    public:
        int ok;
        std::string okay;
};

int main() {
    /*declare the list with the type that you want*/
    stl::List<int> lista;
    
    /*append the items (start or end)*/
    lista.appendStart(5);
    lista.appendStart(10);
    lista.appendEnd(20);
    lista.appendEnd(10);

    /*print the lenght of the list*/
    std::cout<<"\nLenght of the list: "<<lista.lenght()<<std::endl;

    /*print the list with a simple for*/
    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<lista.getItem(i)<<std::endl;
    }

    /*remove the items from the list and check if they are been removed*/
    if(lista.remove(5)) {
        std::cout<<"\nItem succesfully removed"<<std::endl;
    }
    lista.remove(10);

    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<lista.getItem(i)<<std::endl;
    }

    /*
    if you want to have more control on your nodes, you can use stn::Node namespace (namespace built into list.hpp)
    to declare a node and move it with the showen methods!!
    */
    std::cout<<std::endl;

    int i=0;
    for(stn::Node<int>* node = lista.begin(); !lista.end(node); node = lista.next(node), i++) {
        node->data = i;
    }

    std::cout<<"\nPrint the list after the modify"<<std::endl;
    for(int i=0; i<lista.lenght(); i++) {
        std::cout<<lista.getItem(i)<<std::endl;
    }

    /*find the position of the items in the list*/
    std::cout<<"\nPosition of the item that has 0 as value: "<<lista.find(0)<<std::endl;

    /*free the list*/
    lista.free();

    std::cout<<std::endl;
    return 0;
}