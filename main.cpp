#include <iostream>
#include <assert.h>
#include <cmath>

#include "Stack.h"

int main()
{
    MyType a = 10,
           b = 11,
           c = 12;

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

/*    MyType a = 5;
    Stack st;
    int p = 2;


    for(int i = 0; i < 200; i++){
        st.Push(&a);
        if (i == p - 2) {
            for(int j = 0; j < 3; j++){
                st.Push(&a);
                st.Pop(&a);
                st.Ok();
            }
            p *= 2;
        }
    }*/
}

