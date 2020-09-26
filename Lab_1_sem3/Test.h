#pragma once

#include <exception>

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

void InitializeTests(TestEnvironment& env);


