#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> selectionSort (vector <int> input);//����������


vector <int> funcA (const vector <int> &arr)
{
    vector <int> sortArr = selectionSort(arr);//������ ��������������� ������

    vector <int> output;//���������� ��� ������

    for (int i = 0; i < sortArr.size()/2; i++)//���� �� ��������
    {
        output.push_back(sortArr[i]);//���� ������ �������
        output.push_back(sortArr[sortArr.size() - 1 - i]);//���� ��������� �������
    }

    return output;//���������� ����
}