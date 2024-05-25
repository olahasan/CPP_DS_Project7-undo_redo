#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{

protected:
    int _Size = 0;
    T* _TempArray;

public:
    T* OriginalArray;   //float * ptr;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];   //ptr = new float[num/_size]

    }

    ~clsDynamicArray()
    {

        delete[]  OriginalArray;  //delete[] ptr

    }


    bool SetItem(int index, T Value)
    {

        if (index >= _Size || index < 0)
        {
            return false;
        }

        OriginalArray[index] = Value;
        return true;

    }


    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);

    }

    void PrintList()
    {

        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << "\n";

    }

    /*
    void Resize(T Size)
    {
        _Size = Size;

        for (int i = 0; i <= _Size - 1; i++)
        {
            OriginalArray[i];
        }
    }
    */

    void Resize(int NewSize)
    {

        if (NewSize < 0)
        {
            NewSize = 0;
        };

        _TempArray = new T[NewSize];

        //limit the original size to the new size if it is less.
        if (NewSize < _Size)
            _Size = NewSize;

        //copy all data from original array until the size
        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;

        delete[] OriginalArray;
        OriginalArray = _TempArray;

    }

    T GetItem(int index)
    {
        return OriginalArray[index];

        /*
            if (Index > _Size - 1 || Index < 0)
        {
            return 0;
        }

        for (T i = 0; i <= _Size - 1; i++)
        {
            if (i == Index)
            {
                return OriginalArray[Index];
            }
        }
        */
    }

    void Reverse()
    {
        /*
            for (T i = 0; i <= _Size - 1; i++)
        {
            T S = i;
            T E = _Size - 1 - i;

            if (S == E)
            {
                return;
            }

            T Temp = OriginalArray[E];
            OriginalArray[E] = OriginalArray[S];
            OriginalArray[S] = Temp;
        }
        */

        _TempArray = new T[_Size];

        int counter = 0;

        for (int i = _Size - 1; i >= 0; i--)
        {
            _TempArray[counter] = OriginalArray[i];
            counter++;
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    void Clear()
    {
        /*
            delete[] OriginalArray;
            _Size = 0;
        */

        _Size = 0;
        _TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }



    /*
    void DeleteItemAt(int Index)
    {
        if (Index > _Size - 1 || Index < 0)
        {
            return;
        }

        for (T i = 0; i <= _Size - 1; i++)
        {
            if (i == Index)
            {
                OriginalArray[Index] = OriginalArray[Index + 1];
                OriginalArray[Index++];
            }
        }
        _Size -= 1;
    }
    */

    bool DeleteItemAt(int index)
    {

        if (index >= _Size || index < 0)
        {
            return false;
        }

        _Size--;

        _TempArray = new T[_Size];

        //copy all before index
        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        //copy all after index
        for (int i = index + 1; i < _Size + 1; i++)
        {
            _TempArray[i - 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

    }

    void DeleteFirstItem()
    {
        DeleteItemAt(0);
    }

    void DeleteLastItem()
    {
        DeleteItemAt(_Size - 1);
    }


    int Find(T Value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == Value)
            {
                return i;
            }
        }
        return -1;
    }


    bool DeleteItem(T Value) {

        int index = Find(Value);

        if (index == -1)
        {
            return false;
        }

        DeleteItemAt(index);
        return true;

    }


    bool InsertAt(T index, T Value)
    {
        if (index > _Size || index < 0)
        {
            return false;
        }

        _Size++;

        _TempArray = new T[_Size];

        //copy all before index
        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _TempArray[index] = Value;

        //copy all after index
        for (int i = index; i < _Size - 1; i++)
        {
            _TempArray[i + 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;
    }


    void InsertAtBeginning(T value)
    {

        InsertAt(0, value);

    }


    bool InsertBefore(T index, T value)
    {
        if (index < 1) // ola it is better to write  (index == 0) to prevent user enter -1 or -2.....
            return InsertAt(0, value);
        else
            return InsertAt(index - 1, value);

    }


    bool InsertAfter(T index, T value)
    {
        if (index >= _Size)
            return InsertAt(_Size - 1, value);
        else
            return InsertAt(index + 1, value);

    }

    bool InsertAtEnd(T value)
    {

        return InsertAt(_Size, value);

    }


};
