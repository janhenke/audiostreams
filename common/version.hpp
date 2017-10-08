#pragma once

#include "audiostreams_export.h"
#include "config.hpp"

#include <cstdint>
#include <string>

namespace audiostreams {

	/// \brief Return the library's version at compile time as a string
	/// \return A string identifying the version of the library.
	/// \see AUDIOSTREAMS_VERSION for the version of the header files
	AUDIOSTREAMS_EXPORT const std::string &getVersion();

	/// \brief Return the major version of this library at compile time.
	/// \return An unsigned 8 bit integer representing this libraries major version number.
	AUDIOSTREAMS_EXPORT uint8_t getMajorVersion();

	/// \brief Return the minor version of this library at compile time.
	/// \return An unsigned 8 bit integer representing this libraries major version number.
	AUDIOSTREAMS_EXPORT uint8_t getMinorVersion();

	/// \brief Return the patch version of this library at compile time.
	/// \return An unsigned 8 bit integer representing this libraries major version number.
	AUDIOSTREAMS_EXPORT uint16_t getPatchVersion();
}
