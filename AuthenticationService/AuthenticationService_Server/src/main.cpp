#include <TCP_Server.h>

int main(int argc, char** argv)
{
	TCP_Server server("127.0.0.1", "8017");

	server.InitializeServer();

	return 0;
}