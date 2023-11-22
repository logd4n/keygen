#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void scanKey(std::string key)
{
    char lowLetters[4];
    char highLetters[6];
    int numbers[5], numberPosition = 0;

    for (size_t i = 0; i < 13; i++)
    {
        if (!isalpha(key[i]))
        {
            numbers[numberPosition++] = key[i];
        }
    }
    
    for (auto i : numbers)
    {
        cout << i << " ";
    }
    
}

int main()
{
    system("clear");
    
    srand(time(0));
    
    std::string key;

    cin >> key;

    cout << "Your key: " << key << '\n';

    scanKey(key);

    cout << endl;
    return 0;
}