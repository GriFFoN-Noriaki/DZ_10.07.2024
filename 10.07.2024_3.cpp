#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция для шифрования текста шифром Цезаря
string encryptCaesarCipher(string text, int shift)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            char encryptedChar = text[i] + shift;

            if (isupper(text[i]))
            {
                if (encryptedChar > 'Z')
                {
                    encryptedChar = encryptedChar - 26;
                }
            }
            else
            {
                if (encryptedChar > 'z')
                {
                    encryptedChar = encryptedChar - 26;
                }
            }

            result += encryptedChar;
        }
        else
        {
            result += text[i];
        }
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "rus");

    string inputFileName = "input.txt";
    string outputFileName = "output.txt";
    string text;
    int shift;

    // Получаем текст из файла
    ifstream inputFile(inputFileName);
    if (inputFile.is_open())
    {
        getline(inputFile, text);
        inputFile.close();
    }
    else
    {
        cout << "Невозможно открыть файл" << endl;
        return 1;
    }

    // Получаем значение сдвига
    cout << "Введите значение сдвига для шифра Цезаря: ";
    cin >> shift;

    // Шифруем текст и записываем результат в файл
    string encryptedText = encryptCaesarCipher(text, shift);
    ofstream outputFile(outputFileName);
    if (outputFile.is_open())
    {
        outputFile << encryptedText;
        outputFile.close();
    }
    else
    {
        cout << "Невозможно открыть файл" << endl;
        return 1;
    }

    cout << "Текст успешно зашифрован и записан в выходной файл" << endl;

    return 0;
}