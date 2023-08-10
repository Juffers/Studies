#include <iostream>
using namespace std;


class MilitaryUnit{
    string unit_type;
    int unit_count;
    int unit_strength;
public:
// Создаем конструктор, у него должно быть такое же имя, как и у класса
MilitaryUnit(const string& type, int count, int strength){
    unit_type = type;
    unit_count = count;
    unit_strength = strength;
}

// Конструктор копирования, такое же имя, как и у класса
MilitaryUnit(const MilitaryUnit& other){
    unit_type = other.unit_type;
    unit_strength = other.unit_strength;
    unit_count = other.unit_count;
}

// Деструктор, создаем с ~
~MilitaryUnit(){
    cout << "-----" << endl;
    cout << "Destroyed military unit: " << unit_type << endl;
}

// Перегружаем оператор сложения, при этом проверяем одинаковые ли роды войск
MilitaryUnit operator+(const MilitaryUnit& other){
    if(unit_type == other.unit_type){
        return MilitaryUnit(unit_type, unit_count + other.unit_count, unit_strength);
    }else{
        cout << "-------" << endl << "Impossible to subtract, as different types of troops" << endl << "-------" << endl;
        return *this;
    }
}

// Перегружаем оператор вычитания, проверяем совпадает ли род войск
// Далее проверяем вычитание, не является ли разность < 0
MilitaryUnit operator-(const MilitaryUnit& other){
    if(unit_type == other.unit_type){
        int new_count = unit_count - other.unit_count;
        if(new_count < 0){
            new_count = 0;
        }
        return MilitaryUnit(unit_type, new_count, unit_strength);
//      return MilitaryUnit(unit_type, unit_count - other.unit_count, unit_strength);
    }else{
        cout << "-------" << endl << "Impossible to subtract, as different types of troops" << endl << "-------" << endl;
        return *this;
    }
}

// Перегружаем оператор +=
MilitaryUnit operator+=(const MilitaryUnit& other){
    unit_count += other.unit_count;
    return *this;
}

// Перегружаем оператор -=
MilitaryUnit operator-=(const MilitaryUnit& other){
    unit_count -= other.unit_count;
    return *this;
}

// Перегружаем оператор *
MilitaryUnit operator*(MilitaryUnit& other){
    unit_count *= other.unit_count;
    return *this;
}

// Перегружаем оператор /
MilitaryUnit operator/(MilitaryUnit& other){
    unit_count /= other.unit_count;
    return *this;
}

// Перегружаем оператор присваивания + проверяем не является изначальный объект тем же самым
MilitaryUnit operator=(MilitaryUnit& other){
    if(this != &other){
    unit_type = other.unit_type;
    unit_count = other.unit_count;
    unit_strength = other.unit_strength;
    }
    return *this;
}

friend ostream& operator<<(ostream& os, const MilitaryUnit& unit);
friend istream& operator>>(istream& is, MilitaryUnit& unit);
};

ostream& operator<<(ostream& os, const MilitaryUnit& unit){
    os << "Unit type: " << unit.unit_type << endl << "Count: " << unit.unit_count << endl << "Strength: " << unit.unit_strength << endl;
    return os;
}

istream& operator>>(istream& is, MilitaryUnit& unit){
    cout << "Enter Unit Type: " << endl;
    is >> unit.unit_type;
    cout << "Enter Unit Count: " << endl;
    is >> unit.unit_count;
    cout << "Enter Unit Strength: " << endl;
    is >> unit.unit_strength;
    return is;
}



int main(){
    MilitaryUnit unit1("Russia", 100, 150);
    MilitaryUnit unit2("Spain", 500, 300);

    cout << "Unit 1: " << endl << "-------" << endl << unit1 << endl;
    cout << "Unit 2: " << endl << "-------" << endl << unit2 << endl;

    MilitaryUnit unit3 = unit2 + unit2;
    cout << "Unit 3: " << endl << "-------" << endl << unit3 << endl;


    MilitaryUnit unit4 = unit3 - unit1;
    cout << "Unit 4: " << endl << "-------" << endl << unit4 << endl;

    unit4 += unit2;
    cout << "Unit 4 += Unit 2" << unit4;

    unit4 -= unit2;
    cout << "Unit 4 -= Unit 2" << unit4;

    return 0;
}
