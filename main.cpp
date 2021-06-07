/**
* @file main.cpp
*/
#include <hamming32.h>

int main()
{
    try {
        string a, b = "1";
        string text;
        vector<int> code;
        Hamming32 obj;

        do {
            code.clear();
            text = "";

            cout << "Выберите функцию 1 зашифровать, 2 расшифровать" << endl;
            cin >> a;

            if(a == "1") {
                cout << "Введите текст" << endl;
                cin >> text;

                vector<int> code = obj.encode(text);
                cout << "Закодированный текст:" << endl;
                obj.print_vec(code);

                cout << "Чтобы вернуться к выбору операции введите 1, выйти 2" << endl;
                cin >> b;
            } else if(a == "2") {
                cout << "Введите код. Допустимые символы 0 и 1." << endl;
                cin >> text;
                code = obj.stringToVec(text);

                text = obj.decode(code);
                cout << "Декодированный текст:" << endl;
                cout << text << endl;

                cout << "Чтобы вернуться к выбору операции введите 1, выйти 2" << endl;
                cin >> b;
            } else
                break;

        } while(b == "1");
    } catch (const error_hamming & e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
