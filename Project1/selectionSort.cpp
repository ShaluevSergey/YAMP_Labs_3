#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


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
