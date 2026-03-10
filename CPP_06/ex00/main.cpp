#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2) 
    {
		std::cout << "Wrong number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(argv[1]);
	return (EXIT_SUCCESS);
}



//./convert 'a'      # char: 'a'  int: 97   float: 97.0f   double: 97.0
//./convert ' '      # char: ' '  int: 32   float: 32.0f   double: 32.0
//./convert '~'      # char: '~'  int: 126  float: 126.0f  double: 126.0  (last printable ASCII)

//./convert 0        # char: Non displayable  int: 0    float: 0.0f   double: 0.0
//./convert 42       # char: '*'  int: 42   float: 42.0f  double: 42.0
//./convert -1       # char: impossible  int: -1  float: -1.0f  double: -1.0
//./convert 2147483647   # INT_MAX — char: impossible  int: 2147483647  float: 2147483648.0f (precision loss)  double: 2147483647.0
//./convert 2147483648   → Invalid input  (overflows int)//because 1 above INT_MAX
//./convert -2147483648  → INT_MIN char: impossible  int: -2147483648  float: -2147483648.0f  double: -2147483648.0  
//./convert -2147483649  → Invalid input  (underflows int) //because 1 below INT_MIN

//./convert 0.0          # char: Non displayable  int: 0  float: 0.0f  double: 0.0
//./convert 1.5          # char: Non displayable  int: 1  float: 1.5f  double: 1.5
//./convert -inf         # char: impossible  int: impossible  float: -inff  double: -inf
//./convert +inf         # char: impossible  int: impossible  float: +inff  double: +inf
//./convert nan          # char: impossible  int: impossible  float: nanf   double: nan

// ./convert ""           # Invalid input
// ./convert "abc"        # Invalid input
// ./convert "12abc"      # Invalid input
// ./convert "1.2.3"      # Invalid input (two dots)
// ./convert "1.2f3"      # Invalid input
// ./convert "."          # char: '.'  int: 46  float: 46.0f  double: 46.0 
// ./convert ".f"         # Invalid input (catches your isFloat bug)
// ./convert "--1"        # Invalid input
// ./convert "1f"         # Invalid input (no dot, so not a valid float)
// ./convert " 42"        # Invalid input (leading space)
// ./convert ".f"    	  # Invalid input  
// ./convert "0.0f"    	  # char: Non displayable  int: 0  float: 0.0f  double: 0.0 (trailing 'f' with no digits after it is valid)	
// ./convert ".5f"        # char: Non displayable  int: 0  float: 0.5f  double: 0.5  (leading dot with no digits before it is valid) 

// ./convert 31           # char: Non displayable (just below printable range)
// ./convert 32           # char: ' '  (first printable)
// ./convert 126          # char: '~'  (last printable)
// ./convert 127          # char: Non displayable (DEL character)
// ./convert 128          # char: impossible (above ASCII range)