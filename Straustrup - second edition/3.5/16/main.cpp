#include <iostream>
#include <string>

/*
Checking comments in strings didn't implement
*/

std::string removeComments(const std::string s, int pos = 0)
{
	std::string str = s;
	static bool multilineComment = false;
	unsigned int found;
	if (multilineComment)
	{
		found = str.find("*/");
		if (found != std::string::npos)
		{
			str.erase(pos, found + 2 - pos);
			multilineComment = false;
		}
		else
		{
			str.erase(pos, str.length() - pos);
		}
	}
	pos = (pos > 0) ? pos + 2 : pos;
	found = str.find("/*", pos);
	if (found != std::string::npos)
	{
		multilineComment = true;
		str = removeComments(str, found);
	}
	found = str.find("//");
	if (found != std::string::npos)
	{
		str.erase(found, str.length() - found);
	}
	return str;
}

int main()
{
	std::string line;
	std::string code = "";
	while (true) {
        getline(std::cin, line);
        if (line.empty()) {
            break;
        }
        code += (removeComments(line) + '\n');
    }
	std::cout << code << std::endl;
	return 0;
}