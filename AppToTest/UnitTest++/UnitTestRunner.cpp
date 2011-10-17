/*
 *  UnitTestRunner.cpp
 *  AppToTest
 *
 */

#include "UnitTestRunner.h"

#include <sstream>
#include <string>
#include <UnitTest++/UnitTest++.h>

#include "Calculations.h" 


#define USE_DEFERRED_REPORTING  // activate this to display results in dialog instead of console

#ifdef USE_DEFERRED_REPORTING
#include <UnitTest++/DeferredTestReporter.h>
#include <UnitTest++/DeferredTestResult.h>
#else
#include <UnitTest++/TestReporterStdout.h>
#endif  // USE_DEFERRED_REPORTING


std::string failureList; 
bool haveFailures = false; 

std::string GetFileNameFromPath( const std::string& filePath )
{
	return filePath.substr( filePath.find_last_of("/\\") + 1 );
}

std::string GetFailureSubStringFromInt( const int n, const bool includeColon )
{
	std::string failureString; 
	
	std::ostringstream stream;
	stream << n;  
	failureString += stream.str();
	
	if ( includeColon )
		failureString += ": ";
	
	return failureString; 
}

std::string GetPassesOutOfTotalStr( const int passingTests, const int totalTests )
{
	std::string failureString; 

	failureString += GetFailureSubStringFromInt( passingTests, false ); 
	failureString += " out of ";
	failureString += GetFailureSubStringFromInt( totalTests, false );
	failureString += " tests passed.";
	
	return failureString; 
}

void RunUnitTests( const int maxTime /*= 0*/ )
{
#ifndef USE_DEFERRED_REPORTING
	// Spit results out to console
	UnitTest::TestReporterStdout reporter;
	UnitTest::TestRunner runner( reporter );
	runner.RunTestsIf( UnitTest::Test::GetTestList(), NULL, UnitTest::True(), maxTime ) > 0; 

#else

	// Launch Cocoa dialog to display results
	UnitTest::DeferredTestReporter reporter; 
	UnitTest::TestRunner runner( reporter );
	const int numFailures = runner.RunTestsIf( UnitTest::Test::GetTestList(), NULL, UnitTest::True(), maxTime ); 
	
	UnitTest::DeferredTestReporter::DeferredTestResultList& resultList = reporter.GetResults();
	int failureNum = 1; 
	int totalTests = 0, passingTests = 0; 
	for ( int i = 0 ; i < resultList.size(); i++ )
	{
		UnitTest::DeferredTestResult result = resultList[i]; 
		if ( result.failed )
		{
			failureList += GetFailureSubStringFromInt( failureNum, true );  
			failureList += GetFileNameFromPath( result.failureFile );
			failureList += ", ";
			failureList += result.suiteName;
			failureList += ", ";
			failureList += result.testName;
			failureList += ", line ";

			UnitTest::DeferredTestResult::Failure failure = result.failures[0];
			failureList += GetFailureSubStringFromInt( failure.first, true ); 
			failureList += failure.second;  // the actual failure ("Expected x but was y")
			failureList += "\n\n";
			
			failureNum++; 
		}
		else 
			passingTests++; 

		totalTests++; 
	}
	
	failureList += GetPassesOutOfTotalStr( passingTests, totalTests ); 
	
	haveFailures = numFailures > 0; 
	
#endif // USE_DEFERRED_REPORTING
}

std::string GetUnitTestResults()
{
	return failureList; 
}

bool HaveUnitTestFailures()
{
	return haveFailures; 
}
