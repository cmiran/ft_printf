#include "../inc/ft_printf.h"

int	main(void)
{
	ft_printf("Christopher Nolan\n");
	ft_printf("%%%%\n");
	
	printf("\n1\n");
	printf("lol : %-d Check Norris\n", -42);
	ft_printf("lol : %-d Check Norris\n", -42);
	
	printf("\n2\n");
	printf("%-10d Check\n", 42);
	ft_printf("%-10d Check\n", 42);	
	
	printf("\n3\n");
	printf("%-10i Check\n", 42);
	ft_printf("%-10i Check\n", 42);	

	printf("\n4\n");
	printf("%-.10i Check Norris\n", 42);
	ft_printf("%-.10i Check Norris\n\n", 42);

	printf("\n5\n");
	printf("%-.10i Check Norris\n", -42);
	ft_printf("%-.10i Check Norris\n\n", -42);

	printf("\n6\n");
	printf("%-10.5d Check Norris\n", 42);
	ft_printf("%-10.5d Check Norris\n\n", 42);

	printf("\n7\n");
	printf("%-10.5d Check Norris\n", -42);
	ft_printf("%-10.5d Check Norris\n\n", -42);

	printf("\n8\n");
	printf("%-+5.10i Check Norris\n", 42);
	ft_printf("%-+5.10i Check Norris\n\n", 42);
	
	printf("\n9\n");
	printf("%-+5.10i Check Norris\n", -42);
	ft_printf("%-+5.10i Check Norris\n\n", -42);

	printf("\n10\n");
	printf("% -10d Check\n", 42);
	ft_printf("% -10d Check\n", 42);

	printf("\n11\n");
	printf("% -10d Check\n", -42);
	ft_printf("% -10d Check\n", -42);


	printf("\n12\n");
	printf("% -d Check\n", -42);
	ft_printf("% -d Check\n", -42);

	printf("\n13\n");
	printf("% +-d Check\n", -42);
	ft_printf("% +-d Check\n", -42);

	printf("\n14\n");
	printf("%0-10d Check\n", -42);
	ft_printf("%0-10d Check\n", -42);
	
	printf("\n15\n");
	printf("%015d Check\n", -42);
	ft_printf("%015d Check\n", -42);
	
	printf("\n16\n");
	printf("%010.4d Check\n", -42);
	ft_printf("%010.4d Check\n", -42);
	
	printf("\n17\n");
	printf("%0 14d Check\n", -42);
	ft_printf("%0 14d Check\n", -42);
	
	printf("\n18\n");
	printf("%0 d Check\n", -42);
	ft_printf("%0 d Check\n", -42);

	printf("\n19\n");
	printf("%0 +-14d Check\n", -42);
	ft_printf("%0 +-14d Check\n", -42);
	
	printf("\n20\n");
	printf("%0 +17.89d Check\n", -42);
	ft_printf("%0 +17.89d Check\n", -42);

	printf("\n21\n");
	printf("%- +17.89d Check\n", +42);
	ft_printf("%- +17.89d Check\n", +42);

	printf("\n22\n");
	printf("%- +89.17d Check\n", -42);
	ft_printf("%- +89.17d Check\n", -42);

	printf("\n23\n");
	printf("%0 +89.17d Check\n", -42);
	ft_printf("%0 +89.17d Check\n", -42);

	printf("\n24\n");
	printf("%-10u Check\n", 42);
	ft_printf("%-10u Check\n", 42);	
	
	printf("\n25\n");
	printf("%-10u Check\n", 42);
	ft_printf("%-10u Check\n", 42);	

	printf("\n26\n");
	printf("%-.10u Check Norris\n", 42);
	ft_printf("%-.10u Check Norris\n\n", 42);

	printf("\n27\n");
	printf("%-10.5u Check Norris\n", 42);
	ft_printf("%-10.5u Check Norris\n\n", 42);

	printf("\n28\n");
	printf("%-+5.10u Check Norris\n", 42);
	ft_printf("%-+5.10u Check Norris\n\n", 42);

	printf("\n29\n");
	printf("% -10u Check\n", 42);
	ft_printf("% -10u Check\n", 42);

	printf("\n30\n");
	printf("% -u Check\n", 42);
	ft_printf("% -u Check\n", 42);

	printf("\n31\n");
	printf("% +-u Check\n", 42);
	ft_printf("% +-u Check\n", 42);

	printf("\n32\n");
	printf("%0-10u Check\n", 42);
	ft_printf("%0-10u Check\n", 42);
	
	printf("\n33\n");
	printf("%015u Check\n", 42);
	ft_printf("%015u Check\n", 42);
	
	printf("\n34\n");
	printf("%010.4u Check\n", 42);
	ft_printf("%010.4u Check\n", 42);
	
	printf("\n35\n");
	printf("%0 14u Check\n", 42);
	ft_printf("%0 14u Check\n", 42);
	
	printf("\n36\n");
	printf("%0 u Check\n", 42);
	ft_printf("%0 u Check\n", 42);

	printf("\n37\n");
	printf("%0 +-14u Check\n", 42);
	ft_printf("%0 +-14u Check\n", 42);
	
	printf("\n38\n");
	printf("%0 +17.89u Check\n", 42);
	ft_printf("%0 +17.89u Check\n", 42);

	printf("\n39\n");
	printf("%- +17.89u Check\n", +42);
	ft_printf("%- +17.89u Check\n", +42);

	printf("\n40\n");
	printf("%- +89.17u Check\n", 42);
	ft_printf("%- +89.17u Check\n", 42);

	printf("\n41\n");
	printf("%0 +89.17u Check\n", 42);
	ft_printf("%0 +89.17u Check\n", 42);

	printf("\n42\n");
	printf("%+u Check\n", 42);
	ft_printf("%+u Check\n", 42);

	printf("\n43\n");
	printf("%u Check\n", 42);
	ft_printf("%u Check\n", 42);

	printf("\n44\n");
	printf("%16o Check\n", 42001654);
	ft_printf("%16o Check\n", 42001654);
	
	printf("\n45\n");
	printf("%016.34u Check\n", 42);
	ft_printf("%016.34u Check\n", 42);

	printf("\n46\n");
	printf("%+u Check\n", 0);
	ft_printf("%+u Check\n", 0);

	printf("\n47\n");
	printf("%hhd Check\n", (char)'c');
	ft_printf("%hhd Check\n", (char)'c');

	printf("\n48\n");
	printf("% 5d Check\n", 0);
	ft_printf("% 5d Check\n", 0);
	
	printf("\n49\n");
	printf("% +.6d Check\n", 0);
	ft_printf("% +.6d Check\n", 0);

	printf("\n50\n");
	printf("%-5.1d Check\n", 0);
	ft_printf("%-5.1d Check\n", 0);
	
	printf("\n51\n");
	printf("% +-.1d Check\n", 0);
	ft_printf("% +-.1d Check\n", 0);

	printf("\n52\n");
	printf("lol % +-.1d, %4u, kde%-32.45d\n Check\n", 0, 56, -43);
	ft_printf("lol % +-.1d, %4u, kde%-32.45d\n Check\n", 0, 56, -43);
	
	printf("\n53\n");
	printf("% +15.5u Check\n", 0);
	ft_printf("% +15.5u Check\n", 0);

	printf("\n54\n");
	printf("% -.5u Check\n", 0);
	ft_printf("% -.5u Check\n", 0);
	
	printf("\n55\n");
	printf("% -.5d Check\n", 0);
	ft_printf("% -.5d Check\n", 0);

	printf("\n56\n");
	printf("%#o Check\n", 0);
	ft_printf("%#o Check\n", 0);

	printf("\n57\n");
	printf("%#o Check\n", 10);
	ft_printf("%#o Check\n", 10);

	printf("\n58\n");
	printf("%+#o Check\n", 10);
	ft_printf("%+#o Check\n", 10);

	printf("\n59\n");
	printf("%#10o Check\n", 10);
	ft_printf("%#10o Check\n", 10);

	printf("\n60\n");
	printf("%#10.5o Check\n", 10);
	ft_printf("%#10.5o Check\n", 10);

	printf("\n61\n");
	printf("%#5.10o Check\n", 10);
	ft_printf("%#5.10o Check\n", 10);

	printf("\n62\n");
	printf("%+#10o Check\n", 10);
	ft_printf("%+#10o Check\n", 10);

	printf("\n63\n");
	printf("% #.2o Check\n", 10);
	ft_printf("% #.2o Check\n", 10);

	printf("\n64\n");
	printf("%+#10.5o Check\n", 10);
	ft_printf("%+#10.5o Check\n", 10);

	printf("\n65\n");
	printf("%-+#10.5o Check\n", 10);
	ft_printf("%-+#10.5o Check\n", 10);

	printf("\n66\n");
	printf("%-+#.5o Check\n", 10);
	ft_printf("%-+#.5o Check\n", 10);
	
	printf("\n67\n");
	printf("%-+#2o Check\n", 10);
	ft_printf("%-+#2o Check\n", 10);

	printf("\n67\n");
	printf("%-+#48.75o Check\n", 94289528529245);
	ft_printf("%-+#48.75o Check\n", 94289528529245);
	
	printf("\n68\n");
	printf("%#x Check\n", 4098594);
	ft_printf("%#x Check\n", 4098594);

	printf("\n69\n");
	printf("%#X Check\n", 4098594);
	ft_printf("%#X Check\n", 4098594);

	printf("\n70\n");
	printf("%#10x Check\n", 4098594);
	ft_printf("%#10x Check\n", 4098594);

	printf("\n71\n");
	printf("%#10.2x Check\n", 4098594);
	ft_printf("%#10.2x Check\n", 4098594);

	printf("\n72\n");
	printf("%#10.15x Check\n", 4098594);
	ft_printf("%#10.15x Check\n", 4098594);

	printf("\n73\n");
	printf("%0#10.15x Check\n", 4098594);
	ft_printf("%0#10.15x Check\n", 4098594);	
	
	printf("\n74\n");
	printf("%-0#10.15x Check\n", 4098594);
	ft_printf("%-0#10.15x Check\n", 4098594);

	printf("\n75\n");
	printf("%-0#34.10x Check\n", 4098594);
	ft_printf("%-0#34.10x Check\n", 4098594);

	printf("\n76\n");
	printf("%0#34.10x Check\n", 4098594);
	ft_printf("%0#34.10x Check\n", 4098594);

	printf("\n77\n");
	printf("%+0#34.10x Check\n", 4098594);
	ft_printf("%+0#34.10x Check\n", 4098594);
	
	printf("\n78\n");
	printf("% +0#34.10x Check\n", 4098594);
	ft_printf("% +0#34.10x Check\n", 4098594);
	
	printf("\n79\n");
	printf("% +0#10.34x Check\n", 4098594);
	ft_printf("% +0#10.34x Check\n", 4098594);

	printf("\n80\n");
	ft_printf("%10b Check\n", 100);

	printf("\n81\n");
	ft_printf("%b Check\n", 256);

	printf("\n82\n");
	ft_printf("%-#10b Check\n", 100);

	printf("\n83\n");
	ft_printf("%#b Check\n", 12546);

	printf("\n84\n");
	ft_printf("%#+b Check\n", -2546);

	printf("\n85\n");
	ft_printf("%#+.64b Check\n", 62990);

	printf("\n86\n");
	printf("sal$#ut\n)*$$%%\t,cavabiendad%#75.43lX , %#0d , %#+-o\n\n", (unsigned long)3213, 431, 4314);
	ft_printf("sal$#ut\n)*$$%%\t,cavabiendad%#75.43lX , %#0d ,%#0b, %#+-o\n", (unsigned long)3213, 431, 45422, 4314);

	printf("\n87\n");
	ft_printf("%b Check\n", 0);

	printf("\n88\n");
	printf("%c Check\n", -74);
	
	printf("\n89\n");
	printf("%lc Check\n", 74);
	
	printf("\n90\n");
	printf("%.8f Check\n", 0.6);
	ft_printf("%f Check\n", 0.61);

	printf("\n91\n");
	printf("%+15f Check\n", 0.6);
//	ft_printf("%.25f Check\n", 0.6);

	printf("\n92\n");
	printf("%.f Check\n", 1.6);
//	ft_printf("%#.25f Check\n", 0.6);

	printf("\n93\n");
	printf("%#.25f Check\n", 6.6);
//	ft_printf("%#.25f Check\n", 0.6);

	printf("\n94\n");
	printf("%4.2f Check\n", 4.2);
//	ft_printf("%.5f Check\n", 0.6);

	printf("\n95\n");
	printf("%4.2f Check\n", 4.2);
//	ft_printf("%.5f Check\n", 0.6);

	printf("\n96\n");
	printf("%.0f\n", 99.99);
	
	printf("\n97\n");
	printf("%.17f\n", 0.6);

	printf("\n98\n");
	printf("%.f\n", -127.32435);
//	ft_printf("%.f\n", -127.32435);

	printf("\n99\n");
	printf("%.7f\n", 1456.45416345);

	printf("\n100\n");
	printf("%#145.50f\n", 12.345);
	short		nb;
	nb = -23;
	printf("max int :  %d\n", INT16_MAX);
	ft_printf("max int :  %d\n", INT16_MAX);
	printf("min int :  %d\n", INT16_MIN);
	ft_printf("min int :  %d\n", INT16_MIN);
	printf("max int :  %d\n", INT32_MAX);
	ft_printf("max int :  %d\n", INT32_MAX);
	printf("min int :  %d\n", INT32_MIN);
	ft_printf("min int :  %d\n", INT32_MIN);
	printf("max long :  %ld\n", LONG_MAX);
	ft_printf("max long :  %ld\n", LONG_MAX);
	printf("min long :  %ld\n", LONG_MIN);
	ft_printf("min long :  %ld\n", LONG_MIN);
	printf("max long long :  %lld\n", __LONG_LONG_MAX__);
	ft_printf("max long long :  %lld\n", __LONG_LONG_MAX__);
	printf("min long long :  %lld\n",LLONG_MIN);
	ft_printf("min long long :  %lld\n",LLONG_MIN);

	ft_printf("MINE>\t[%+1d]\n", 650);
	printf("ORIG>\t[%+1d]\n", 650);

	return (0);
}
