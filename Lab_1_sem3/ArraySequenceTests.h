#pragma once

#include "Sequence.h"
#include "ArraySequence.h"
#include "SequenceIterator.h"

#include "TestEnvironment.h"
#include "SequenceAssertions.h"

using namespace sequences;
using namespace sequences::iterators;

void TestArrayInsertions();
void TestArraySubsequence();
void TestArrayConcatenation();

void TestArrayMap();
void TestArrayWhere();
void TestArrayReduce();