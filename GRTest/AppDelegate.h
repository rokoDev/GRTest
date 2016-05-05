//
//  AppDelegate.h
//  GRTest
//
//  Created by roko on 5/3/16.
//  Copyright © 2016 roko. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GLView.h"

@class ViewController;

@interface AppDelegate : UIResponder <UIApplicationDelegate> {
    UIWindow * m_window;
    GLView * m_view;
}

@property (nonatomic, readonly) ViewController * viewController;


@end

