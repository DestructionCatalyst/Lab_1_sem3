#pragma once

#include <exception>
#include <sstream>

#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "SequenceIterator.h"

#include "TestEnvironment.h"
#include "SequenceAssertions.h"
#include "TimedTest.h"

#include "ArraySequenceTests.h"
#include "ListSequenceTests.h"

#include "NumberGeneratorTests.h"
#include "SequenceGeneratorTest.h"

#include "TimerTest.h"

#include "SorterTest.h"
#include "MergeSorter.h"

#include "RandomNumberGenerator.h"

void InitializeTests(TestEnvironment& env);


