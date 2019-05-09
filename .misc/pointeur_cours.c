#include <stdio.h>

int (*f[256])( int );


int toto( int salut){
	return 2;
}

int titi( int salut){
	return salut;
}

int main(){
	f['x'] = toto;
	f['w'] = titi;
	printf("%d %d\n", f['x'](3), f['x'](3));
	printf("%d %d\n", f['w'](3), f['w'](3));
}
