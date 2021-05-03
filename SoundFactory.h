#pragma once

#include <string>
#include <memory>
#include "SoundInterface.h"

std::unique_ptr<SoundInterface> makeSound(const std::string &fileName);