/*  # # #   # # #  # # #  # # # #       # # # #     #       #        # # #   # # # #
  #     # #     # #    # #             #    # #   #        #       # * * #  #
 #       #     # #    # # # # #       # # #   # #         #       #  *  #  #  # # #
#     # #     # #    # #             #    #   #          #       # * * #  #      #
# # #   # # #  # # #  # # # #       # # #    #          # # # #  # # #    # # # # */

//testingKey VERSION 1.0.0

#include <iostream>

using std::cout, std::cin, std::endl;

bool checkNumbers(int numbers[5])
{
    int sum = 0;

    cout << "Numbers: ";
    for (size_t i = 0; i < 4; i++)
    {
        cout << numbers[i] << " ";
    }
    
    sum = numbers[0] + numbers[1] + numbers[2];

    if (sum < 17)
    {
        if ((sum + numbers[3]) != 17)
            return false;
    }
    else if (sum > 17)
    {
        if ((sum - numbers[3]) != 17)
            return false;
    }
    else
    {
        if (numbers[3] != 0)
            return false;
    }    

    return true;
}

bool checkLetters(char letters[9])
{
    cout << "Letters: ";
    for (size_t i = 0; i < 8; i++)
    {
        cout << letters[i] << " ";
    }
    
    cout << '\n';

    return true;
}

bool scanKey(std::string &key)
{
    char letters[9];
    int numbers[5], numberPosition = 0, letterPosition = 0;

    for (size_t i = 0; i < 13; i++)
    {
        if (!isalpha(key[i]))
        {
            numbers[numberPosition] = key[i] - 48;

            numberPosition++;
        }
        else
        {
            letters[letterPosition] = key[i];

            letterPosition++;
        }
    }
    
    numbers[4] = '\0';

    if (checkNumbers(numbers))
    {
        cout << "\nNumbers is correct!\n";
    }
    else
    {
        cout << "\nNumbers is incorrect!\n";
        return false;
    }

    cout << '\n';

    if (checkLetters(letters))
    {
        cout << "\nLetters is correct!\n";
    }
    else
    {
        cout << "\nLetters is incorrect!\n"; return false;
    }

    return true;
}

int main()
{
    system("clear");

    std::string key; //
    int keySize = 0; //

    cout << "Enter the key: ";
    cin >> key; //

    keySize = key.length();

    if (keySize != 12) //
    {
        cout << "Error!\n";
        return 1;
    }    
    else
    {
        cout << "\nYour key: " << key << "\n\n";

        if (!scanKey(key))
        {
            cout << "Error!\n";        
            return 1;
        }
    }

    cout << endl;
    return 0;
}