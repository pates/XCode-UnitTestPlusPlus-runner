//
//  UnitTest__AppDelegate.m
//  UnitTest++

#import "UnitTest__AppDelegate.h"

#import "UnitTestRunner.h"

@implementation UnitTest__AppDelegate

@synthesize window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification 
{
	NSString* failureString = [NSString stringWithUTF8String:GetUnitTestResults().c_str()];
	[failureView setString:failureString];
	
	if ( !HaveUnitTestFailures() )
	{
		// All tests pass!  Exit out after a couple seconds so the user doesn't have to. 
		[NSApp performSelector:@selector(terminate:) withObject:nil afterDelay:2.0];
	}
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
    return YES;
}

@end
