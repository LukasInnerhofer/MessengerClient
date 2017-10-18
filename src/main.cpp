#include "main.h"

int main(int argc, char *argv[])
{
	const std::vector<std::string> availableMethods = { "GET", "POST", "PUT", "DELETE" };
	std::string requestedMethod = "", url = "", data = "";
	
	try
	{
		switch(argc)
		{
		case 1:
			std::cout << "Pick an HTTP method [";
			for(std::string method : availableMethods) { std::cout << " " << method << " "; }
			std::cout << "] ";
			std::cin >> requestedMethod;
			validateRequestedMethod(availableMethods, requestedMethod);
			std::cout << "\nURL: ";
			std::cin >> url;
			std::cout << "\nData: ";
			std::cin >> data;
			break;

		case 3:
			requestedMethod = std::string(argv[1]);
			validateRequestedMethod(availableMethods, requestedMethod);
			url = std::string(argv[2]);
			std::cout << "Data: ";
			std::cin >> data;
			break;
			
		case 4:
			requestedMethod = std::string(argv[1]);
			validateRequestedMethod(availableMethods, requestedMethod);
			url = std::string(argv[2]);
			data = std::string(argv[3]);
			break;
			
		default:
			throw std::invalid_argument("Usage:\n" + std::string(argv[0]) + "\n" + std::string(argv[0]) + " <HTTP method>\n");
		}
	}
	catch(const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument. " << e.what() << std::endl;
		return -1;
	}
	catch(const std::length_error &e)
	{
		std::cerr << "Length error while handling input. " << e.what() << std::endl;
		return -1;
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << "Error allocating memory while handling input. " << e.what() << std::endl;
		return -1;
	}
	
	std::map<std::string, std::function<std::string(const std::string &, const std::string &)>> methods = 
	{
		{ "GET", [](const std::string &url, const std::string &data) { return restClient::GET(url, data); } },
		{ "POST", [](const std::string &url, const std::string &data) { return restClient::POST(url, data); } },
		{ "PUT", [](const std::string &url, const std::string &data) { return restClient::PUT(url, data); } },
		{ "DELETE", [](const std::string &url, const std::string &data) { return restClient::DELETE(url, data); } }
	};
	
	std::cout << methods[requestedMethod](url, data) << std::endl;
	
	std::cin.get();
	
	return 0;
}

template<typename T>
void validateRequestedMethod(const std::vector<T> &availableMethods, const T &requestedMethod)
{
	if(!vectorContains(availableMethods, requestedMethod))
	{
		std::string errorMessage = "Invalid HTTP method. Available methods are: ";
		for(std::string method : availableMethods)
		{
			errorMessage += " " + method + " ";
		}
		throw std::invalid_argument(errorMessage);
	}
}

template<typename T>
bool vectorContains(const std::vector<T> &vector, const T &element)
{
	return std::find(vector.begin(), vector.end(), element) != vector.end();
}