#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue<int> kk) {
	queue<int> sp = kk;
	cout << "Kuyruk yazdiriliyor... FRONT ";
	while (!sp.empty()) {
		cout << sp.front() << " ";
		sp.pop();
	}
	cout << "BACK\n";
}

template<typename T>
void cut(queue<T>& q, int n, const T& item) {
	queue<T> stc;
	int x = 1;

	if (n == q.size() + 1) {
		while (!q.empty()) {
			stc.push(q.front());
			q.pop();
		}
		stc.push(item);
	}
	else {
		while (!q.empty()) {
			if (x == n) {
				stc.push(item);
			}
			else
			{
				stc.push(q.front());
				q.pop();
			}
			x++;
		}
	}
	q = stc;
}

int main()
{
	queue<int> que;
	int xd, al;


	cout << "Kuyruga kac eleman eklemek istiyorusunuz: "; cin >> xd; cout << xd << " tamsayi deger giriniz...";
	for (int i = 0; i < xd; i++) {
		cin >> al;
		que.push(al);
	}

	cout << "Kuyrugun ilk hali :\n";
	printQueue(que);

	cout << "Kuyrugun neresine yeni degeri eklemek istersiniz : "; cin >> xd;
	while (xd<1 || xd>que.size() + 1) {
		if (xd < 1)
			cout << "Cok kucuk deger girdiniz. Daha buyuk deger giriniz: ";
		else if (xd > que.size() + 1)
			cout << "Cok buyuk deger girdiniz. Daha kucuk deger giriniz: ";
		cin >> xd;
	}
	cout << "Eklemek istediginiz degeri giriniz: ";
	cin >> al;

	cut(que, xd, al);
	printQueue(que);
}
