//
//  VCSLoggerSession.h
//  VCSMediaKit
//
//  Created by SailorGa on 2024/3/8.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
#import <VCSMediaKit/VCSMediaObjects.h>
#else
#import "VCSMediaObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSLoggerSession;

#pragma mark - 日志组件回调
@protocol VCSLoggerSessionDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 行为日志扩展回调
/// 行为日志扩展回调
/// - Parameters:
///   - session: 日志组件实例
///   - loggerParamItem: 行为日志对象
- (VCSLoggerParamItem *)loggerSession:(VCSLoggerSession *)session onLoggerExpand:(VCSLoggerParamItem *)loggerParamItem;

#pragma mark 实时日志扩展回调
/// 实时日志扩展回调
/// - Parameters:
///   - session: 日志组件实例
///   - metricParamItem: 实时日志对象
- (VCSMetricParamItem *)loggerSession:(VCSLoggerSession *)session onMetricExpand:(VCSMetricParamItem *)metricParamItem;

#pragma mark 重定向日志扩展回调
/// 重定向日志扩展回调
/// - Parameters:
///   - session: 日志组件实例
///   - redirectParam: 重定向日志对象
- (VCSRedirectParam *)loggerSession:(VCSLoggerSession *)session onRedirectExpand:(VCSRedirectParam *)redirectParam;

@end

@interface VCSLoggerSession : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 日志组件是否启用
@property (nonatomic, assign, readonly) BOOL serviceEnabled;
/// 当前会议号码
@property (nonatomic, copy, readonly) NSString *roomNo;
/// 网络类型
@property (nonatomic, copy, readonly) NSString *networkType;

#pragma mark 获取单例
/// 获取单例
+ (VCSLoggerSession *)sharedInstance;

#pragma mark 启动日志组件
/// 启动日志组件
/// - Parameters:
///   - domainUrl: 服务地址
///   - secretKey: 服务密钥
///   - delegate: 日志代理
- (void)startLoggerSession:(NSString *)loggerHost secretKey:(NSString *)secretKey delegate:(nullable id <VCSLoggerSessionDelegate>)delegate;

#pragma mark 变更服务地址
/// 变更服务地址
/// - Parameters:
///   - domainUrl: 服务地址
///   - secretKey: 服务密钥
- (void)changeLoggerHost:(NSString *)loggerHost secretKey:(NSString *)secretKey;

#pragma mark 追加行为日志
/// 追加行为日志
/// - Parameter loggerParamItem: 行为日志
- (void)addLoggerWithItem:(VCSLoggerParamItem *)loggerParamItem;

#pragma mark 追加实时日志
/// 追加实时日志
/// - Parameter metricParamItem: 实时日志
- (void)addMetricWithItem:(VCSMetricParamItem *)metricParamItem;

#pragma mark 上报黑窗口重定向日志
/// 上报黑窗口重定向日志
/// - Parameter filePath: 文件路径
/// - Parameter folderName: 文件夹名称
- (void)uploadRedirectWithFilePath:(NSString *)filePath folderName:(NSString *)folderName;

#pragma mark 上报行为日志以及实时日志
/// 上报行为日志以及实时日志
- (void)uploadOtherLogs;

#pragma mark 是否启用日志上报
/// 是否启用日志上报
/// - Parameter enabled: YES-启用 NO-关闭
- (void)enableUploadLogs:(BOOL)enabled;

#pragma mark 绑定当前会议号码
/// 绑定当前会议号码
/// - Parameter roomNo: 会议号码
- (void)bindRoomNo:(nullable NSString *)roomNo;

#pragma mark 追加打印日志
/// 追加打印日志
/// - Parameter format: 版式串
+ (void)VCSLOGGER:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

@end

NS_ASSUME_NONNULL_END
