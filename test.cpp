#include <iostream>
#include <typeinfo>

class Derived;
class Base {
public:
	Base();
	virtual ~Base() noexcept = default;
	void call(){
		std::cout << "call: " << typeid(*this).name() << std::endl;
	}
};

class Derived : public Base {
public:
	Derived()
	:Base()
	{
	}
	virtual ~Derived() noexcept = default;
};

Base::Base()
{
	std::cout << typeid(*static_cast<Derived*>(this)).name() << std::endl;
}

int main(int argc, char** argv){
	Derived d;
	std::cout << typeid(d).name() << std::endl;
	d.call();
	return 0;
}
