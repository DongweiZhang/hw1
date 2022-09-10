#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

ULListStr::~ULListStr()
{
    clear();
}

bool ULListStr::empty() const
{
    return size_ == 0;
}

size_t ULListStr::size() const
{
    return size_;
}

// WRITE YOUR CODE HERE

/**
 * Adds a new value to the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::push_back(const std::string& val) {
    if (empty()) {// empty list
        Item *item = new Item();
        item->first = 0;
        item->val[item->first] = val;
        item->last = 1;

        head_= item;
        tail_ = item;
    } else {
        if (tail_->last == ARRSIZE) {// tail full
            Item *item = new Item();
            item->first = 0;
            item->val[item->first] = val;
            item->last = 1;

            item->prev = tail_;
            tail_->next = item;
            tail_ = item;
        } else {
            tail_->val[tail_->last] = val;
            tail_->last++;
        }
    }
    size_++;
}

/**
 * Removes a value from the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_back() {
    if (!empty()) {
        if (tail_->last - tail_->first == 1) {
            Item * del = tail_;

            tail_ = tail_->prev;
            if (tail_ != nullptr) tail_->next = nullptr;

            del->prev = nullptr;
            delete del;
        } else {
            tail_->last--;
        }
        size_--;
    }
}

/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise,
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string& val) {
    if (empty()) {// empty list
        Item *item = new Item();
        item->first = ARRSIZE - 1;
        item->val[item->first] = val;
        item->last = ARRSIZE;

        head_= item;
        tail_ = item;
    } else {
        if (head_->first == 0) {// head full
            Item *item = new Item();
            item->first = ARRSIZE - 1;
            item->val[item->first] = val;
            item->last = ARRSIZE;

            item->next = head_;
            head_->prev = item;
            head_ = item;
        } else {
            head_->first--;
            head_->val[head_->first] = val;
        }
    }
    size_++;
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front() {
    if (!empty()) {
        if (head_->last - head_->first == 1) {
            Item * del = head_;

            head_ = head_->next;
            if (head_ != nullptr) head_->prev = nullptr;

            del->next = nullptr;
            delete del;
        } else {
            head_->first++;
        }
        size_--;
    }
}

/**
 * Returns a const reference to the back element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::back() const{
    if (empty()) {
        throw std::invalid_argument("Empty list");
    }

    return tail_->val[tail_->last - 1];
}

/**
 * Returns a const reference to the front element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::front() const{
    if (empty()) {
        throw std::invalid_argument("Empty list");
    }

    return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear()
{
    while(head_ != NULL){
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}

/**
 * Returns a pointer to the item at index, loc,
 *  if loc is valid and NULL otherwise
 *   - MUST RUN in O(n)
 */

std::string* ULListStr::getValAtLoc(size_t loc) const{
    Item * tmp = head_;

    while (tmp != nullptr) {
        int validLoc = tmp->last - tmp->first;
        int diff = loc - validLoc;
        if (diff >= 0) {
            tmp = tmp->next;
            loc -= validLoc;
        } else {
            return &tmp->val[tmp->first + loc];
        }
    }

    return nullptr;
}