#include <iostream>
#include <cpr/cpr.h>

using namespace cpr;

int main() {
	/*std::string name, city;
	std::cout << "Input name and city: ";
	std::cin >> name >> city;
	Response r = Post(Url("https://httpbin.org/post"),
		cpr::Payload({ {"name",name}, {"city",city} }));
	std::cout << r.text << std::endl;*/

	std::string command;
	std::cout << "Input command (get, post, put, delete, patch): ";
	std::cin >> command;

	while (command != "exit")
	{
		if (command == "get")
		{
			Response r = Get(Url("https://www.httpbin.org/get")
				, Header({ {"User-agent","Mozilla / 5.0 (Windows NT 10.0; Win64; x64) AppleWebKit / 537.36 (KHTML, like Gecko) Chrome / 114.0.0.0 Safari / 537.36 OPR / 100.0.0.0"},
					{"Accept","text/html"}}));
			std::cout << r.text << std::endl;
		}
		if (command == "post")
		{
			std::string name, city;
			std::cout << "Input name and city: ";
			std::cin >> name >> city;
			Response r = Post(Url("https://www.httpbin.org/post"),
				Payload({ {"name", name},{"city",city}}));
			std::cout << r.text << std::endl;
		}
		if (command == "put")
		{
			Response r = Put(Url("https://www.httpbin.org/put"));
			std::cout << r.text << std::endl;
		}
		if (command == "patch")
		{
			Response r = Put(Url("https://www.httpbin.org/patch"));
			std::cout << r.text << std::endl;
		}
		if (command == "delete")
		{
			Response r = Put(Url("https://www.httpbin.org/delete"));
			std::cout << r.text << std::endl;
		}
		
		std::cout << "Input command (get, post, put, delete, patch): ";
		std::cin >> command;
	}
}
