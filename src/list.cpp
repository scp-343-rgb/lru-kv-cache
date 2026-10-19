#include "list.h"
void List::addToHead(Node* node)
{
    node->next_ = head->next_;
    head->next_->prev_ = node;
    head->next_ = node;
    node->prev_ = head;
    size_++;
}
void List::removeNode(Node* node)
{
    node->prev_->next_ = node->next_;
    node->next_->prev_ = node->prev_;
    node->next_ = nullptr;
    node->prev_ = nullptr;
    size_--;
}
void List::moveToHead(Node* node)
{
    removeNode(node);
    addToHead(node);
}