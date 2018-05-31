//
//  QAVStatisticsUELog.h
//  CommonQAV_a
//
//  Created by qitmac000482 on 2018/5/2.
//  Copyright © 2018年 Qunar.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "StatisticsUELogConfig.h"
#import "StatisticsUELogProtocol.h"
//#import "UINavigationController+QAVStatistics.h"

typedef enum : NSUInteger
{
    eTraceEventTypeNomal, //外部唤起
    eTraceEventTypeInner, //内部唤起
}eTraceEventType;

@interface QAVStatisticsUELog : NSObject

//单例
+ (id)getInstance;

//开启UELog统计并设置表示：pid：APP的唯一ID； vid：版本表示； cid：渠道表示；uid：设备标识
//注意：请勿多次调用loadStatistics函数。loadStatistics应该只被调用一次
- (void)loadStatisticsWithPid:(NSString *)pid
                      withVid:(NSString *)vid
                      withCid:(NSString *)cid
                      withUid:(NSString *)uid;


//开启UELog统计
- (void)loadStatistics;

//关闭UELog统计
- (void)unLoadStatistics;

//向服务端发送统计
- (void)sendStatistics;

//保存统计数据
- (void)saveStatistics;

//保存并发送采集
- (void)saveAndSendStatistics;

//更新最小、最大上传数量
- (void)updateMinUpload:(NSNumber *)minUpload WithMaxUpload:(NSNumber *)maxUpload;

#if (BETA_BUILD == 1)
//设置是否展示UE日志
- (void)openShowLog:(BOOL)isShowlog;

//是否展示UE日志
- (void)isOpenShowLog;
#endif

@property (nonatomic) Class<StatisticsUELogConfig> config;

//自定义事件主动记录(接受记录数据，准备进入异步线程) 此方法只为各个分类提供，不得调用
- (void)addStatisticsWithString:(NSString *)string;
- (NSMutableArray *)gestureTargets;

@end


