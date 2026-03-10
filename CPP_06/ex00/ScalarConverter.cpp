#include "ScalarConverter.hpp"

//static_cast is a a C++ type conversion operator.
//use: static_cast<new type>(variable to cast on)
//This function has internal linkage — it is visible only inside this file- so static

static bool isChar(const std::string &str)
{
	if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])) &&
		!std::isdigit(static_cast<unsigned char>(str[0])))
		return true;
	return false;
}

static bool isDigit(const std::string &str)
{
	size_t i = 0;

	if (str.empty())
		return false;

	if (str[i] == '-' || str[i] == '+')
		i++;

	if (i == str.length())
		return false;

	for (; i < str.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

static bool isFloat(const std::string &str)
{
    size_t i = 0;
    bool dotFound = false;
    bool digitFound = false;

    if (str.back() != 'f')
        return false;

    if (str[i] == '-' || str[i] == '+')
        i++;

    for (; i < str.length() - 1; i++)
    {
        if (str[i] == '.')
        {
            if (dotFound) return false;//if we find a second dot, it's not a valid float
            dotFound = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(str[i])))
            digitFound = true; 
        else
            return false;
    }
    return dotFound && digitFound;
}

static bool isDouble(const std::string &str)
{
	size_t i = 0;
	bool dotFound = false;

	if (str[i] == '-' || str[i] == '+')
		i++;

	for (; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (dotFound)
				return false;
			dotFound = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return dotFound;
}

static bool isPseudoLiteralFloat(const std::string &str)
{
	return (str == "nanf" || str == "+inff" || str == "-inff");
}

static bool isPseudoLiteralDouble(const std::string &str)
{
	return (str == "nan" || str == "+inf" || str == "-inf");
}

//numeric_limits: a class in the C++ Library made of functions(is_integer, is_signed, is_exact, has_infinity) and constants(min, max, lowest, epsilon) 
//numeric_limits is used to check the properties of arithmetic types (like int, float, double) and to get their limits and special values.
//quiet_NaN() is a static member function of std::numeric_limits that returns a quiet Not-a-Number (NaN) value for the specified type.
//infinity() is a static member function of std::numeric_limits that returns a positive infinity value for the specified type.

static double convertPseudoValue(const std::string &str)
{
	if (str == "nanf" || str == "nan")
		return std::numeric_limits<double>::quiet_NaN();
	if (str == "+inff" || str == "+inf")
		return std::numeric_limits<double>::infinity();
	if (str == "-inff" || str == "-inf")
		return -std::numeric_limits<double>::infinity();
	return 0.0;
}

static void printConverted(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)//isnan function checks if the value is NaN (Not a Number); 
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (std::isnan(value) ||
		value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;

	std::cout << "float: ";
	float f = static_cast<float>(value);

	if (std::isnan(f))
		std::cout << "nanf";
	else if (std::isinf(f))//isinf function checks if the value is positive or negative infinity.
	{
		if (f < 0)
			std::cout << "-inff";
		else
			std::cout << "+inff";
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << f << "f";//setprecision(1) sets the number of digits to display after the decimal point to 1, and fixed ensures that the number is displayed in fixed-point notation (not scientific notation)
	}
	std::cout << std::endl;

	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan";
	else if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "-inf";
		else
			std::cout << "+inf";
	}
	else
		std::cout << std::fixed << std::setprecision(1) << value;
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
    double value = 0.0; 
    if (isChar(input))
        value = static_cast<double>(input[0]);
	else if (isDigit(input))
	{
		try
		{
			long val = std::stol(input); // C++ version of atoi, throws exception and returns long
			if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
			{
				std::cout << "Invalid input" << std::endl;
				return;
			}
			value = static_cast<double>(static_cast<int>(val));//cast long to int, then cast int to double
		}
		catch (std::exception &e)//catches any exception thrown by stol
		{
			std::cout << "Invalid input" << std::endl;
			return;
		}
	}
    else if (isFloat(input))
        value = static_cast<double>(std::atof(input.c_str()));//atof converts a C-string to a double
    else if (isPseudoLiteralFloat(input))
        value = convertPseudoValue(input);
    else if (isPseudoLiteralDouble(input))
        value = convertPseudoValue(input);
    else if (isDouble(input))
        value = std::atof(input.c_str());
    else
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    printConverted(value);
}

