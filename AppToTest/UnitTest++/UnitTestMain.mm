//
//  UnitTestMain.m
//  UnitTest++
//
//  Created on 9/30/11.
//

#import <Cocoa/Cocoa.h>

#include <UnitTest++/DeferredTestReporter.h>

#include "UnitTestRunner.h"

int main(int argc, char *argv[])
{
	RunUnitTests(); 
	NSApplicationMain(argc,  (const char **) argv);
}
