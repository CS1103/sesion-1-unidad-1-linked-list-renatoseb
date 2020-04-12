

#include"linked_list.h"

utec::first::linked_list_t::linked_list_t(const linked_list_t& other):size_{other.size_}{
    auto next = new node_t{other.item(0),nullptr};
    head_ = next;
    for(size_t i = 1; i < other.size_ ; ++i){
        auto newNode = new node_t{other.item(i),nullptr};
        next->next_ = newNode;
        next = newNode;
        if(i == other.size_-1)
            tail_=newNode;
    }
};

utec::linked_list_t& utec::first::linked_list_t:: operator=(const linked_list_t& other){
    if(this == &other) return *this;
    if(head_ != nullptr || tail_ != nullptr){
        auto actual = head_;
        auto clean = head_;
        while(size_--){ 
            actual = actual->next_;
            delete clean;
            clean = actual;
        }

    }
    size_= other.size_;
    auto next = new node_t{other.item(0),nullptr};
    head_ = next;
    for(size_t i = 1; i < other.size_ ; ++i){
        auto newNode = new node_t{other.item(i),nullptr};
        next->next_ = newNode;
        next = newNode;
        if(i == other.size_-1)
            tail_=newNode;
    }

};

utec::first::linked_list_t:: linked_list_t(const linked_list_t&& other) noexcept{

};

utec::linked_list_t& utec::first::linked_list_t:: operator=(const linked_list_t&& other) noexcept{
    return *this;
};

void utec::first::linked_list_t:: push_back(int value){
    auto node= new node_t{value,nullptr};
    if(head_ == nullptr) {
        tail_=node;
        head_=tail_;
    }
    else{
        tail_->next_ = node;
        tail_= node;
    }
    ++size_;
}

void utec::first::linked_list_t::push_front(int value){
    /* 
    auto node = new node_{value,head_}
    head_ = node;
    */
    head_ = new node_t{value,head_};
    if(tail_ == nullptr) tail_ = head_;

    size_++;
    
}

void utec::first::linked_list_t::insert(size_t index, int value){
    if(index == 0){
        push_front(value);
    }
    else if(index == size_ - 1){
        push_back(value);
    }
    else{
        auto actual = head_;
        auto post = head_;
        while(index--){
            if(index >= 1) post = post->next_;
        }
        auto node = new node_t{value,post->next_};
        post->next_=node;
        ++size_;
    }

};

void utec::first::linked_list_t::pop_back(){
    if(head_ == tail_){
        delete tail_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else{
        auto actual = head_;
        size_t ultimo = size_ - 1; 
        while(ultimo != 1){
            actual = actual->next_;
            ultimo--;
        }
        delete tail_;
        tail_ = actual;
        actual->next_ = nullptr;
        --size_;
    }
};

void utec::first::linked_list_t::pop_front(){
     if(head_ == tail_){
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else{
        auto next = head_->next_;
        delete head_;
        head_=next;
        --size_;
    }
};

void utec::first::linked_list_t:: erase(size_t index){
    if(size_==1 || tail_ == head_){
        pop_front();
        
    }
    else if (index == size_-1)
    {
        pop_back();
    }
    else{
        auto actual = head_;
        node_t* post = head_;
        while(index--){
            actual = actual->next_;
            if(index >= 1) post = post->next_;
        }
        post->next_ = actual->next_;
        delete actual;
        size_--;
   }
}

int& utec::first::linked_list_t::item(size_t index){
    auto actual = head_;
    while(index--)
        actual = actual->next_;
    return actual->value_;
};

const int& utec::first::linked_list_t:: item(size_t index) const{
    auto actual = head_;
    while(index--)
        actual = actual->next_;
    return actual->value_;
};

size_t utec::first::linked_list_t:: size() const{
    return size_;
};

utec::first::linked_list_t:: ~linked_list_t(){
    auto actual = head_;
    auto clean = head_;
    while(size_--){ 
        actual = actual->next_;
        delete clean;
        clean = actual;
    }
    size_=0;
    head_ = tail_ = nullptr;
};