#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Hamming32
{
private:
    vector<int> toBin(int num); //Переводит в двоичную и дополняет до 8 символов
    int toDec(vector<int> vec); //Переводит в десятичную вектор из 8 символов
public:
    vector<int> encode(string text); //Кодирует
    string decode(vector<int> code); //Декодирует
    void print_vec(vector<int> vec); //Печатает вектор
    vector<int> stringToVec(string str); //Переводит строку в вектор
};
