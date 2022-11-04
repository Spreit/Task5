// Task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Задача №5
//«Умный динамический массив»

//Вам предлагается создать класс, который опишет умный динамический
// массив из целых чисел.Количество чисел заранее неизвестно.
// Ограничением служит размер доступной оперативной памяти компьютера, но использовать память все же надо рационально.
//
//Что он должен уметь :
//1.	Добавлять элемент в конец.              .append+
//2.	Выдавать текущее количество элементов.  .length+
//3.	Выдавать элемент по индексу.            .value +
//4.	Изменять элемент по индексу.            .change+
//5.	Удалять элемент по индексу.             .remove+
//6.	Вставлять элемент по индексу.           .add   +
//

#include <iostream>

class smartmass {
private:
    int mass_length = 0;
    int* mass = new int[mass_length];

public:
    smartmass() {
        std::cout << "Initiated\n";
    };

    ~smartmass() {
        std::cout << "Destroyed\n";
    };

public:
    void append(int value) {
        mass_length += 1;
        int* tmp = new int[mass_length];

        memcpy( tmp, mass, (mass_length - 1) * 4);
        tmp[mass_length - 1] = value;

        delete[] mass;
        mass = tmp;
    };

    int length() {
        return mass_length;
    };

    int value(int index) {
        if (index < 0) {
            std::cout << "Negative Index!\n";
        }
        else {
            return mass[index];
        }
    };

    void change(int index, int value) {
        if (index < 0) {
            std::cout << "Negative Index!\n";
        }
        else {
            mass[index] = value;
        }
    };

    void remove(int index) {
        if (index < 0) {
            std::cout << "Negative Value!\n";
        }
        else {
            int* tmp = new int[mass_length - 1];

            memcpy(tmp, mass, index * 4);
            memcpy(tmp + index, mass + index + 1, (mass_length - index - 1) * 4);

            mass_length -= 1;

            delete[] mass;
            mass = tmp;
        }
    };

    //Никакой хеш таблицы! Растягиваем массив до индекса
    void add(int index, int value) {
        if (index < 0) {
            std::cout << "Negative Index!\n";
        }else {
            if (index > mass_length) {
                int og_mass_length = mass_length;
                mass_length = index + 1;
                int* tmp = new int[mass_length];

                memcpy(tmp, mass, og_mass_length * 4);
                tmp[index] = value;

                delete[] mass;
                mass = tmp;
            }
            else {
                mass_length = mass_length + 1;
                int* tmp = new int[mass_length];

                memcpy(tmp, mass, index * 4);
                memcpy(tmp + index + 1, mass + index, (mass_length - index) * 4);
                tmp[index] = value;

                delete[] mass;
                mass = tmp;
            }
        }
    };
};

int main()
{
    smartmass box;
    box.append(1);
    box.append(2);
    box.append(3);
    box.append(4);
    box.add(8,256);
    std::cout << box.value(0) << "\n";
    std::cout << box.value(1) << "\n";
    std::cout << box.value(2) << "\n";
    std::cout << box.value(3) << "\n";
    std::cout << box.value(4) << "\n";
    std::cout << box.value(7) << "\n";
    std::cout << box.value(8) << "\n";

//    std::cout << box.length() << "\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
