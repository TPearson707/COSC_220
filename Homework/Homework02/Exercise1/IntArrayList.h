/*
 * Name: Thomas Pearson
 * Date of Creation: 09/17/2023
 * Date of Last Update: 09/18/2023
 */

#ifndef INT_ARRAY_LIST
#define INT_ARRAY_LIST

class IntArrayList {
private:
    int *list;
    int size;
public:
    IntArrayList();
    ~IntArrayList();

    void duplicate(IntArrayList&);
    void display(bool vert = false);
    void displayAddress();
    void sort();
    bool sorted();
    void add(int);
    void concat(const IntArrayList&);
    void remove(int, int);
    void shuffle();
    void sub(int, int);
    void insert(const IntArrayList&, int);
    void insert(int, int);
    int get(int);
    void set(int, int);
    void resize(int);
    int length();
};
#endif // INT_ARRAY_LIST
