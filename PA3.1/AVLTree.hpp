#ifndef AVLTree_h
#define AVLTree_h
 
#include <iostream>
#include "AVLNode.hpp"
 
 
template <typename T>
class AVLTree{
private:
    AVLNode<T> *root;
    int numNodes;
 
public:
 
    AVLNode<T>* get_root()
    {
        return root;
    }
 
    AVLNode<T>* rightRotation(AVLNode<T>* head)
    {
        AVLNode<T>* a = head->get_left();
        head->set_left(a->get_right());
        
        a->set_right(head);
        head->set_height(1 + std::max(height(head->get_left()), height(head->get_right())));
        a->set_height(1 + std::max(height(a->get_left()), height(a->get_right())));
        return a;
    }
 
    AVLNode<T>* leftRotation(AVLNode<T>* head)
    {
        AVLNode<T>* a = head->get_right();
        head->set_right(a->get_left());
        a->set_left(head);
        head->set_height(1 + std::max(height(head->get_left()), height(head->get_right())));
        a->set_height(1 + std::max(height(a->get_left()), height(a->get_right())));
        return a;
    }
 
    void printInOrder(AVLNode<T>* head, std::string label)
    {
        if(head == nullptr)
            return;
        printInOrder(head->get_left());
        std::cout << label << ". " << head->get_data().get_country() <<  head->get_data().get_rate() << std::endl;
        printInOrder(head->get_right());
    }
 
    AVLNode<T>* insert(T a, AVLNode<T>* head)
    {
        if(head == NULL)
        {
            //numNodes++;
            AVLNode<T>* temp = new AVLNode<T>(a);
            return temp;
        }
    
        if(a.get_rate() < head->get_data().get_rate())
            head->set_left(insert(a, head->get_left()));
    
        else if(a.get_rate() > head->get_data().get_rate())
            head->set_right(insert(a, head->get_right()));
        
        head->set_height(1 + std::max(height(head->get_left()), height(head->get_right())));
        
        int b = height(head->get_left()) - height(head->get_right());
       
        if(b > 1)
        {
            if(a.get_rate() < head->get_left()->get_data().get_rate())
            {
                return rightRotation(head);
            }
            else
            {
                head->set_left(leftRotation(head->get_left()));
                return rightRotation(head);
            }
        }
        else if(b < -1)
        {
            if(a.get_rate() > head->get_right()->get_data().get_rate())
            {
                return leftRotation(head);
            }
            else
            {
                head->set_right(rightRotation(head->get_right()));
                return leftRotation(head);
            }
        }
        return head;
    }
        
    AVLNode<T>* remove(AVLNode<T>* head, T a)
    {
        if(head == nullptr)
            return nullptr;
        
        if(a < head->get_data().get_rate())
        {
            head->set_left(remove(head->get_left(), a));
        }
        else if(a > head->get_data().get_rate())
        {
            head->set_right(remove(head->get_right(), a));
        }
        else
        {
            AVLNode<T>* b = head->get_right();
            if(head->get_right() == nullptr)
            {
                AVLNode<T>* c = head->get_left();
                delete(head);
                head = c;
            }
            else if(head->get_left() == nullptr)
            {
                delete(head);
                head = b;
            }
            else
            {
                while(b->get_left() != nullptr)
                    b = b->get_left();
                head->set_data(b->get_data().get_rate());
                head->set_right(remove(head->get_right(), b->get_data().get_rate()));
            }
        }
        
        if(head == nullptr)
            return head;
        
        head->set_height(1 + std::max(height(head->get_left()), height(head->get_right())));
        int d = height(head->get_left()) - height(head->get_right());
        if(d > 1)
        {
            if(a > head->get_left()->get_data().get_rate())
                return rightRotation(head);
            else
            {
                head->set_left(leftRotation(head->get_left()));
                return rightRotation(head);
            }
        }
        else if(d < -1)
        {
            if(a < head->get_right()->get_data().get_rate())
            {
                return leftRotation(head);
            }
            else
            {
                head->set_right(rightRotation(head->get_right()));
                return leftRotation(head);
            }
        }
        return head;
    }
    
     int height(AVLNode<T>* head)
    {
         if(head == NULL)
             return 0;
         return head->get_height();
    }
    
    void insertHelp(T a)
    {
        root = insert(a, root);
    }
    
    void removeHelp(T a)
    {
        root = remove(root, a);
    }
    
    void findMinimum(AVLNode<T>* head)
    {
        AVLNode<T>* temp = head;
        if(temp == nullptr)
            return;
        
        while(temp->get_left() != nullptr)
            temp = temp->get_left();
        
        std::cout << "Minimum value is: " << temp->get_data().get_rate() << std::endl;
        
    }
    
    void findMaximum(AVLNode<T>* head)
    {
        if(head == nullptr)
            return;
        
        while(head->get_right() != nullptr)
            head = head->get_right();
        
        std::cout << "Maximum value is: " << head->get_data().get_rate() << std::endl;
        
    }
    
    void clear()
    {
        delete root;
    }
};
 
#endif 





