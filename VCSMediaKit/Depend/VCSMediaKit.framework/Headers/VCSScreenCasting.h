//
//  VCSScreenCasting.h
//  VCSMediaKit
//
//  Created by SailorGa on 2024/3/5.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
#import <VCSMediaKit/VCSMediaObjects.h>
#else
#import "VCSMediaObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSScreenCasting;

#pragma mark - 投屏回调代理
@protocol VCSScreenCastingDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 投屏检测状态回调
/// 投屏检测状态回调
/// @param screenCasting 投屏实例
/// @param status 状态码
/// @param reason 拒绝原因
- (void)screenCasting:(VCSScreenCasting *)screenCasting onCastingProbesStatus:(VCSScreenCastingStatus)status reason:(nullable NSString *)reason;

#pragma mark 屏幕录制状态回调
/// 屏幕录制状态回调
/// @param screenCasting 投屏实例
/// @param status 状态码
- (void)screenCasting:(VCSScreenCasting *)screenCasting onScreenRecordStatus:(VCSScreenRecordStatus)status;

#pragma mark 投屏状态回调
/// 投屏状态回调
/// @param screenCasting 投屏实例
/// @param status 状态码
/// @param reason 拒绝原因
- (void)screenCasting:(VCSScreenCasting *)screenCasting onCastingScreenStatus:(VCSScreenCastingStatus)status reason:(nullable NSString *)reason;

#pragma mark 发送状态信息回调
/// 发送状态信息回调
/// @param screenCasting 投屏实例
/// @param sendModel 发送状态数据
- (void)screenCasting:(VCSScreenCasting *)screenCasting onSendStreamModel:(VCSStreamSendModel *)sendModel;

#pragma mark 当前服务延时回调
/// 当前服务延时回调
/// @param screenCasting 投屏实例
/// @param timestamp 服务延时
- (void)screenCasting:(VCSScreenCasting *)screenCasting onSignalingDelayed:(NSInteger)timestamp;

@end

#pragma mark - 投屏完成回调
/// 投屏完成回调
typedef void (^VCSScreenCastingFinishedBlock)(NSString * _Nullable reason);

#pragma mark - VCSScreenCasting
@interface VCSScreenCasting : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 当前屏幕录制状态
@property (nonatomic, assign, readonly) VCSScreenRecordStatus screenRecordStatus;

#pragma mark 获取投屏单例
/// 获取投屏单例
+ (VCSScreenCasting *)sharedInstance;

#pragma mark 配置投屏参数
/// 配置投屏参数
/// - Parameters:
///   - castingConfig: 配置参数
///   - appGroup: Application Group Identifier
///   - delegate: 代理回调
- (void)setupCastingConfig:(VCSScreenCastingConfig *)castingConfig appGroup:(NSString *)appGroup delegate:(nullable id <VCSScreenCastingDelegate>)delegate;

#pragma mark 启动投射音频
/// 启动投射音频
/// - Parameter enable: YES-启用 NO-关闭
- (void)enableCastingAudio:(BOOL)enable;

#pragma mark 停止投屏
/// 停止投屏
- (void)stopCasting;

@end

NS_ASSUME_NONNULL_END
