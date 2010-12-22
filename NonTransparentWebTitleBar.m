//
//  NonTransparentWebTitleBar.m
//  CoGeWebKit
//
//  Created by vade on 7/6/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "NonTransparentWebTitleBar.h"


@implementation NonTransparentWebTitleBar
- (void)drawRect:(NSRect)dirtyRect
{
	[[NSColor colorWithCalibratedWhite:0.88 alpha:1.0] set];
	
	[NSBezierPath fillRect:dirtyRect];
}

@end
