#include <iostream>
#include <cstring>

using namespace std;

bool customComp(char one, char two)
{
    if (islower(one))
    {
        one = one - 31;
    }

    if (islower(two))
    {
        two = two - 31;
    }

    if (one == ' ')
    {
        return true;
    }

    if (two == ' ')
    {
        return false;
    }

    return one > two;
}

template <typename T>
void sorting(int n, T arr[])
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <>
void sorting<char>(int n, char arr[])
{
    for (int i = 0; i < n; ++i)
    {
        if (!isalpha(arr[i]))
        {
            arr[i] = ' ';
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (customComp(arr[j], arr[j + 1]))
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Number of elements:" << endl;
    cin >> n;

    cout << "Choose datatype:" << endl;
    char* type = new char[30];
    cin >> type;

    if (!strcmp(type, "int"))
    {
        auto* a = new int[n];
        cout << "Enter array's elements:" << endl;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sorting <int> (n, a);

        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << ' ';
        }

        delete[] a;
        delete[] type;
        return 0;
    }
    if (!strcmp(type, "double"))
    {
        auto* a = new double[n];
        cout << "Enter array's elements:" << endl;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sorting <double> (n, a);

        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << ' ';
        }

        delete[] a;
        delete[] type;
        return 0;
    }
    if (!strcmp(type, "float"))
    {
        auto* a = new float[n];
        cout << "Enter array's elements:" << endl;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sorting <float> (n, a);

        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << ' ';
        }

        delete[] a;
        delete[] type;
        return 0;
    }
    if (!strcmp(type, "char"))
    {
        auto* a = new char[n];
        cout << "Enter array's elements:" << endl;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sorting <char> (n, a);

        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << a[i];
        }

        delete[] a;
        delete[] type;
        return 0;
    }

    return 0;
}
