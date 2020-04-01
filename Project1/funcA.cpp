#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> selectionSort (vector <int> input);//сортировка


vector <int> funcA (const vector <int> &arr)
{
    vector <int> sortArr = selectionSort(arr);//создаём отсортированный массив

    vector <int> output;//переменная для записи

    for (int i = 0; i < sortArr.size()/2; i++)//цикл до середины
    {
        output.push_back(sortArr[i]);//берём первый элемент
        output.push_back(sortArr[sortArr.size() - 1 - i]);//берём последний элемент
    }

    return output;//возвращаем пары
}