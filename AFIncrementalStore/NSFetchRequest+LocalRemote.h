//
//  NSFetchRequest+LocalRemote.h
//  vrtii
//
//  Created by Zoran Plesko on 30/10/14.
//  Copyright (c) 2014 Ivana Rast. All rights reserved.
//

#import <CoreData/CoreData.h>

/**
 `NSFetchRequest (LocalRemote)` is a category on NSFetchRequest that adds a possibility to fetch only from local core data storage without accessing the remote storage so we can freely access the cache in AFIncrementalStore
*/

@interface NSFetchRequest (LocalRemote)


/**
 marks this NSFetchRequest as local (not fetching remote values)
 
 @discussion When used with this version of AFIncrementalStore, you can check if fetch request is local in your AFIncrementalStoreClient implementation of method requestForFetchRequest:withContext: and return nil if this boolValue is NO
 
 example:
 
 - (NSURLRequest *)requestForFetchRequest:(NSFetchRequest *)fetchRequest withContext:(NSManagedObjectContext *)context
 {
	if(fetchRequest.isLocalFetch && fetchRequest.isLocalFetch.boolValue) return nil;
 */
@property (nonatomic, strong) NSNumber *isLocalFetch;


/**
 fetchLimit is sometimes overwritten (I'm not sure if it's a bug)
 this is just an alternative to be used if there is a need for pagging on remote API
 */
@property (nonatomic, strong) NSNumber *additionalLimit;

@end
