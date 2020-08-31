#include <cmath>
#include <iostream>
#include <string>
#include <vector>
typedef std::string                 T_expr;
typedef std::vector     < int   >   T_ternary_number;
 
T_expr make_expr(T_ternary_number const & ternary_number, T_expr const & digits)
{
    T_expr  res;
    for( size_t  i{}; i < digits.size(); ++i )
    {
        if(i)
        {
            switch  (ternary_number[ i - 1 ])
            {
            case    1   :   res     +=  '+';    break;
            case    2   :   res     +=  '-';    break;
            default     :
                ;
            }//switch
        }//if
        res += digits[i];
    }//for
    return  res;
}
///////////////////////////////////////////////////////////////////////////////
int calc_expr( T_expr   expr )
{
    size_t  pos{};
    int res = std::stoi(expr, &pos);
    expr = expr.substr( pos );
 
    while (!expr.empty())
    {
        char op = expr.front();
        expr.erase(0, 1);
        int term = std::stoi(expr, &pos);
        expr = expr.substr( pos );
        op  ==  '+' ? res += term : res -= term;
    }//while
 
    return  res;
}
///////////////////////////////////////////////////////////////////////////////
bool    successfully_inc_ternary_number( T_ternary_number     &   ternary_number )
{
    for (int i = ternary_number.size() - 1; i >= 0; --i)
    {
        if  (ternary_number[i] < 3)
        {
            ++ternary_number[i];
            return  true;
        }
        else
        {
            ternary_number[i]   =   0;
        }
    }//for
 
    return  false;
}
///////////////////////////////////////////////////////////////////////////////
bool successfully_set_expr(int n, T_expr & expr)
{
    static const T_expr  DIGITS{ "123456789"   };
    T_ternary_number ternary_number(DIGITS.size() - 1);
 
    do
    {
        expr = make_expr(ternary_number, DIGITS);
        if (calc_expr( expr ) == n)
        {
            return  true;
        }
    }
    while (successfully_inc_ternary_number( ternary_number ));
 
    return  false;
}
///////////////////////////////////////////////////////////////////////////////
int main()
{
        int n{};
        n = 1;
        while (n<274)
        {
            n++;
            T_expr expr;
            std::cout << (successfully_set_expr( n,   expr ) ? expr : "") <<  std::endl;
        }
}
