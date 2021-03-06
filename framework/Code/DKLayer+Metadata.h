///**********************************************************************************************************************************
///  DKLayer+Metadata.h
///  DrawKit ©2005-2008 Apptree.net
///
///  Created by Graham Cox on 19/03/2007.
///
///	 This software is released subject to licensing conditions as detailed in DRAWKIT-LICENSING.TXT, which must accompany this source file. 
///
///**********************************************************************************************************************************

#import "DKLayer.h"
#import "DKMetadataItem.h"

typedef enum
{
	kDKLayerMetadataOriginalSchema			= 1,
	kDKLayerMetadataCaseInsensitiveSchema	= 2,
	kDKLayerMetadata107Schema				= 3
}
DKLayerMetadataSchema;


@interface DKLayer (Metadata)

+ (void)		setMetadataChangesAreUndoable:(BOOL) undo;
+ (BOOL)		metadataChangesAreUndoable;

- (void)					setupMetadata;
- (NSMutableDictionary*)	metadata;
- (DKLayerMetadataSchema)	schema;
- (NSArray*)				metadataKeys;

- (void)		addMetadata:(NSDictionary*) dict;
- (void)		setMetadata:(NSDictionary*) dict;

- (void)		setMetadataItem:(DKMetadataItem*) item forKey:(NSString*) key;
- (DKMetadataItem*)	metadataItemForKey:(NSString*) key;
- (void)		setMetadataItemValue:(id) value forKey:(NSString*) key;
- (void)		setMetadataItemType:(DKMetadataType) type forKey:(NSString*) key;

- (id)			metadataObjectForKey:(NSString*) key;

- (BOOL)		hasMetadataForKey:(NSString*) key;
- (void)		removeMetadataForKey:(NSString*) key;

- (void)		setFloatValue:(float) val forKey:(NSString*) key;
- (CGFloat)		floatValueForKey:(NSString*) key;

- (void)		setIntValue:(int) val forKey:(NSString*) key;
- (NSInteger)	intValueForKey:(NSString*) key;

- (void)		setString:(NSString*) string forKey:(NSString*) key;
- (NSString*)	stringForKey:(NSString*) key;

- (void)		setColour:(NSColor*) colour forKey:(NSString*) key;
- (NSColor*)	colourForKey:(NSString*) key;

- (void)		setSize:(NSSize) size forKey:(NSString*) key;
- (NSSize)		sizeForKey:(NSString*) key;

- (void)		updateMetadataKeys;
- (NSUInteger)	metadataChecksum;

- (BOOL)		supportsMetadata;
- (void)		metadataWillChangeKey:(NSString*) key;
- (void)		metadataDidChangeKey:(NSString*) key;

@end

extern NSString*	kDKLayerMetadataUserInfoKey;
extern NSString*	kDKLayerMetadataUndoableChangesUserDefaultsKey;
extern NSString*	kDKMetadataWillChangeNotification;
extern NSString*	kDKMetadataDidChangeNotification;



@interface DKLayer (MetadataDeprecated)

- (void)		setMetadataObject:(id) obj forKey:(id) key;

@end

/* adds some convenience methods for standard meta data attached to a graphic object. By default the metadata is just an uncomitted
id, but using this sets it to be a mutable dictionary. You can then easily get and set values in that dictionary.

*/
