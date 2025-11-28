#ifndef MPAGSCIPHER_RUNCEASARCIPHER_HPP
#define MPAGSCIPHER_RUNCEASARCIPHER_HPP

#include <string>
#include <vector>

std::string runCeasarCipher(const std::string& inputText,
                            const size_t key, const bool encrypt);

#endif      // MPAGSCIPHER_RUNCEASARCIPHER_HPP