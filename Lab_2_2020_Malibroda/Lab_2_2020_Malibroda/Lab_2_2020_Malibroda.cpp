#include <iostream>
#include <vector>
using namespace std;

template<class T>
class stack_fa /*****fixed array*****/
{
private:

    T* stack;
    size_t head;
    size_t size;

public:

    stack_fa(size_t max)
    {
            size = max;
            stack = new T[size];
            head = 0;
    }
    
    ~stack_fa()
    {
        delete[] stack;
    }

    bool is_empty()
    {
        if (head < 1) return 1;
        else return 0;
    }

    void push(T a) 
    {
        if (head < size) 
        {
            head++;
            stack[head-1] = a;
        }
        else
        {
            cout << "Err: too much elements in stack..." << endl;
        }
    }

    void pop()
    {
        if (is_empty())
        {
            cout << "Err: stack is empty..." << endl;
        }
        else 
        {
            head--;
        }
    }

    T peek()
    {
        if (is_empty())
        {
            cout << "Err: stack is empty..." << endl;
            return stack[0];
        }
        else
        {
            return stack[head-1];
        }
    }
};

template<class T>
class stack_al /*****array list*****/
{
private:

    vector<T> stack;

public:

    bool is_empty()
    {
        if (stack.size() == 0) return 1;
        else return 0;
    }

    void push(T a)
    {
        stack.push_back(T);
    }

    void pop()
    {
        if (is_empty())
        {
            cout << "Err: stack is empty..." << endl;
        }
        else
        {
            stack.pop_back();
        }
    }

    T peek()
    {
        if (is_empty())
        {
            cout << "Err: stack is empty..." << endl;
            T res;
            return res;
        }
        else
        {
            return stack.back();
        }
    }
};

int main()
{
    return 0;
}