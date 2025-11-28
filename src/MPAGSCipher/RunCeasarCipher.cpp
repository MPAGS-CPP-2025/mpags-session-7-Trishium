#include "RunCeasarCipher.hpp"

#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

std::string runCeasarCipher(const std::string& inputText, const size_t key, const bool encrypt){
    std::string outputText{""};
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for (auto &i : inputText){
        for (int j{0}; j < int(alphabet.size()); j++){
            if (i == alphabet[j]){
                if (encrypt){
                    outputText += alphabet[(j+key)%26];
                }
                else{
                    outputText += alphabet[(j-key+26)%26];
                }
            }
        }
    }


    return outputText;
}