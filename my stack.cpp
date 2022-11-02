#include<vector>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Stack{
    public:
       vector <T> a;
       bool empty(); 
       T& top(); 
       void push(T element); 
       void pop(); 
};

template <typename T>
bool Stack<T> :: empty(){
    if(a.size()==0){
        return true;
    }
    return false;
}
template <typename T>
T& Stack<T> :: top(){
    if(empty()==true){
        return a[a.size()-1];
    }else{
        T& top=a[a.size()-1];
        return top;
    }
}
template <typename T>
void Stack<T> :: push(T element){
        a.push_back(element);
}
template <typename T>
void Stack<T> :: pop(){
    if(empty()==false){
        a.pop_back();
    }
}


template <typename T>
Stack<T> operator+(Stack<T> &s1, Stack<T> &s2)
{
    Stack<T> s3;
    while (!s1.empty())
    {
        s3.push(s1.top());
        s1.pop();
    }
    while (!s2.empty())
    {
        s3.push(s2.top());
        s2.pop();
    }
    return s3;
}


int main(int argc, char const *argv[])
{
    Stack <int > a, b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    //print a top
    cout << a.top() << endl;
    //print b top
    cout << b.top() << endl;
    //print a+b top
    Stack <int > c = a + b;
    cout << c.top() << endl;
    c.pop();
    cout << c.top() << endl;
    c.pop();
    cout << c.top() << endl;
    c.pop();
    return 0;
}