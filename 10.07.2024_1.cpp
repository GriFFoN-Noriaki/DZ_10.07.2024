#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    setlocale(LC_ALL, "Rus");

    // Открываем два текстовых файла для чтения
    std::ifstream file1("file1.txt");
    std::ifstream file2("file2.txt");

    std::string line1, line2;
    bool mismatch = false;

    // Считываем строки из каждого файла и сравниваем их
    while (std::getline(file1, line1) && std::getline(file2, line2)) {
        if (line1 != line2) 
        {
            std::cout << "Совпадают ли строки в файле 1 и файле 2: Нет\\n";
            std::cout << "Несовпадающая строка в файле 1: " << line1 << "\\n";
            std::cout << "Несовпадающая строка в файле 2: " << line2 << "\\n";
            mismatch = true;
            break; // Прерываем цикл, так как уже найдена несовпадающая строка
        }
    }

    // Если не найдено несовпадающих строк, выводим сообщение о совпадении
    if (!mismatch) 
    {
        std::cout << "Совпадают ли строки в файле 1 и файле 2: Да\n";
    }

    // Закрываем файлы
    file1.close();
    file2.close();

    return 0;
}