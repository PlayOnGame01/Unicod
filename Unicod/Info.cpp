#include <iostream>
#include <sstream> // создает стринг стрим объект 
#include <tchar.h>
#include <string>
#include <memory> // часть управления динамической паматью 
#include <cctype> // Этот заголовок объявляет набор функций для классификации и преобразования отдельных символов.
#include <cstring> // Для управления строками и массивами 
using namespace std;

bool check_polindrom(wstring word)
{
    int length = word.length();
    for (int i = 0; i < length / 2; ++i)
    {
        if (word[i] != word[length - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    wstring test = _TEXT("I'm ___");
    {
        unsigned int num = NULL;
        unsigned int let = NULL;
        unsigned int acetra = NULL;
        for (auto i = test.begin(); i != test.end(); i++)
            if (*i >= '0' && *i <= '9')
            {
                ++num;
            }
            else if (*i >= 'a' && *i <= 'z' || *i >= 'A' && *i <= 'Z')
            {
                ++let;
            }
            else
            {
                ++acetra;
            }
        wcout << _TEXT("Colichestvo chisel -> ") << num << endl;
        wcout << _TEXT("Colichestvo bukv: ") << let << endl;
        wcout << _TEXT("Prochee: ") << acetra << endl;
        wcout << endl;
    }
    {
        wstringstream m_stream(test);
        istream_iterator<wstring, wchar_t> it(m_stream);
        wcout << "You has got  " << distance(it, istream_iterator<wstring, wchar_t>())<< " words" << endl << endl;
    }
    {
        bool proverka = true;
        for (size_t i = NULL; i < test.size() / 2; i++)
            if (test[i] != test[test.size() - i - 1])
            {
                proverka = false;
                break;
            }
        wcout << "This is " << (proverka ? "palindrome" : "not palindrome") << endl << endl;
    }
    {
        size_t chislo;
        do
        {
            while (true)
            {
                wcout << "Enter index: ";
                wcin >> chislo;
                if (!wcin.good())
                {
                    wcin.clear();
                    wcin.ignore(32767, '\n');// и удаляем значения предыдущего ввода из входного буфера
                }
                else break;
            }
        } while (chislo >= test.size());
        test.erase(test.begin() + chislo);
        wcout << test << endl;
    }
    {
        wchar_t word;
        while (true)
        {
            wcout << "Enter char: ";
            wcin >> word;
            if (!wcin.good()) // предыдущее извлечение оказалось хорошим 
            {
                wcin.clear(); // то возвращаем cin в 'обычный' режим работы
                wcin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            }
            else break;
        }
        auto i = test.begin();
        if (*i == word) test.erase(i);
        while (i != test.end())
        {
            if (*i == word) test.erase(i--);
            else ++i;
        }
        wcout << test << endl;
    }
    {
        size_t chislo;
        do
        {
            while (true)
            {
                wcout << "Enter index: ";
                wcin >> chislo;
                if (!wcin.good()) // предыдущее извлечение оказалось хорошим 
                {
                    wcin.clear(); // то возвращаем cin в 'обычный' режим работы
                    wcin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
                }
                else break;
            }
        } while (chislo >= test.size());
        wchar_t word;
        while (true)
        {
            wcout << "Enter char: ";
            wcin >> word;
            if (!wcin.good()) // предыдущее извлечение оказалось хорошим 
            {
                wcin.clear(); // то возвращаем cin в 'обычный' режим работы
                wcin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            }
            else break;
        }
        test.insert(test.begin() + chislo, word);
        wcout << test << endl;
    }



}