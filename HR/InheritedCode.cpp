#include <exception>
#include <string>
#include <iostream>

class BadLengthException : public std::exception{
    private :
        std::string m_len;
    public :
		BadLengthException(int len) {m_len = std::to_string(len);}
        virtual const char* what() const throw()
        {
			return m_len.c_str();
        }
};

/*
int main(){
	try{
		throw BadLengthException(4);
	}
	catch(BadLengthException e){
		std::cout << e.what();
		int i;
		std::cin>>i;
	}
	
	return 0;
}
*/