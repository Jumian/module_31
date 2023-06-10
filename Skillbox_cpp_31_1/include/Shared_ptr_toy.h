#pragma once

#include <string>
#include <iostream>

class Toy {
	std::string name;
public:
	Toy(std::string _name) : name(_name) { name = _name; }
	std::string get_name() { return name; }
	~Toy() {
		std::cout << "Toy " << name << " is destroyed\n";
	}
	Toy(const Toy& oth) { name = oth.name;}
	Toy& operator=(const Toy& oth) { name = oth.name; }
};

class Shared_ptr_toy {
	Toy* obj;
	int* p_counter;
	void destroyObj() {
		if (obj!=nullptr) {
			delete obj;
			obj = nullptr;
		}
		if (p_counter != nullptr) {
			delete p_counter;
			p_counter = nullptr;
		}
	}
	void print_state() { std::cout  << "Shared_ptr " << this <<", obj = " <<obj << (obj ? " name=" + obj->get_name() : "") << " " << (p_counter ? *p_counter : 0) << "\n"; }
public:
	void print(){ std::cout << "shared ptr = " << this << " " << (get() ? get()->get_name() : "") << std::endl; }
	Toy* get() { return obj; }
	void reset() {
		if (p_counter) {
			if (*p_counter <= 0) {
				destroyObj();
				--* p_counter;
			}
			else {
				p_counter = nullptr;
				obj = nullptr;
			}
		}
	}
	Shared_ptr_toy(Toy _toy) {
		p_counter = nullptr;
		obj = nullptr;
		if (&_toy) {
			obj = new Toy(_toy);
			p_counter = new int(1);
		}
		else return;
	}
	Shared_ptr_toy() : Shared_ptr_toy(Toy("Some toy")) {
		
	}
	Shared_ptr_toy(const Shared_ptr_toy& oth) {
		if (&oth!=nullptr) {
			if (oth.obj && oth.p_counter) {
				obj = oth.obj;
				p_counter = oth.p_counter;
				++* p_counter;
			}
			else { std::cout << this << " Shared pointer reseted\n"; }
		} else {  std::cout << this << " Shared pointer not inited\n";  }
	}
	Shared_ptr_toy& operator=(const Shared_ptr_toy& oth) {
		if (this == &oth) return *this;
		else if (&oth) {
			if (oth.obj && oth.p_counter) {
				if (obj != nullptr) delete obj;
				obj = oth.obj;
				p_counter = oth.p_counter;
			}
			++* p_counter;
			return *this;
		}
		else if (&oth == nullptr) {
			std::cout << "Right side is not initialized\n";
		}
	}
	static Shared_ptr_toy* make(std::string _name) { 
		return new Shared_ptr_toy(Toy(_name)); 
	}
	~Shared_ptr_toy() {
		reset();
	};
};