#pragma once
#include "XAFilmingSerializer.h"
#include <XAFilmingLogger.h>

struct DataPacketHeader
{
	DataPacketHeader()
		: uid(),
		  index(0),
		  total(0)
	{
	}

	std::string uid;
	int index;
	int total;

	void DeserializeFrom(const std::string& serializedDataPacketHeader)
	{
		std::vector<std::string> strings;
		deserializeStrings(serializedDataPacketHeader, strings);

		try
		{
			uid = strings.at(0);
			index = string_to_int(strings.at(1));
			total = string_to_int(strings.at(2));
		}
		catch (std::exception& e)
		{
			LOG_ERROR_XA_FILMING << "Failed to deserialize with exception : " << e.what() << LOG_END;
		}
	}
};
