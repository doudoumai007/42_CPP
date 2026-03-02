#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 1;
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			char c = argv[i][j];
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				c = static_cast<char>(std::toupper(argv[i][j]));
			std::cout << c;
			j++;
		}
		if (i < argc - 1)
			std::cout << ' ';
		i++;
	}
	std::cout << std::endl;
	return (0);
}