# CodingStyle

## My Naming:
0. no prefix/postfix systems  
1. UPPER_CASE FOR MACRO, ENUMERATOR, CONST_VALUE  
2. CapitalCase For TypeName, ClassName, FunctionName, LambdaConatiner  
3. lower_case for namespace, variable, method, input_parameter  
4. use Abstract for AbstractClass

## Preference
  * never focus on anything can be formatted by formatter  
  * never focus on anything can be optimized by compiler  
  
  * no abbreviate as possible
  * no macro as possible  
  * no global variable as possible  
  * no functional programming as possible  
  * no RTTI as possible  
  * no friend keyword
  
  * use if (true == var) for avoiding missuse =
  * use != for bool conversion  
  * use "//" for comment  
  * use return type instead of out parameter as possible  
  * use Trailing Return Type as possible  
  * use const as possible  
  * use smart pointer as possible  
  * use RAII as possible  
  * use nullptr as possible  
  * use static_cast and reinterpret_cast as possible  

  * reduce local static variable  
  * reduce pass lambda to template parameter  

### Reasons for Naming Rules
0. C++ has standard prefix for member_variable and C++ has namespace  
1. enum was common defined with MACRO  
2. operator() can be implemented with Class(Functor), Function, Lambda  
3. It is easy to distinguish namespace, variable, method, parameter.  
4. Separating TypeName and variable_name is friendly to IDE.  

## References
https://llvm.org/docs/CodingStandards.html  
https://google.github.io/styleguide/cppguide.html  
