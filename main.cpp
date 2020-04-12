#include<iostream>
#include<cassert>
#include<string>
#include "linked_list.h"

int main(){
    utec::linked_list_t ll;

   // Probar el metodo push_front;
    for(int i = 0; i < 10; ++i) {
        ll.push_front(i);
    }

    // Verifico el tamano
    assert(ll.size() == 10);

    string result;
    for (int i = 0; i < 10; ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    
    assert(result == "9 8 7 6 5 4 3 2 1 0 ");

    // prueba pop front
    for (int i = 0; i < 10; ++i) {
        ll.pop_front();
    }
    assert(ll.size() == 0);

    // prueba push_back
    for(int i = 0; i < 10; ++i) {
        ll.push_back(i);
    }

    assert(ll.size() ==10);
    
    //prueba erase
    ll.erase(1);
    ll.erase(4);
    
    // prueba pop back
    ll.pop_back();

    assert(ll.size() == 7);
    
    //prueba insert
    ll.insert(1,1);
    ll.insert(5,5);
    ll.push_back(9);

    //prueba constructor copy 
    utec::linked_list_t ll_1(ll);
    string result_1;
    for (int i = 0; i < 10; ++i) {
        result_1 += to_string(ll_1.item(i)) + " ";
    }

    assert(result_1 == "0 1 2 3 4 5 6 7 8 9 ");

    //prueba constructor asignacion
    utec::linked_list_t ll_2 = ll_1;
    string result_2;
    for (int i = 0; i < 10; ++i) {
        result_2 += to_string(ll_2.item(i)) + " ";
    }

    assert(result_2 == "0 1 2 3 4 5 6 7 8 9 ");

}

