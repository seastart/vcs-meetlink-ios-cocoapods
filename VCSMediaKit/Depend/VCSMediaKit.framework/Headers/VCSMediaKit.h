//
//  VCSMediaKit.h
//  VCSMediaKit
//
//  Created by SailorGa on 2024/3/11.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version string for VCSMediaKit.
FOUNDATION_EXTERN NSString *__nonnull const VCSMEDIAKITVERSION;

//! 引入相关头文件
#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
/// 播放组件
#import <VCSMediaKit/RTYUVPlayer.h>
/// 网络检测
#import <VCSMediaKit/VCSSpeedTest.h>
/// 媒体组件
#import <VCSMediaKit/VCSStreamMedia.h>
/// 视频渲染
#import <VCSMediaKit/VCSVideoRender.h>
/// 视频采集
#import <VCSMediaKit/VCSVideoCapture.h>
/// 无线投屏
#import <VCSMediaKit/VCSScreenCasting.h>
/// 远程画面
#import <VCSMediaKit/VCSRemoteSession.h>
/// 日志组件
#import <VCSMediaKit/VCSLoggerSession.h>
/// 网络研讨会
#import <VCSMediaKit/VCSWebinarSession.h>
/// 屏幕采集客户端
#import <VCSMediaKit/VCSScreenRecordClient.h>
/// 屏幕采集服务端
#import <VCSMediaKit/VCSScreenRecordServer.h>
/// 研讨会远程画面
#import <VCSMediaKit/VCSWebinarRemoteSession.h>
#else
/// 播放组件
#import "RTYUVPlayer.h"
/// 网络检测
#import "VCSSpeedTest.h"
/// 媒体组件
#import "VCSStreamMedia.h"
/// 视频渲染
#import "VCSVideoRender.h"
/// 视频采集
#import "VCSVideoCapture.h"
/// 无线投屏
#import "VCSScreenCasting.h"
/// 远程画面
#import "VCSRemoteSession.h"
/// 日志组件
#import "VCSLoggerSession.h"
/// 网络研讨会
#import "VCSWebinarSession.h"
/// 屏幕采集客户端
#import "VCSScreenRecordClient.h"
/// 屏幕采集服务端
#import "VCSScreenRecordServer.h"
/// 研讨会远程画面
#import "VCSWebinarRemoteSession.h"
#endif

