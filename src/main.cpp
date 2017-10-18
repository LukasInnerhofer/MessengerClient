#include "main.h"

int main(int argc, char *argv[])
{
	const std::vector<std::string> availableMethods = { "GET", "POST", "PUT", "DELETE" };
	std::string requestedMethod = "";
	
	try
	{
		if(argc == 1)
		{
			std::cout << "Pick an HTTP method [";
			for(std::string method : availableMethods) { std::cout << " " << method << " "; }
			std::cout << "] ";
			std::cin >> requestedMethod;
			if(vectorContains(availableMethods, requestedMethod))
			{
				std::string errorMessage = "Invalid HTTP method. Available methods are: ";
				for(std::string method : availableMethods)
				{
					errorMessage += " " + method + " ";
				}
				throw std::invalid_argument(errorMessage);
			}
		}
		else if(argc == 2)
		{
			requestedMethod = std::string(argv[1]);
			if(vectorContains(availableMethods, requestedMethod))
			{
				std::string errorMessage = "Invalid HTTP method. Available methods are: ";
				for(std::string method : availableMethods)
				{
					errorMessage += " " + method + " ";
				}
				throw std::invalid_argument(errorMessage);
			}
		}
		else
		{
			throw std::invalid_argument("Usage:\n" + std::string(argv[0]) + "\n" + std::string(argv[0]) + " <HTTP method>\n");
		}
	}
	catch(const std::invalid_argument &e)
	{
		std::cout << "Invalid argument: " << e.what() << std::endl;
		return -1;
	}
	
	std::cin.get();
	
	return 0;
}

template<typename T>
bool vectorContains(const std::vector<T> vector, const T element)
{
	return std::find(vector.begin(), vector.end(), element) == vector.end();
}