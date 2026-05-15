#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include "dop_file_for_Task1.h"

using namespace std;

void Add_FUnction(map<string, pair<string, int>>& storage) {
    string item, when;
    int count;
    cin >> item >> count >> when;
    if (storage.count(when) == 0) {
        if (count <= 10) {
            storage[when] = {item, count};
            cout << "Добавили предмет " << item << " в ячейку " << when << '\n'; }
        else 
            cout << "В ячейке нету места \n";       
    }
    else {
        if (storage[when].first != item) {
            cout << "Ячейка занята другим предметом \n";
        }
        else {
            if (storage[when].second + count <= 10) {
                storage[when].second += count;
                cout << storage[when].second;
        }
            else {
               cout << "В ячейке нехватка места \n"; 
            }
        }
    }
    return;
}

void Remove_FUnction(map<string, pair<string, int>>& storage) {
    string item, when;
    int count;
    cin >> item >> count >> when;
    if (storage.count(when) != 0) {
        if (storage[when].first == item) {
            if (count <= storage[when].second) {
                storage[when].second -= count;
                cout << "Было убрано " << count << " предметов (Остаток: " << storage[when].second << ")\n";
            }
            else if (storage[when].second == 0)
                storage.erase(when);
            else 
                cout << "В ячейке нет столько предметов \n"; 
        }
        else {
            cout << "В ячейке нет такого предмета \n";
        }
    }
    else {
        cout << "Из ячейки нечего удалять \n";
    }
}

void Info_FUnction(const map<string, pair<string, int>>& storage) {
    cout << "Заполненость склада " << storage.size() / (6000.0 / 100.0)  << "% \n";
    int countA = 0, countB = 0, countC = 0;
    for (pair<string, pair<string, int>> item : storage) {
        if (item.first[0] == 'A') {
            countA++;
        }
        if (item.first[0] == 'B') {
            countB++;
        }
        if (item.first[0] == 'C') {
            countC++;
        }
    }
    cout << "A : " << countA / (2000.0 / 100.0) << "% \n";
    cout << "B : " << countB / (2000.0 / 100.0) << "% \n";
    cout << "C : " << countC / (2000.0 / 100.0) << "% \n";
    cout << "Заполненость склада: \n";
    for (pair<string, pair<string, int>> item : storage) {
            cout << item.first << " " << item.second.first << " " << item.second.second << "\n";
    }
    cout << "Пустые ячейки:";
    for (string item : {"A", "B", "C"}) {
        for (int i = 1; i <= 20; ++i) {
            for (int j = 1; j <= 5; ++j) {
                for (int k = 1; k <= 2; ++k) {
                    if (storage.count(item + to_string(i) + to_string(j) + to_string(k)) == 0)
                    cout << item + to_string(i) + to_string(j) + to_string(k) << " ";
                }
            }
        }
    }
    cout << "\n";
}

int main() {
    map<string, pair<string, int>> storage;
    string d;
    cin >> d;
    while (true) {
    switch(returnEnam(d)) {
        case Doing::ADD:
        Add_FUnction(storage);
        break;
        case Doing::REMOVE:
        Remove_FUnction(storage);
        break;
        case Doing::INFO:
        Info_FUnction(storage);
        break;
        default:
        cout << "Такой операции не существует,введите другую \n";
        break;
    }
    cin >> d;
}
}

Doing returnEnam(string a) {
    if (a == "ADD") return Doing::ADD;
    if (a == "REMOVE") return Doing::REMOVE;
    if (a == "INFO") return Doing::INFO;
    return Doing::EMPTY;
};