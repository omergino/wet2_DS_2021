#ifndef WET2_DYNAMICARRAY_H
#define WET2_DYNAMICARRAY_H

#define DEFAULT_SIZE 16

enum ArrayStatus {AS_SUCCESS,AS_FAIL};

/*------------------------------------------------------------------------------
-----------------------------------DynamicArray---------------------------------
------------------------------------------------------------------------------*/

template<class Data>
class DynamicArray
{
    Data* array = nullptr;
    int size = DEFAULT_SIZE;
    int usedSize = 0;
public:
    DynamicArray();
    ~DynamicArray();

    ArrayStatus expand();
    ArrayStatus insert(Data& data,int& n);

    Data operator[](int n);

};




#endif //WET2_DYNAMICARRAY_H
