//--------------------------------------------------------------------------------
// 다형성을 통해 문제를 해결해보자.
//--------------------------------------------------------------------------------
#include <iostream>
#include <random>
using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ 1,6 };

class Animal {
public:
	virtual void move() const {			// 다형성을 구현하기 위해선 virtual을 사용해줘야 한다.
		cout << "동물 - 움직인다." << '\n';
	}
};
class Dog : public Animal {
public:
	void move() const override {
		cout << "개 - 달린다." << '\n';
	}
};

class Bird : public Animal {
public:
	void move() const override {
		cout << "새 - 난다." << '\n';
	}
};

// [문제 1] 동물 10마리를 관리하는 코드를 작성한다.
// 주사위를 던져 홀수이면 Dog를 만들고 짝수이면 Bird를 만들어라.
// 모든 동물의 move를 호출하여 다형성이 구현됨을 확인하라.

//int main()
//{
//	Animal* animals[10];			// 포인터로 만들어야 각각이 다른 객체를 가리키도록 할 수 있음
//	for (Animal*& as : animals) {		// animals는 Animal* 이니까 *&를 써줘야 됨
//		if (uid(dre) % 2)			// 홀수일땐 new를 사용해 Dog만큼의 메모리를 할당해줌
//			as = new Dog;
//		else as = new Bird;			// 짝수일땐 Bird만큼의 메모리를 할당해 준다.
//	}
//
//	for (Animal*& as : animals)		// 전제를 move호출 시켜주면 virtual에 의해 Dog와 Bird의 move가 실행된다.
//		as->move();
//
//	for (Animal*& as : animals)
//		delete as;				// new로 동적할당을 했으니 꼭 delete로 지워줘야 한다. 
//}

// [문제 2] 동물 여러 마리를 관리하는 코드를 작성한다.
// 몇 마리인지는 사용자 입력에 따른다.		
// 주사위를 던져 홀수이면 Dog를 만들고 짝수이면 Bird를 만들어라.
// 모든 동물의 move를 호출하여 다형성이 구현됨을 확인하라.


int main()
{
	int num;
	
	cout << "관리할 동물의 수 - ";
	cin >> num;

	Animal** animals = new Animal*[num];			// 우리는 사용자가 입력한 수 만큼 Animal*를 만들어 줘야 한다.
													// 이때 Animal*를 배열로 만들었으니 이 메모리를 가리키는 
													// 이름의 타입은 Animal**여야 한다.

	for (int i = 0; i < num; ++i) {
		if (uid(dre) % 2)
			animals[i] = new Dog;
		else animals[i] = new Bird;
	}

	for (int i = 0; i < num; ++i) {
		animals[i]->move();
	}
	for (int i = 0; i < num; ++i)
		delete animals[i];		// 여기에서 사라지는건 Dog와 Bird의 메모리
	delete[] animals;			// 처음 할당한 Animal*[]의 메모리
}
// 사용해준 new의 종류에 맞게 delete를 해줘야 한다.