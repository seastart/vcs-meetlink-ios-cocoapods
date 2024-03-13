//
//  VCSScreenRecordClient.h
//  VCSMediaKit
//
//  Created by SailorGa on 2022/7/23.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>

NS_ASSUME_NONNULL_BEGIN

@class VCSScreenRecordClient;

#pragma mark - 屏幕共享客户端回调代理
@protocol VCSScreenRecordClientDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 录屏完成回调
/// 录屏完成回调
/// @param client VCSScreenRecordClient实例
/// @param reason 原因描述
- (void)screenClient:(VCSScreenRecordClient *)client didBroadcastFinished:(NSString *)reason;

@end

#pragma mark - VCSScreenRecordClient
@interface VCSScreenRecordClient : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

#pragma mark 获取屏幕共享客户端实例
/// 获取屏幕共享客户端实例
+ (VCSScreenRecordClient *)sharedInstance;

#pragma mark 录屏启动方法
/// 录屏启动方法
/// 需要在 RPBroadcastSampleHandler 的实现类中的 broadcastStartedWithSetupInfo 方法中调用
/// - Parameters:
///   - appGroup: Application Group Identifier
///   - delegate: 回调对象
- (void)broadcastStartedWithAppGroup:(NSString *)appGroup delegate:(nullable id<VCSScreenRecordClientDelegate>)delegate;

#pragma mark 媒体数据(音视频)发送方法
/// 媒体数据(音视频)发送方法
/// - Parameters:
///   - sampleBuffer: 系统回调的视频或音频帧
///   - sampleBufferType: 媒体输入类型
/// 注释：sampleBufferType 当前支持 RPSampleBufferTypeVideo 和 RPSampleBufferTypeAudioApp 类型的数据帧处理；
/// RPSampleBufferTypeAudioMic 不支持，可以在宿主 App 处理麦克风采集数据。
- (void)sendSampleBuffer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType;

@end

NS_ASSUME_NONNULL_END
