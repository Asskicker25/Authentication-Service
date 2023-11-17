#pragma once

#include <string>
#include "../../ProtocolFile/authentication.pb.h"


static enum Command
{
	REGISTER = 0,
	AUTHENTICATE = 1,
};

static std::string SerializeWithCommandAndLengthPrefix(const Command& command, const google::protobuf::Message& message)
{
	std::string serializedMessage;
	message.SerializeToString(&serializedMessage);

	Authentication::CommandAndData commnadData;

	commnadData.set_command((int)command);
	commnadData.set_data(serializedMessage);

	std::string serializedMessageData;
	commnadData.SerializeToString(&serializedMessageData);

	Authentication::LengthPrefix lengthPrefix;
	lengthPrefix.set_messagelength(serializedMessageData.size());

	std::string serializedLengthPrefix;
	lengthPrefix.SerializeToString(&serializedLengthPrefix);

	std::string result;
	result.append(serializedLengthPrefix);
	result.append(serializedMessageData);

	return result;
}