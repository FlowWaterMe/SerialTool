//
//  Product.h
//  Product
//
//  Created by Yuekie on 3/1/16.
//  Copyright (c) 2016 Intelligent. All rights reserved.
//

#pragma once

#include <iostream>

class Product
{
public:
    
    static const char* GetJSONInfo(const char * TableName,const char* KeyWord);
    static const char* GetProductType();
    virtual void SetProductPID_VID(int PID,int VID);
    virtual int GetProductPID();
    virtual int GetProductVID();
};

