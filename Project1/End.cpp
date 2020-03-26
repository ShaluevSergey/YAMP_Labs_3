#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//сортировка
vector <int> selectionSort (vector <int> input)//передаём в функцию вектор
{
    for (int i = 0; i < input.size(); i++)//пока не дойдём до конца массива
    {
        int indMaxValue = 0; // индекс максимального значения в неотсортированной части массива
        for (int j = 1; j < input.size() - i; j++) // ищем этот индекс
        {
            if (input[j] > input[indMaxValue])//если это значение больше максимального
                indMaxValue = j;//запоминаем его индекс как максимальное
        }

        int indLastNoSortSubArr = input.size() - 1 - i;//индекс последнего несортированного элемента массива
        swap (input[indMaxValue], input[indLastNoSortSubArr]);//меняем местами элементы
    }

    return input;//возвращаем отсортированный вектор (массив)
}



int main()
{

   vector <int> arr1 = {56, 1, 2, 1, 14, 28, 4, 56};

    vector <int> sortArr = selectionSort(arr1);//создаём отсортированный массив

    vector <int> taskA;//переменная для записи

    for (int i = 0; i < sortArr.size()/2; i++)//цикл до середины
    {
        taskA.push_back(sortArr[i]);//берём первый элемент
        taskA.push_back(sortArr[sortArr.size() - 1 - i]);//берём последний элемент
    }

    for (int i = 0; i < taskA.size(); i++)//выводим пары
    {
        cout << taskA[i] << " ";
        if (i % 2 == 1) cout << endl;
    }


    cout << endl << endl;



    vector <int> arr2 = {56, 1, 2, -56, 1, 14, 28, 4, 56, -1};
    vector <int> sortArr2 = selectionSort(arr2);//создаём сортированный массив

    vector <int> taskB;
        
    int sizeNegSubArr = 0;
    for (; sizeNegSubArr < sortArr2.size() && sortArr2[sizeNegSubArr] < 0; sizeNegSubArr++);//подсчитываем количество отрицательных чисел

    for (int i = 0; i < sizeNegSubArr/2; i++)//создаём отрицательные пары
    {
        taskB.push_back(sortArr2[i]);//добавляем на место первого
        taskB.push_back(sortArr2[sizeNegSubArr - 1 - i]);//добавляем на место второго
    }

    for (int i = sizeNegSubArr; i < sizeNegSubArr + (sortArr2.size()-sizeNegSubArr)/2; i++)//создаём положительные пары
    {
        taskB.push_back(sortArr2[i]);//на место первого
        taskB.push_back(sortArr2[sortArr2.size() - 1 - i + sizeNegSubArr]);//на место второго
    }


    for (int i = 0; i < taskB.size(); i++)//выводим пары
    {
        cout << taskB[i] << "\t";
        if (i % 2 == 1) cout << endl;
    }

    return 0;
}