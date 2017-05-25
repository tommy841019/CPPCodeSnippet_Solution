#include <string>
#include <iostream>
#include <vector>

class Person{
public:
	std::string m_name;
	int m_age;

	virtual void getdata() = 0;
	virtual void putdata() const = 0;
};



class Professor : public Person{
public:
	int m_publications;
	int m_cur_id;
	static int s_cur_id;

	Professor();
	void getdata();
	void putdata() const;
};
int Professor::s_cur_id = 0;
Professor::Professor(){
	m_cur_id = ++s_cur_id;
}
void Professor::getdata(){
	std::cin >> m_name >> m_age >> m_publications;
}
void Professor::putdata() const{
	std::cout << m_name << " " << m_age << " " << m_publications << " " << m_cur_id << std::endl;
}



class Student : public Person{
public:
	std::vector<int> m_marks;
	int m_cur_id;
	static int s_cur_id;

	Student();
	void getdata();
	void putdata() const;
};
int Student::s_cur_id = 0;
Student::Student(){
	m_cur_id = ++s_cur_id;
}
void Student::getdata(){
	std::cin >> m_name >> m_age;
	for(int i=0; i<6; ++i){
		int mark;
		std::cin >> mark;
		m_marks.push_back(mark);
	}
}
void Student::putdata() const{
	int sum = 0;
	for(unsigned int i=0; i<m_marks.size(); ++i){
		sum += m_marks[i];
	}
	std::cout << m_name << " " << m_age << " " << sum << " " << m_cur_id << std::endl;
}


/*
int main(){

    int n, val;
    std::cin>>n; //The number of objects that is going to be created.
    Person *per[4];

    for(int i = 0;i < n;i++){

        std::cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
*/