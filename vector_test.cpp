#include "vector.h"

using namespace std;

int main()
{
    Vector v;
    cout << "sukurimas" << endl;
    for (int i = 1; i < 12; ++i)
    {
        v.PushBack(i);
    }
    for (int i = 0; i < v.Size(); ++i)
    {
        cout << v.Array(i) << " ";
    }
    cout << endl;
    cout << "capacity: " << v.Capacity() << " size: " << v.Size() << " is empty: " << v.isEmpty() << endl;

    cout << "kppijavimo konstruktorius" << endl;
    Vector w = v;
    for (int i = 0; i < w.Size(); ++i)
    {
        cout << w.Array(i) << " ";
    }
    cout << endl;
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;
    w.PushBack(100);
    cout << "pushback" << endl;
    for (int i = 0; i < w.Size(); ++i)
    {
        cout << w.Array(i) << " ";
    }
    cout << endl;
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;

    w.PopBack();
    w.PopBack();

    w = v;
    cout << "kopijavimo operacija" << endl;
    for (int i = 0; i < w.Size(); ++i)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;

    cout << "erase" << endl;
    w.Erase(4);
    for (int i = 0; i < w.Size(); ++i)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    w.Erase(7);
    for (int i = 0; i < w.Size(); ++i)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;

    return 0;
}