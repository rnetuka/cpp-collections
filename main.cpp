#include <iostream>

#include "vector.h"

using namespace std;
using namespace collections;

void assert_true(bool actual)
{
    if (! actual)
        cerr << "Expected true, but got false" << endl;
}

void assert_false(bool actual)
{
    if (actual)
        cerr << "Expected false, but got true" << endl;
}

void assert_equals(int expected, int actual)
{
    if (expected != actual)
        cerr << "Expected: " << expected << ", but got " << actual << endl;
}

template <typename T>
void assert_equals(const T& expected, const T& actual)
{
    if (expected != actual)
        cerr << "Not as expected" << endl;
}

template <typename T>
void assert_equals(const Vector<T>& expected, const Vector<T>& actual)
{
    if (expected != actual)
        cerr << "Expected: " << expected << ", but got " << actual << endl;
}

template <typename T>
void assert_not_equal(const T& expected, const T& actual)
{
    if (expected == actual)
        cerr << "Not as expected" << endl;
}

int main()
{
    Vector<int> v = { 1, 2, 3, 4, 5 };
    cout << v << endl;

    auto it = v.begin();
    while (it.has_next())
        cout << it.next() << ", ";

    assert_equals(5, v.size());
    assert_true(v.contains(2));
    assert_false(v.contains(6));

    v.push_back(6);
    v.add(7);
    v.insert(3, 666);

    assert_equals(Vector<int> { 1, 2, 3, 666, 4, 5, 6, 7 }, v);

    v.remove(2);
    assert_equals(Vector<int> { 1, 3, 666, 4, 5, 6, 7 }, v);

    assert_true(v.all_of([](int x) { return x > 0; }));
    assert_false(v.any_of([](int x) { return x < 0; }));

    auto it2 = find(v.begin(), v.end(), 666);
    assert_not_equal(it2, v.end());
    it2 = find(v.begin(), v.end(), -1);
    assert_equals(it2, v.end());
}