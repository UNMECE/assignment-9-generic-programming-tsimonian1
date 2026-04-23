#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>
using namespace std;

template <typename DataType>
class GenericArray      {
        private:
                DataType *array;
                int size;
        public:
                GenericArray()  {
                         size = 0;
                         array = new DataType[1];
                }
                ~GenericArray() {
                        delete [] array;
                }
                void addElement(DataType param) {
                        DataType *newArray = new DataType[size+1];
                        for(int i=0;i<size;i++) {
                                newArray[i] = array[i];
                        }
                        newArray[size] = param;
                        delete[] array;
                        array = newArray;
                        size++;

                }
                void print() {
                        for (int i = 0; i < size; i++) {
                                cout << array[i] << " ";
                                        }
                                cout << endl;
                }
                int at(int param)       {
                        DataType value;
                        value = array[param];
                        return value;
                }
                int getSize()   {
                        int s = size;
                        return s;
                }
                DataType sum()  {
                        DataType sum = 0;
                        for(int i=0; i<size;i++)        {
                                sum += array[i];
                        }
                        return sum;
                }

                DataType max()  {
                        DataType maxim = array[0];
                        for(int i=0; i<size;i++)        {
                                if(array[i]>maxim)      {
                                        maxim = array[i];
                                }
                        }
                        return maxim;
                }
                DataType min()  {
                        DataType min =array[0];
                        for(int i=0;i<size;i++) {
                                if(array[i]<min)        {
                                        min = array[i];
                                }
                        }
                        return min;
                }

                DataType* slice(int begin, int end)     {
                        int slicedSize = end - begin;
                        DataType* sliced = new int[slicedSize];
                        for(int i=0;i<slicedSize;i++)   {
                                sliced[i] = array[begin+i];
                        }
                        return sliced;
                }
};

int main()      {
        GenericArray <int> int_array;
        int_array.addElement(10);
        int_array.addElement(2);
        int_array.addElement(1);
        int_array.addElement(2);
        int_array.addElement(22);
        int_array.addElement(12);
        int_array.addElement(7);
        int_array.addElement(1);
        int_array.addElement(0);
        int_array.addElement(5);

        int sizeOf = int_array.getSize();
        cout << "The members of the array are:" << endl;
        int_array.print();
        cout << "The size of the array is:  " << sizeOf << endl;
        cout << "The sum of the array is:  " << int_array.sum() << endl;
        cout << "The 4th element of the array is(index:3):  " << int_array.at(3) << endl;
        cout << "The maximum and the minimum of the array is:  " << int_array.max() << ", " << int_array.min() << endl;
        int* sliced_array = int_array.slice(5,10);
        cout << "The sliced array is:\n";
        for(int j=0;j<5;j++)    {
                cout << sliced_array[j] << "  ";
        }
        cout << endl;
        delete [] sliced_array;

        return 0;
}
