#include <iostream>
#include <string>

int main() 
{
    std::string key{};
    double value{0.0}, sum{0.0}, sum_squares{0.0};
    size_t count{0};

    while (std::cin >> key >> value) 
    {
        sum += value;
        sum_squares += value * value;
        ++count;
    }

    if (count > 0) 
    {
        double mean = sum / count;
        double variance = (sum_squares / count) - (mean * mean);
        std::cout << "variance\t" << variance << std::endl;
    }

    return 0;
}

