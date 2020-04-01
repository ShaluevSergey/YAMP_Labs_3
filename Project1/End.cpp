#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> selectionSort(vector <int> input);//сортировка
vector <int> funcA(const vector <int>& arr);//А
vector <int> funcB(const vector <int>& arr);//Б


int main()
{

    vector <int> arr1 = { 56, 1, 2, 1, 14, 28, 4, 56 };

    vector <int> sortArr = selectionSort(arr1);//Сортируем

    vector <int> taskA = funcA(sortArr);//делаем пары

    cout << " A:" << endl;
    for (int i = 0; i < taskA.size(); i++)//выводим пары
    {
        cout << taskA[i] << " ";
        if (i % 2 == 1) cout << endl;
    }


    cout << endl << endl;

    cout << " B:" << endl;

    vector <int> arr2 = { -56, 1, -2, 56, -1, -14, 28, 4, 56, -1 };

    vector <int> taskB = funcB(arr2);//Вызываем главную функцию

    for (int i = 0; i < taskB.size(); i++)//выводим пары
    {
        cout << taskB[i] << "\t";
        if (i % 2 == 1) cout << endl;
    }

    return 0;
}
