//
//  AlertPanel.h
//  UI
//
//  Created by ZL-Pro on 2017/7/13.
//
//
#define NSRunAlertPanel NSRunAlertPanelEx
#import <Foundation/Foundation.h>
NSInteger NSRunAlertPanelEx(NSString *title, NSString *msgFormat, NSString *defaultButton, NSString *alternateButton, NSString *otherButton, ...);
