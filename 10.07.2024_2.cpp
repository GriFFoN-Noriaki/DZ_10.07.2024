#include <iostream>
#include <fstream>
#include <cctype>

int main() 
{
    setlocale(LC_ALL, "rus");

    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    if (!in.is_open() || !out.is_open()) 
    {
        std::cout << "Ошибка открытия файлов!" << std::endl;
        return 1;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    char c;
    while (in.get(c)) 
    {
        // Count characters
        charCount++;

        // Count lines
        if (c == '\\n') 
        {
            lineCount++;
        }

        // Count vowels and consonants
        if (isalpha(c)) 
        {
            if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }

        // Count digits
        if (isdigit(c)) 
        {
            digitCount++;
        }
    }

    // Close files
    in.close();
    out << "Количество символов: " << charCount << std::endl;
    out << "Количество строк: " << lineCount << std::endl;
    out << "Количество гласных букв: " << vowelCount << std::endl;
    out << "Количество согласных букв: " << consonantCount << std::endl;
    out << "Количество цифр: " << digitCount << std::endl;
    out.close();

    std::cout << "Статистика записана в файл output.txt." << std::endl;

    return 0;
}