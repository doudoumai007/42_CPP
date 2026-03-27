#pragma once

#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN() {}
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN(){}
	
		void	processInput(const std::string& token);
		int		applyOp(int a, int b, char op);
		void	printResult();
};
