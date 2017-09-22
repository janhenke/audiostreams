#include "version.hpp"

const char *audiostreams::getVersion() {
	return PROJECT_VERSION;
}

uint8_t audiostreams::getMajorVersion() {
	return PROJECT_VERSION_MAJOR;
}

uint8_t audiostreams::getMinorVersion() {
	return PROJECT_VERSION_MINOR;
}

uint8_t audiostreams::getPatchVersion() {
	return PROJECT_VERSION_PATCH;
}
