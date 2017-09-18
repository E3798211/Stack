#include <iostream>
#include <assert.h>

// DEBUG
//=================================================================
// Comment next line if you want to turn debug off
#define _DEBUG

#if defined (_DEBUG)
    #define DEBUG
#else
    #define DEBUG if(0)
#endif // defined

//=================================================================

#define ERR_WHERE "In " << __FILE__ << ": " << __func__ << "(): " << ex.what()

/// Error codes
enum ERR_CODE{
    SUCCESS = 0,
    BAD_ALLOC,
    NOT_ENOUGH_ELEMENTS
};


/// Type of data to be saved in stack
typedef double MyType;


/// Stack class
class Stack {
private:
    /// Current size
    int _size = 0;
    /// Current amount of elements in stack
    int _n_elem = 0;
    /// Array that contains elements
    MyType* _stack = nullptr;
    /// Resizing stack
    /**
        \param new_size     New size of the stack
    */
    int StackResize(int new_size);
public:
    /// Default constructor
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
    int Pop(MyType* pop_elem);
    /// Push element
    /**
        \param [in] new_elem    New element in stack.
    */
    int Push(MyType* new_elem);



    // DEBUG
    MyType GetPos(int pos)  {return _stack[pos];}

    int GetSize()           {return _size;}

    int GetNElem()          {return _n_elem;}
};


using std::cout;
using std::cin;
using std::endl;

//=================================================================

int main()
{
    MyType a = 10,
           b = 11,
           c = 12;

    Stack st;
    cout << "init" << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;
    st.Push(&a);
    cout << "elem 'a' added." << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;
    st.Push(&b);
    cout << "elem 'b' added." << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;
    st.Push(&c);
    cout << "elem 'c' added." << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;


    MyType* elem_ptr = &a;

    cout << "BEGIN" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    st.Push(&c);
    cout << "elem 'c' added." << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    st.Push(&b);
    cout << "elem 'b' added." << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    cout << "error = " << st.Pop(elem_ptr) << endl;
    cout << "elem = " << *elem_ptr << endl;
    cout << "_size = " << st.GetSize() << " _n_elem = " << st.GetNElem() << "\n" << endl;

    st.~Stack();

    //cout << st.Get(0) << endl;
    //cout << st.Get(1) << endl;
    //cout << st.Get(2) << endl;
}

// Class functions
//=================================================================

// Private
int Stack::StackResize(int new_size)
{
    // Exceptions
    assert(new_size > 0);


    MyType* new_stack = nullptr;
    try{
        new_stack = new MyType [new_size];
    }
    catch(const std::bad_alloc& ex){
        DEBUG cout << ERR_WHERE << ". Cannot allocate " << new_size << " bytes." << endl;
        return BAD_ALLOC;
    }


    int _min = (_n_elem < new_size)? _n_elem : new_size;
    for(int i = 0; i < _min; i++)
        new_stack[i] = _stack[i];

    //Swap
    MyType* tmp = _stack;
    _stack = new_stack;
    new_stack = tmp;

    //Clearing memory
    delete [] new_stack;
    new_stack = nullptr;

    return SUCCESS;
}

// Public
Stack::Stack()
{
    _stack  = new MyType[1];
    _size   = 1;
    _n_elem = 0;
}


// SOULD BE CHECKED!!!

Stack::Stack(MyType* elements, int n_elements)
{
    //Exceptions
    assert(elements != nullptr);
    assert(n_elements > 0);

    int new_size = 1;
    while(new_size < n_elements)
        new_size *= 2;

    _stack  = elements;
    _size   = new_size;
    _n_elem = n_elements;
}

Stack::~Stack()
{
    if (_n_elem != 0)   delete [] _stack;
}

int Stack::Push(MyType* new_elem)
{
    //Exceptions
    assert(new_elem != nullptr);


    // SHOULD BE CHECKED FOR BAD ALLOC IN StackResize()


    if(_n_elem >= _size){
        _size *= 2;
        StackResize(_size);
    }

    _stack[_n_elem] = *new_elem;
    _n_elem++;

    return SUCCESS;
}

int Stack::Pop(MyType* pop_elem)
{
    //Exceptions
    assert(pop_elem != nullptr);

    if(_n_elem < 1){
        DEBUG cout << "Not enough elements in the stack" << endl;
        return NOT_ENOUGH_ELEMENTS;
    }


    *pop_elem = _stack[_n_elem - 1];
    _n_elem--;


    // SHOULD BE CHECKED FOR BAD ALLOC IN StackResize()


    if(_n_elem < _size / 2){
        _size /= 2;
        StackResize(_size);
    }

    return SUCCESS;
}


