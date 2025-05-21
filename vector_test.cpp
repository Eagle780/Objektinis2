#include "vector.h"
#include "studentas.h"

using namespace std;

int main()
{
    Vector<int> v;
    cout << "sukurimas" << endl;
    for (int i = 1; i < 12; ++i)
    {
        v.Push_back(i);
    }
    for (int i = 0; i < v.Size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "capacity: " << v.Capacity() << " size: " << v.Size() << " is empty: " << v.isEmpty() << endl;
    cout << "---" << endl;

    cout << "kppijavimo konstruktorius" << endl;
    Vector<int> w = v;
    for (int i = 0; i < w.Size(); ++i)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;
    w.Push_back(100);
    cout << "---" << endl;

    cout << "pushback" << endl;
    for (int i = 0; i < w.Size(); ++i)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;
    cout << "---" << endl;

    w.Pop_back();
    w.Pop_back();

    w = v;
    cout << "kopijavimo operacija" << endl;
    for (int i = 0; i < w.Size(); ++i)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;
    cout << "---" << endl;

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
    cout << "---" << endl;

    cout << "shrink" << endl;
    w.Shrink_to_fit();
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;
    cout << "---" << endl;

    cout << "reserve" << endl;
    w.Reserve(20);
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;
    cout << "---" << endl;

    cout << "at, front, back" << endl;
    cout << w.At(3) << " " << w.Front() << " " << w.Back() << endl;
    cout << "---" << endl;

    cout << "begin, back, reverse" << endl;
    cout << *w.Begin() << " " << *w.End() << " " << *w.Rbegin() << " " << *w.Rend() << endl;
    cout << "---" << endl;

    cout << "insert, clear" << endl;
    cout << w.Data() << endl;
    w.Insert(4, 100);
    for (int i = 0; i < w.Size(); ++i)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    w.Clear();
    cout << "capacity: " << w.Capacity() << " size: " << w.Size() << " is empty: " << w.isEmpty() << " ar equal: " << (v == w) << endl;
    cout << w.Data() << endl;
    cout << "---" << endl;

    Vector<int> d = {1, 2, 3};
    for (int i = 0; i < d.Size(); ++i)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    d.Resize(5);
    for (int i = 0; i < d.Size(); ++i)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    d.Resize(2);
    for (int i = 0; i < d.Size(); ++i)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    d.Resize(6, 4);
    for (int i = 0; i < d.Size(); ++i)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    Vector<int> a{1, 2, 3}, b{1, 4, 3}, c{1, 2, 3, 4};
    cout << "a > b " << (a > b) << " a > c " << (a > c) << " b > c " << (b > c) << " a <= b " << (a <= b) << " a <= c " << (a <= c) << " b <= c " << (b <= c) << endl;

    Vector<int> vi;
    vi.Push_back(5);
    cout << vi[0] << " " << vi.Data() << endl;

    Vector<std::string> vs;
    vs.Push_back("hello");
    cout << vs[0] << endl;

    Vector<Studentas> studenti;
    studenti.Push_back(Studentas("Vardenis", "Pavardenis", {8, 9}, 10));
    cout << studenti[0].getVardas() << " " << studenti[0].getPavarde() << " ";
    for (int i = 0; i < studenti[0].getNd().size(); i++)
    {
        cout << studenti[0].getNd()[i] << " ";
    }
    cout << studenti[0].getEgz() << endl;

    Vector<char> characters;

    characters.Assign(5, 'a');
    for (int i = 0; i < characters.Size(); ++i)
    {
        cout << characters[i] << " ";
    }
    cout << endl;

    cout << characters.Data() << endl;

    characters.Assign({'C', '+', '+', '1', '7'});
    for (int i = 0; i < characters.Size(); ++i)
    {
        cout << characters[i] << " ";
    }
    cout << endl;

    cout << characters.Data() << endl;

    return 0;
}