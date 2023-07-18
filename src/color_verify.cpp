#include <iostream>
#include <string>

#define MACRO_VAR 5

namespace ns
{

template<typename Type>
class TPClass
{
public:
    int member_var = MACRO_VAR;
    int MemberFun() { return member_var; }
    static const int static_member = 10;

    static TPClass& StaticFunction() { 
        ns::TPClass<Type> instance; 
        return instance;
    }

private:
    TPClass() {};
    ~TPClass() {};
};

static int global_var = 333;

template<typename Type> 
std::string TPFunction() {
    auto output = "output" + std::to_string(ns::TPClass<int>::StaticFunction().member_var);
    return output += "test";
}

void GlobalFun() {
    std::cout << TPFunction<float>();
}

} // namespace ns
