#include <iostream>
#include <assert.h>
#include <cmath>

#include "Stack.h"

int main()
{
    MyType a = 10,
           b = 11,
           c = 12;


    //Stack st;
    /*
    cout << "init" << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;
    st.Push(&a);
    cout << "elem 'a' added." << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;
    st.Push(&b);
    cout << "elem 'b' added." << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;
    st.Push(&c);
    cout << "elem 'c' added." << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;


    MyType* elem_ptr = &a;

    cout << "BEGIN" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    st.Push(&c);
    cout << "elem 'c' added." << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    st.Push(&b);
    cout << "elem 'b' added." << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetASize() << " _n_elem = " << st.GetNElem() << "\n" << endl;
    */

    Stack st;
    st.Push(&c);
    st.Push(&c);
    st.Push(&c);
    st.Push(&a);
    st.Push(&b);
    st.Pop(&a);
    st.Pop(&a);
    st.Pop(&a);
    st.Pop(&a);
    //cout << a << endl;
    //*(int*)&st = 0;
    st.Pop(&a);
    //cout << a << endl;
    st.~Stack();
    st.~Stack();

    //cout << st.Get(0) << endl;
    //cout << st.Get(1) << endl;
    //cout << st.Get(2) << endl;
}

