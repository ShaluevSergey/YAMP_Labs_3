#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> selectionSort (vector <int> input);


vector <int> funcBMultiplication_NP_NP (const vector <int> &sortArr, int sizeNegSubArr)
{
    vector <int> output;

    // составляем пары из максимального по модулю отриц. числа и минимального положит. числа
    for (int i = 0; i < sortArr.size() / 2; i++)
    {
        output.push_back(sortArr[i]);
        output.push_back(sortArr[i + sizeNegSubArr]);

    }
    return output;
}


vector <int> funcBMultiplication_NN_PP (const vector <int> &sortArr, int sizeNegSubArr)
{
    vector <int> output;

    for (int i = 0; i < sizeNegSubArr/2; i++)
    {
        output.push_back(sortArr[i]);
        output.push_back(sortArr[sizeNegSubArr - 1 - i]);
    }
//середина положит. подмассива
    for (int i = sizeNegSubArr; i < sizeNegSubArr + (sortArr.size() - sizeNegSubArr) / 2; i++)
    {
        output.push_back(sortArr[i]);
        output.push_back(sortArr[sortArr.size() - 1 - i + sizeNegSubArr]);
    }

    return output;
}


vector <int> funcB (const vector <int> &arr) //главная функция
{
    vector <int> sortArr = selectionSort(arr);

    int sizeNegSubArr = 0;
    while (sizeNegSubArr < sortArr.size() && sortArr[sizeNegSubArr] < 0) //считаем количество отриц. чисел
    {
        sizeNegSubArr++;
    }

    enum varMuplip {NN_PP, NP_NP};

    varMuplip varMuplip = NP_NP;
    int multiplication = sortArr[0] * sortArr[sizeNegSubArr];
    // пробуем перемножать отриц. на положит, если произвед. совпадают, то пары составляются из отриц. и положит. числа, если не совпадают,
    for (int i = 1; i < sortArr.size()/2 - 1; i++)                              // то пары составляются из отриц-отриц, положит-положит.
    {
        int temp = sortArr[i] * sortArr[sizeNegSubArr + i];
        if (temp != multiplication)
        {
            varMuplip = NN_PP;
            break;
        }
    }

    if (varMuplip == NN_PP)
        return funcBMultiplication_NN_PP(sortArr, sizeNegSubArr);
    else
        return funcBMultiplication_NP_NP(sortArr, sizeNegSubArr);

}
