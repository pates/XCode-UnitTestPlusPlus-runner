//
//  UnitTest__AppDelegate.h
//  UnitTest++

#import <Cocoa/Cocoa.h>

@interface UnitTest__AppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;
    IBOutlet NSTextView *failureView;
}

@property (assign) IBOutlet NSWindow *window;

@end
