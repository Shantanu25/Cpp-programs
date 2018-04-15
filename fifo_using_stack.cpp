#include <iostream>

using namespace std;
#define MAX 1000

class Stack {
    public:
        int arr[MAX];
        int top;
        
    Stack () { top = -1; }
    bool isEmpty();
    void push(int data);
    int pop();
};
void Stack::push(int data) {
    if(top >= MAX)
        cout << "stack overflow!" << endl;
    else
        arr[++top] = data;
}

int Stack::pop() {
    if(isEmpty()) { 
        cout << "Nothing to pop" << endl;
        return 0;
    }
    else
        return arr[top--];
}

bool Stack::isEmpty() {
    return (top == -1);
}

/////////////////////////////////////////////////

class fifo {
    public:
        Stack s1,s2;
    void put(int data);
    int get();
};

void fifo::put(int data) {
    if (s1.top+s2.top >= MAX)
        cout << "FIFO full" << endl;
    else
        s1.push(data);
}

int fifo::get() {
    if(s1.isEmpty() && s2.isEmpty()) {
        cout << "FIFO empty" << endl;
        return 0;
    }
    else if (!s1.isEmpty() && s2.isEmpty()) {
        int i = s1.top;
        //Offload data from stack-1 (implementing LIFO)
        while (i!=-1) {
            s2.push(s1.pop());
            i--;
        }
        return s2.pop();
    }
    else if (!s2.isEmpty())
        //Stack-2 has some data, pop that
        return s2.pop();
}


int main()
{
   cout << "Hello World" << endl;
   
   fifo f;
   f.put(10);
   f.put(20);
   f.put(30);

   cout << f.get() << endl;
   cout << f.get() << endl;
   cout << f.get() << endl;
   
   return 0;
}