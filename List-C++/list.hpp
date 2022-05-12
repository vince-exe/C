#pragma once

#include <iostream>
#include <memory>

#define ITEM_NOT_FOUND -1

namespace stn {
    template<typename var> struct Node {
        var data;
        struct Node* next;
    };
}

namespace stl {

    template <class T> class List {
        private:
            struct stn::Node<T>* head;
            struct stn::Node<T>* end_;
            int lenght_;

        public:
            /*default constructor*/
            List();

            /*append the item to the start of the list*/
            void appendStart(T value);

            /*free the list*/
            void free();    

            /*append the item to the end of the list*/
            void appendEnd(T value);
            
            /*return the address of memory of the first element in the list*/
            stn::Node<T>* begin();

            /*move the given pointer to the next node of the list*/
            stn::Node<T>* next(stn::Node<T>* it);

            /*
            check if the given pointer point to the end of the list
            
            True: The pointer does.
            False: The pointer doesn't
            */
            bool end(stn::Node<T>* it);

            /*
            remove the item in the list with that value, return true if the item has been successfully removed
            WARNING: This method return only the first item that has the given value,
                     If there are other items with the given value, they will not be removed
                     Use this method only if your list is one of this type: (int, char, string, bool, float, double)
                     otherwise you have to overload the == operator
            */
            bool remove(T value);

            /*
            search in the list the item that has the given value and return his position,
            if the method doesn't find anithing it will return -1
            WARNING: use this method only if your list is one of this type (int, char, string, bool, float, double)
            otherwise you have to overload the == operator
            */
            int find(T value);
            
            /*
            return the item at the given position,
            WARNING: this method does not check if the given index exist
            */
            T getItem(int index);

            /*
            return the item at the given position
            WARNING: It's different from "getItem" because this method check if the given index exist
            
            Case: Index Greater Than List Lenght: the method will return the item at the first position
            Case: Index Negative: the method will return the item at the first position
            */
            T getItem2(int index);

            /*return the lenght of the list*/
            int lenght();
    };
}