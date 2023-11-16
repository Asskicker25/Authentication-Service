
#include <TCP_Client.h>

int main(int argc, char** argv)
{

	TCP_Client client("127.0.0.1", "8017");

	client.ConnectToServer();

	return 0;
}