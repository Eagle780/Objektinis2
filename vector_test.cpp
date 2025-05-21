#include "vector.h"
#include "studentas.h"

using namespace std;

int main()
{
    /*
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
    */

    Vector<int> vi;
    vi.PushBack(5);
    cout << vi[0] << endl;

    Vector<std::string> vs;
    vs.PushBack("hello");
    cout << vs[0] << endl;

    Vector<Studentas> studenti;
    studenti.PushBack(Studentas("Vardenis", "Pavardenis", {8, 9}, 10));
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

    characters.Assign({'C', '+', '+', '1', '1'});
    for (int i = 0; i < characters.Size(); ++i)
    {
        cout << characters[i] << " ";
    }
    cout << endl;

    cout << characters.Data() << endl;

    return 0;
}