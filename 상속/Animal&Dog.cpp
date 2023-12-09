//--------------------------------------------------------------------------------
// Animal과 Dog클래스를 통해 상속에 대해 공부하기
//--------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Animal {
	int age{};
public:
	Animal() {
		cout << "Animal 기본생성" << '\n';
	}
	Animal(int n) : age{ n } {
		cout << "Animal 생성" << '\n';
	}
	~Animal() {
		cout << "Animal 소멸" << '\n';
	}

	void move() const {
		cout << age << "살 - 움직인다." << '\n';
	}
};

class Dog : public Animal {
	string name;
public:
	Dog() {
		cout << "Dog 기본생성" << '\n';
	}
	Dog(int n) : Animal{ n } {		// Animal의 age에 접근할 수 없기에 그냥 떠넘김
		cout << "Dog 생성" << '\n';
	}
	~Dog() {
		cout << "Dog 소멸" << '\n';
	}
};

int main() {
	//Dog dog{ 10 };

	//dog.move();			// Dog가 Animal을 상속받았기에 move를 쓸 수 있다.

	Animal a;
	Dog d;
	Animal* pa;
	Dog* pd;
	pa = &d;
	pd = static_cast<Dog*>(pa);
}

// 기본적으로 업 캐스팅은 된다. Dog d, Animal a  a=d 처럼 
// d에는 a의 정보가 있기에 가능하다.
// 하지만 다운캐스팅 d = a는 불가능 하다. 
// a에는 d에 대한 내용이 없기에
// 하지만 포인터를 사용한다면 다운 캐스팅이 되도록 할 수 있지만 별로 추천하지는 않는다.
// Animal* pa, Dog* pd를 통해 pa = &d , pd = pa로 한다면 될 수도 있다.
// 이렇게 한다면 pa는 Dog를 가리키고 있기에 어느정도 가능은 하지만 이렇게만 쓸 경우 오류가 발생한다.