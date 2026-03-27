#include "RPN.hpp"

#include <sstream>
#include <cstdlib>
#include <iostream>

RPN::RPN(const RPN& other)
{
	*this = other;
}
RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

bool	isNumber(const std::string& token)
{
	if (token.empty())
		return (false);

	if (token.length() != 1)
	{
		//With sign
		if (token.length() == 2 && \
			(token[0] == '+' || token[0] == '-') && \
			isdigit(token[1]))
			return (true);
		else
			throw (std::runtime_error("Error: Input not one digit number!"));
	}
	if (!isdigit(token[0]))
		return (false);
	return (true);
}

bool	isOperator(const std::string& token)
{
	if (token.empty())
		return (false);
	
	if ((token[0] == '+' || \
		token[0] == '-' || \
		token[0] == '*' || \
		token[0] == '/') \
		&& token.length() == 1)
		return (true);
	return (false);
}

int	RPN::applyOp(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (!b)
			throw (std::runtime_error("Error: Divison by 0!"));
		return (a / b);
	}
	else
		throw (std::runtime_error("Error: Bad character in input!"));

}
void	RPN::processInput(const std::string& input)
{
	std::stringstream iss(input);
	std::string token;

	//Automatically splits the input by whitespace (spaces, tabs, newlines)
	while (iss >> token)
	{
		if (isNumber(token))
			_stack.push(std::atoi(token.c_str()));
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw (std::runtime_error("Error: Not enough operands!"));
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();

			_stack.push(applyOp(b, a, token[0]));
		}
		else
			throw (std::runtime_error("Error: Bad character in input!"));
	}
	if (_stack.size() > 1)
		throw (std::runtime_error("Error: Not enough operators!"));

}

void	RPN::printResult()
{
	std::cout << _stack.top() << std::endl;
}