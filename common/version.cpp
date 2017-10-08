#include "version.hpp"

const std::string audiostreams::getVersion() {
	return std::string(AUDIOSTREAMS_VERSION);
}

uint8_t audiostreams::getMajorVersion() {
	return static_cast<uint8_t>(AUDIOSTREAMS_MAJOR_VERSION);
}

uint8_t audiostreams::getMinorVersion() {
	return static_cast<uint8_t>(AUDIOSTREAMS_MINOR_VERSION);
}

uint16_t audiostreams::getPatchVersion() {
	return static_cast<uint16_t>(AUDIOSTREAMS_PATCH_VERSION);
}
