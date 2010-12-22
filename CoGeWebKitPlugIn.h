//
//  CoGeWebKitPlugIn.h
//  CoGeWebKit
//
//  Created by Tamas Nagy on 6/30/09.
//  Copyright (c) 2009 __MyCompanyName__. All rights reserved.
//

#import <Quartz/Quartz.h>
#import <WebKit/WebKit.h>
#import <OpenGL/OpenGL.h>
#import <TransparentWindow.h>

#import <Appkit/Appkit.h>

// AWT java view forward class declaration for Java plugins a la Processing 

@interface CoGeWebKitPlugIn : QCPlugIn
{
	NSNib* WebViewNib;
	IBOutlet TransparentWindow *offscreenWindow;
	IBOutlet WebView *theWebView;

	NSString* theURLString;
	
	// we use two textures to double buffer texture upload
	NSBitmapImageRep* webBitmap;
	NSUInteger width, height;
	
	GLuint webTexture1;
	
	// cheap way to keep form spawning too many threads.
	BOOL workingOn1;	
	NSRecursiveLock* lock1;

	// this is a boolean that trigers properties that only need to be set once per frame, ie
	// output document height,width, source, image urls.
	BOOL updateOneshotOutputPorts;
	
	NSMutableArray *urlList;
	NSString *stringHTMLSource;	
	BOOL needJSExecute;
	
	//remember to scrollview current location
	double lastScrollValueX;
	double lastScrollValueY;
	
	NSString *JSOut;
	
	BOOL needsrebuild;
	
	BOOL rendersflash;
	BOOL needsforcerenderflash;
	
	BOOL liveresize;
	
}

@property (readwrite, retain) NSString* theURLString;
@property (readwrite, retain) NSBitmapImageRep* webBitmap;
@property (readwrite, assign) BOOL workingOn1;
@property (readwrite, retain) NSString* stringHTMLSource;
@property (readwrite, retain) NSMutableArray *urlList;

// QC input/output  ports
@property (assign) NSString* inputFilePath;
@property (assign) BOOL inputShowWindow;
@property (assign) BOOL inputShowScrollbars;

@property (assign) double inputWidth;
@property (assign) double inputHeight;
@property (assign) NSString* inputJavascript;

@property (assign) BOOL inputReload;
@property (assign) BOOL inputForwardHistory;
@property (assign) BOOL inputBackwardHistory;

// natural input to webkit for "real browsing".
@property (assign) double inputMouseScrollX;
@property (assign) double inputMouseScrollY;
@property (assign) double inputMouseX;
@property (assign) double inputMouseY;
@property (assign) BOOL inputMouseLeftDown;
@property (assign) BOOL inputMouseRightDown;

@property (assign) NSString* inputCharacter;

// javascript specific
@property (assign) BOOL inputReexecuteJS;

//for fucking swf
@property (assign) BOOL inputForceFlashRendering;

@property (assign) id<QCPlugInOutputImageProvider> outputImage;
@property (assign) double outputDocWidth;
@property (assign) double outputDocHeight;

@property (assign) NSString* outputJavascript;
@property (assign) NSString* outputCurrentURL;
@property (assign) NSArray* outputImageUrls;
@property (assign) NSString* outputHTMLStringSource;
@property (assign) double outputProgress;


@end

@interface CoGeWebKitPlugIn (Execution)

// thread worker method..
- (void) copyWebViewToBitmapInBackground;
- (NSPoint) normalizedMouseLocationForMouseX:(double)inputMouseX mouseY:(double)inputMouseY isFlippedY:(BOOL)flippedy;

- (NSString *)sourceFromWebView:(WebView *)webView;
- (void) handleLoadingFlashSetup:(NSString *)swffile;



@end
