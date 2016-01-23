#include<iostream>
using namespace std;
static const char c[4] = {'|', '/', '-', '\\'};
//void delay(int n) { for(volatile int i = 0; i < n; i++); }
void delay(int n) { for(int i = 0; i < n; i++); }
int main() {
	int p = 0;
	while(1) {
		cout << c[p];
		cout.flush();
		delay(1 << 28);
		p = (p + 1) % 4;
		//cout << '\b';
	}
	return 0;
}
//http://stackoverflow.com/questions/4437527/why-do-we-use-volatile-keyword-in-c
