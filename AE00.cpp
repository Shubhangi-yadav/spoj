#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main( int argc , char * argv[] ) {

	int a,d;
	long int count = 0;
	float b,c;

	cin >> a;
	b=a;

	c=sqrt(b);
	d=c;

	for( int i=1 ; i <= d ; i++ ) {
		printf("%d/%d - %d-%i\n" , a,i,d,i);
		count = count + ( (a/i) - (d-i) );
	}
	
	cout << count << endl;
	return 0;
}
