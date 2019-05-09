#include "../ft_printf.h"

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
	ft_printf("%#+.6333b Check\n", 62990);

	printf("\n86\n");
//	printf("sal$#ut\n)*$$%%\t,cavabiendad%#75.43lX , %#0d , %n+-o\n", (unsigned long)3213, 431, 4314);
	ft_printf("sal$#ut\n)*$$%%\t,cavabiendad%#75.43lX , %#0d ,%#0b, %#+-o\n", (unsigned long)3213, 431, 45422, 4314);

	printf("\n87\n");
	ft_printf("%b Check\n", 0);

	printf("\n88\n");
	printf("%c Check\n", -74);
	
	printf("\n89\n");
	printf("%lc Check\n", 74);

	printf("\n90\n");
	printf("%.8f Check\n", 0.6);
	ft_printf("%.8f Check\n", 0.6);

	printf("\n91\n");
	printf("%+15f Check\n", 0.6);
	ft_printf("%+15f Check\n", 0.6);

	printf("\n92\n");
	printf("%.f Check\n", 1.6);
	ft_printf("%.f Check\n", 1.6);

	printf("\n93\n");
	printf("%#.25f Check\n", 6.6);
	ft_printf("%#.25f Check\n", 6.6);

	printf("\n94\n");
	printf("%4.2f Check\n", 4.2);
	ft_printf("%4.2f Check\n", 4.2);

	printf("\n95\n");
	printf("%+4.2f Check\n", 4.2);
	ft_printf("%+4.2f Check\n", 4.2);

	printf("\n96\n");
	printf("%.0f\n", 99.99);
	ft_printf("%.0f\n", 99.99);

	printf("\n97\n");
	printf("%.25f\n", 0.6);
	ft_printf("%.25f\n", 0.6);

	printf("\n97\n");
	printf("%.19f\n", 0.6);
	ft_printf("%.19f\n", 0.6);

	printf("\n97\n");
	printf("%.17f\n", 0.6);
	ft_printf("%.17f\n", 0.6);

	printf("\n97\n");
	printf("%.16f\n", 0.6);
	ft_printf("%.16f\n", 0.6);

	printf("\n98\n");
	printf("%.f\n", -127.52435);
	ft_printf("%.f\n", -127.52435);

	printf("\n99\n");
	printf("%.25f\ta\n", 1456.45416345);
	ft_printf("%.25f\ta\n", 1456.45416345);

	printf("\n99\n");
	printf("%.15f\n\t", 1456.454199988996345);
	ft_printf("%.15f\n", 1456.454199988996345);

	printf("\n100\n");
	printf("%#145.13fnorris\n", 12.345);
	ft_printf("%#145.13fnorris\n", 12.345);

	printf("\n101\n");
	printf("%# fnorris\n", 12.345);
	ft_printf("%# fnorris\n", 12.345);

	printf("\n102\n");
	printf("%-156.14f check\n", 12.345);
	ft_printf("%-156.14f check\n", 12.345);

	printf("\n103\n");
	printf("%#15.f check\n", 12);
	ft_printf("%#15.f check\n", 12);

	printf("\n104\n");
	printf("%#15.f check\n", 12);
	ft_printf("%#15.f check\n", 12);

	printf("\n105\n");
	printf("max int :  %d\n", INT16_MAX);
	ft_printf("max int :  %d\n", INT16_MAX);
	
	printf("\n106\n");	
	printf("min int :  %d\n", INT16_MIN);
	ft_printf("min int :  %d\n", INT16_MIN);
		
	printf("\n107\n");	
	printf("max int :  %d\n", INT32_MAX);
	ft_printf("max int :  %d\n", INT32_MAX);
		
	printf("\n97\n");
	printf("%.25f\n", 0.6);
	ft_printf("%.25f\n", 0.6);

	printf("\n97\n");
	printf("%.19f\n", 0.6);
	ft_printf("%.19f\n", 0.6);

	printf("\n97\n");
	printf("%.17f\n", 0.6);
	ft_printf("%.17f\n", 0.6);

	printf("\n97\n");
	printf("%.16f\n", 0.6);
	ft_printf("%.16f\n", 0.6);

	printf("\n98\n");
	printf("%.f\n", -127.52435);
	ft_printf("%.f\n", -127.52435);

	printf("\n99\n");
	printf("%.26f\ta\n", 1456.45416345);
	ft_printf("%.26f\ta\n", 1456.45416345);
	printf("%.31f\ta\n", 1456.45416345);
	ft_printf("%.31f\ta\n", 1456.45416345);
	printf("%.36f\ta\n", 1456.45416345);
	ft_printf("%.36f\ta\n", 1456.45416345);

	printf("\n99\n");
	printf("%.15f\n\t", 1456.454199988996345);
	ft_printf("%.15f\n", 1456.454199988996345);

	printf("\n100\n");
	printf("%#145.13fnorris\n", 12.345);
	ft_printf("%#145.13fnorris\n", 12.345);

	printf("\n101\n");
	printf("%# fnorris\n", 12.345);
	ft_printf("%# fnorris\n", 12.345);

	printf("\n102\n");
	printf("%-156.14f check\n", 12.345);
	ft_printf("%-156.14f check\n", 12.345);

	printf("\n103\n");
	printf("%#15.f check\n", 12);
	ft_printf("%#15.f check\n", 12);

	printf("\n104\n");
	printf("%#15.f check\n", 12);
	ft_printf("%#15.f check\n", 12);
/*
	printf("\n105\n");
	printf("max int :  %d\n", INT16_MAX);
	ft_printf("max int :  %d\n", INT16_MAX);
	
	printf("\n106\n");	
	printf("min int :  %d\n", INT16_MIN);
	ft_printf("min int :  %d\n", INT16_MIN);
		
	printf("\n107\n");	
	printf("max int :  %d\n", INT32_MAX);
	ft_printf("max int :  %d\n", INT32_MAX);
		
	printf("\n108\n");	
	printf("min int :  %d\n", INT32_MIN);
	ft_printf("min int :  %d\n", INT32_MIN);
		
	printf("\n109\n");	
	printf("max long :  %ld\n", LONG_MAX);
	ft_printf("max long :  %ld\n", LONG_MAX);
		
	printf("\n110\n");	
	printf("min long :  %ld\n", LONG_MIN);
	ft_printf("min long :  %ld\n", LONG_MIN);
		
	printf("\n112\n");	
	printf("max long long :  %lld\n", LLONG_MAX);
	ft_printf("max long long :  %lld\n", LLONG_MAX);
		
	printf("\n113\n");	
	printf("min long long :  %lld\n",LLONG_MIN);
	ft_printf("min long long :  %lld\n",LLONG_MIN);

	int	nb;
	nb = -45; 
		
	printf("\n114\n");	
	printf("space% d\n", nb);
	ft_printf("space% d\n", nb);
			
	printf("\n115\n");
	printf("space% d\n", nb);
	ft_printf("plus:%+d\n", nb);
			
	printf("\n116\n");
	printf("precision:%.5d\n", nb);
	ft_printf("precision:%.5d\n", nb);
			
	printf("\n117\n");
	printf("space + prec:% .5d\n", nb);
	ft_printf("space + prec:% .5d\n", nb);
			
	printf("\n118\n");
	printf("Plus + prec / grande:%+.5d\n", nb);
	ft_printf("Plus + prec / grande:%+.5d\n", nb);
			
	printf("\n119\n");
	printf("Plus + prec / petite:%+.0d\n", nb);
	ft_printf("Plus + prec / petite:%+.0d\n", nb);
			
	printf("\n120\n");
	printf("Prec + 0:%0.5d\n", nb);
	ft_printf("Prec + 0:%0.5d\n", nb);
			
	printf("\n121\n");
	printf("Prec + minus:%-.5d\n", nb);
	ft_printf("Prec + minus:%-.5d\n", nb);
			
	printf("\n122\n");
	printf("size:%5d\n", nb);
	ft_printf("size:%5d\n", nb);
			
	printf("\n123\n");
	printf("size + space:% 5d\n", nb);
	ft_printf("size + space:% 5d\n", nb);
			
	printf("\n124\n");
	printf("size + plus:%+5d\n", nb);
	ft_printf("size + plus:%+5d\n", nb);
			
	printf("\n125\n");
	printf("size + minus:%-5d\n", nb);
	ft_printf("size + minus:%-5d\n", nb);
			
	printf("\n126\n");
	printf("size + 0:%05d\n", nb);
	ft_printf("size + 0:%05d\n", nb);
			
	printf("\n127\n");
	printf("size + 0 + plus:%+05d\n", nb);
	ft_printf("size + 0 + plus:%+05d\n", nb);
			
	printf("\n128\n");
	printf("size + 0 + plus:%0+5d\n", nb);
	ft_printf("size + 0 + plus:%0+5d\n", nb);
			
	printf("\n129\n");
	printf("size + 0 + prec:%05.3d\n", nb);
	ft_printf("size + 0 + prec:%05.3d\n", nb);
			
	printf("\n130\n");
	printf("size + minus + prec:%-5.3d\n", nb);
	ft_printf("size + minus + prec:%-5.3d\n", nb);
			
	printf("\n131\n");
	printf("size + plus + 0 + prec:%+05.3d\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3d\n", nb);
			
	printf("\n132\n");
	printf("size + espace + zero + prec:%0 5.3d\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3d\n", nb);
			
	printf("\n133\n");
	printf("size + espace + zero + prec:% 05.3d\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3d\n", nb);
			
	printf("\n134\n");
	printf("size + minus + plus + prec:%-+5.3d\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3d\n", nb);

	nb = 12;

	printf("\n135\n");
	printf("%x\n", nb);
	ft_printf("%x\n", nb);
	
	printf("\n136\n");
	printf("test X:%X\n", nb);
	ft_printf("test X:%X\n", nb);
	
	printf("\n137\n");
	printf("Hash:%#X\n", nb);
	ft_printf("Hash:%#X\n", nb);
	
	printf("\n138\n");
	printf("prec / grande:%.5X\n", nb);
	ft_printf("prec / grande:%.5X\n", nb);
	
	printf("\n139\n");
	printf("prec / petite:%.0X\n", nb);
	ft_printf("prec / petite:%.0X\n", nb);
	
	printf("\n140\n");
	ft_printf("hash + prec / grande:%#.5X\n", nb);
	ft_printf("hash + prec / grande:%#.5X\n", nb);
	
	printf("\n141\n");
	printf("hash + prec / petite:%#.1X\n", nb);
	ft_printf("hash + prec / petite:%#.1X\n", nb);
	
	printf("\n142\n");
	printf("prec + 0: %0.5X\n", nb);
	ft_printf("prec + 0: %0.5X\n", nb);
	
	printf("\n143\n");
	printf("Prec + minus:%-.5X\n", nb);
	ft_printf("Prec + minus:%-.5X\n", nb);
	
	printf("\n144\n");
	printf("size:%5X\n", nb);
	ft_printf("size:%5X\n", nb);
	
	printf("\n145\n");
	printf("size + prec:%7.3X\n", nb);
	ft_printf("size + prec:%7.3X\n", nb);
	
	printf("\n146\n");
	printf("size + mminus:%-5X\n", nb);
	ft_printf("size + mminus:%-5X\n", nb);
	
	printf("\n147\n");
	printf("size + 0:%05X\n", nb);
	ft_printf("size + 0:%05X\n", nb);
	
	printf("\n148\n");
	printf("size + 0 + hash:%#05X\n", nb);
	ft_printf("size + 0 + hash:%#05X\n", nb);
	
	printf("\n149\n");
	printf("size + 0 + prec:%05.3X\n", nb);
	ft_printf("size + 0 + prec:%05.3X\n", nb);
	
	printf("\n150\n");
	printf("size + minus + prec:%-5.3X\n", nb);
	ft_printf("size + minus + prec:%-5.3X\n", nb);
	
	printf("\n151\n");
	printf("size + hash + 0 + prec:%#05.3X\n", nb);
	ft_printf("size + hash + 0 + prec:%#05.3X\n", nb);
	
	printf("\n152\n");
	printf("size + hash + 0 + prec:%0#5.3X\n", nb);
	ft_printf("size + hash + 0 + prec:%0#5.3X\n", nb);
	
	printf("\n153\n");
	printf("size + hash + minus + prec:%-#7.3X\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3X\n", nb);

	nb = 45;
		
	printf("\n154\n");
	printf("precision:%.5u\n", nb);
	ft_printf("precision:%.5u\n", nb);
		
	printf("\n155\n");
	printf("Prec + 0:%0.5u\n", nb);
	ft_printf("Prec + 0:%0.5u\n", nb);
		
	printf("\n156\n");
	printf("Prec + minus:%-.5u\n", nb);
	ft_printf("Prec + minus:%-.5u\n", nb);
		
	printf("\n157\n");
	printf("size:%5u\n", nb);
	ft_printf("size:%5u\n", nb);
		
	printf("\n158\n");
	printf("size + minus:%-5u\n", nb);
	ft_printf("size + minus:%-5u\n", nb);
		
	printf("\n159\n");
	printf("size + 0:%05u\n", nb);
	ft_printf("size + 0:%05u\n", nb);
		
	printf("\n160\n");
	printf("size + 0 + prec:%05.3u\n", nb);
	ft_printf("size + 0 + prec:%05.3u\n", nb);
		
	printf("\n161\n");
	printf("size + minus + prec:%-5.3u\n", nb);
	ft_printf("size + minus + prec:%-5.3u\n", nb);
		
	printf("\n162\n");
	printf("%-5.3u\n", nb);
	ft_printf("%-5.3u\n", nb);
		
	printf("\n163\n");
	printf("%050.u\n", nb);
	ft_printf("%050.u\n", nb);
		
	printf("\n164\n");
	printf("%-1.45u\n", nb);
	ft_printf("%-1.45u\n", nb);
		
	printf("\n165\n");
	printf("%-55.35u\n", nb);
	ft_printf("%-55.35u\n", nb);

	printf("\n166\n");
	printf("%050.d\n", nb);
	ft_printf("%050.d\n", nb);

*/
	double		db;
	db = -12547.58;
	db = 0;
	db = 45.123456789;
//	db = 12389123798;
//	db = -0.000;

	
	printf("\n167\n");
	printf("space:% fa\n", db);
	ft_printf("space:% fa\n", db);
	
	printf("\n168\n");
	printf("plus:%+fa\n", db);
	ft_printf("plus:%+fa\n", db);
	
	printf("\n169\n");
	printf("hash:%#fa\n", db);
	ft_printf("hash:%#fa\n", db);
	
	printf("\n170\n");
	printf("precision:%.2fa\n", db);
	ft_printf("precision:%.2fa\n", db);
	
	printf("\n171\n");
	printf("big prec:%.14fa\n", db);
	ft_printf("big prec:%.14fa\n", db);
	
	printf("\n172\n");
	printf("precision + hash:%#.0fa\n", db);
	ft_printf("precision + hash:%#.0fa\n", db);
	
	printf("\n173\n");
	printf("space + prec:% .5fa\n", db);
	ft_printf("space + prec:% .5fa\n", db);
	
	printf("\n174\n");
	printf("space + prec + hash:%# .0fa\n", db);
	ft_printf("space + prec + hash:%# .0fa\n", db);
	
	printf("\n175\n");
	printf("space + prec + hash:% #.0fa\n", db);
	ft_printf("space + prec + hash:% #.0fa\n", db);
	
	printf("\n176\n");
	printf("Plus + prec / grande:%+.5fa\n", db);
	ft_printf("Plus + prec / grande:%+.5fa\n", db);
	
	printf("\n177\n");
	printf("Plus + prec / petite:%+.0fa\n", db);
	ft_printf("Plus + prec / petite:%+.0fa\n", db);
	
	printf("\n178\n");
	printf("Plus + prec + hash:%#+.0fa\n", db);
	ft_printf("Plus + prec + hash:%#+.0fa\n", db);
	
	printf("\n179\n");
	printf("Prec + 0:%0.5fa\n", db);
	ft_printf("Prec + 0:%0.5fa\n", db);
	
	printf("\n180\n");
	printf("Prec + minus:%-.5fa\n", db);
	ft_printf("Prec + minus:%-.5fa\n", db);
	
	printf("\n181\n");
	printf("size:%5fa\n", db);
	ft_printf("size:%5fa\n", db);
	
	printf("\n182\n");
	printf("size + space:% 5fa\n", db);
	ft_printf("size + space:% 5fa\n", db);
	
	printf("\n183\n");
	printf("size + plus:%+5fa\n", db);
	ft_printf("size + plus:%+5fa\n", db);
	
	printf("\n184\n");
	printf("size + space:%# 5fa\n", db);
	ft_printf("size + space:%# 5fa\n", db);
	
	printf("\n185\n");
	printf("size + plus:%#+5fa\n", db);
	ft_printf("size + plus:%#+5fa\n", db);
	
	printf("\n186\n");
	printf("size + minus:%-5fa\n", db);
	ft_printf("size + minus:%-5fa\n", db);
	
	printf("\n187\n");
	printf("size + 0:%05fa\n", db);
	ft_printf("size + 0:%05fa\n", db);
	
	printf("\n188\n");
	printf("size + 0 + plus:%+05fa\n", db);
	ft_printf("size + 0 + plus:%+05fa\n", db);
	
	printf("\n189\n");
	printf("size + 0 + plus:%0+5fa\n", db);
	ft_printf("size + 0 + plus:%0+5fa\n", db);
	
	printf("\n190\n");
	printf("size + 0 + prec:%05.3fa\n", db);
	ft_printf("size + 0 + prec:%05.3fa\n", db);
	
	printf("\n191\n");
	printf("size + 0 + prec + hash:%0#5.0fa\n", db);
	ft_printf("size + 0 + prec + hash:%0#5.0fa\n", db);
	
	printf("\n192\n");
	printf("size + minus + prec:%-5.3fa\n", db);
	ft_printf("size + minus + prec:%-5.3fa\n", db);
	
	printf("\n193\n");
	printf("size + minus + prec + hash:%-#5.0fa\n", db);
	ft_printf("size + minus + prec + hash:%-#5.0fa\n", db);
	
	printf("\n194\n");
	printf("size + plus + 0 + prec:%+05.3fa\n", db);
	ft_printf("size + plus + 0 + prec:%+05.3fa\n", db);
	
	printf("\n195\n");
	printf("size + plus + 0 + prec + hash:%0+#5.0fa\n", db);
	ft_printf("size + plus + 0 + prec + hash:%0+#5.0fa\n", db);
	
	printf("\n196\n");
	printf("size + espace + zero + prec:%0 5.3fa\n", db);
	ft_printf("size + espace + zero + prec:%0 5.3fa\n", db);
	
	printf("\n197\n");
	printf("size + espace + zero + prec:% 05.3fa\n", db);
	ft_printf("size + espace + zero + prec:% 05.3fa\n", db);
	
	printf("\n198\n");
	printf("size + espace + zero + prec:%0 5.3fa\n", db);
	ft_printf("size + espace + zero + prec:%0 5.3fa\n", db);
	
	printf("\n199\n");
	printf("size + espace + zero + prec + hash:%#0 5.0fa\n", db);
	ft_printf("size + espace + zero + prec + hash:%#0 5.0fa\n", db);
	
	printf("\n200\n");
	printf("size + minus + plus + prec:%-+5.3fa\n", db);
	ft_printf("size + minus + plus + prec:%-+5.3fa\n", db);
		
	printf("\n200\n");
	printf("ret : %d\n", printf("size + minus + plus + prec:%-+5.3fa\n", db));
	printf("ret : %d\n", ft_printf("size + minus + plus + prec:%-+5.3fa\n", db));

	printf("\n201\n");
	printf("size + minus + plus + prec + hash:%-#+5.0fa\n", db);
	ft_printf("size + minus + plus + prec + hash:%-#+5.0fa\n", db);
/*
	printf("\n202\n");
	printf("%hd\n", INT_MAX);
	ft_printf("%hd\n", INT_MAX);

	nb = 0;

	printf("\n203\n");
	printf("null prec : %+.0da\n", nb);
	ft_printf("null prec : %+.0da\n", nb);

	printf("\n203\n");
	printf("null prec : %+da\n", nb);
	ft_printf("null prec : %+da\n", nb);

	nb = 8;

	printf("\n204\n");
	printf("null prec : %+.0da\n", nb);
	ft_printf("null prec : %+.0da\n", nb);
	
	nb = -1234212;

	printf("\n205\n");
	printf("null prec : %+.0da\n", nb);
	ft_printf("null prec : %+.0da\n", nb);

	nb = 0;

	printf("\n206\n");
	printf("null prec : %.0da\n", nb);
	ft_printf("null prec : %.0da\n", nb);
	
	nb = 8;

	printf("\n207\n");
	printf("null prec : %.0da\n", nb);
	ft_printf("null prec : %.0da\n", nb);
	
	nb = -1234212;

	printf("\n208\n");
	printf("null prec : %.0da\n", nb);
	ft_printf("null prec : %.0da\n", nb);

	
	nb = 0;

	printf("\n209\n");
	printf("null prec : %+.0da\n", nb);
	ft_printf("null prec : %+.0da\n", nb);

	printf("\n210\n");
	printf("null prec : %+.da\n", nb);
	ft_printf("null prec : %+.da\n", nb);

	printf("\n211\n");
	printf("null prec : %.0da\n", nb);
	ft_printf("null prec : %.0da\n", nb);

	printf("\n212\n");
	printf("null prec : %012.0da\n", nb);
	ft_printf("null prec : %012.0da\n", nb);

	printf("\n213\n");
	printf("null prec : %-.0da\n", nb);
	ft_printf("null prec : %-.0da\n", nb);

	printf("\n214\n");
	printf("null prec : %-12.0da\n", nb);
	ft_printf("null prec : %-12.0da\n", nb);

	nb = 0;

	printf("\n214\n");
	printf("null prec : %.0ua\n", nb);
	ft_printf("null prec : %.0ua\n", nb);
	
	nb = 8;

	printf("\n215\n");
	printf("null prec : %.0ua\n", nb);
	ft_printf("null prec : %.0ua\n", nb);
	
	nb = -1234212;

	printf("\n216\n");
	printf("null prec : %.0ua\n", nb);
	ft_printf("null prec : %.0ua\n", nb);
	
	nb = -1;

	printf("\n217\n");
	printf("null prec : %.0ua\n", nb);
	ft_printf("null prec : %.0ua\n", nb);
	
	nb = 12354;

	printf("\n218\n");
	printf("null prec : %.0ua\n", nb);
	ft_printf("null prec : %.0ua\n", nb);


	printf("\n219\n");
	db = 0;
	printf("null prec : %+.0fa\n", db);
	printf("%d\n", printf("null prec : %+.0fa\n", db));
	ft_printf("null prec : %+.0fa\n", db);
	printf("%d\n", ft_printf("null prec : %+.0fa\n", db));


	printf("\n220\n");
	db = 12.5;
	printf("null prec : %+.0fa\n", db);
	ft_printf("null prec : %+.0fa\n", db);

	printf("\n221\n");
	db = -25632.2541;
	printf( "null prec : %+.0fa\n", db);
	ft_printf("null prec : %+.0fa\n", db);

	printf("\n222\n");
	db = -1.0123;
	printf("null prec : %+.0fa\n", db);
	ft_printf("null prec : %+.0fa\n", db);

	printf("\n223\n");
	db = 12354.569874;
	printf("null prec : %+.0fa\n", db);
	ft_printf("null prec : %+.0fa\n", db);

	printf("\nDELAAAAAAAAAa\n");
	nb = 0;

	printf("\n224\n");
	printf("null prec : %.0xa\n", nb);
	ft_printf("null prec : %.0xa\n", nb);

	printf("\n225\n");
	printf("null prec : %.xa\n", nb);
	ft_printf("null prec : %.xa\n", nb);

	printf("\n226\n");
	printf("null prec : %12.0xa\n", nb);
	ft_printf("null prec : %12.0xa\n", nb);

	printf("\n227\n");
	printf("null prec : %-5.xa\n", nb);
	ft_printf("null prec : %-5.xa\n", nb);


	printf("\n228\n");
	printf("null prec : %#.0xa\n", nb);
	ft_printf("null prec : %#.0xa\n", nb);

	printf("\n229\n");
	printf("null prec : %#.xa\n", nb);
	ft_printf("null prec : %#.xa\n", nb);

	printf("\n230\n");
	printf("null prec : %#12.0xa\n", nb);
	ft_printf("null prec : %#12.0xa\n", nb);

	printf("\n231\n");
	printf("null prec : %#-5.xa\n", nb);
	ft_printf("null prec : %#-5.xa\n", nb);

	nb = 0;

	printf("\n232\n");
	printf("null prec : %.0Xa\n", nb);
	ft_printf("null prec : %.0Xa\n", nb);

	printf("\n233\n");
	printf("null prec : %.Xa\n", nb);
	ft_printf("null prec : %.Xa\n", nb);

	printf("\n234\n");
	printf("null prec : %12.0Xa\n", nb);
	ft_printf("null prec : %12.0Xa\n", nb);

	printf("\n235\n");
	printf("null prec : %-5.Xa\n", nb);
	ft_printf( "null prec : %-5.Xa\n", nb);


	printf("\n236\n");
	printf("null prec : %#.0Xa\n", nb);
	ft_printf("null prec : %#.0Xa\n", nb);

	printf("\n237\n");
	printf("null prec : %#.Xa\n", nb);
	ft_printf("null prec : %#.Xa\n", nb);

	printf("\n238\n");
	printf("null prec : %#12.0Xa\n", nb);
	ft_printf("null prec : %#12.0Xa\n", nb);

	printf("\n239\n");
	printf("null prec : %#-5.Xa\n", nb);
	ft_printf("null prec : %#-5.Xa\n", nb);

	nb = 45;

	printf("\n240\n");
	printf("null prec : %.0oa\n", nb);
	ft_printf("null prec : %.0oa\n", nb);

	printf("\n241\n");
	printf("null prec : %.oa\n", nb);
	ft_printf("null prec : %.oa\n", nb);

	printf("\n242\n");
	printf("null prec : %12.0oa\n", nb);
	ft_printf("null prec : %12.0oa\n", nb);

	printf("\n243\n");
	printf("null prec : %-5.oa\n", nb);
	ft_printf( "null prec : %-5.oa\n", nb);


	printf("\n244\n");
	printf("null prec : %#.0oa\n", nb);
	ft_printf("null prec : %#.0oa\n", nb);

	printf("\n245\n");
	printf("null prec : %#.oa\n", nb);
	ft_printf("null prec : %#.oa\n", nb);

	printf("\n246\n");
	printf("null prec : %#12.0oa\n", nb);
	ft_printf("null prec : %#12.0oa\n", nb);

	printf("\n247\n");
	printf("null prec : %#-5.oa\n", nb);
	ft_printf("null prec : %#-5.oa\n", nb);

	nb = 21;

	printf("\n248\n");
	printf("null prec : %.0xa\n", nb);
	ft_printf("null prec : %.0xa\n", nb);

	printf("\n249\n");
	printf("null prec : %.xa\n", nb);
	ft_printf("null prec : %.xa\n", nb);

	printf("\n250\n");
	printf("null prec : %12.0xa\n", nb);
	ft_printf("null prec : %12.0xa\n", nb);

	printf("\n251\n");
	printf("null prec : %-5.xa\n", nb);
	ft_printf("null prec : %-5.xa\n", nb);

	nb = 21;

	printf("\n252\n");
	printf("null prec : %.0Xa\n", nb);
	ft_printf("null prec : %.0Xa\n", nb);

	printf("\n253\n");
	printf("null prec : %.Xa\n", nb);
	ft_printf("null prec : %.Xa\n", nb);

	printf("\n254\n");
	printf("null prec : %12.0Xa\n", nb);
	ft_printf("null prec : %12.0Xa\n", nb);

	printf("\n255\n");
	printf("null prec : %-5.Xa\n", nb);
	ft_printf( "null prec : %-5.Xa\n", nb);

	nb = 21;

	printf("\n256\n");
	printf("null prec : %.0oa\n", nb);
	ft_printf("null prec : %.0oa\n", nb);

	printf("\n257\n");
	printf("null prec : %.oa\n", nb);
	ft_printf("null prec : %.oa\n", nb);

	printf("\n258\n");
	printf("null prec : %12.0oa\n", nb);
	ft_printf("null prec : %12.0oa\n", nb);

	printf("\n259\n");
	printf("null prec : %-5.oa\n", nb);
	ft_printf( "null prec : %-5.oa\n", nb);

	nb = -543;

	printf("\n260\n");
	printf("null prec : %.0xa\n", nb);
	ft_printf("null prec : %.0xa\n", nb);

	printf("\n261\n");
	printf("null prec : %.xa\n", nb);
	ft_printf("null prec : %.xa\n", nb);

	printf("\n262\n");
	printf("null prec : %12.0xa\n", nb);
	ft_printf("null prec : %12.0xa\n", nb);

	printf("\n263\n");
	printf("null prec : %-5.xa\n", nb);
	ft_printf("null prec : %-5.xa\n", nb);

	nb = -543;

	printf("\n264\n");
	printf("null prec : %.0Xa\n", nb);
	ft_printf("null prec : %.0Xa\n", nb);

	printf("\n265\n");
	printf("null prec : %.Xa\n", nb);
	ft_printf("null prec : %.Xa\n", nb);

	printf("\n266\n");
	printf("null prec : %12.0Xa\n", nb);
	ft_printf("null prec : %12.0Xa\n", nb);

	printf("\n267\n");
	printf("null prec : %-5.Xa\n", nb);
	ft_printf( "null prec : %-5.Xa\n", nb);

	nb = -543;

	printf("\n268\n");
	printf("null prec : %.0oa\n", nb);
	ft_printf("null prec : %.0oa\n", nb);

	printf("\n269\n");
	printf("null prec : %.oa\n", nb);
	ft_printf("null prec : %.oa\n", nb);

	printf("\n270\n");
	printf("null prec : %12.0oa\n", nb);
	ft_printf("null prec : %12.0oa\n", nb);

	printf("\n271\n");
	printf("null prec : %-5.oa\n", nb);
	ft_printf( "null prec : %-5.oa\n", nb);

	printf("\nALLAAAAA\n");
	nb = 0;
	printf("\n272\n");
	printf("test o:%oa\n", nb);
	ft_printf("test o:%oa\n", nb);

	printf("\n273\n");
	printf("hash:%#oa\n", nb);
	ft_printf("hash:%#oa\n", nb);

	printf("\n274\n");
	printf("precision / grande:%.5oa\n", nb);
	ft_printf("precision / grande:%.5oa\n", nb);

	printf("\n275\n");
	printf("Prec + hash / grande:%#.5oa\n", nb);
	ft_printf("Prec + hash / grande:%#.5oa\n", nb);

	printf("\n276\n");
	printf("Prec + hash / petite:%#.1oa\n", nb);
	ft_printf("Prec + hash / petite:%#.1oa\n", nb);

	printf("\n277\n");
	printf("Prec + 0:%0.5oa\n", nb);
	ft_printf("Prec + 0:%0.5oa\n", nb);

	printf("\n278\n");
	printf("Prec + minus:%-.5oa\n", nb);
	ft_printf("Prec + minus:%-.5oa\n", nb);

	printf("\n279\n");
	printf("Size:%5oa\n", nb);
	ft_printf("Size:%5oa\n", nb);

	printf("\n280\n");
	printf("size + prec:%7.3oa\n", nb);
	ft_printf("size + prec:%7.3oa\n", nb);

	printf("\n281\n");
	printf("size + minus:%-5oa\n", nb);
	ft_printf("size + minus:%-5oa\n", nb);

	printf("\n282\n");
	printf("size + zero:%05oa\n", nb);
	ft_printf("size + zero:%05oa\n", nb);

	printf("\n283\n");
	printf("size + zero + hash:%#05oa\n", nb);
	ft_printf("size + zero + hash:%#05oa\n", nb);

	printf("\n284\n");
	printf("size + zero + prec:%05.3oa\n", nb);
	ft_printf("size + zero + prec:%05.3oa\n", nb);

	printf("\n285\n");
	printf("size + minus + prec:%-5.3oa\n", nb);
	ft_printf("size + minus + prec:%-5.3oa\n", nb);

	printf("\n286\n");
	printf("size + hash + zero + prec:%#05.3oa\n", nb);
	ft_printf("size + hash + zero + prec:%#05.3oa\n", nb);

	printf("\n287\n");
	printf("size + hash + zero + prec:%0#5.3oa\n", nb);
	ft_printf("size + hash + zero + prec:%0#5.3oa\n", nb);

	printf("\n288\n");
	printf("size + hash + minus + prec:%-#7.3oa\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3oa\n", nb);

	nb = 45;

	printf("\n289\n");
	printf("test o:%o\n", nb);
	ft_printf("test o:%o\n", nb);

	printf("\n290\n");
	printf("hash:%#o\n", nb);
	ft_printf("hash:%#o\n", nb);

	printf("\n291\n");
	printf("precision / grande:%.5o\n", nb);
	ft_printf("precision / grande:%.5o\n", nb);

	printf("\n292\n");
	printf("precision / petite:%.0o\n", nb);
	ft_printf("precision / petite:%.0o\n", nb);

	printf("\n293\n");
	printf("Prec + hash / grande:%#.5o\n", nb);
	ft_printf("Prec + hash / grande:%#.5o\n", nb);

	printf("\n294\n");
	printf("Prec + hash / petite:%#.1o\n", nb);
	ft_printf("Prec + hash / petite:%#.1o\n", nb);

	printf("\n295\n");
	printf("Prec + 0:%0.5o\n", nb);
	ft_printf("Prec + 0:%0.5o\n", nb);

	printf("\n296\n");
	printf("Prec + minus:%-.5o\n", nb);
	ft_printf("Prec + minus:%-.5o\n", nb);

	printf("\n297\n");
	printf("Size:%5o\n", nb);
	ft_printf("Size:%5o\n", nb);

	printf("\n298\n");
	printf("size + prec:%7.3o\n", nb);
	ft_printf("size + prec:%7.3o\n", nb);

	printf("\n299\n");
	printf("size + minus:%-5o\n", nb);
	ft_printf("size + minus:%-5o\n", nb);

	printf("\n300\n");
	printf("size + zero:%05o\n", nb);
	ft_printf("size + zero:%05o\n", nb);

	printf("\n301\n");
	printf("size + zero + hash:%#05o\n", nb);
	ft_printf("size + zero + hash:%#05o\n", nb);

	printf("\n302\n");
	printf("size + zero + prec:%05.3o\n", nb);
	ft_printf("size + zero + prec:%05.3o\n", nb);

	printf("\n303\n");
	printf("size + minus + prec:%-5.3o\n", nb);
	ft_printf("size + minus + prec:%-5.3o\n", nb);

	printf("\n304\n");
	printf("size + hash + zero + prec:%#05.3o\n", nb);
	ft_printf("size + hash + zero + prec:%#05.3o\n", nb);

	printf("\n305\n");
	printf("size + hash + zero + prec:%0#5.3o\n", nb);
	ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);

	printf("\n306\n");
	printf("size + hash + minus + prec:%-#7.3o\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3o\n", nb);

	db = -0.0;
	printf("\n307\n");
	printf("%f\n", db);
	ft_printf("%f\n", db);

	db = 0.0;
	printf("\n308\n");
	printf("%f\n", db);
	ft_printf("%f\n", db);

	db = -45.0;
	printf("\n309\n");
	printf("%f\n", db);
	ft_printf("%f\n", db);

	
	char c;
	
	c = '!';

	
	printf("\n310\n");
	printf( "%cb\n", c);
	ft_printf( "%cb\n", c);
	
	printf("\n311\n");
	printf( "%1cb\n", c);
	ft_printf( "%1cb\n", c);
	
	printf("\n312\n");
	printf( "%7cb\n", c);
	ft_printf( "%7cb\n", c);
	
	printf("\n313\n");
	printf( "%-1cb\n", c);
	ft_printf( "%-1cb\n", c);
	
	printf("\n314\n");
	printf( "%-5cb\n", c);
	ft_printf( "%-5cb\n", c);

	c = 'A';

	printf("\n315\n");
	printf("%cb\n", c);
	ft_printf("%cb\n", c);
	
	printf("\n316\n");
	printf("%12cb\n", c);
	ft_printf("%12cb\n", c);
	
	printf("\n317\n");
	printf("%-12cb\n", c);
	ft_printf("%-12cb\n", c);
	
	printf("\n318\n");
	printf("%-1cb\n", c);
	ft_printf("%-1cb\n", c);
	
	printf("\n319\n");
	printf("%1cb\n", c);
	ft_printf("%1cb\n", c);
	
	printf("\n320\n");
	printf("%5cb\n", c);
	ft_printf("%5cb\n", c);
	
	printf("\n321\n");
	printf("%-5cb\n", c);
	ft_printf("%-5cb\n", c);

	printf("\n322\n");
	printf("% cb\n", 0);
	ft_printf("% cb\n", 0);
	
	printf("\n323\n");
	printf("%+cb\n", 0);
	ft_printf("%+cb\n", 0);
	
	printf("\n324\n");
	printf("%cb\n", 0);
	ft_printf("%cb\n", 0);

	
	printf("\n325\n");
	printf("%cb\n", c);
	ft_printf("%cb\n", c);
	
	printf("\n326\n");
	printf("%0.12cb\n", c);
	ft_printf("%0.12cb\n", c);
	
	printf("\n327\n");
	printf("%0-10.5cb\n", c);
	ft_printf("%0-10cb\n", c);
	
	printf("\n328\n");
	printf("%1cb\n", c);
	ft_printf("%1cb\n", c);
	
	printf("\n329\n");
	printf("%.5cb\n", c);
	ft_printf("%.5cb\n", c);
	
	printf("\n330\n");
	printf("%-.5cb\n", c);
	ft_printf("%-.5cb\n", c);


	char	*s = "$dd!^&@printf BATARD";

	printf("\n331\n");
	printf("%sb\n", s);
	ft_printf("%sb\n", s);
	
	printf("\n332\n");
	printf("%030.12sb\n", s);
	ft_printf("%030.12sb\n", s);
	
	printf("\n333\n");
	printf("%7sb\n", s);
	ft_printf("%7sb\n", s);
	
	printf("\n334\n");
	printf("%-1sb\n", s);
	ft_printf("%-1sb\n", s);
	
	printf("\n335\n");
	printf("%-5sb\n", s);
	ft_printf("%-5sb\n", s);

	printf("\n336\n");
	printf("%sb\n", s);
	ft_printf("%sb\n", s);
	
	printf("\n337\n");
	printf("%12sb\n", s);
	ft_printf("%12sb\n", s);
	
	printf("\n338\n");
	printf("%-12sb\n", s);
	ft_printf("%-12sb\n", s);
	
	printf("\n339\n");
	printf("%-11sb\n", s);
	ft_printf("%-11sb\n", s);
	
	printf("\n340\n");
	printf("%11sb\n", s);
	ft_printf("%11sb\n", s);
	
	printf("\n341\n");
	printf("%5sb\n", s);
	ft_printf("%5sb\n", s);
	
	printf("\n342\n");
	printf("%-5sb\n", s);
	ft_printf("%-5sb\n", s);

	printf("\n343\n");
	printf("% sb\n", 0);
	ft_printf("% sb\n", 0);
	
	printf("\n344\n");
	printf("%+sb\n", 0);
	ft_printf("%+sb\n", 0);
	
	printf("\n345\n");
	printf("%010.3sb\n", 0);
	ft_printf("%010.3sb\n", 0);

	printf("\n346\n");
	printf("%sb\n", s);
	ft_printf("%sb\n", s);
	
	printf("\n347\n");
	printf("%0.12sb\n", s);
	ft_printf("%0.12sb\n", s);
	
	printf("\n348\n");
	printf("%0-10.5sb\n", s);
	ft_printf("%0-10.5sb\n", s);
	
	printf("\n349\n");
	printf("%1sb\n", s);
	ft_printf("%1sb\n", s);
	
	printf("\n350\n");
	printf("%.5sb\n", s);
	ft_printf("%.5sb\n", s);
	
	printf("\n351\n");
	printf("%-.1sb\n", s);
	ft_printf("%-.1sb\n", s);

	s = "Okalm";
//	s = "NULL";
	
	printf("\n352\n");
	printf("test basique:%sb\n", s);
	ft_printf("test basique:%sb\n", s);
	
	printf("\n353\n");
	printf("precision / zero:%.0sb\n", s);
	ft_printf("precision / zero:%.0sb\n", s);
	
	printf("\n354\n");
	printf("precision / petite:%.5sb\n", s);
	ft_printf("precision / petite:%.5sb\n", s);
	
	printf("\n355\n");
	printf("precision / grande:%.15sb\n", s);
	ft_printf("precision / grande:%.15sb\n", s);
	
	printf("\n356\n");
	printf("prec + minus:%-.5sb\n", s);
	ft_printf("prec + minus:%-.5sb\n", s);
	
	printf("\n357\n");
	printf("size / petite:%5sb\n", s);
	ft_printf("size / petite:%5sb\n", s);
	
	printf("\n358\n");
	printf("size / grande:%15sb\n", s);
	ft_printf("size / grande:%15sb\n", s);
	
	printf("\n359\n");
	printf("Minus + size / petite:%-5sb\n", s);
	ft_printf("Minus + size / petite:%-5sb\n", s);
	
	printf("\n360\n");
	printf("Minus + size / grande:%-015sb\n", s);
	ft_printf("Minus + size / grande:%-015sb\n", s);
	
	printf("\n361\n");
	printf("Minus + size + prec:%-015.5sb\n", s);
	ft_printf("Minus + size + prec:%-015.5sb\n", s);
	
	printf("\n362\n");
	printf("NULL:%12sb\n", NULL);
	ft_printf("NULL:%12sb\n", NULL);
	
	printf("\n363\n");
	printf("NULL:%1sb\n", NULL);
	ft_printf("NULL:%1sb\n", NULL);
	
	printf("\n364\n");
	printf("NULL:%-5.6sb\n", NULL);
	ft_printf("NULL:%-5.6sb\n", NULL);
	
	printf("\n365\n");
	printf("NULL:%-.8sb\n", NULL);
	ft_printf("NULL:%-.8sb\n", NULL);
	
	printf("\n366\n");
	printf("NULL:%.12sb\n", NULL);
	ft_printf("NULL:%.12sb\n", NULL);
	
	printf("\n367\n");
	printf("empty:%-.5sb\n", "");
	ft_printf("empty:%-.5sb\n", "");
	
	printf("\n368\n");
	printf("empty:%-1.32sb\n", "");
	ft_printf("empty:%-1.32sb\n", "");
	
	printf("\n369\n");
	printf("empty:%1.4sb\n", "");
	ft_printf("empty:%1.4sb\n", "");
	
	printf("\n370\n");
	printf("empty:%23sb\n", "");
	ft_printf("empty:%23sb\n", "");

	
	printf("\n371\n");
	printf("%d\n", printf("Okalmos : %c %f %d %x\n", 'A', 1235.123, 0, 56985));
	printf("%d\n", ft_printf("Okalmos : %c %f %d %x\n", 'A', 1235.123, 0, 56985));

	printf("\n372\n");
	printf("%d\n", printf("Okalmos : %12c %-5f %020d %#x\n", 'A', 1235.123, 0, 56985));
	printf("%d\n", ft_printf("Okalmos : %12c %-5f %020d %#x\n", 'A', 1235.123, 0, 56985));


	nb = 0;
	c = 'W';

	printf("\n373\n");
	printf("%5p b\n", &nb);
	ft_printf("%5p b\n", &nb);

	printf("\n374\n");
	printf("%-15p b\n", &nb);
	ft_printf("%-15p b\n", &nb);

	printf("\n375\n");
	printf("%-5p b\n", &nb);
	ft_printf("%-5p b\n", &nb);

	printf("\n376\n");
	printf("%042p b\n", &nb);
	ft_printf("%042p b\n", &nb);

	printf("\n377\n");
	printf("%-18p b\n", &nb);
	ft_printf("%-18p b\n", &nb);

	printf("\n378\n");
	printf("%42p b\n", &nb);
	ft_printf("%42p b\n", &nb);

	printf("\n379\n");
	printf("%5p b\n", &c);
	ft_printf("%5p b\n", &c);

	printf("\n380\n");
	printf("%-15p b\n", &c);
	ft_printf("%-15p b\n", &c);

	printf("\n381\n");
	printf("%-5p b\n", &c);
	ft_printf("%-5p b\n", &c);

	printf("\n382\n");
	printf("%42p b\n", &c);
	ft_printf("%42p b\n", &c);

	printf("\n383\n");
	printf("%-18p b\n", &c);
	ft_printf("%-18p b\n", &c);

	printf("\n384\n");
	printf("%42p b\n", &c);
	ft_printf("%42p b\n", &c);
*/

	printf("\n385\n");
	printf("%-#23hX|%-023hX|%#023hX|%-#023hX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	ft_printf("%-#23hX|%-023hX|%#023hX|%-#023hX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);

	printf("\n386\n");
	printf("%%|%%%%|%%%%%%|%%abc%%def%%ghi%%\n");
	printf("%d\n", printf("%%|%%%%|%%%%%%|%%abc%%def%%ghi%%\n"));
	ft_printf("%%|%%%%|%%%%%%|%%abc%%def%%ghi%%\n");
	printf("%d\n", ft_printf("%%|%%%%|%%%%%%|%%abc%%def%%ghi%%\n"));

	printf("\n387\n");
	printf("%-#23o|%-023o|%#023o|%-#023oa\n", 0U, 0U, 0U, 0U);
	ft_printf("%-#23o|%-023o|%#023o|%-#023oa\n", 0U, 0U, 0U, 0U);
	
	printf("\n388\n");
	printf("%-#23.5llo|%-023.5llo|%#023.5llo|%-#023.5llo\n", 0U, 0U, 0U, 0U);
	ft_printf("%-#23.5llo|%-023.5llo|%#023.5llo|%-#023.5llo\n", 0U, 0U, 0U, 0U);

	printf("\n389\n");
	printf("%23.5hho|%-23.5hho|%#23.5hho|%023.5hho\n", 0U, 0U, 0U, 0U);
	ft_printf("%23.5hho|%-23.5hho|%#23.5hho|%023.5hho\n", 0U, 0U, 0U, 0U);

	printf("\n390\n");
	printf("%d\n", printf("%-#23o|%-023o|%#023o|%-#023o\n", 0U, 0U, 0U, 0U));
	printf("%d\n", ft_printf("%-#23o|%-023o|%#023o|%-#023o\n", 0U, 0U, 0U, 0U));

	printf("\n391\n");
	printf("%1.o|%-1.o|%#1.o|%01.oa\n", 0U, 0U, 0U, 0U);
	ft_printf("%1.o|%-1.o|%#1.o|%01.oa\n", 0U, 0U, 0U, 0U);
	
	printf("\n392\n");
	printf("%-#1.o|%-01.o|%#01.o|%-#01.oa\n", 0U, 0U, 0U, 0U);
	ft_printf("%-#1.o|%-01.o|%#01.o|%-#01.oa\n", 0U, 0U, 0U, 0U);

	printf("\n393\n");
	printf("%-#23.o|%-023.o|%#023.o|%-#023.oa\n", 0U, 0U, 0U, 0U);
	ft_printf("%-#23.o|%-023.o|%#023.o|%-#023.oa\n", 0U, 0U, 0U, 0U);
	
	printf("\n394\n");
	printf("%-#23.5hho|%-023.5hho|%#023.5hho|%-#023.5hhoa\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	ft_printf("%-#23.5hho|%-023.5hho|%#023.5hho|%-#023.5hhoa\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);

	printf("\n394 bis\n");
	printf("%-#23.5ho|%-023.5ho|%#023.5ho|%-#023.5hoa\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	ft_printf("%-#23.5ho|%-023.5ho|%#023.5ho|%-#023.5hoa\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
/*
	printf("\n395\n");
	printf("%-#23o|%-023o|%#023o|%-#023oa\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	ft_printf("%-#23o|%-023o|%#023o|%-#023oa\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	
	printf("\n396\n");
	printf("%ho|%-ho|%#ho|%0hoa\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	ft_printf("%ho|%-ho|%#ho|%0hoa\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	
	printf("\n397\n");
	printf("%-#23.X|%-023.X|%#023.X|%-#023.Xa\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	ft_printf("%-#23.X|%-023.X|%#023.X|%-#023.Xa\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
*/	
	printf("\n398\n");
	printf("%li|%-li|%+li|% li|%0lia\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	ft_printf("%li|%-li|%+li|% li|%0lia\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);

	printf("\n399\n");
	printf("%-+23.5hi|%- 23.5hi|%-023.5hi|%+ 23.5hi|%+023.5hi|% 023.5hi|%-+ 023.5hia\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	ft_printf("%-+23.5hi|%- 23.5hi|%-023.5hi|%+ 23.5hi|%+023.5hi|% 023.5hi|%-+ 023.5hia\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
	
	printf("\n400\n");
	ft_printf("%#b\n", 257);

	printf("\n401\n");
	ft_printf("%14b\n", -150);

	printf("\n402\n");
	ft_printf("%10.15b\n", -150);

	printf("\n403\n");
	ft_printf("%#14b\n", -150);

	printf("\n404\n");
	ft_printf("%#10.15b\n", -150);

	printf("\n405\n");
	ft_printf("%0b\n", -150);

	printf("\n406\n");
	ft_printf("%0#b\n", 150);

	printf("\n407\n");
	ft_printf("%10.5b\n", 150);

	printf("\n408\n");
	ft_printf("%-10.5b\n", -150);

	printf("\n409\n");
	printf("ret : %i\n", printf("%lld, %lld\n", LLONG_MIN + 1, LLONG_MIN));
	ft_printf("ret : %i\n", ft_printf("%lld, %lld\n", LLONG_MIN + 1, LLONG_MIN));

	printf("\n410\n");
	printf("%f|%-f|%+f|% f|%#f|%0f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);
	ft_printf("%f|%-f|%+f|% f|%#f|%0f\n", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.);

	printf("\n411\n");
	printf("%lf|%-lf|%+lf|% lf|%#lf|%0lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);
	ft_printf("%lf|%-lf|%+lf|% lf|%#lf|%0lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);

	printf("\n411\n");
//	printf("%.2147483649f|%2147483649f\n", 1.0, 1.0);
//	ft_printf("%.2147483649f|%2147483649f\n", 1.0, 1.0);

//	printf("\n412\n");
//	printf("%.1150f|%.1150f|%.1150f|%.1150f\n", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);
//	ft_printf("%.1150f|%.1150f|%.1150f|%.1150f\n", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037);
	
	printf("\n412\n");
	printf("%15.8lf|%-15.8lf|%+15.8lf|% 15.8lf|%#15.8lf|%015.8lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);
	ft_printf("%15.8lf|%-15.8lf|%+15.8lf|% 15.8lf|%#15.8lf|%015.8lf\n", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849);
	
	printf("\n413\n");
	printf("%Lf\n", LDBL_MAX);
	ft_printf("%Lf\n", LDBL_MAX);

	printf("\n414\n");
	printf("%f\n", -12547.58);
	ft_printf("%f\n", -12547.58);
/*
	printf("\n415\n");
	printf("%.f|%.f|%.f|%.f|%.f\n", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52);
	ft_printf("%.f|%.f|%.f|%.f|%.f\n", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52);
*/
	return (0);
}
