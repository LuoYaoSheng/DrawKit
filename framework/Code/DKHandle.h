//
//  DKHandle.h
//  GCDrawKit
//
//  Created by Graham Cox on 4/09/09.
//  Copyright 2009 Apptree.net. All rights reserved.
//
//  Updated and refactored by Stephan Zehrer
//  Copyright (c) 2013 zehrer.net. All rights reserved.

#import <Cocoa/Cocoa.h>
#import "DKCommonTypes.h"

@class DKQuartzCache;

/*
 
 DKHandle is a base class for all handles, which are the knobs attached to shapes for interacting with them. This is an evolution of DKKnob which is still used as a central helper class for dispatching drawing to handles as needed.
 
 DKHandle is subclassed for each handle type, making it easier to customise and also add caching.
 
*/
@interface DKHandle : NSObject
{
@private
	DKQuartzCache*		mCache;
}

+ (DKKnobType)			type;
+ (DKHandle*)			handleForType:(DKKnobType) type size:(NSSize) size colour:(NSColor*) colour;
+ (void)				setHandleClass:(Class) hClass forType:(DKKnobType) type;

+ (NSColor*)			fillColour;
+ (NSColor*)			strokeColour;
+ (NSBezierPath*)		pathWithSize:(NSSize) size;
+ (CGFloat)				strokeWidth;
+ (CGFloat)				scaleFactor;

- (id)					initWithSize:(NSSize) size;
- (id)					initWithSize:(NSSize) size colour:(NSColor*) colour;

@property (nonatomic, readonly) NSSize size;
@property (nonatomic, strong) NSColor* colour;

- (void)				drawAtPoint:(NSPoint) point;
- (void)				drawAtPoint:(NSPoint) point angle:(CGFloat) radians;
- (BOOL)				hitTestPoint:(NSPoint) point inHandleAtPoint:(NSPoint) hp;


@end
