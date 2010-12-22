//
//  TransparentWindow.m
//  CoGeWebKit
//
//  Created by vade on 7/5/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "TransparentWindow.h"


@implementation TransparentWindow

- (id)initWithContentRect:(NSRect)contentRect styleMask:(NSUInteger)windowStyle backing:(NSBackingStoreType)bufferingType defer:(BOOL)deferCreation
{
	if(![super initWithContentRect:contentRect styleMask:windowStyle backing:bufferingType defer:deferCreation])
		return nil;

	[self setBackgroundColor:[NSColor clearColor]];
	[self setOpaque:NO];
	
	return self;
}

-(void)setNaviPath:(NSString *)path {
	
	[urlField setTitleWithMnemonic:path];
	
	[urlField performClick:nil];
}
@end
