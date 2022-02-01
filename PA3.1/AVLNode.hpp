#ifndef AVLNode_h
#define AVLNode_h
 
 
template <class T>
class AVLNode{
private:
    T data;
    int height;
    AVLNode<T>* left;
    AVLNode<T>* right;
    
public:
    AVLNode<T> (const T& a) : data(a), left(nullptr), right(nullptr), height(1){};
 
    int get_height()
    {
        return height;
    }
    void set_height(int a)
    {
        height = a;
    }
    T get_data()
    {
        return data;
    }
    void set_data(T a)
    {
        data = a;
    }
    AVLNode *get_left()
    {
        return left;
    }
    AVLNode *get_right()
    {
        return right;
    }
    void set_left(AVLNode* a)
    {
        left = a;
    }
    void set_right(AVLNode *a)
    {
        right = a;
    }
};
 
#endif /* AVLNode_h */




 
