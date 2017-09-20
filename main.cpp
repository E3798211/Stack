#include <iostream>
#include <assert.h>
#include <cmath>

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

const MyType EDGE = 123456789;
const MyType EMPT = 987654321;
const int DELETED = -1;

/// Stack class
class Stack {
private:
    /// Current size
    int _size   = 0;

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
//  Stack(MyType* elements, int n_elements);

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
    bool IsEdge(MyType elem);
    bool IsEmpt(MyType elem);
    bool Dump(const char* func_name);


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
    st.Push(&c);
    st.Push(&c);
    st.Push(&c);
    st.Push(&a);
    st.Push(&b);
    st.Pop(&a);
    cout << a << endl;
    st.Pop(&a);
    cout << a << endl;
    st.Pop(&a);
    cout << a << endl;
    st.Pop(&a);
    cout << a << endl;
    st.Pop(&a);
    cout << a << endl;
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

    Dump(__func__);

    _size = new_size;

    MyType* new_stack = nullptr;
    try{
        new_stack = new MyType [new_size];
    }
    catch(const std::bad_alloc& ex){
        DEBUG cout << ERR_WHERE << ". Cannot allocate " << new_size << " bytes." << endl;

        Dump(__func__);
        return BAD_ALLOC;
    }


    new_stack[0]            = EDGE;
    new_stack[new_size - 1] = EDGE;

    int _min = (_n_elem < new_size)? _n_elem : new_size;
    for(int i = 0; i <= _min; i++)
        new_stack[i] = _stack[i];

    for(int i = _min + 1; i < new_size - 1; i++)
        new_stack[i] = EMPT;


    //Swap
    MyType* tmp = _stack;
    _stack = new_stack;
    new_stack = tmp;

    //Clearing memory
    delete [] new_stack;
    new_stack = nullptr;


    Dump(__func__);
    return SUCCESS;
}

bool Stack::IsEdge(MyType elem)
{
    return (elem == EDGE)? true : false;
}

bool Stack::IsEmpt(MyType elem)
{
    return (elem == EMPT)? true : false;
}

// Public
Stack::Stack()
{
    Dump(__func__);

    _stack  = new MyType[3];

    _stack[0]   = EDGE;
    _stack[1]   = EMPT;
    _stack[2]   = EDGE;

    _size       = 3;
    _n_elem     = 0;

    Dump(__func__);
}

Stack::~Stack()
{
    if(_size < 2){
        delete [] _stack;
        _stack  = nullptr;

        _size   = DELETED;
        _n_elem = DELETED;
    }
}

/*
// SHOULD BE CHECKED!!!

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
    if (_n_elem != 0){
        delete [] _stack;
        _stack = nullptr;
    }
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
*/

int Stack::Pop(MyType* pop_elem)
{
    //Exceptions
    assert(pop_elem != nullptr);

    Dump(__func__);

    if(_n_elem < 1){
        DEBUG cout << "Not enough elements in the stack" << endl;
        return NOT_ENOUGH_ELEMENTS;
    }


    *pop_elem = _stack[_n_elem];
    _stack[_n_elem] = EMPT;
    _n_elem--;


    // SHOULD BE CHECKED FOR BAD ALLOC IN StackResize()


    if(_n_elem < (_size - 2)/ 2)
        StackResize((_size - 2)/2 + 2);


    Dump(__func__);
    return SUCCESS;
}

int Stack::Push(MyType* new_elem)
{
    //Exceptions
    assert(new_elem != nullptr);

    Dump(__func__);

    // SHOULD BE CHECKED FOR BAD ALLOC IN StackResize()

    if(_n_elem >= (_size - 2))
        StackResize((_size - 2)*2 + 2);

    _stack[_n_elem + 1] = *new_elem;
    _n_elem++;

    Dump(__func__);
    return SUCCESS;
}


// DEBUG

bool Stack::Dump(const char* func_name)
{
    cout << endl;
    cout << "Dump() in " << func_name << "():" << endl;

    cout << "_size\t= "     << _size    << endl;
    cout << "_n_elem\t= "   << _n_elem  << endl;

    if(_stack == nullptr){
        cout << "_stack\t= nullptr" << endl;
        return false;
    }

    if(_size < 2){
        cout << "_size < 2, wrong stack size" << endl;
        cout << "Can not print elements" << endl;
        return false;
    }

    for(int i = 0; i < _size; i++){
        cout << "_stack[" << i << "] = ";

        if      (IsEdge(_stack[i]))
            cout << "EDGE" << endl;

        else if (IsEmpt(_stack[i]))
            cout << "EMPTY" << endl;

        else
            cout << _stack[i] << endl;
    }

    return true;
}

