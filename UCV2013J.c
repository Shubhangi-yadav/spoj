#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int main ( int argc , char * argv[] ) {

	while ( 1 ) {
		int n;
		scanf("%d" , &n);

		if ( n == 0 )
			break;

		int m = n / 2;
		int i = 0;
		int sum = 0;

		for ( i = 0 ; i < n ; i++ ) {
			int x;
			scanf("%d" , &x);
			if ( m == 0 ) {
				sum += x;
			}
			else {
				m--;
			}
		}

		printf("%d\n" , sum);

	}


	return 0;
}
