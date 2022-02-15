#ifndef HEADER_H
#define HEADER_H

#pragma once
#include<vector>

enum ArrayIndices {
	PROGRAMNAME = 0,
	INPUTFILENAME = 1,
	EXPECTEDARGS = 2,

};

enum SuccessValues {
	SUCCESS = 0,
	WRONG_ARGS = 1,
	EXTRACTIONERROR = 2,
	FILEERROR = 3
};

#endif /* HEADER_H */