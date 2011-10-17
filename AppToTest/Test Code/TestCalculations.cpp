/*
 *  TestCalculations.cpp
 *  AppToTest
 *
 */

#include <UnitTest++/UnitTest++.h>

#include "Calculations.h"

#if 1
SUITE( Calculations )
{
    TEST( thatTwoNumbersAreAdded )
    {
		CHECK_EQUAL( 0, SimpleSum( 0, 0 ) );
		CHECK_EQUAL( 1, SimpleSum( 1, 0 ) );
    }

    TEST( thatTwoNumbersAreMultiplied )
    {
		CHECK_EQUAL( 0, SimpleMult( 1, 0 ) );
		CHECK_EQUAL( 2, SimpleMult( 1, 2 ) );
		CHECK_EQUAL( 6, SimpleMult( 2, 3 ) );
    }
}
#endif 

#if 0

// These are the original UnitTest++ usage examples, including intentional failures.
// Activate this block to see them in action.


SUITE( YourSuiteName )
{
    TEST( CheckEquality )
    {
		CHECK_EQUAL( 10, 20 );
		CHECK_EQUAL( "foo", "bar" );
		CHECK_CLOSE( 3.14, 3.1415, 0.01 );
    }
	
	TEST( CheckArrays )
	{
		const float oned[2] = { 10, 20 };
		CHECK_ARRAY_EQUAL( oned, oned, 2 );
		CHECK_ARRAY_CLOSE( oned, oned, 2, 0.00 );
		
		const float twod[2][3] = { {0, 1, 2}, {2, 3, 4} };
		CHECK_ARRAY2D_CLOSE( twod, twod, 2, 3, 0.00 );
	}
	
	TEST( CheckExceptionThrown )
	{
		struct TestException {};
		CHECK_THROW( throw TestException(), TestException );
	}
	
	TEST( YourTimedTest )
	{
		{
			UNITTEST_TIME_CONSTRAINT( 50 );
			usleep( 60000 );
		}
	}
	
	TEST( NotoriouslySlowTest )
	{
		UNITTEST_TIME_CONSTRAINT_EXEMPT();
		usleep( 100000 );
	}
}

#endif // 0

