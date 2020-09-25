#pragma once

#include <iostream>

#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"

#include "INumberGenerator.h"
#include "ConstantNumberGenerator.h"
#include "ConsecutiveNumberGenerator.h"
#include "ReverseNumberGenerator.h"
#include "RandomNumberGenerator.h"

#include "TestEnvironment.h"
#include "SequenceAssertions.h"

using namespace sequences;

void TestConstantSequence();
void TestConsecutiveSequence();
void TestReverseSequence();
void TestRandomSequence();

