#ifndef PRACTICE_03_DYNARRAY_HPP
#define PRACTICE_03_DYNARRAY_HPP


class DynArray
{
private:
    double* a;
    int ptr;
    int maxSize;
public:
    DynArray(int n);
    void append(int n);
    double get(int i);
    int size();
    void resize();
    ~DynArray();
};


#endif //PRACTICE_03_DYNARRAY_HPP
