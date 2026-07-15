#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
class MinCalculator {
public:
    using ResultType = std::common_type_t<T1, T2>;

    ResultType Min(T1 lhs, T2 rhs) const
    {
        return lhs < rhs ? static_cast<ResultType>(lhs) : static_cast<ResultType>(rhs);
    }
};

int main()
{
    MinCalculator<int, int> intInt;
    MinCalculator<float, float> floatFloat;
    MinCalculator<double, double> doubleDouble;
    MinCalculator<int, float> intFloat;
    MinCalculator<int, double> intDouble;
    MinCalculator<float, double> floatDouble;

    std::cout << "int, int: " << intInt.Min(10, 20) << '\n';
    std::cout << "float, float: " << floatFloat.Min(3.5f, 1.25f) << '\n';
    std::cout << "double, double: " << doubleDouble.Min(7.25, 8.25) << '\n';
    std::cout << "int, float: " << intFloat.Min(5, 2.5f) << '\n';
    std::cout << "int, double: " << intDouble.Min(4, 6.75) << '\n';
    std::cout << "float, double: " << floatDouble.Min(8.511f, 3.121) << '\n';

    return 0;
}
