#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& cmdLineArgs,
                        bool& helpRequested, bool& versionRequested,
                        std::string& inputFile, std::string& outputFile, 
                        bool& encrypt_or_decrypt, std::string& cipher_key);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP