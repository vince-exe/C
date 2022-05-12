#include "list.hpp"

template<class T> inline stl::List<T>::List() {
    this->head = NULL;
    this->end_ = NULL;
    this->lenght_ = 0;
}

template<class T> void stl::List<T>::appendStart(T value) {
    struct stn::Node<T>* newNode = new stn::Node<T>;

    newNode->data = value;
    newNode->next = NULL;

    if(this->head == NULL) {
        this->head = newNode;
        this->end_ = newNode;
        this->head;
        this->lenght_ += 1;
        return;
    }else if(newNode == NULL) {
        return;
    }

    newNode->next = this->head;
    this->end_ = head;
    this->head = newNode;
    this->lenght_ += 1;
}

template<class T> void stl::List<T>::appendEnd(T value) {
    struct stn::Node<T>* newNode = new stn::Node<T>;

    newNode->data = value;
    newNode->next = NULL;

    if(this->head == NULL) {
        this->head = newNode;
        this->end_ = newNode;
        this->lenght_ += 1;
        return;
    }else if(newNode == NULL) {
        return;
    }    
    
    this->end_->next = newNode;
    this->end_ = newNode;
    this->lenght_ += 1;
}

template<class T> void stl::List<T>::free() {
    struct stn::Node<T>* tmp = this->head;

    while(this->head != NULL) {
        this->head = this->head->next;
        delete tmp;

        tmp = this->head;
        this->lenght_ -= 1;
    }
}

template<class T> stn::Node<T>* stl::List<T>::begin() {
    return this->head;
}

template<class T> stn::Node<T> *stl::List<T>::next(stn::Node<T> *it) {
    return (it = it->next);
}

template<class T> T stl::List<T>::getItem(int index) {
    struct stn::Node<T>* tmp = this->head;

    for(int i=0; i<index && tmp != NULL; i++) {
        tmp = tmp->next;
    }

    return tmp->data;
}

template<class T> T stl::List<T>::getItem2(int index) {
    struct stn::Node<T>* tmp = this->head;

    if(index < 0 || index >= this->lenght_) {
        return tmp->data;
    } 

    for(int i=0; i<index && tmp; i++) {
        tmp = tmp->next;
    }

    return tmp->data;
}

template<class T> int stl::List<T>::lenght() {
    return this->lenght_;
}

template<class T> bool stl::List<T>::end(stn::Node<T>* it) {
    if(it == NULL) {
        return true;
    }
    return false;
}

template<class T> bool stl::List<T>::remove(T value) {
    struct stn::Node<T>* tmp = this->head;

    if(this->head->data == value) {
        this->head = tmp->next;
        this->lenght_ -= 1;
        delete tmp;

        return true;
    }

    struct stn::Node<T>* prev = NULL;
    while(tmp != NULL && tmp->data != value) {
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp == NULL) {
        return false;
    }

    prev->next = tmp->next;
    delete tmp;

    this->lenght_ -= 1;
    return true;
}

template<class T> int stl::List<T>::find(T value) {
    struct stn::Node<T>* tmp = this->head;
    int i = 0;

    while(tmp != NULL && tmp->data != value) {
        tmp = tmp->next;
        i++;
    }

    if(tmp == NULL) {
        return ITEM_NOT_FOUND;
    }

    return i;
}