#include <stdio.h>
#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		check_valid(char *base);
int		ft_strlen(char *str);
char	*ft_itoa_base(int nbr, char *base_to);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

void	run_test_case(char *nbr, char *base_from, char *base_to)
{
	char	*result;

	result = ft_convert_base(nbr, base_from, base_to);
	if (result)
	{
		printf("Conversion of \"%s\" from base \"%s\" to base \"%s\": %s\n",
			nbr, base_from, base_to, result);
		free(result);  // Don't forget to free memory after use
	}
	else
	{
		printf("Conversion failed for \"%s\" from base \"%s\" to base \"%s\".\n",
			nbr, base_from, base_to);
	}
}

int	main(void)
{
	// Test Case 1: Binary to Hexadecimal
	run_test_case("101011", "01", "0123456789ABCDEF");  // 101011 in binary to hexadecimal

	// Test Case 2: Decimal to Binary
	run_test_case("43", "0123456789", "01");  // 43 in decimal to binary

	// Test Case 3: Hexadecimal to Decimal
	run_test_case("2B", "0123456789ABCDEF", "0123456789");  // 2B in hexadecimal to decimal

	// Test Case 4: Invalid Base Conversion (Invalid base_from)
	run_test_case("101011", "01", "0");  // Invalid base_to (base is too short)

	// Test Case 5: Invalid Base Conversion (Invalid nbr value for base)
	run_test_case("123456", "012345", "01");  // Invalid input number for base "012345"

	// Test Case 6: Base 10 to Base 16
	run_test_case("255", "0123456789", "0123456789ABCDEF");  // 255 in decimal to hexadecimal

	// Test Case 7: Base 16 to Base 10
	run_test_case("FF", "0123456789ABCDEF", "0123456789");  // FF in hexadecimal to decimal

	// Test Case 8: Zero Case
	run_test_case("0", "0123456789", "01");  // Zero in decimal to binary

	// Test Case 8: Zero Case
	run_test_case("-2147483648", "0123456789", "01");  // Zero in decimal to binary
	return (0);
}
