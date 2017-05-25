#include <iostream>

class Box{
private : 
	int l, b, h;

public :
	Box() : l(0), b(0), h(0) {}
	Box(int length, int breadth, int height) : l(length), b(breadth), h(height) {}
	Box( Box const &box) : l(box.l), b(box.b), h(box.h) {}

	int getLength() const;
	int getBreadth() const;
	int getHeight() const;
	long long CalculateVolume();
};

int Box::getLength() const {
	return l;
}
int Box::getBreadth() const {
	return b;
}
int Box::getHeight() const {
	return h;
}
long long Box::CalculateVolume(){
	return ((long)l)*((long)b)*((long)h);
}
bool operator<(const Box &A, const Box &B){
	if(	A.getLength()<B.getLength()
		|| (A.getLength()==B.getLength() && A.getBreadth()<B.getBreadth()) 
		|| (A.getLength()==B.getLength() && A.getBreadth()==B.getBreadth() && A.getHeight()<B.getHeight())) return true;
	else return false;
}
std::ostream& operator<<(std::ostream &cout, const Box &B){
	return cout << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
}