/*
 * TopologicalSort.cpp
 *
 *  Created on: Oct 26, 2014
 *      Author: Arpit Bhayani
 */

#include <map>
#include <cmath>
#include <set>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;

#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define pi(x) printf("%d\n" , x)
#define pl(x) printf("%ld\n" , x)
#define pll(x) printf("%lld\n" , x)
#define pc(x) printf("%c\n" , x)
#define ps(x) printf("%s\n" , x)

#define fup(i,a,b) for(int i=a;i<b;i++)
#define fdn(i,a,b) for(int i=a;i>=b;i--)

#define DEBUG 0
#define gc getchar
#define ll long long

#define SEPERATOR " : "

#define trace1(a) cout << #a << SEPERATOR << a << endl;
#define trace2(a,b) cout << #a << SEPERATOR << a << SEPERATOR << #b << SEPERATOR << b << endl;
#define trace3(a,b,c) cout << #a << SEPERATOR << a << SEPERATOR << #b << SEPERATOR << b << #c << SEPERATOR << c << endl;

void scanint(ll int &x) {
	register ll int c = gc();
	x = 0;
	for (; (c < 48 || c > 57); c = gc())
		;
	for (; c > 47 && c < 58; c = gc()) {
		x = (x << 1) + (x << 3) + c - 48;
	}
}

int readline(char * str) {

	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

#define ASIZE 10

list<int> nodes[6];
int visited[100];
stack<int> s;

void topo_sort(int start) {

	if (visited[start] == 1) {
		return;
	}

	visited[start] = 1;

	for (list<int>::iterator itr = nodes[start].begin();
			itr != nodes[start].end(); itr++) {
		if (visited[*itr] == 0) {
			topo_sort(*itr);
		}
	}
	s.push(start);
}

int main(int argc, char * argv[]) {

	list<int> nodes[6];

	nodes[5].push_back(2);
	nodes[5].push_back(0);
	nodes[4].push_back(0);
	nodes[4].push_back(1);
	nodes[2].push_back(3);
	nodes[3].push_back(1);

	for (int i = 0; i < 6; i++) {
		if (visited[i] == 0) {
			topo_sort(i);
		}
	}

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}
