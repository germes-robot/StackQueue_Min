#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <numeric>

using namespace std;

typedef long long ll;

//#define int ll
const int INF = 1e9 + 10;

#define all(x) x.begin(), x.end()


template <class Type>
struct StackMin
{
    void push(const Type &x)
    {
        elements.push(x);

        mins.push(mins.empty() ?
                    x :
                    min(x, mins.top())  );
    }

    void pop()
    {
        elements.pop();
        mins.pop();
    }

    Type top() const
    {
        return elements.top();
    }

    Type getMin() const
    {
        return mins.top();
    }

    size_t size() const
    {
        return elements.size();
    }

    bool empty() const
    {
        return size() == 0;
    }

private:
    stack<Type> elements;
    stack<Type> mins;
};

template<class Type>
struct QueueMin
{
    void push(const Type &x)
    {
        left.push(x);
    }

    void pop()
    {
        moveToRight();
        right.pop();
    }

    Type front() const
    {
        moveToRight();
        return right.top();
    }

    Type getMin() const
    {
        if (!left.empty() && !right.empty())
            return min(left.getMin(), right.getMin());
        else if (left.empty())
            return right.getMin();
        else
            return left.getMin();
    }

    bool empty() const
    {
        return size() == 0;
    }

    size_t size() const
    {
        return left.size() + right.size();
    }

private:

    void moveToRight() const
    {
        if (right.empty())
        {
            while (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
    }

    mutable StackMin<Type> left;
    mutable StackMin<Type> right;

};

signed main()
{
    cout <<"Stack" << endl;
    StackMin<long double> myStack;
    myStack.push(0.7);
    myStack.push(0.6);
    myStack.push(17);

    cout << myStack.getMin() << endl; //0.6
    myStack.push(0.3);
    cout << myStack.getMin() << endl; //0.3


    cout << "\nQueue" << endl;
    QueueMin<long double> myQueue;
    myQueue.push(0.2);
    myQueue.push(0.7);
    cout << myQueue.getMin() << endl;//0.2
    myQueue.push(0.3);
    cout << myQueue.getMin() << endl;//0.2
    myQueue.pop();
    cout << myQueue.getMin() << endl;//0.3

    return 0;
}