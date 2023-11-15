#include "../../ProtocolFile/Authentication.pb.h"

int main(int argc, char** argv)
{
	Authentication::CreateAccountWeb createAccount;

	createAccount.set_requestid(123);
	createAccount.set_email("test@example.com");
	createAccount.set_plaintextpassword("secretpassword");

	std::string serializedMessage;
	if (createAccount.SerializeToString(&serializedMessage)) 
	{
		std::cout << "Serialized Message: " << serializedMessage << std::endl;

		// Deserialize the string back to a message
		Authentication::CreateAccountWeb deserializedAccount;
		if (deserializedAccount.ParseFromString(serializedMessage)) 
		{
			std::cout << "Deserialized Message:" << std::endl;
			std::cout << "RequestId: " << deserializedAccount.requestid() << std::endl;
			std::cout << "Email: " << deserializedAccount.email() << std::endl;
			std::cout << "PlaintextPassword: " << deserializedAccount.plaintextpassword() << std::endl;
		}
		else 
		{
			std::cerr << "Failed to deserialize the message." << std::endl;
			return 1;
		}
	}
	else 
	{
		std::cerr << "Failed to serialize the message." << std::endl;
		return 1;
	}

	return 0;

}