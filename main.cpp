#include <iostream>
#include <assert.h>

#define ERR_WHERE "In " << __FILE__ << ": " << __func__ << "(): " << ex.what()


/// Mistakes
enum ERR_CODE{
    SUCCESS = 0,
    BAD_ALLOC
};


/// Type to be saved in stack
typedef double MyType;


/// Stack class
class Stack {
private:
    /// Current amount of elements in stack
    int _n_elem = 0;
    /// Array that contains elements
    MyType* _stack = nullptr;
public:
    /// Constructor empty
    Stack();
    /// Constructor with parameters
    /**
        \param [in] elements    Array with elements to be placed in stack.
        \param [in] n_elements  Amount of elements to be placed.
    */
    Stack(MyType* elements, int n_elements);
    /// Destructor
    ~Stack();
    /// Pop element
    int Pop();
    /// Push element
    /**
        \param [in] new_elem    New element in stack.
    */
    int Push(MyType* new_elem);

    //DEBUG
    MyType Get(int pos);

};


using namespace std;

int main()
{
    MyType a = 5,
           b = 4,
           c = 3;

    Stack st;
    st.Push(&a);
    st.Push(&b);
    st.Push(&c);

    cout << st.Get(0) << endl;
    cout << st.Get(1) << endl;
    cout << st.Get(2) << endl;
}

Stack::Stack()
{
    _stack = new MyType;
}

Stack::Stack(MyType* elements, int n_elements)
{
    //Exceptions
    assert(elements != nullptr);
    assert(n_elements > 0);

    _n_elem = n_elements;
    _stack = elements;
}

Stack::~Stack()
{
    delete [] _stack;
}

int Stack::Push(MyType* new_elem)
{
    //Exceptions
    assert(new_elem != nullptr);

    MyType* tmp_arr = nullptr;
    try{
        tmp_arr = new MyType [_n_elem];
    }
    catch(const bad_alloc& ex){
        cout << ERR_WHERE << ". Cannot allocate " << _n_elem << " bytes." << endl;
        return BAD_ALLOC;
    }


    for(int i = 0; i < _n_elem; i++)
        tmp_arr[i] = _stack[i];


    delete [] _stack;
    try{
        _stack = new MyType [_n_elem + 1];
    }
    catch(const bad_alloc& ex){
        cout << ERR_WHERE << ". Cannot allocate " << _n_elem + 1 << " bytes." << endl;
        return BAD_ALLOC;
    }


    for(int i = 0; i < _n_elem; i++)
        _stack[i] = tmp_arr[i];

    _stack[_n_elem] = *new_elem;
    _n_elem++;

    //Memory free
    delete [] tmp_arr;
    tmp_arr = nullptr;

    return SUCCESS;
}




// Debug

MyType Stack::Get(int pos)
{
    return _stack[pos];
}
