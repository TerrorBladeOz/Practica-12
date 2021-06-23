#include <iostream>
#include <ctime>

using  namespace std;

int* addelement(int*& arr, int& size, int num) {
    int* CopyArr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        *(CopyArr + i) = *(arr + i);
    }
    CopyArr[size] = num;
    delete[] arr;
    arr = CopyArr;

    size++;
    return CopyArr;
}

void insert(int* a, int& n, int x)
{
    for (int i = n - 2; a[i] > x && i >= 0; i--)
        a[i + 1] = a[i];
    for (int i = n - 2; i >= 0; i--)
    {
        if (x >= a[i])
        {
            a[i + 1] = x;
            return;
        }
    }
    a[0] = x;
}

int* dele(int* arr, int& size, int deletes) {
    if (deletes > size || deletes < 1) {
        cout << "Error" << endl;
        return 0;
    }
    else {
        for (int i = deletes - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return arr;
    }
}

void sort(int* arrN, int sizeN)
{
    int tmp = 0;
    for (int i = 0; i < sizeN; ++i)
    {
        for (int j = i + 1; j < sizeN; ++j)
        {
            if (arrN[j] < arrN[i])
            {
                tmp = arrN[j];
                arrN[j] = arrN[i];
                arrN[i] = tmp;
            }
        }
    }
}

void vozvrat(int* dig, int n)
{
    int sum = 0, proz = 1;
    for (int i = 0; i < n; i++)
    {
        sum = sum + dig[i];
        proz = proz * dig[i];

    }
    cout << "Сумма элементов массива равна " << sum << endl;
    cout << "Произведение элементов массива равно " << proz << endl;
}

void nuplmi(int* dig, int n)
{
    int p = 0, m = 0, null = 0;
    for (int i = 0; i < n; i++)
    {
        if (dig[i] < 0)
        {
            m++;
        }
        else if (dig[i] > 0)
        {
            p++;
        }
        else null++;

    }
    cout << "Элементов больше нуля  " << p << endl;
    cout << "Элементов меньше нуля " << m << endl;
    cout << "Элементов равных нулю " << null << endl;

}

int* DelNeg(int* Arr, int n, int& k)
{
    int i, j, * r;
    k = 0;
    for (i = 0; i < n; i++) if (Arr[i] >= 0) k++;
    r = new int[k];
    j = 0;
    for (i = 0; i < n; i++) if (Arr[i] >= 0) r[j++] = Arr[i];
    delete[] Arr;
    return r;
}

void a1()
{
    int sizeA, sizeB;
    cout << "Введите размер первого массива: ";
    cin >> sizeA;
    cout << "Введите размер второго массива: ";
    cin >> sizeB;
    int sizeC = sizeA + sizeB;
    int* arrA = new int[sizeA];
    int* arrB = new int[sizeB];
    cout << "\n\nПервый массив: ";
    cout << "{ ";
    for (int i = 0; i < sizeA; i++)
    {
        arrA[i] = rand() % 25;
        cout << arrA[i] << ", ";
    }
    cout << "}";
    cout << "\n\nВторой массив: ";
    cout << "{ ";
    for (int i = 0; i < sizeB; i++)
    {
        arrB[i] = rand() % 25;
        cout << arrB[i] << ", ";
    }
    cout << "}\n";

    int* arrC = new int[sizeC];
    int c = 0;
    for (int i = 0; i < sizeA; i++)
    {
        arrC[c++] = arrA[i];
    }
    for (int i = 0; i < sizeA; i++)
    {
        arrC[c++] = arrB[i];
    }
    cout << "\n\nМассив с элементами обоих массивов >>>  ";
    cout << "{ ";
    for (int i = 0; i < sizeC; i++)
    {
        cout << arrC[i] << ", ";
    }
    cout << "}\n";
}

void a2()
{

    int sizeA, sizeB;
    cout << "Введите размер первого массива: ";
    cin >> sizeA;
    cout << "Введите размер второго массива: ";
    cin >> sizeB;
    int* arrA = new int[sizeA];
    int* arrB = new int[sizeB];
    cout << "\n\nПервый массив: ";
    cout << "{ ";
    for (int i = 0; i < sizeA; i++)
    {
        arrA[i] = rand() % 25;
        cout << arrA[i] << ", ";
    }
    cout << "}";
    cout << "\n\nВторой массив: ";
    cout << "{ ";
    for (int i = 0; i < sizeB; i++)
    {
        arrB[i] = rand() % 25;
        cout << arrB[i] << ", ";
    }
    cout << "}\n";

    sort(arrA, sizeA);
    sort(arrB, sizeB);

    int* arrC = new int[sizeA < sizeB ? sizeA : sizeB];
    int sizeC = 0;

    for (int x = 0, y = 0; x < sizeA && y < sizeB; )
    {
        if (arrA[x] < arrB[y]) ++x;
        else if (arrA[x] > arrB[y]) ++y;
        else
        {
            arrC[sizeC++] = arrA[x];
            x++; y++;
        }
    }

    cout << "Mассив с общими элементами >>>  ";
    cout << "{ ";
    for (int i = 0; i < sizeC; i++)
    {
        cout << arrC[i] << ", ";
    }
    cout << "}";
    delete arrA;
    delete arrB;
    delete arrC;
}

void a3()
{
    int size; bool af = true;
    cout << "Введите размер массива: ";
    cin >> size;
    int* a = new int[size];
    cout << "\nМассив: ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 25;
        cout << a[i] << ", ";
    }
    cout << "}";

    while (af == true)
    {
        int n;
        cout << "\nMenu:" << endl;
        cout << "1 - удалить чётные числа" << endl;
        cout << "2 - удалить нечётные числа" << endl;
        cout << "3 - выход \n>>> ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            for (int i = 0; i < size; i++)
            {
                if (a[i] % 2 == 0)
                {
                    for (int j = i; j < size - 1; j++)
                    {
                        a[j] = a[j + 1];
                    }
                    size--;
                    i--;
                }
            }
            cout << "\nМассив без четных: { ";
            for (int i = 0; i < size; i++)
            {
                cout << a[i] << ", ";
            }
            cout << "}\n";
        } break;
        case 2:
        {
            for (int i = 0; i < size; i++)
            {
                if (!(a[i] % 2 == 0))
                {
                    for (int j = i; j < size - 1; j++)
                    {
                        a[j] = a[j + 1];
                    }
                    size--;
                    i--;
                }
            }
            cout << "\nМассив без нечетных : { ";
            for (int i = 0; i < size; i++)
            {
                cout << a[i] << ", ";
            }
            cout << "}\n";
            break;
        }
        case 3:
        {
            af = false; cout << "\nВыход из программы>>>>>>>>>>>>";
        }

        }
    }

}

void a4()
{
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* a = new int[size];
    cout << "\nМассив: ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 25;
        cout << a[i] << ", ";
    }
    cout << "}\n";
    vozvrat(a, size);
}

void a5()
{
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* a = new int[size];
    cout << "\nМассив: ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << ", ";
    }
    cout << "}\n";
    nuplmi(a, size);
}

void a6()
{
    cout << "\n\nНе понял задачу\n\n";
}

void a7()
{
    int  n, * r, size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* a = new int[size];
    cout << "\nМассив: ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << ", ";
    }
    cout << "}\n";

    r = DelNeg(a, size, n);
    cout << "Массив без отрицательных чисел \n{ ";
    for (int i = 0; i < n; i++) cout << r[i] << ", ";

    cout << "}" << endl;

    delete[] r;

}

void a8()
{
    int size, n;
    cout << "Введите размер массива: ";
    cin >> size;
    int* a = new int[size];
    cout << "\nМассив: ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << ", ";
    }
    cout << "}\n\n";
    cout << "Что добавить: "; cin >> n;
    addelement(a, size, n);
    cout << "\nГотовый массив >>> ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ", ";
    }
    cout << "}\n";
}

void a9()
{
    int size, n, g;
    cout << "Введите размер массива: ";
    cin >> size;
    int* a = new int[size];
    cout << "\nМассив: ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << ", ";
    }
    cout << "}\n\n";
    cout << "Что добавить: "; cin >> n;
    cout << "По какому индексу: "; cin >> g;
    insert(a, size, n);
    cout << "\nГотовый массив >>> ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ", ";
    }
    cout << "}\n";
}

void a10()
{
    int size, n;
    cout << "Введите размер массива: ";
    cin >> size;
    int* a = new int[size];
    cout << "\nМассив: ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << ", ";
    }
    cout << "}\n\n";
    cout << "Что удалить по индексу: "; cin >> n;
    dele(a, size, n);
    cout << "\nГотовый массив >>> ";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ", ";
    }
    cout << "}\n";
}

void main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int f;
    do {
        cout << "Ïåðâàÿ 1 - 6  >>> "; cin >> f;
        switch (f)
        {
        case 1:
            a1();
            break;
        case 2:
            a2();
            break;
        case 3:
            a3();
            break;
        case 4:
            a4();
            break;
        case 5:
            a5();
            break;
        case 6:
            a6();
            break;
        case 7:
            a7();
            break;
        case 8:
            a8();
            break;
        case 9:
            a9();
            break;
        case 10:
            a10();
            break;
        }
    } while (f != 0);
}
