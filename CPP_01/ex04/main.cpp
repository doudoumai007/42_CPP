#include <string>
#include <iostream>
#include <fstream> // open file: ifstream, create and write in file: ofstream

std::string	replaceString(const std::string line, const std::string s1, const std::string s2)
{
	std::string newline = line;
	if (s1.empty())
		return (newline);

	// try to find s1 position from 0 until can't find it anymore //
	size_t pos = 0;
	while ((pos = newline.find(s1, pos)) != std::string::npos)
	{
		newline.erase(pos, s1.length());
		newline.insert(pos, s2);
		pos += s2.length();
	}
	return (newline);
}

void	replaceLine
(
	std::ifstream &infile,
 	std::ofstream &outfile,
 	std::string s1,
	std::string s2
)
{
	std::string	line;
	while (std::getline(infile, line))
		outfile << replaceString(line, s1, s2) << std::endl;
}

int main(int argc, char *argv[])
{
	// check argument number //
	if (argc != 4)
	{
		std::cout << "./Replace filename string1 string2" << std::endl;
		return (1);
	}

	// open file //
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		std::cout << "Error: could not open file\n";
		return (1);
	}

	// get filename and add suffix //
	std::string	filename = argv[1];
	std::string outname = filename + ".replace";

	// create file //
	std::ofstream outfile(outname.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error: could not open file\n";
		return (1);
	}

	// replace in file
	replaceLine(infile, outfile, argv[2], argv[3]);
	return (0);
}