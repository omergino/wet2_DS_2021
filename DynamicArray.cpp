#include "DynamicArray.h"

/*------------------------------------------------------------------------------
----------------------------DynamicArray-Implementation-------------------------
------------------------------------------------------------------------------*/

template<class Data>
DynamicArray<Data>::DynamicArray() {
    array = new Data[size];
}

/*----------------------------------------------------------------------------*/

template<class Data>
DynamicArray<Data>::~DynamicArray() {
    delete[] array;
}

/*----------------------------------------------------------------------------*/

template<class Data>
ArrayStatus DynamicArray<Data>::expand() { //assume array is not nullptr
    Data *temp = new Data[2 * size];
    if (!temp) return AS_FAIL;
    else {
        for (int i = 0; i < usedSize; i++) {
        temp[i] = array[i];
        }
        delete [] array;
        return AS_SUCCESS;
    }
}
/*----------------------------------------------------------------------------*/

template<class Data>
Data DynamicArray<Data>::operator[](int n) {
    return n < size ? array[n] : nullptr;
}

template<class Data>
ArrayStatus DynamicArray<Data>::insert(Data &data, int &n) {
    if(size<=n) return AS_FAIL;
    else{
        if(usedSize >= size){
            if(expand() == AS_FAIL) return AS_FAIL;
        }
        array[n] = data;
        usedSize++;
        return AS_SUCCESS;
    }
}



