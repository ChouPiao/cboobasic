#include <memory>
#include <string>
#include <iostream>
#include <map>

class Book
{
public:
	Book(int nId)
	{
		m_nId = nId;
		std::cout<<"Create Book"<<m_nId<<std::endl;
	}
	
	~Book()
	{
		std::cout<<"Destroy Book"<<m_nId<<std::endl;
	}

	int m_nId;
};

#define SHOW_FUNC_ENTER std::cout<<"---"<<__FUNCTION__<<" Enter---\n";
#define SHOW_FUNC_RETURN std::cout<<"---"<<__FUNCTION__<<" Return---\n\n";

void VerifySharedPtr()
{
	SHOW_FUNC_ENTER;

	std::shared_ptr<Book> p(nullptr);
	//p->nId = "Crash"; //"Access nullptr shared_ptr throw exception";
	if (p == nullptr && p == NULL)
	{
		std::cout<<"shared_ptr also can be nullptr and NULL\n";
	}
	
	SHOW_FUNC_RETURN;
	return;
}

void VerifyMap()
{
	SHOW_FUNC_ENTER;
	
	std::cout<<"Ready to create map"<<std::endl;
	auto pMap = new std::map<int, std::shared_ptr<Book>>;
	std::cout<<"Ready to add book0 to map"<<std::endl;
	(*pMap)[0] = std::shared_ptr<Book>(new Book(0));
	std::cout<<"Ready to add book1 to map"<<std::endl;
	(*pMap)[1] = std::shared_ptr<Book>(new Book(1));
	std::cout<<"Ready to add book2 to map"<<std::endl;
	(*pMap)[2] = std::shared_ptr<Book>(new Book(2));
	
	std::cout<<"Erase and not accept iterator will destroy shared_ptr\n";
	std::cout<<"Ready to erase book0 and not accept iterator\n";
	pMap->erase(0);
	
	std::cout<<"Erase and accept iterator will not destroy shared_ptr\n";
	std::cout<<"Ready to erase book1 and accept iterator\n";
	auto itBook1 = (*pMap)[1];
	pMap->erase(1);
	
	std::cout<<"Ready to destroy map\n";
	delete pMap;
	std::cout<<__FUNCTION__<<" return\n";
	
	SHOW_FUNC_RETURN;
	return;
}

int main()
{
	VerifySharedPtr();
	VerifyMap();
		

	return 0;
}

