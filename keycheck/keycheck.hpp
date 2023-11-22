/*  # # #   # # #  # # #  # # # #       # # # #     #       #        # # #   # # # #
  #     # #     # #    # #             #    # #   #        #       # * * #  #
 #       #     # #    # # # # #       # # #   # #         #       #  *  #  #  # # #
#     # #     # #    # #             #    #   #          #       # * * #  #      #
# # #   # # #  # # #  # # # #       # # #    #          # # # #  # # #    # # # # */

//keycheck.hpp VERSION 1.0.0

#ifndef _KEY_CHECK_HPP_
#define _KEY_CHECK_HPP_

#include <iostream>

namespace kc_log
{
  class KeyCheck
  {
  private:

  void deleteSymbol(char array[], int position, int &arrayLenght);

    bool checkNumbers(int numbers[5]);

    bool checkLetters(char letters[9]);

    bool scanKey(std::string &_key);

  public:
    int checkKey(std::string &_key);
  };
}

#endif //_KEY_CHECK_HPP_