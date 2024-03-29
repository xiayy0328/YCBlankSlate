//
//  YCBlankSlateHanlder.h
//  YCBlankSlateDemo
//
//  Created by xiayingying on 2018/8/31.
//  Copyright © 2018年 ejl. All rights reserved.
//  handler基类，请通过子类来实现定制化的配置
//

#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>
#if __has_include(<DZNEmptyDataSet/UIScrollView+EmptyDataSet.h>)
#import <DZNEmptyDataSet/UIScrollView+EmptyDataSet.h>
#else
#import "UIScrollView+EmptyDataSet.h"
#endif

/**数据加载的状态*/
typedef NS_OPTIONS(NSUInteger, YCDataLoadState) {
    YCDataLoadStateIdle     = 1 << 0, //闲置
    YCDataLoadStateLoading  = 1 << 1, //加载中
    YCDataLoadStateEmpty    = 1 << 2, //数据空
    YCDataLoadStateFailed   = 1 << 3, //加载失败
};

/**所有点状态*/
FOUNDATION_EXTERN NSInteger const YCDataLoadStateAll;

@interface YCBlankSlateHanlder : NSObject<DZNEmptyDataSetDelegate, DZNEmptyDataSetSource>

@property (nonatomic,weak) UIScrollView *scrollView;
@property (nonatomic,assign) YCDataLoadState state;

/**初始化配置 子类override父类的方法时，必须在方法内部调用super的这个方法*/
- (void)configure NS_REQUIRES_SUPER;

@end
