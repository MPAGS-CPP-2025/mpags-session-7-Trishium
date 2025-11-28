#include "ProcessCommandLine.hpp"
#include "TransformChar.hpp"
#include "RunCeasarCipher.hpp"

#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    bool will_encrypt{true};
    std::string inputFile{""};
    std::string outputFile{""};
    std::string cipherKey{""};

    // Process command line arguments
    const bool cmdLineStatus{processCommandLine(
        cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, will_encrypt, cipherKey)};

    // Any failure in the argument processing means we can't continue
    // Use a non-zero return value to indicate failure
    if (!cmdLineStatus) {
        return 1;
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << "  -e|--encrypt     Encrypt the provided text\n\n"
            << "  -d|--decrypt     Decrypt the provided text\n\n"
            << "  -k|--key         Cipher Key to encrypt or decrypt text"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        std::ifstream in_file {inputFile};
        bool ok_to_read = in_file.good();
        if (!ok_to_read){std::cerr << "Input file not opened" << std::endl; return 1;}
        while (in_file >> inputChar){
            inputText += transformChar(inputChar);
        }
        in_file.close();
    }
    else{
        while (std::cin >> inputChar) {
            inputText += transformChar(inputChar);
        }
    }
    // loop over each character from user input
    size_t key = std::stoi(cipherKey);
    std::string outputText{runCeasarCipher(inputText, key, will_encrypt)};
    
    // Print out the transliterated text

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::ofstream out_file {outputFile, std::ios::app};
        bool ok_to_write = out_file.good();
        if (!ok_to_write){std::cerr << "Output file not opened" << std::endl; return 1;}
        out_file << outputText << std::endl;
        out_file.close();
    }
    else{
        std::cout << outputText << std::endl;
    }
    
    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}
