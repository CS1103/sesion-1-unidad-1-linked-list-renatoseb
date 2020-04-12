#ifndef LINKED_LIST
#define LINKED_LIST

#include<cctype>
using namespace std;

namespace utec{

    struct node_t{
        int value_ = 0;
        node_t* next_ = nullptr;
    };

    inline namespace first{
            
            class linked_list_t{
                private:
                    node_t* head_ = nullptr;
                    node_t* tail_ = nullptr;
                    size_t size_ = 0;
                public:
                    // constructores
                    linked_list_t() = default;//listo
                    linked_list_t(const linked_list_t& other);//listo
                    linked_list_t& operator=(const linked_list_t& other);//listo
                    linked_list_t(const linked_list_t&& other) noexcept;
                    linked_list_t& operator=(const linked_list_t&& other) noexcept;

                    // destructores
                    ~linked_list_t();//listo

                    // add
                    void push_back(int value);//listo
                    void push_front(int value);//listo
                    void insert(size_t index, int value);//listo

                    // remove
                    void pop_back();//listo
                    void pop_front();//listo
                    void erase(size_t index);//listo

                    // traverse
                    int& item(size_t index);//listo
                    const int& item(size_t index) const;//listo

                    // get size of list
                    size_t size() const;//listo
            };
    }
}

#endif