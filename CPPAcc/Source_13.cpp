#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Core {

	friend class Student_info;  // make protected members available

public :
	Core() :midterm(0), final(0) {}
	Core(std::istream& is) { read(is); }
	virtual ~Core() {}  // for clean up objects based on class
	
	std::string name() const;
	// virtual functions must be defined
	virtual double grade() const;  // virtual: can only be used inside class definition, tell runtime to execute function based on object class
	virtual std::istream& read(std::istream&);
protected:
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;
	virtual Core* clone() const { return new Core(*this); }  // handle polymorphism copy
private:
	std::string n;
};


std::string Core::name() const {
	return n;
}


double Core::grade() const {
	return 100.0;
}


std::istream& Core::read_common(std::istream& in) {
	in >> n >> midterm >> final;
	return in;
}


std::istream& Core::read(std::istream& in) {
	read_common(in);
	//read_hw(in, homework);
	return in;
}


class Grad : public Core {

public:
	Grad() :thesis(0) {}
	Grad(std::istream& is) { read(is); }
	double grade() const;
	std::istream& read(std::istream&);
protected:
	Grad* clone() const { return new Grad(*this); }
private:
	double thesis;
};


std::istream& Grad::read(std::istream& in) {
	read_common(in);
	in >> thesis;
	//read_hw(in, homework);
	return in;
}


double Grad::grade() const {
	return std::min(Core::grade(), thesis);
}


// dynamic binding only works on reference or pointer
bool student_compare(Core& s1, Core& s2) {  // bind at run time
	return s1.grade() < s2.grade();
}


// static binding 
bool student_compare(Core s1, Core s2) {  // bind at compile time
	return s1.grade() < s2.grade();
}



class Student_info {

public:
	Student_info() : cp(0) {}
	Student_info(std::istream& is) : cp(0) { read(is); }
	Student_info(const Student_info&);
	Student_info& operator=(const Student_info&);
	~Student_info() { delete cp; }

	std::istream& read(std::istream&);

	std::string name() const {
		if (cp) return cp->name();
		else throw std::runtime_error("uninitialized");
	}

	double grade() const {
		if (cp) return cp->grade();
		else throw std::runtime_error("uninitialized");
	}

	static bool compare(const Student_info& s1, const Student_info& s2) {  // define as static function to keep it within Student_info scope
		return s1.name() < s2.name();
	}

private:
	Core* cp;
};


std::istream& Student_info::read(std::istream& is) {
	delete cp;

	char ch;
	is >> ch;

	if (ch == 'U')
		cp = new Core(is);
	else
		cp = new Grad(is);

	return is;
}


Student_info::Student_info(const Student_info& s) : cp(0) {
	if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s) {
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}

	return *this;
}