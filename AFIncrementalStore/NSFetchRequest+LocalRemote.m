//
//  NSFetchRequest+LocalRemote.m
//  vrtii
//
//  Created by Zoran Plesko on 30/10/14.
//  Copyright (c) 2014 Ivana Rast. All rights reserved.
//

#import <objc/runtime.h>

#import "NSFetchRequest+LocalRemote.h"

@implementation NSFetchRequest (LocalRemote)

@dynamic isLocalFetch;
@dynamic additionalLimit;

- (void)setIsLocalFetch:(NSNumber *)object {
    objc_setAssociatedObject(self, @selector(isLocalFetch), object, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSNumber *)isLocalFetch {
    return objc_getAssociatedObject(self, @selector(isLocalFetch));
}

- (void)setAdditionalLimit:(NSNumber *)object {
    objc_setAssociatedObject(self, @selector(additionalLimit), object, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSNumber *)additionalLimit {
    return objc_getAssociatedObject(self, @selector(additionalLimit));
}


@end
