//
//  Product.cpp
//  Product
//
//  Created by Yuekie on 3/1/16.
//  Copyright (c) 2016 Intelligent. All rights reserved.
//

#include "Product.h"

const char* Product::GetJSONInfo(const char * TableName,const char* KeyWord)
{
    id InfoTemp = nil;
    if (![[NSFileManager defaultManager] fileExistsAtPath:@"/vault/data_collection/test_station_config/gh_station_info.json"])
    {
        return NULL;
    }
    NSString * ghSFCSInfoContent = [NSString stringWithContentsOfFile:@"/vault/data_collection/test_station_config/gh_station_info.json" encoding:NSUTF8StringEncoding error:nil];
    NSData * ghSFCSInfoData = [ghSFCSInfoContent dataUsingEncoding:NSUTF8StringEncoding];
    if (ghSFCSInfoData)
    {
        NSDictionary * ghSFCSInfo = [NSJSONSerialization JSONObjectWithData:ghSFCSInfoData
                                                                    options:0
                                                                      error:nil];
        NSDictionary * ghInfo = [ghSFCSInfo objectForKey:[NSString stringWithUTF8String:TableName]];
        if (ghInfo)
        {
            InfoTemp = [ghInfo objectForKey:[NSString stringWithUTF8String:KeyWord]];
            if([InfoTemp isKindOfClass:[NSString class]])
            {
                return [InfoTemp UTF8String];
            }
            else if([InfoTemp isKindOfClass:[NSNumber class]])
            {
                return [[InfoTemp stringValue] UTF8String];
            }
        }
    }
    return NULL;
}

const char* Product::GetProductType()
{
    return GetJSONInfo("ghinfo", "PRODUCT");
}

void Product::SetProductPID_VID(int PID,int VID)
{
    @throw [NSException exceptionWithName:@"Overrid error" reason:@"you should overrid  SetProductPID_VID function first!" userInfo:nil];
    
}

int Product::GetProductPID()
{
    @throw [NSException exceptionWithName:@"Overrid error" reason:@"you should overrid  GetProductPID function first!" userInfo:nil];
    return 0;
}

int Product::GetProductVID()
{
    @throw [NSException exceptionWithName:@"Overrid error" reason:@"you should overrid  GetProductVID function first!" userInfo:nil];
    return 0;
}


