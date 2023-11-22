/*  # # #   # # #  # # #  # # # #       # # # #     #       #        # # #   # # # #
  #     # #     # #    # #             #    # #   #        #       # * * #  #
 #       #     # #    # # # # #       # # #   # #         #       #  *  #  #  # # #
#     # #     # #    # #             #    #   #          #       # * * #  #      #
# # #   # # #  # # #  # # # #       # # #    #          # # # #  # # #    # # # # */

//keygen VERSION 1.2.1

#include <iostream>

using std::cout;
using std::endl;    

void printKey(char key[], int numbers[])
{
    cout << "\nKey: ";

    int numberPlace = 0;

    cout << key[0]; //Позиция 1

    numberPlace = 1 + rand() % 2;
    
    if (numberPlace == 1) //Позиция 2 и 3
        cout << numbers[0] << key[2];
    else
        cout << key[1] << numbers[0];

    for (size_t i = 3; i < 7; i++)
    {
        cout << key[i];
    }
    
    numberPlace = 7 + rand() % 2;

    if (numberPlace == 7) //Позиция 8 или 9
        cout << numbers[1] << key[7];
    else
        cout << key[6] << numbers[1];

    cout << numbers[2] << key[8] << numbers[3]; //Позиции 10, 11, 12

    cout << endl;
}

void deleteSymbol(char array[], int position, int arrayLenght)
{
    position--;

    for (size_t i = position; i < arrayLenght - 1; i++)
    {
        array[i] = array[i+1];
    }
}

void deleteSymbol(int numbers[], int &size, int position)
{
    for (size_t i = position; i < size - 1; i++)
    {
        numbers[i] = numbers[i + 1];
    }
    
    size--;

    numbers[size - 1] = '\0';
}

void generateHighLetters(char key[])
{
    int lettersPosition = 0;

    int randomLetterPosition = 0;
    int size = 26;
    char highLetters[27] = {"QWERTYUIOPASDFGHJKLZXCVBNM"};

    randomLetterPosition = rand() % size;
    key[lettersPosition] = highLetters[randomLetterPosition]; //Позиция 1
    deleteSymbol(highLetters, randomLetterPosition, size); size--;

    if (isalpha(key[1])) //Позиция 2 или 3
    {
        randomLetterPosition = rand() % size;
        key[1] = highLetters[randomLetterPosition];
    }
    else
    {
        randomLetterPosition = rand() % size;
        key[2] = highLetters[randomLetterPosition];
    }  

    deleteSymbol(highLetters, randomLetterPosition, size); size--;

    key[5] = highLetters[randomLetterPosition]; //Позиция 6

    deleteSymbol(highLetters, randomLetterPosition, size); size--;

    if (isalpha(key[7])) //Позиция 8 или 9
    {
        randomLetterPosition = rand() % size;
        key[7] = highLetters[randomLetterPosition];
    }
    else
    {
        randomLetterPosition = rand() % size;
        key[8] = highLetters[randomLetterPosition];
    }  

    deleteSymbol(highLetters, randomLetterPosition, size); size--;

    randomLetterPosition = rand() % size;
    key[10] = highLetters[randomLetterPosition]; //Позиция 11

    deleteSymbol(highLetters, randomLetterPosition, size); size--;
}

void generateLowLetters(char key[])
{
    char lowLetters[27] = {"qwertyuiopasdfghjklzxcvbnm"};

    for (size_t i = 0; i < 12; i++)
    {
        key[i] = lowLetters[rand() % 26];
    }
}

void generateNumbers(char letters[])
{
    int numberPlace = 0;
    int sum = 0;
    int numberSize = 8;

    int result[5];
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char key[13];

    for (size_t i = 0; i < 13; i++)
    {
        key[i] = letters[i];
    }

    result[0] = 7;

    deleteSymbol(numbers, numberSize, 6);

    for (size_t i = 1; i < 3; i++)
    {
        int randomNumberPosition = 1 + rand() % (numberSize - 1);

        result[i] = numbers[randomNumberPosition];

        deleteSymbol(numbers, numberSize, randomNumberPosition);
    }
    

    for (size_t i = 0; i < 3; i++)
    {
        sum += result[i];
    }

    result[3] = abs(17 - sum);

    result[4] = '\0';  

    cout << "Numbers: ";
    for (size_t i = 0; i < 4; i++)
    {
        cout << result[i] << " ";
    }

    int size = 0;
    cout << "\nKey: ";
    for (size_t i = 0; i < 12; i++)
    {
        cout << key[i] << " ";

        size++;
    }

    cout << "\nSize: " << size << "\n";

    printKey(key, result);
}

int main()
{
    system("clear");
    srand(time(0));

    char key[13];    

    generateLowLetters(key); //генерация ключа из строчных букв

    generateHighLetters(key); //генерация ключа из заглавных букв

    generateNumbers(key); //генерация чисел

    cout << endl;
    return 0;
}