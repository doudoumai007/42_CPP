#include <vector>
#include <iostream>
using namespace std;

int main() {
    std::vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);  // 添加元素

for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
{
    std::cout << *it << " ";
}
}