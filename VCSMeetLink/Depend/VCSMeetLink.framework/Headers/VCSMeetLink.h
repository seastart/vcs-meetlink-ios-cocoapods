//
//  VCSMeetLink.h
//  VCSMeetLink
//
//  Created by SailorGa on 2024/3/14.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version string for VCSMeetLink.
FOUNDATION_EXTERN NSString *__nonnull const VCSMEETLINKVERSION;

//! 引入相关头文件
#if __has_include(<VCSMeetLink/VCSMeetLink.h>)
/// 枚举类型
#import <VCSMeetLink/VCSMeetEnum.h>
/// 数据结构
#import <VCSMeetLink/VCSMeetObjects.h>
#else
/// 枚举类型
#import "VCSMeetEnum.h"
/// 数据结构
#import "VCSMeetObjects.h"
#endif
