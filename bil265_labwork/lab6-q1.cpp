#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

void printStack(stack<int> kk) {
	while (!kk.empty()) {
		cout << kk.top() << " ";
		kk.pop();
	}
}

template <typename T>
T second(const stack<T>& s) {
	/*if (s.size() < 2) {
		throw std::underflow_error(0);
	}*/
	stack<T> scry = s;
	scry.pop();
	return scry.top();
}

template <typename T>
void n2top(stack<T>& s, int n) {
	int sa;
	stack<T> scry, sp;

	while (n > s.size()) {
		cout << ("\nYigitin bu elemani yok. Daha kucuk deger giriniz :");
		cin >> sa;
		n = sa;
	}

	for (int i = 0; i < n; i++) {
		scry.push(s.top());
		s.pop();
	}
	sp.push(scry.top());
	scry.pop();
	while (!scry.empty()) {
		s.push(scry.top());
		scry.pop();
	}
	s.push(sp.top());
}

int main()
{
	stack<int> stc;
	int tp, xd;

	cout << "Yigita kac eleman eklemek istiyorsunuz: ";
	cin >> tp;
	for (int i = 0; i < tp; i++) {
		cin >> xd;
		stc.push(xd);
	}

	cout << "Yigit yazdiriliyor... TOP "; printStack(stc); cout << "BOTTOM" << endl;

	try { cout << "Yigitin ustten 2. elemani : " << second(stc) << endl; }
	catch (underflow_error ufe) {
		cout << "exception caught.";
	}
	
	cout << "Yigitin kacinci elemanini uste almak istersiniz: "; cin >> xd;
	n2top(stc, xd);
	
	cout << "Yigit yazdiriliyor... TOP "; printStack(stc); cout << "BOTTOM" << endl;

}
