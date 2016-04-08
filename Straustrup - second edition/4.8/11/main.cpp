#include <iostream>
#include <string>

int main()
{
    std::string keys;
    std::string text;
    std::cout << "Enter keys: ";
    std::getline(std::cin, keys);
    std::cout << "Enter text:" << std::endl;
    std::string line;
    do
    {
        std::getline(std::cin, line);
        if (line.length() > 0)
            text += (line + '\n');
    }
    while(line.length() > 0);

    std::string encodedText = "";
    for (size_t i(0), k(0); i < text.length(); ++i, ++k)
    {
        if (k >= keys.length())
            k = 0;
        encodedText += text[i]^keys[k];
    }

    std::cout << "Keys: " << keys << std::endl;
    std::cout << "Text:\n" << text << std::endl;
    std::cout << "\nEncoded text:\n" << encodedText << std::endl;
    return 0;
}
