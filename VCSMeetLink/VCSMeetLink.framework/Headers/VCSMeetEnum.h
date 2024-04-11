//
//  VCSMeetEnum.h
//  VCSMeetLink
//
//  Created by SailorGa on 2024/3/14.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#pragma mark - 命令事件类型
/**
 命令事件类型
 
 - VCSMeetCommandEventAudio: 音频状态
 - VCSMeetCommandEventVideo: 视频状态
 - VCSMeetCommandEventRole: 角色状态
 - VCSMeetCommandEventHandup: 举手状态
 - VCSMeetCommandEventEnter:  成员进入
 - VCSMeetCommandEventExit: 成员退出
 - VCSMeetCommandEventBegin: 会议开始
 - VCSMeetCommandEventEnded: 会议结束
 - VCSMeetCommandEventInvite:  邀请参会
 - VCSMeetCommandEventPassthrough:  消息透传
 - VCSMeetCommandEventKickout: 被踢出房间
 - VCSMeetCommandEventInitiativeExit: 主动退出房间
 */
typedef enum : NSInteger {
    
    VCSMeetCommandEventAudio = 2000,
    VCSMeetCommandEventVideo,
    VCSMeetCommandEventRole,
    VCSMeetCommandEventHandup,
    VCSMeetCommandEventEnter,
    VCSMeetCommandEventExit,
    VCSMeetCommandEventBegin,
    VCSMeetCommandEventEnded,
    VCSMeetCommandEventInvite,
    VCSMeetCommandEventPassthrough,
    VCSMeetCommandEventKickout,
    VCSMeetCommandEventInitiativeExit
} VCSMeetCommandEvent;


NS_ASSUME_NONNULL_END
