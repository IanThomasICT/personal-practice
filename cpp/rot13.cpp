#include <string>
#include <iostream>

std::string rot13(std::string msg)
{
	std::string result;
	for (unsigned int i = 0; i < msg.size(); i++){
		if ((msg[i] + 13) <= 'Z') // Gppd
			result += (msg[i] + 13);
		else if ((msg[i] + 13) <= 'z' && (msg[i] + 13) > 'a') // Good
			result += (msg[i] + 13);
		else if ((msg[i] + 13) > 'Z' && (msg[i] < 'Z')) // FIX
			result += ('@' + ((int(msg[i]) + 13) % 90)); 
		else if ((msg[i] + 13) > 'z') // Good
			result += ('`' + ((int(msg[i]) +13) % 122));
	}
		  
	return result;
}

int main()
{
	std::cout << rot13("test") << "\n";
	std::cout << rot13("Test") << "\n";
	std::cout << rot13("AbCd") << "\n";

	return 0;
}



