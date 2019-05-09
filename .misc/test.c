#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	intValue;
	float	floatValue;
	double	doubleValue;

	if (argc < 2)
	{
		printf("use : ./a.out [int] [float] [double]\n");
		return (0);
	}
	
	intValue = atoi(argv[1]);
	if (argv[2])
		floatValue = atoi(argv[2]);
	if (argv[3])
		doubleValue = atoi(argv[3]);

/*

Printf formatting is controlled by format identifiers which are shown below in their
simplest form.

' '		No argument expected.
%d %i		Signed decimal.
%o		Unsigned octal.
%u		Unsigned decimal.
%x %X		Unsigned hexadecimal (x and X) notation.

%D		Long int signed decimal.
%O		Long int unsigned octal.
%U		Long int unsigned decial.

%c		Character.
%s		String.
%p		Pointer (address).

%f		Double.

%e %E		Double.
%g %G		Double.

%n		Number of characters written by printf.
%%		%. No argument expected.

These identifiers actually have up to 6 parts as shown in the table below.
They MUST be used in the order shown:

%[flags][width][.precision][size_flag]type

The % marks the start and therfore is mandatory.

*/

// %d, %i
	printf("printf(\"%%d\", intValue);\n");
	printf("%d\n\n", intValue);
	printf("printf(\"%%i\", intValue);\n");
	printf("%i\n\n", intValue);

// %o
	printf("printf(\"%%o\", intValue);\n");
	printf("%o\n\n", intValue);

// %u
	printf("printf(\"%%u\", Unsigned intValue);\n");
	printf("%u\n\n", intValue);

// %x
	printf("printf(\"%%x\", intValue);\n");
	printf("%x\n\n", intValue);

// %X
	printf("printf(\"%%X\", intValue);\n");
	printf("%X\n\n", intValue);

// %c
	printf("printf(\"%%c\", Unsigned intValue);\n");
	printf("%u\n\n", intValue);

/*

FLAGS

The format identifers can be altered from their default function by applying the
following flags:
0	Field is padded with 0's instead of blanks.
-	Left justify.
+	Include sign in the output, + or -.
space	Positive values begin with a space, negative with a -.
# 	Various uses:
	%#o (Octal)	0 prefix inserted.
	%#x (Hex)	0x prefix added to non-zero values.
	%#X (Hex)	0X prefix added to non-zero values.
	%#e		Always show the decimal point.
	%#E		Always show the decimal point.
	%#f		Always show the decimal point.
	%#g		Always show the decimal point trailing 
			zeros not removed.
	%#G		Always show the decimal point trailing
			zeros not removed.

*/

// [FLAGS] 
	printf("// %%[FLAGS][no_width][no_.precision][no-size_flag]type\n\n");

// [+]d, include sign in the output, + or -
	printf("// [+], include sign in the output, + or -\nprintf(\"%%+d\", intValue);\n");
	printf("%+d\n\n", intValue);


// [ ]d, use space or - for the sign
	printf("// [ ], use space or - for the sign\nprintf(\"%% d\", intValue);\n");
	printf("% d\n\n", intValue);


// [-]d, left justify the output with space if necessary
	printf("// [-], left justify the output with space if necessary\nprintf(\"%%-10d\", intValue);\n");
	printf("%-10dc\n\n", intValue);


// [-+]d, combination with [+] (above), replace one space with sign
	printf("// [-+], combination with the above, put the sign with [+]\nprintf(\"%%-+10d\", intValue);\n");
	printf("%-+10dc\n\n", intValue);


// [#]o, prefix octal value with 0
	printf("// [#]o, prefix octal value with 0\nprintf(\"%%#o\", intValue);\n");
	printf("%#o\n", intValue);

// [#]x or [#]X, prefix hexadecimal output value with with 0x or 0X 	
	printf("// [#]x or [#]X, prefix hexadecimal output value with with 0x or 0X\nprintf(\"%%#x\", intValue);\n");
	printf("%#x\n", intValue);
	printf("printf(\"%%#X\", intValue);\n");
	printf("%#X\n\n", intValue);

// [#]e, [#]E or [#]f, always include a decimal point in floating-point value
	printf("// [#]e, [#]E or [#]f, always include a decimal point in floating-point value\nprintf(\"%%e\", doubleValue);\n");
	printf("%e\n", doubleValue);
	printf("printf(\"%%#E\", doubleValue);\n");
	printf("%#E\n", doubleValue);
	printf("printf(\"%%#f\", doubleValue);\n");
	printf("%#f\n\n", doubleValue);

// [#]g or [#]G, do not remove trailling zero
	printf("// [#]g or [#]G, do not remove trailling zero\nprintf(\"%%#g\", doubleValue);\n");
	printf("%#g\n", doubleValue);
	printf("printf(\"%%#G\", doubleValue);\n");
	printf("%#G\n\n", doubleValue);

// [0+value], use 0 as the pad character to the left in a right-justified numerical output value
	printf("// [0], use 0 as the pad character to the left in a right-justified numerical output value\nprintf(\"%%05d\", intValue);\n");
	printf("%05d\n\n", intValue);
		
	return (0);
}
