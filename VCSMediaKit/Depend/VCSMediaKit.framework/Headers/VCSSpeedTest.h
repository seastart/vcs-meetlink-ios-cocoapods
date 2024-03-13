//
//  VCSSpeedTest.h
//  VCSMediaKit
//
//  Created by SailorGa on 2022/7/27.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
#import <VCSMediaKit/VCSMediaObjects.h>
#else
#import "VCSMediaObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSSpeedTest;

#pragma mark - 网络测速回调代理
@protocol VCSSpeedTestDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 网络测速开始回调
/// 网络测速开始回调
/// @param speedTest  VCSSpeedTest实例
- (void)speedTestDidBegined:(VCSSpeedTest *)speedTest;

#pragma mark 网络测速的结果回调
/// 网络测速的结果回调
/// @param speedTest VCSSpeedTest实例
/// @param uploadResult 上行网速测试数据
/// @param downResult 下行网速测试数据
/// @param connectResult 连接情况
- (void)speedTest:(VCSSpeedTest *)speedTest didFinishUploadResult:(nullable VCSSpeedTestResult *)uploadResult downResult:(nullable VCSSpeedTestResult *)downResult connectResult:(nullable VCSSpeedTestConnectResult *)connectResult;

@end

#pragma mark - VCSSpeedTest
@interface VCSSpeedTest : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 网络测速参数
@property (nonatomic, strong, readonly) VCSSpeedTestParams *params;

#pragma mark 获取网络测速实例
/// 获取网络测速实例
+ (VCSSpeedTest *)sharedInstance;

#pragma mark 开始网络测速
/// 开始网络测速
/// @param params 测速参数
/// @param delegate 测速回调代理
/// 1、请在进入房间前进行网速测试，在房间中网速测试会影响正常的音视频传输效果，而且由于干扰过多，网速测试结果也不准确。
/// 2、同一时间只允许一项网速测试任务运行。
- (VCSError)startSpeedTest:(VCSSpeedTestParams *)params delegate:(nullable id <VCSSpeedTestDelegate>)delegate;

#pragma mark 停止网络测速
/// 停止网络测速
- (void)stopSpeedTest;

#pragma mark 资源销毁
/// 资源销毁
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
