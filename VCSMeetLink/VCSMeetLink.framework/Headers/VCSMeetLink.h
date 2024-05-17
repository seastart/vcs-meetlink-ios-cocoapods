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
/// 登录组件
#import <VCSMeetLink/VCSMeetLogin.h>
/// 呼叫组件
#import <VCSMeetLink/VCSMeetCall.h>
/// 会控组件
#import <VCSMeetLink/VCSMeetControl.h>
/// 消息连接器(通讯桥梁)
#import <VCSMeetLink/VCSMsgLinker.h>
#else
/// 登录组件
#import "VCSMeetLogin.h"
/// 呼叫组件
#import "VCSMeetCall.h"
/// 会控组件
#import "VCSMeetControl.h"
/// 消息连接器(通讯桥梁)
#import "VCSMsgLinker.h"
#endif
