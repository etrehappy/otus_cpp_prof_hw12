#include <iostream>
#include <string>
#include <sstream>

void ParseString(const std::string& line, const size_t target_column)
{
    bool quotes_open{false};
    size_t column{0};
    double price{0.0};  
    std::string line_part{};


    for (char ch : line) 
        {
            if (ch == '\"') 
            {
                quotes_open = !quotes_open; 
            } 
            else if (ch == ',' && !quotes_open) 
            {
                if ( column == target_column) 
                {                  
                    price = std::stod(line_part);
                  
                    std::cout << "price\t" << price << std::endl;
                    break; 
                }

                line_part.clear();
                column ++;
            } 
            else 
            {
                line_part += ch;
            }
        }
}

int main() 
{
    std::string line;
    const size_t target_column = 9;

    while (std::getline(std::cin, line)) 
    {       
        ParseString(line, target_column);        
    }

    return 0;
}
